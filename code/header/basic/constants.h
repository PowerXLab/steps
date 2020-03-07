#ifndef CONSTANTS_H
#define CONSTANTS_H

const unsigned int STEPS_1K = 1024;
const unsigned int STEPS_1M = 1048576;
const unsigned int STEPS_10M = 10485760;
const unsigned int STEPS_100M = 104857600;
const double PI = 3.1415926535897932384626433832795; // math pi
const double DOUBLE_PI = 6.283185307179586476925286766559; // 2*pi
const double HALF_PI = 1.5707963267948966192313216916398; // 0.5*pi = pi/2
const double QUARTER_PI = 0.78539816339744830961566084581988; // 0.25*pi = pi/4
const double THIRD_PI = 1.0471975511965977461542144610932; // 0.33333*pi = pi/3
const double ONE_OVER_PI = 0.31830988618379067153776752674503; // 1.0/pi
const double THREE_OVER_PI = 0.95492965855137201461330258023509; // 3.0/pi
const double ONE_OVER_DOUBLE_PI = 0.15915494309189533576888376337251; // 0.5/pi = 1.0/(2*pi)
const double PI_OVER_180 = 0.01745329251994329576923690768489; // pi/180
const double ONE_EIGHTY_OVER_PI = 57.295779513082320876798154814105; // 180/pi
const double SQRT2 = 1.4142135623730950488016887242097; // sqrt(2)
const double SQRT3 = 1.7320508075688772935274463415059; // sqrt(3)
const double SQRT6 = 2.4494897427831780981972840747059; // sqrt(6)
const double THREE_SQRT2_OVER_PI = 1.3504744742356591043327987865101; // 3*sqrt(2)/pi
const double PI_OVER_THREE_SQRT2 = 0.74048048969306104116931349834345; // pi/(3*sqrt(2))
const double SQRT6_OVER_PI = 0.77969680123367610790586805027326; // sqrt(6)/pi
const double FLOAT_EPSILON = 1e-6;
const double DOUBLE_EPSILON = 1e-10;
const double DSTATE_THRESHOLD = 100.0;
const unsigned int INDEX_NOT_EXIST = 1000000000;
const double INFINITE_THRESHOLD = 1e9;

const unsigned int STEPS_MAX_TOOLKIT_SIZE = 1000;
const unsigned int STEPS_MAX_TEMP_CHAR_BUFFER_SIZE = 500;
const unsigned int STEPS_MODEL_FEEDBACK_LOOP_INTEGRATION_COUNT = 5;
const unsigned int STEPS_MAX_LOAD_RELAY_STAGE = 50;
const unsigned int STEPS_MAX_RELAY_COUNT = 5;
const unsigned int STEPS_MAX_STABILIZER_INPUT_SIGNAL_SLOT = 5;
const unsigned int STEPS_MAX_CONTINUOUS_BUFFER_SIZE = 1000;
const unsigned int STEPS_MAX_WIND_RECORD_SIZE = 100;
const unsigned int STEPS_MAX_WIND_TURBINE_MAXIMUM_LOOP = 100;
const unsigned int STEPS_MAX_WIND_TURBINE_POWER_SPEED_LOOKUP_TABLE_SIZE = 24;
const unsigned int STEPS_MAX_VDCOL_TABLE_SIZE = 10;
const unsigned int STEPS_MAX_HVDC_BYPASS_RECORD_SIZE = 10;
const unsigned int STEPS_SHORT_STRING_SIZE = 64;
const unsigned int STEPS_MEDIUM_STRING_SIZE = 128;
const unsigned int STEPS_LONG_STRING_SIZE = 256;
const unsigned int STEPS_METER_TYPE_STRING_SIZE = STEPS_SHORT_STRING_SIZE;
const unsigned int STEPS_MODEL_MAX_ALLOWED_DEVICE_COUNT = 2;

const int STEPS_MAGIC1 = 621877636;
const int STEPS_MAGIC2 = 40966531;
const int STEPS_MAGIC3 = 20389910;
const int STEPS_MAGIC4 = 7807000;

#ifndef get_variable_name
    #define get_variable_name(x) #x
#endif // get_variable_name(x)


#endif // CONSTANTS_H
