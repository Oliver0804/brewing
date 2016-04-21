void INIT_GPIO() {
  pinMode(STEPPER_MOTOR_1_STEP, OUTPUT);
  pinMode(STEPPER_MOTOR_1_DIR, OUTPUT);
  pinMode(STEPPER_MOTOR_2_STEP, OUTPUT);
  pinMode(STEPPER_MOTOR_2_DIR, OUTPUT);
  pinMode(PUMP_1, OUTPUT);
  pinMode(PUMP_2, OUTPUT);
  pinMode(FAN_1, OUTPUT);
  pinMode(FAN_2, OUTPUT);
  pinMode(HEATER_PIN, OUTPUT);
  pinMode(COOL_PIN, OUTPUT);
  digitalWrite(STEPPER_MOTOR_1_STEP, INACTIVE);
  digitalWrite(STEPPER_MOTOR_1_DIR, INACTIVE);
  digitalWrite(STEPPER_MOTOR_2_STEP, INACTIVE);
  digitalWrite(STEPPER_MOTOR_2_DIR, INACTIVE);
  digitalWrite(PUMP_1, INACTIVE);
  digitalWrite(PUMP_2, INACTIVE);
  digitalWrite(FAN_1, INACTIVE);
  digitalWrite(FAN_2, INACTIVE);
  digitalWrite(HEATER_PIN, INACTIVE);
  digitalWrite(COOL_PIN, INACTIVE);
}

void RUN_WAITING() {

}

void RUN_HEATING(int x) {
  if (x == 1) {
    digitalWrite(HEATER_PIN, ACTIVE);
  } else if (x == 0) {
    digitalWrite(HEATER_PIN, INACTIVE);
  }
}

void RUN_COOLING(int x) {
  if (x == 1) {
    digitalWrite(COOL_PIN, ACTIVE);
  } else if (x == 0) {
    digitalWrite(COOL_PIN, INACTIVE);
  }
}

void RUN_WASHING() {
}

void RUN_PUMPING_1(int x) {
  if (x == 1) {
    digitalWrite(PUMP_1, ACTIVE);
  } else if (x == 0) {
    digitalWrite(PUMP_1, INACTIVE);
  }
}

void RUN_PUMPING_2(int x) {
  if (x == 1) {
    digitalWrite(PUMP_2, ACTIVE);
  } else if (x == 0) {
    digitalWrite(PUMP_2, INACTIVE);
  }
}

