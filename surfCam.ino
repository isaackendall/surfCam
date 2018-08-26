/*
Test program to see if the TPL_5110 is working
*/
# define DONEPIN          5
# define BATT_VOLTAGE_PIN A0
# define BATTERY_VOLTAGE  4
# define LIGHT_LEVEL      A1

void setup() {
  pinMode(DONEPIN, OUTPUT);
  digitalWrite(DONEPIN, LOW);
  Serial.begin(9600);
  Serial.println("Program starting");
  delay(100);

}

void loop() {
  /*
    // read the input on analog pin A0 (battery voltage):
  int sensorValue = analogRead(BATT_VOLTAGE_PIN);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float batteryVoltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.print("batteryVoltage: "); // prints the value coming from the sensor on the screen
  Serial.println(batteryVoltage); // puts it all on one line
  delay(1500);
*/

  int sensorValue = analogRead(BATT_VOLTAGE_PIN);
  delay(20);
  //batteryVoltage = analogRead(BATT_VOLTAGE_PIN);
  float batteryVoltage = (sensorValue * (0.00488281));
  Serial.print("batteryVoltage: "); 
  Serial.println(batteryVoltage);
  delay(100);
  
  int light = analogRead(LIGHT_LEVEL);   //reads battery voltage 
  delay(500);
  //lightLevel = analogRead(BATT_VOLTAGE_PIN);
  float lightLevel = (light * (1));
  Serial.print("lightLevel: "); // prints the value coming from the sensor on the screen
  Serial.println(lightLevel); // puts it all on one line
 
 if (batteryVoltage >= BATTERY_VOLTAGE) //checks to see if the voltage is OK.
{
  Serial.println("voltage OK");
  delay(1500);
} 
if (batteryVoltage < BATTERY_VOLTAGE) //if voltage not OK, turn off circuit.
{
  Serial.println("voltage not OK turing off circuit");
  delay(1500);
  // toggle DONE so TPL knows to cut power!
  Serial.println("turnOffCircuit running and Switching Off");
  while (1) {
    digitalWrite(DONEPIN, HIGH);
    delay(1);
    digitalWrite(DONEPIN, LOW);
    delay(1000);
  }
  
  

}
  
}

/*
Test program to see if the TPL_5110 is working

//Triggers the done pin on the TPL5111
void turnOffCircuit()
{
  // toggle DONE so TPL knows to cut power!
  Serial.println("turnOffCircuit running and Switching Off");
  while (1) {
    digitalWrite(DONEPIN, HIGH);
    delay(1);
    digitalWrite(DONEPIN, LOW);
    delay(1);
  }
 
}
*/
