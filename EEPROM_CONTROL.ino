void EEPROM_RESET() {
  for (int x = 0; x < EEPROM_MAX_ADDR; x++) {
    EEPROM.write(x, 0x00);
    delay(1);
  }
}
/*
 * a=EEPROM_ACTION
 * t=EEPROM_POSITION
 * d=EEPROM_TEMP
 * t=EEPROM_TIME
 */
 
void EEPROM_WRITE(int index, byte ACTION, int POSITION, int TEMP, int Time) {
  index *= 5;
  index += EEPROM_SCRIPT_START_ADDR;
  EEPROM.write(index + EEPROM_ACTION, ACTION);
  delay(5);
  EEPROM.write(index + EEPROM_POSITION, POSITION);
  delay(5);
  EEPROM.write(index + EEPROM_TEMP, TEMP);
  delay(5);
  EEPROM.write(index + EEPROM_WORKING_TIME, Time);
  delay(5);
}



