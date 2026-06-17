// Manual Motorized Camera Focus Controller
// Arduino + Cytron MD10C + HW-504 Joystick Module

const int DIR_PIN = 4;
const int PWM_PIN = 5;
const int SW_PIN  = 10;

const int JOY_X = A0;
const int JOY_Y = A1;

int centerX = 0;
int centerY = 0;

const int DEADZONE = 80;
const int MIN_PWM = 70;
const int MAX_PWM = 255;

void setup() {
  pinMode(DIR_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(SW_PIN, INPUT_PULLUP);

  Serial.begin(9600);

  long sumX = 0;
  long sumY = 0;

  Serial.println("Calibrating joystick. Do not touch it.");

  for (int i = 0; i < 100; i++) {
    sumX += analogRead(JOY_X);
    sumY += analogRead(JOY_Y);
    delay(5);
  }

  centerX = sumX / 100;
  centerY = sumY / 100;

  stopMotor();
}

void loop() {
  int xVal = analogRead(JOY_X);
  int yVal = analogRead(JOY_Y);
  int swVal = digitalRead(SW_PIN);

  if (swVal == LOW) {
    stopMotor();
    Serial.println("Stop button pressed");
    delay(100);
    return;
  }

  int xMove = xVal - centerX;
  int yMove = yVal - centerY;

  if (abs(xMove) < DEADZONE) {
    stopMotor();
    delay(50);
    return;
  }

  if (xMove > 0) {
    digitalWrite(DIR_PIN, HIGH);
  } else {
    digitalWrite(DIR_PIN, LOW);
  }

  int speedPWM = map(abs(yMove), 0, centerY, MIN_PWM, MAX_PWM);
  speedPWM = constrain(speedPWM, MIN_PWM, MAX_PWM);

  analogWrite(PWM_PIN, speedPWM);

  delay(50);
}

void stopMotor() {
  analogWrite(PWM_PIN, 0);
}
