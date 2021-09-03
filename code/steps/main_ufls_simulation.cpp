#include <istream>
#include <iostream>
#include "header/power_system_database.h"
#include "header/steps_namespace.h"
#include "header/toolkit/powerflow_solver/powerflow_solver.h"
#include "header/toolkit/dynamic_simulator/dynamic_simulator.h"
#include "header/basic/utility.h"
#include "header/data_imexporter/psse_imexporter.h"
#include "header/model/all_supported_models.h"
using namespace std;

int main()
{
    POWER_SYSTEM_DATABASE& psdb = default_toolkit.get_power_system_database();

    PSSE_IMEXPORTER importer(default_toolkit);

    importer.load_powerflow_data("../../../bench/IEEE39.raw");
    importer.load_dynamic_data("../../../bench/IEEE39_GENROU_SEXS_IEEEG1_UFLS.dyr");

    POWERFLOW_SOLVER solver(default_toolkit);

    solver.set_max_iteration(30);
    solver.set_allowed_max_active_power_imbalance_in_MW(0.00001);
    solver.set_allowed_max_reactive_power_imbalance_in_MVar(0.00001);
    solver.set_flat_start_logic(false);
    solver.set_transformer_tap_adjustment_logic(true);

    solver.solve_with_fast_decoupled_solution();

    DYNAMICS_SIMULATOR simulator(default_toolkit);
    default_toolkit.set_dynamic_simulation_time_step_in_s(0.01);

    simulator.set_allowed_max_power_imbalance_in_MVA(0.001);
    simulator.set_max_network_iteration(200);
    simulator.set_max_DAE_iteration(10);
    simulator.set_iteration_accelerator(0.8);

    simulator.prepare_meters();

    simulator.set_output_file("IEEE_39_bus_model_dynamic_test_result_GENROU_SEXS_IEEEG1_UFLS");

    // change spinning reserve
    double SR = 0.0001;
    vector<GENERATOR*> generators = psdb.get_all_generators();
    unsigned int n = generators.size();
    GENERATOR* gen;
    for(unsigned int i=0; i!=n; ++i)
    {
        gen = generators[i];
        double pgen = gen->get_p_generation_in_MW();
        double one_over_mbase = gen->get_one_over_mbase_in_one_over_MVA();
        double pmax = pgen*one_over_mbase+SR;

        TURBINE_GOVERNOR_MODEL* tg_model = gen->get_turbine_governor_model();
        if(tg_model!=NULL)
        {
            string model_name = tg_model->get_model_name();
            if(model_name=="IEEEG1")
            {
                IEEEG1* g1_model = (IEEEG1*) tg_model;
                g1_model->set_Pmax_in_pu(pmax);
            }
        }

        //SYNC_GENERATOR_MODEL* sync_model = gen->get_sync_generator_model();
        //sync_model->set_D(2.0);
    }


    simulator.start();
    simulator.run_to(1.0);

    for(unsigned int i=0; i!=n; ++i)
    {
        gen = generators[i];
        simulator.shed_generator(gen->get_device_id(), 0.25);
    }
/*
    DEVICE_ID did;
    did.set_device_type(STEPS_GENERATOR);
    TERMINAL terminal;
    terminal.append_bus(39);
    did.set_device_terminal(terminal);
    did.set_device_identifier_index(get_index_of_string("1"));

    simulator.trip_generator(did);

    terminal.clear();
    terminal.append_bus(38);
    did.set_device_terminal(terminal);
    simulator.trip_generator(did);

    terminal.clear();
    terminal.append_bus(37);
    did.set_device_terminal(terminal);
    simulator.trip_generator(did);
*/
    simulator.run_to(20);

    return 0;
}
