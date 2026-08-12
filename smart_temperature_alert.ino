const int tempPin = A0;
const int greenLED = 7;
const int redLED = 8;
const int buzzer = 9;

void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(tempPin);

  // Convert analog reading to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // TMP36 temperature calculation
  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature < 25) {
    // Normal
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println("Status: NORMAL");
  }

  else if (temperature < 35) {
    // Warm
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, LOW);

    Serial.println("Status: WARM");
  }

  else {
    // Hot
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);

    Serial.println("Status: HIGH TEMPERATURE!");
  }

  Serial.println("--------------------");

  delay(1000);
}
