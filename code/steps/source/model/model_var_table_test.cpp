#include "header/basic/test_macro.h"
#include "header/model/model_var_table_test.h"
#include "header/basic/utility.h"

#ifdef ENABLE_STEPS_TEST
using namespace std;

MODEL_VAR_TABLE_TEST::MODEL_VAR_TABLE_TEST()
{
    TEST_ADD(MODEL_VAR_TABLE_TEST::test_clear);
    TEST_ADD(MODEL_VAR_TABLE_TEST::test_add_get_variable_name_index_pair);
}


void MODEL_VAR_TABLE_TEST::setup()
{
    table = new MODEL_VAR_TABLE;
}

void MODEL_VAR_TABLE_TEST::tear_down()
{
    delete table;

    show_test_end_information();
}

void MODEL_VAR_TABLE_TEST::test_clear()
{
    show_test_information_for_function_of_class(__FUNCTION__,"MODEL_VAR_TABLE_TEST");

    table->add_variable_name_index_pair("abc", 0);
    TEST_ASSERT((*table)["abc"]==0);
    TEST_ASSERT((*table)[0]=="ABC");
    table->clear();
    TEST_ASSERT((*table)["abc"]==INDEX_NOT_EXIST);
}

void MODEL_VAR_TABLE_TEST::test_add_get_variable_name_index_pair()
{
    show_test_information_for_function_of_class(__FUNCTION__,"MODEL_VAR_TABLE_TEST");

    table->add_variable_name_index_pair("abc", 0);
    TEST_ASSERT((*table)["abc"]==0);
    TEST_ASSERT((*table)[0]=="ABC");
    TEST_ASSERT((*table).size()==1);
    table->add_variable_name_index_pair("def", 1);
    TEST_ASSERT((*table)["abc"]==0);
    TEST_ASSERT((*table)[0]=="ABC");
    TEST_ASSERT((*table)["def"]==1);
    TEST_ASSERT((*table)[1]=="DEF");
    TEST_ASSERT((*table).size()==2);
    table->add_variable_name_index_pair("def", 2);
    TEST_ASSERT((*table)["abc"]==0);
    TEST_ASSERT((*table)[0]=="ABC");
    TEST_ASSERT((*table)["def"]==1);
    TEST_ASSERT((*table)[1]=="DEF");
    TEST_ASSERT((*table)[2]=="");
    TEST_ASSERT((*table).size()==3);
    table->add_variable_name_index_pair("acf", 0);
    TEST_ASSERT((*table)["abc"]==0);
    TEST_ASSERT((*table)[0]=="ABC");
    TEST_ASSERT((*table)["def"]==1);
    TEST_ASSERT((*table)[1]=="DEF");
    TEST_ASSERT((*table).size()==3);
    TEST_ASSERT((*table)["acf"]==INDEX_NOT_EXIST);
}

#endif
