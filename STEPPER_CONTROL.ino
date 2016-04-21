int RUN_STEPPER(String s, boolean d, int step_count ) {
  if (s == "STEP_1") {
    if (d == FORWARD) {
      digitalWrite(STEPPER_MOTOR_1_DIR, ACTIVE);
    }
    else if (d == REVERSION) {
      digitalWrite(STEPPER_MOTOR_1_DIR, INACTIVE);
    }
    for (int x = 0; x < step_count; x++) {
      digitalWrite(STEPPER_MOTOR_1_STEP, ACTIVE);
      delayMicroseconds(STEPPER_DELAY);
      digitalWrite(STEPPER_MOTOR_1_STEP, INACTIVE);
      delayMicroseconds(STEPPER_DELAY);
    }
  }
  else if (s == "STEP_2") {
    if (d == FORWARD) {
      digitalWrite(STEPPER_MOTOR_2_DIR, ACTIVE);
    }
    else if (d == REVERSION) {
      digitalWrite(STEPPER_MOTOR_2_DIR, INACTIVE);
    }
    for (int x = 0; x < step_count; x++) {
      digitalWrite(STEPPER_MOTOR_2_STEP, ACTIVE);
      delayMicroseconds(STEPPER_DELAY);
      digitalWrite(STEPPER_MOTOR_2_STEP, INACTIVE);
      delayMicroseconds(STEPPER_DELAY);
    }
  }
}
