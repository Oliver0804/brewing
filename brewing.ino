#include "brewing.h"
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include <Timer.h>
#include <Event.h>
#include <Wire.h>
//#include <TimerOne.h>
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_LENGTH, LCD_HEIGHT); //G
int run_index = 1;
int run_mode = 0;
int workTime_hh = 0, workTime_mm = 0, workTime_ss;
int CT_hh, CT_mm, CT_ss;

Timer SYS_TIMER;
Timer CT_TIMER;

void setup() {
  Serial.begin(DEBUG_BAUD);//DEEBUG_COM
  Serial1.begin(RS485_BAUD);//RS485_COM to PID
  Serial2.begin(RS485_BAUD);//CONTROL CMD
  INIT_LCD();
  INIT_GPIO();
  if (EEPROM.read(EEPROM_SYSTEM_FIRST_RUN) == 0xFF) {
    EEPROM_RESET();
  } else {
    Serial.println("EEPROM READY");
  }
  /*
  * TIMER SETTING
  */
  SYS_TIMER.every(1000, UPDATA_SYS_TIMER);
  CT_TIMER.every(1000, COUNTDOWN_TIMER);
  /*
   * attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
   * Mega, Mega2560, MegaADK 2, 3, 18, 19, 20, 21
   */
  attachInterrupt(0, WORKING_CHANGE, CHANGE);
  /*
   * Test Function
   * void EEPROM_WRITE(int index, byte ACTION, int POSITION, int TEMP, int Time)
   */
  EEPROM_WRITE(1, HEATING, 10, 25, 1);
  EEPROM_WRITE(2, WAITING, 10, 25, 1);
  EEPROM_WRITE(3, COOLING, 10, 25, 1);
  EEPROM_WRITE(4, HEATING, 10, 25, 1);
  EEPROM_WRITE(5, WAITING, 10, 25, 1);
  EEPROM_WRITE(6, COOLING, 10, 25, 1);
  EEPROM_WRITE(7, PUMPING_1, 10, 25, 1);
  EEPROM_WRITE(8, END, 10, 25, 1);
  EEPROM.write(EEPROM_SYSTEM_ACTION_COUNT, 8);
}

void loop() {
  SYS_TIMER.update();
  if (run_mode == 1) {
    RUN_SCRIPT(run_index);
    run_index++;
  }
}

void WORKING_CHANGE() {
  run_mode = 1;
}

