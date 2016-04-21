/*LCD Function
    LiquidCrystal()
    begin()
    clear()
    home()
    setCursor()
    write()
    print()
    cursor()
    noCursor()
    blink()
    noBlink()
    display()
    noDisplay()
    scrollDisplayLeft()
    scrollDisplayRight()
    autoscroll()
    noAutoscroll()
    leftToRight()
    rightToLeft()
    createChar()
 */
char LCD_BUFF[20];


void INIT_LCD() {
  lcd.init();
  lcd.backlight();
  lcd.cursor();
  lcd.setCursor(0, 0);
  //lcd.noBacklight();
  lcd.setCursor(0, 0);
  lcd.print("BREWING SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("LOADING...");
  lcd.setCursor(0, 2);
  for (int loading = 0; loading < 100; loading++) {
    delay(10);
    if ((loading % 10) == 0) {
      lcd.write(0xFF);
      lcd.write(0xFF);
    }
  }
  lcd.setCursor(0, 3);
  lcd.print("SYSTEM READY!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BREWING SYSTEM");
  LCD_ACTION("");
}
void LCD_TITEL() {
  lcd.setCursor(0, 0);
  sprintf(LCD_BUFF, "%s (%000d)", "BREWING SYSTEM", EEPROM.read(EEPROM_SYSTEM_ACTION_COUNT));
  lcd.print(LCD_BUFF);
}
void LCD_TIMER() {
  lcd.setCursor(0, 1);
  sprintf(LCD_BUFF, "TIME:%02d:%02d:%02d", workTime_hh, workTime_mm, workTime_ss);
  lcd.print(LCD_BUFF);
}
void LCD_ACTION(char* s) {
  if (s == "") {
    lcd.setCursor(0, 2);
    sprintf(LCD_BUFF, "MODE:%s(%s)   ", s, "*");
    lcd.print(LCD_BUFF);
  } else {
    lcd.setCursor(0, 2);
    sprintf(LCD_BUFF, "MODE:%s(%00d)   ", s, run_index);
    lcd.print(LCD_BUFF);
  }
}
void LCD_COUNTDOWN() {
  lcd.setCursor(0, 3);
  sprintf(LCD_BUFF, "C.T.:%02d:%02d:%02d", CT_hh, CT_mm, CT_ss);
  lcd.print(LCD_BUFF);
}
void PRINT_UI() {
  lcd.setCursor(0, 1);
  // sprintf(LCD_BUFF, "MODE:%L4s and Weight=%L4s", workTime_hh, workTime_mm);
  lcd.setCursor(0, 2);

  lcd.setCursor(0, 3);
}

