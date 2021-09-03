#include "header/basic/test_macro.h"
#include "header/model/sg_models/sg_model_test.h"
#include "header/basic/utility.h"
#include "header/steps_namespace.h"
#include <cstdlib>
#include <cstring>
#include <istream>
#include <iostream>
#include <cstdio>
#include <cmath>

#ifdef ENABLE_STEPS_TEST
using namespace std;

SG_MODEL_TEST::SG_MODEL_TEST()
{
    ;
}

void SG_MODEL_TEST::setup()
{
    POWER_SYSTEM_DATABASE& psdb = default_toolkit.get_power_system_database();
    psdb.clear();
    psdb.set_allowed_max_bus_number(100);
    psdb.set_system_base_power_in_MVA(100.0);

    BUS bus(default_toolkit);
    bus.set_bus_number(1);
    bus.set_bus_type(PV_TYPE);
    bus.set_base_voltage_in_kV(21.0);
    bus.set_base_frequency_in_Hz(50.0);
    bus.set_positive_sequence_voltage_in_pu(1.0);
    bus.set_positive_sequence_angle_in_rad(0.0);

    psdb.append_bus(bus);

    GENERATOR generator(default_toolkit);
    generator.set_generator_bus(1);
    generator.set_identifier("#1");
    generator.set_status(true);
    generator.set_mbase_in_MVA(200.0);
    generator.set_source_impedance_in_pu(complex<double>(0.0, 0.1));
    generator.set_p_generation_in_MW(100.0);
    generator.set_q_generation_in_MVar(30.0);

    psdb.append_generator(generator);
}

void SG_MODEL_TEST::tear_down()
{
    POWER_SYSTEM_DATABASE& psdb = default_toolkit.get_power_system_database();
    psdb.clear();
}

GENERATOR* SG_MODEL_TEST::get_test_generator()
{
    DEVICE_ID did;
    did.set_device_type(STEPS_GENERATOR);
    TERMINAL terminal;
    terminal.append_bus(1);
    did.set_device_terminal(terminal);
    did.set_device_identifier_index(get_index_of_string("#1"));
    POWER_SYSTEM_DATABASE& psdb = default_toolkit.get_power_system_database();
    return psdb.get_generator(did);
}

SYNC_GENERATOR_MODEL* SG_MODEL_TEST::get_test_sync_generator_model()
{
    GENERATOR* genptr = get_test_generator();
    if(genptr!=NULL)
        return genptr->get_sync_generator_model();
    else
        return NULL;
}

EXCITER_MODEL* SG_MODEL_TEST::get_test_exciter_model()
{
    GENERATOR* genptr = get_test_generator();
    if(genptr!=NULL)
        return genptr->get_exciter_model();
    else
        return NULL;
}

STABILIZER_MODEL* SG_MODEL_TEST::get_test_stabilizer_model()
{
    GENERATOR* genptr = get_test_generator();
    if(genptr!=NULL)
        return genptr->get_stabilizer_model();
    else
        return NULL;
}

COMPENSATOR_MODEL* SG_MODEL_TEST::get_test_compensator_model()
{
    GENERATOR* genptr = get_test_generator();
    if(genptr!=NULL)
        return genptr->get_compensator_model();
    else
        return NULL;
}

TURBINE_GOVERNOR_MODEL* SG_MODEL_TEST::get_test_turbine_governor_model()
{
    GENERATOR* genptr = get_test_generator();
    if(genptr!=NULL)
        return genptr->get_turbine_governor_model();
    else
        return NULL;
}

TURBINE_LOAD_CONTROLLER_MODEL* SG_MODEL_TEST::get_test_turbine_load_controller_model()
{
    GENERATOR* genptr = get_test_generator();
    if(genptr!=NULL)
        return genptr->get_turbine_load_controller_model();
    else
        return NULL;
}


#endif
