// workTime_hh,workTime_mm,workTime_ss;
void UPDATA_SYS_TIMER() {
  if (workTime_ss <= 59) {
    workTime_ss++;
  } else {
    workTime_mm++;
    workTime_ss = 0;
  }
  if (workTime_mm <= 59) {
  } else {
    workTime_hh++;
    workTime_mm = 0;
  }
  if (workTime_hh <= 23) {
  } else {
    workTime_ss = 0;
    workTime_mm = 0;
    workTime_hh = 0;
  }
  LCD_TIMER();
  LCD_TITEL();
  LCD_COUNTDOWN();
}
//int CT_hh, CT_mm, CT_ss;
void COUNTDOWN_TIMER() {
  if (CT_ss == 0 && CT_mm == 0 && CT_hh == 0) {
    Serial.print("COUNT END");
  }
  if (CT_ss > 0) {
    CT_ss--;
  } else {
    if (CT_mm > 0) {
      CT_mm--;
      CT_ss = 59;
    } else {
      CT_hh--;
      CT_mm = 59;
    }
  }
}

void SET_CT_TIME(int x) {
  CT_mm = x;
  while (1) {
    SYS_TIMER.update();
    CT_TIMER.update();
    if (CT_ss == 0 && CT_mm == 0 && CT_hh == 0) {
      break;
    }
  }
}


