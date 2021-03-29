#include "header/basic/test_macro.h"
#include "header/basic/utility_test.h"
#include "header/steps_namespace.h"
#include "header/prepare_for_tests/prepare_models_for_test.h"
#include <cstdlib>
#include <cstring>
#include <istream>
#include <iostream>
#include <cstdio>
#include <cmath>

#ifdef ENABLE_STEPS_TEST
using namespace std;

UTILITY_TEST::UTILITY_TEST()
{
    //TEST_ADD(UTILITY_TEST::test_num2str);
    TEST_ADD(UTILITY_TEST::test_str2int);
    TEST_ADD(UTILITY_TEST::test_str2double);
    TEST_ADD(UTILITY_TEST::test_string2upper);

    TEST_ADD(UTILITY_TEST::test_get_integer_data);
    TEST_ADD(UTILITY_TEST::test_get_double_data);
    TEST_ADD(UTILITY_TEST::test_get_string_data);

    TEST_ADD(UTILITY_TEST::test_rad2deg);
    TEST_ADD(UTILITY_TEST::test_deg2rad);
    TEST_ADD(UTILITY_TEST::test_round_angle_to_PI);
    TEST_ADD(UTILITY_TEST::test_steps_fast_complex_abs);
    TEST_ADD(UTILITY_TEST::test_steps_fast_complex_arg);
    TEST_ADD(UTILITY_TEST::test_steps_fast_sin);
    TEST_ADD(UTILITY_TEST::test_steps_fast_cos);
    TEST_ADD(UTILITY_TEST::test_steps_fast_tan);
    TEST_ADD(UTILITY_TEST::test_steps_fast_sqrt);
    TEST_ADD(UTILITY_TEST::test_steps_fast_inv_sqrt);

    TEST_ADD(UTILITY_TEST::test_radps2hz);
    TEST_ADD(UTILITY_TEST::test_hz2radps);

    TEST_ADD(UTILITY_TEST::test_trim_string);
    TEST_ADD(UTILITY_TEST::test_replace_string_contents);
    TEST_ADD(UTILITY_TEST::test_shrink_sucessive_blanks);
    TEST_ADD(UTILITY_TEST::test_string2csv);
    TEST_ADD(UTILITY_TEST::test_split_string);
    TEST_ADD(UTILITY_TEST::test_string_vector2csv);

    TEST_ADD(UTILITY_TEST::test_is_file_exist);
    TEST_ADD(UTILITY_TEST::test_generate_and_delete_toolkit);
    TEST_ADD(UTILITY_TEST::test_get_toolkit);


    //TEST_ADD(UTILITY_TEST::test_redirect_and_recover_stdout);

    //TEST_ADD(UTILITY_TEST::test_set_get_dynamic_simulation_time_step);
    //TEST_ADD(UTILITY_TEST::test_set_get_dynamic_simulation_time);
}

void UTILITY_TEST::setup()
{
    ;
}

void UTILITY_TEST::tear_down()
{
    POWER_SYSTEM_DATABASE& psdb = default_toolkit.get_power_system_database();
    psdb.clear();

    show_test_end_information();
}

void UTILITY_TEST::test_get_next_alphabeta()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='A');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='B');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='C');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='D');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='E');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='F');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='G');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='H');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='I');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='J');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='K');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='L');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='M');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='N');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='O');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='P');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='Q');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='R');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='S');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='T');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='U');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='V');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='W');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='X');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='Y');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='Z');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='A');
    TEST_ASSERT(default_toolkit.get_next_alphabeta()=='B');
}

void UTILITY_TEST::test_num2str()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(num2str(123)=="123"); // integer
    TEST_ASSERT(num2str(123.45)=="123.45"); // float
    TEST_ASSERT(num2str(123456.7)=="123456.7");
    TEST_ASSERT(num2str(1000000)=="1E+6");
}

void UTILITY_TEST::test_str2int()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(str2int("123")==123);
    TEST_ASSERT(str2int("123.45")==123);
    TEST_ASSERT(str2int("123.5")==124);
}
void UTILITY_TEST::test_str2double()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(fabs(str2double("123.0")-123)<FLOAT_EPSILON);
    TEST_ASSERT(fabs(str2double("123.45")-123.45)<FLOAT_EPSILON);
    TEST_ASSERT(fabs(str2double("1.23e3")-1230)<FLOAT_EPSILON);
}


