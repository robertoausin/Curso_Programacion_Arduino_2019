// Parpadeo 2 LED //

#define ledRojo 2
#define ledAzul 3

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledRojo, HIGH);      // turn the red LED on (HIGH is the voltage level)
  digitalWrite(ledAzul, LOW);       // turn the blue LED off (LOW is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(ledRojo, LOW);       // turn the red LED off (LOW is the voltage level)
  digitalWrite(ledAzul, HIGH);      // turn the blue LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
}
