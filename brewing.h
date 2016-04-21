#ifndef _BREWING_H
#define _BREWING_H

#define DEBUG_MODE 1
/*
 * 參數
 */
#define EEPROM_MAX_ADDR           4000
#define DEBUG_BAUD                115200
#define RS485_BAUD                9600
#define E_STOP                    2
#define ACTIVE                    HIGH
#define INACTIVE                  LOW
#define SYS_DELAY                 100
//LCD
#define LCD_ADDR                  0x3F
#define LCD_LENGTH                20
#define LCD_HEIGHT                4

//步進馬達
#define FORWARD                   0
#define REVERSION                 1
#define STEPPER_DELAY             100

//限位開關
//Mega, Mega2560, MegaADK  2, 3, 18, 19, 20, 21
#define LEFT_LIMIT_SWITCH         18
#define RIGHT_LIMIT_SWITCH        19
#define BOTTOM_LIMIT_SWITCH       20

/*
 * 腳位
 */
#define STEPPER_MOTOR_1_STEP      22
#define STEPPER_MOTOR_1_DIR       23
#define STEPPER_MOTOR_2_STEP      24
#define STEPPER_MOTOR_2_DIR       25
#define PUMP_1                    26
#define PUMP_2                    27
#define FAN_1                     28
#define FAN_2                     29
#define HEATER_PIN                31
#define COOL_PIN                  32

/*
 * EEPROM 名稱定義
 */
#define EEPROM_SYSTEM_FIRST_RUN         0
#define EEPROM_SYSTEM_MODE              1
#define EEPROM_SYSTEM_ACTION_COUNT      2
#define EEPROM_SYSTEM_ACTION_COUNT_MAX  255
#define EEPROM_SCRIPT_START_ADDR        10
#define EEPROM_SCRIPT_END_ADDR          EEPROM_SCRIPT_START_ADDR+(EEPROM_SYSTEM_ACTION_COUNT_MAX*5)
#define EEPROM_ACTION                   1
#define EEPROM_POSITION                 2
#define EEPROM_TEMP                     3
#define EEPROM_WORKING_TIME             4
//#define EEPROM_PUMP_TIME              5

//動作
#define END                      0xAA
#define WAITING                  0x01
#define HEATING                  0x02
#define COOLING                  0x03
#define WASHING                  0x04
#define READ_TEMP                0x05
#define WAITING_TRIGGER          0x06
#define PUMPING_1                0x10
#define PUMPING_2                0x11
#define ADD_TO_ING_1             0x21
#define ADD_TO_ING_2             0x22

#endif
