// Simple Stepper Motor Control
//
// by Achim pieters, www.studiopieters.nl
// updated by Pierre Baillargeon to reflect usage for DIYbio orbital shaker
//

// Defines pins numbers
const int stepPin = 7;
const int dirPin = 8;

int potentiometerDelayValue,mappedPotentiometerValue; // Defines variables

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
}

void loop() {
  potentiometerDelayValue = potentiometerRead(); // Gets custom delay values from the custom speedUp function
  // Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(potentiometerDelayValue);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(potentiometerDelayValue);
}

// Function for reading the Potentiometer
int potentiometerRead() {
  int rawPotentiometerValue = analogRead(A0); // Reads the potentiometer
  int mappedPotentiometerValue = map(rawPotentiometerValue, 0, 1023, 550,4000); // Convrests the read values of the potentiometer from 0 to 1023 into desireded delay values (300 to 4000)
  Serial.println(mappedPotentiometerValue);
  return mappedPotentiometerValue;
}