void UTILITY_TEST::test_get_integer_data()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(get_integer_data("10","2")==10);
    TEST_ASSERT(get_integer_data("","2")==2);
}

void UTILITY_TEST::test_get_double_data()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(fabs(get_double_data("10.0","100.0")-10.0)<FLOAT_EPSILON);
    TEST_ASSERT(fabs(get_double_data("","100.0")-100.0)<FLOAT_EPSILON);
}

void UTILITY_TEST::test_get_string_data()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(get_string_data("AB","DEF")=="AB");
    TEST_ASSERT(get_string_data("'AB'","DEF")=="AB");
    TEST_ASSERT(get_string_data("","DEF")=="DEF");
    TEST_ASSERT(get_string_data("1","1")=="1");
}


void UTILITY_TEST::test_string2upper()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(string2upper("abc DeF.")=="ABC DEF.");
}

void UTILITY_TEST::test_rad2deg()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    double angle = 0.234;
    double angle2 = angle*180.0/PI;
    TEST_ASSERT(fabs(rad2deg(angle)-angle2)<FLOAT_EPSILON);
}

void UTILITY_TEST::test_deg2rad()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    double angle = 23.45;
    double angle2 = angle*PI/180.0;
    TEST_ASSERT(fabs(deg2rad(angle)-angle2)<FLOAT_EPSILON);
}

void UTILITY_TEST::test_round_angle_to_PI()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    double angle = 3.2;
    TEST_ASSERT(fabs(round_angle_in_rad_to_PI(angle)-(angle-DOUBLE_PI))<FLOAT_EPSILON);

    angle = -3.2;
    TEST_ASSERT(fabs(round_angle_in_rad_to_PI(angle)-(angle+DOUBLE_PI))<FLOAT_EPSILON);
}

void UTILITY_TEST::test_steps_fast_complex_abs()
{
	show_test_information_for_function_of_class(__FUNCTION__, "UTILITY_TEST");

	complex<double> V;
	V = complex<double>(0.0, 0.0);
	TEST_ASSERT(fabs(steps_fast_complex_abs(V) - abs(V))<FLOAT_EPSILON);
	V = complex<double>(1.0, 0.0);
	TEST_ASSERT(fabs(steps_fast_complex_abs(V) - abs(V))<FLOAT_EPSILON);
	V = complex<double>(0.0, 1.0);
	TEST_ASSERT(fabs(steps_fast_complex_abs(V) - abs(V))<FLOAT_EPSILON);
}

