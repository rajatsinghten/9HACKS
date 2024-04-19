int TRIG = 3;
int ECHO = 2;
int DURATION;
int DISTANCE;
int SPEAKER_PIN = 8; // Pin connected to the piezo speaker

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  DURATION = pulseIn(ECHO, HIGH);
  DISTANCE = DURATION / 58.2;

  if (DISTANCE > 0 && DISTANCE <= 50) {
    Serial.print("Distance: ");
    Serial.print(DISTANCE);
    Serial.println(" cm");

    if (DISTANCE <= 5) {
      playNote(262); 
    } else if (DISTANCE <= 10) {
      playNote(294); 
    } else if (DISTANCE <= 15) {
      playNote(330); 
    } else if (DISTANCE <= 20) {
      playNote(349); 
    } else if (DISTANCE <= 25) {
      playNote(392); 
    } else if (DISTANCE <= 30) {
      playNote(440); 
    } else {
      playNote(494); 
    }

    delay(100);
  }
}

void playNote(int frequency) {
  int period = 1000000 / frequency; // Calculate the period in microseconds
  int halfPeriod = period / 2; // Calculate half of the period

  for (int i = 0; i < 1000; i++) { // Play the tone for 1 second (1000 milliseconds)
    digitalWrite(SPEAKER_PIN, HIGH); // Turn the speaker on
    delayMicroseconds(halfPeriod); // Delay for half of the period
    digitalWrite(SPEAKER_PIN, LOW); // Turn the speaker off
    delayMicroseconds(halfPeriod); // Delay for half of the period
  }
}
