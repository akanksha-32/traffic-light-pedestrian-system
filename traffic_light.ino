// === Pin Config ===
const int red = 2, yellow = 3, green = 4;
const int pedRed = 5, pedGreen = 6;
const int button = 7, buzzer = 8;
const int seg[] = {9, 10, 11, 12, 13, A1, A0}; // a–g

// Digits for 7-segment (0–9)
const byte digit[10][7] = {
  {1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}
};

bool request = false;

void setup() {
  pinMode(red, OUTPUT); pinMode(yellow, OUTPUT); pinMode(green, OUTPUT);
  pinMode(pedRed, OUTPUT); pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT); pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 7; i++) pinMode(seg[i], OUTPUT);
}

void loop() {
  if (digitalRead(button) == HIGH) request = true;

  // Green Light
  setLights(LOW, LOW, HIGH, HIGH, LOW);
  countdown(5);

  // Yellow Light
  setLights(LOW, HIGH, LOW, HIGH, LOW);
  countdown(2);

  // Red Light
  setLights(HIGH, LOW, LOW, HIGH, LOW);

  if (request) {
    digitalWrite(pedRed, LOW);
    digitalWrite(pedGreen, HIGH);
    tone(buzzer, 1000, 500);
    delay(500);

    for (int i = 7; i > 0; i--) {
      showDigit(i);
      if (i <= 3) { digitalWrite(pedGreen, LOW); delay(300); digitalWrite(pedGreen, HIGH); delay(300); }
      else delay(1000);
    }

    tone(buzzer, 1000, 500); delay(500);
    digitalWrite(pedGreen, LOW); digitalWrite(pedRed, HIGH);
    request = false;
  } else {
    countdown(5); // Red time if no pedestrian
  }
}

void countdown(int sec) {
  for (int i = sec; i > 0; i--) {
    if (digitalRead(button) == HIGH) request = true;
    showDigit(i);
    delay(1000);
  }
}

void showDigit(int n) {
  if (n > 9) n = 9;
  for (int i = 0; i < 7; i++)
    digitalWrite(seg[i], digit[n][i]);
}

void setLights(int r, int y, int g, int pr, int pg) {
  digitalWrite(red, r); digitalWrite(yellow, y); digitalWrite(green, g);
  digitalWrite(pedRed, pr); digitalWrite(pedGreen, pg);
}
