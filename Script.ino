/*
#define WAITING                  0x01
#define HEATING                  0x02
#define COOLING                  0x03
#define WASHING                  0x04
#define PUMPING_1                0x10
#define PUMPING_2                0x11
EEPROM.read
EEPROM.write
 */

int RUN_SCRIPT(int index) {
  byte scpipt_action = 0x00;
  byte scpipt_position = 0x00;
  byte scpipt_temp = 0x00;
  byte scpipt_working_time = 0x00;
  index *= 5;
  index += EEPROM_SCRIPT_START_ADDR;
  if (index > EEPROM_SCRIPT_END_ADDR) {
    return 1;
  }
  scpipt_action = EEPROM.read(index + EEPROM_ACTION); delay(1);
  scpipt_position = EEPROM.read(index + EEPROM_POSITION); delay(1);
  scpipt_temp = EEPROM.read(index + EEPROM_TEMP); delay(1);
  scpipt_working_time = EEPROM.read(index + EEPROM_WORKING_TIME); delay(1);

  Serial.print("INDEX:"); Serial.println(index);
  Serial.print("scpipt_action:"); Serial.println(scpipt_action, HEX);
  Serial.print("scpipt_position:"); Serial.println(scpipt_position, HEX);
  Serial.print("scpipt_temp:"); Serial.println(scpipt_temp, HEX);
  Serial.print("scpipt_working_time:"); Serial.println(scpipt_working_time, HEX);
  delay(500);
  if (scpipt_action == WAITING) {
    LCD_ACTION("WAITING");
    RUN_WAITING();
    SET_CT_TIME(scpipt_working_time);
  }
  if (scpipt_action == END) {
    LCD_ACTION("END         ");
    run_mode = 0;
    run_index = 0;
  }
  if (scpipt_action == HEATING) {
    LCD_ACTION("HEATING");
    RUN_HEATING(1);
    SET_CT_TIME(scpipt_working_time);
  }
  if (scpipt_action == COOLING) {
    LCD_ACTION("COOLING");
    RUN_COOLING(1);
    SET_CT_TIME(scpipt_working_time);
  }
  if (scpipt_action == WASHING) {
    LCD_ACTION("WASHING");
    RUN_WASHING();
    SET_CT_TIME(scpipt_working_time);
  }
  if (scpipt_action == PUMPING_1) {
    LCD_ACTION("PUMPING1");
    RUN_PUMPING_1(0);
    SET_CT_TIME(scpipt_working_time);
  }
  if (scpipt_action == PUMPING_2) {
    LCD_ACTION("PUNPING2");
    RUN_PUMPING_2(0);
    SET_CT_TIME(scpipt_working_time);
  }
  if (scpipt_action == READ_TEMP) {
    LCD_ACTION("READ_TEMP");

    SET_CT_TIME(scpipt_working_time);
  }
  if (scpipt_action == WAITING_TRIGGER) {
    LCD_ACTION("WAITING_TRIGGER");

    SET_CT_TIME(scpipt_working_time);
  }
}