void UTILITY_TEST::test_steps_fast_complex_arg()
{
	show_test_information_for_function_of_class(__FUNCTION__, "UTILITY_TEST");

	complex<double> V;
	V = complex<double>(0.0, 0.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(1.0, 0.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(-1.0, 0.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(0.0, 1.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(0.0, -1.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(1.0, 1.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(-1.0, 1.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(-1.0, -1.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
	V = complex<double>(1.0, -1.0);
	TEST_ASSERT(fabs(steps_fast_complex_arg(V) - arg(V))<FLOAT_EPSILON);
}


void UTILITY_TEST::test_steps_fast_sin()
{
	show_test_information_for_function_of_class(__FUNCTION__, "UTILITY_TEST");

	double angle = 0.01;
	TEST_ASSERT(fabs(steps_fast_sin(angle)-sin(angle))<1e-8);
	angle = 0.1;
	TEST_ASSERT(fabs(steps_fast_sin(angle)-sin(angle))<1e-8);
	angle = 1.0;
	TEST_ASSERT(fabs(steps_fast_sin(angle)-sin(angle))<1e-8);
	angle = 10.0;
	TEST_ASSERT(fabs(steps_fast_sin(angle)-sin(angle))<1e-8);
}

void UTILITY_TEST::test_steps_fast_cos()
{
	show_test_information_for_function_of_class(__FUNCTION__, "UTILITY_TEST");

	double angle = 0.01;
	TEST_ASSERT(fabs(steps_fast_cos(angle)-cos(angle))<1e-8);
	angle = 0.1;
	TEST_ASSERT(fabs(steps_fast_cos(angle)-cos(angle))<1e-8);
	angle = 1.0;
	TEST_ASSERT(fabs(steps_fast_cos(angle)-cos(angle))<1e-8);
	angle = 10.0;
	TEST_ASSERT(fabs(steps_fast_cos(angle)-cos(angle))<1e-8);
}

void UTILITY_TEST::test_steps_fast_tan()
{
	show_test_information_for_function_of_class(__FUNCTION__, "UTILITY_TEST");

	double angle = 0.01;
	TEST_ASSERT(fabs(steps_fast_tan(angle)-tan(angle))<1e-8);
	angle = 0.1;
	TEST_ASSERT(fabs(steps_fast_tan(angle)-tan(angle))<1e-8);
	angle = 1.0;
	TEST_ASSERT(fabs(steps_fast_tan(angle)-tan(angle))<1e-8);
	angle = 10.0;
	TEST_ASSERT(fabs(steps_fast_tan(angle)-tan(angle))<1e-8);
}

void UTILITY_TEST::test_steps_fast_sqrt()
{
	show_test_information_for_function_of_class(__FUNCTION__, "UTILITY_TEST");

	double x = 0.01;
	TEST_ASSERT(fabs(steps_fast_sqrt(x)-sqrt(x))<1e-6);
	x = 0.1;
	TEST_ASSERT(fabs(steps_fast_sqrt(x)-sqrt(x))<1e-6);
	x = 1.0;
	TEST_ASSERT(fabs(steps_fast_sqrt(x)-sqrt(x))<1e-6);
	x = 10.0;
	TEST_ASSERT(fabs(steps_fast_sqrt(x)-sqrt(x))<1e-6);
}

void UTILITY_TEST::test_steps_fast_inv_sqrt()
{
	show_test_information_for_function_of_class(__FUNCTION__, "UTILITY_TEST");

	double x = 0.01;
	TEST_ASSERT(fabs(steps_fast_inv_sqrt(x)-1.0/sqrt(x))<1e-4);
	x = 0.1;
	TEST_ASSERT(fabs(steps_fast_inv_sqrt(x)-1.0/sqrt(x))<1e-4);
	x = 1.0;
	TEST_ASSERT(fabs(steps_fast_inv_sqrt(x)-1.0/sqrt(x))<1e-4);
	x = 10.0;
	TEST_ASSERT(fabs(steps_fast_inv_sqrt(x)-1.0/sqrt(x))<1e-4);
}

void UTILITY_TEST::test_radps2hz()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    double w = 1.0;
    double f = w*ONE_OVER_DOUBLE_PI;
    TEST_ASSERT(fabs(radps2hz(w)-f)<FLOAT_EPSILON);
}

void UTILITY_TEST::test_hz2radps()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    double f = 1.0;
    double w = f*DOUBLE_PI;
    TEST_ASSERT(fabs(hz2radps(f)-w)<FLOAT_EPSILON);
}

void UTILITY_TEST::test_trim_string()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    string str=" \t  \n \t\nA\tB C\nD\n\t  \t \n";
    TEST_ASSERT(trim_string(str)=="A\tB C\nD");

}
void UTILITY_TEST::test_replace_string_contents()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    string str="abAB12''\"\"";
    TEST_ASSERT(replace_string_contents(str, "ab", "AB")=="ABAB12''\"\"");
    TEST_ASSERT(replace_string_contents(str, "12", "21")=="abAB21''\"\"");
    TEST_ASSERT(replace_string_contents(str, "'", "\"")=="abAB12\"\"\"\"");
    TEST_ASSERT(replace_string_contents(str, "\"", "'")=="abAB12''''");
    TEST_ASSERT(replace_string_contents(str, "c", "C")=="abAB12''\"\"");

}
void UTILITY_TEST::test_shrink_sucessive_blanks()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    string str="a    bc  \t d";
    TEST_ASSERT(shrink_sucessive_blanks(str)=="a bc d");
}
void UTILITY_TEST::test_string2csv()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");
    string str="1 2  3,4 ,5, 6 , 7 '8 9' \" 0 1\"";
    str = string2csv(str);
    TEST_ASSERT(str=="1,2,3,4,5,6,7,\"8 9\",\" 0 1\"");

}
void UTILITY_TEST::test_split_string()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

}
void UTILITY_TEST::test_string_vector2csv()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");
    vector<string> vec;
    vec.push_back("a");
    vec.push_back("b");
    vec.push_back("c");
    vec.push_back("d");
    vec.push_back("");
    vec.push_back("e");
    vec.push_back(" ");
    vec.push_back("f");
    vec.push_back("g");
    TEST_ASSERT(string_vector2csv(vec)=="a, b, c, d, , e,  , f, g");
}

void UTILITY_TEST::test_is_file_exist()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    TEST_ASSERT(is_file_exist("../../../bench/ieee9.raw")==true);
    TEST_ASSERT(is_file_exist("sample2.raw")==false);
}
void UTILITY_TEST::test_generate_and_delete_toolkit()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    ostringstream osstream;
    osstream<<"If utility test stops at here, check if the configuration in steps_config.json is too great.\n"
            <<"When you run STEPS in parallel mode, too great capacity may lead to failure of memory allocation, and STEPS may quit.";
    default_toolkit.show_information_with_leading_time_stamp(osstream);

    for(unsigned int k=0; k!=10; ++k)
    {
        TEST_ASSERT(toolkits[k]==NULL);
    }

    unsigned int i=INFINITE_THRESHOLD;
    i = generate_new_toolkit();
    TEST_ASSERT(i==0);
    TEST_ASSERT(toolkits[i]!=NULL);
    TEST_ASSERT(toolkits[i]->get_toolkit_name()=="TK 0000");
    delete_toolkit(i);
    TEST_ASSERT(toolkits[i]==NULL);

    for(unsigned int k=0; k!=3; ++k)
    {
        i = generate_new_toolkit();
        TEST_ASSERT(i==k);
        TEST_ASSERT(toolkits[i]!=NULL);
        TEST_ASSERT(get_toolkit_count()==i+1);
        if(toolkits[i]!=NULL)
            toolkits[i]->show_information_with_leading_time_stamp("You should find this message in log.");
        else
            toolkits[i]->show_information_with_leading_time_stamp("You should NOT find this message in log.");
    }
    for(unsigned int k=0; k!=3; ++k)
    {
        delete_toolkit(k);
        TEST_ASSERT(toolkits[k]==NULL);
    }
}
void UTILITY_TEST::test_get_toolkit()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    ostringstream osstream;
    osstream<<"If utility test stops at here, check if the configuration in steps_config.json is too great.\n"
            <<"When you run STEPS in parallel mode, too great capacity may lead to failure of memory allocation, and STEPS may quit.";
    default_toolkit.show_information_with_leading_time_stamp(osstream);

    for(unsigned int k=0; k!=3; ++k)
    {
        generate_new_toolkit();
    }
    TEST_ASSERT(&get_toolkit(INDEX_NOT_EXIST)==&default_toolkit);
    for(unsigned int k=0; k!=3; ++k)
    {
        TEST_ASSERT(&(get_toolkit(k))==toolkits[k]);
    }
    for(unsigned int k=3; k!=6; ++k)
    {
        TEST_ASSERT(&(get_toolkit(k))==&(default_toolkit));
    }
    for(unsigned int k=0; k!=3; ++k)
    {
        delete_toolkit(k);
    }
}
/*void UTILITY_TEST::test_redirect_and_close_log_file()
{
    show_test_information_for_function_of_class(__FUNCTION__,"UTILITY_TEST");

    default_toolkit.open_log_file("test_log/test_redirect_stdout.dat");
    show_information_with_leading_time_stamp_with_default_toolkit("This is a test line for redirecting stdout to this file.");
    show_information_with_leading_time_stamp_with_default_toolkit("This is the second test line for redirecting stdout to this file.");

    default_toolkit.close_log_file();
    show_information_with_leading_time_stamp_with_default_toolkit("This line should be outputted to stdout.");
}
*/

#endif
