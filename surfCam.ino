/*
Remote cam code for Arduino
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  #define BATT_VOLTAGE_PIN          A0
  #define LIGHT_LEVEL_PIN           A1
  #define ENABLE_PHONE_CHARGE_PIN   1
  #define SWITCH_PHONE_ON           5
  #define SLEEP_PIN                 3
  #define GOOD_LIGHT_LEVEL          400
  #define CHARGE_PHONE_VOLTAGE      4    
  #define BATTERY_VOLTAGE           3.5
  #define PHONE_RELAY_SWITCH_TIME   3000  //Length of time required to switch phone on
  #define DELAY_BEFORE_OFF          600000  //Length of time before switching off

}

// the loop routine runs over and over again forever:
void loop() {
  
  pinMode(ENABLE_PHONE_CHARGE_PIN, OUTPUT); //Pulls the enable pin of the powerBoost low, which disables 5v output
  pinMode(SLEEP_PIN, OUTPUT); //Sends circuit to sleep
  pinMode(SWITCH_PHONE_ON, OUTPUT); //Switches phone on
  pinMode(LED_BUILTIN, OUTPUT);// initialize digital pin LED_BUILTIN as an output

 //digitalWrite(
 
  // read the input on analog pin A0 (battery voltage):
  int sensorValue = analogRead(BATT_VOLTAGE_PIN);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float batteryVoltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.print("batteryVoltage: "); // prints the value cominmg from the sensor on the screen
  Serial.println(batteryVoltage); // puts it all on one line
  delay(1500);

if (batteryVoltage >= BATTERY_VOLTAGE) //checks to see if the voltage is OK.
{
  Serial.println("voltage OK");
  delay(1500);
} 
if (batteryVoltage < BATTERY_VOLTAGE) //if voltage not OK, turn off circuit.
{
  Serial.println("voltage not OK turing off circuit");
  delay(1500);
  turnOffCircuit();
}
int lightValue = analogRead(LIGHT_LEVEL_PIN); // read the value from the sensor
  Serial.print("light Level: "); //prints the values coming from the sensor on the screen
  Serial.println(lightValue); // puts it all on one line
  delay(1500);

if (lightValue < GOOD_LIGHT_LEVEL) // reads light level from LDR
  Serial.println("Light level not ok");
  delay(1500);
  //turnOffCircuit();

if (lightValue >= GOOD_LIGHT_LEVEL) // reads light level from LDR
  Serial.println("Light level ok");
  delay(1500);

if (lightValue >= GOOD_LIGHT_LEVEL, batteryVoltage >= BATTERY_VOLTAGE )
  {
  Serial.println("light and battery voltage OK, starting phone");
  delay(1500);
  digitalWrite(SWITCH_PHONE_ON, HIGH);
  delay(PHONE_RELAY_SWITCH_TIME);
  digitalWrite(SWITCH_PHONE_ON, LOW);
  delay(DELAY_BEFORE_OFF);
  turnOffCircuit();
  }
  
/* 
digitalWrite(SWITCH_PHONE, HIGH);
delay(PHONE_RELAY_SWITCH_TIME);
digitalWrite(SWITCH_PHONE, LOW);
delay(DELAY_BEFORE_OFF);
*/

//turnOffCircuit();
}

//Triggers the done pin on the TPL5111
void turnOffCircuit()
{
Serial.println("Switching Off");
  for ( int i = 0; i < 5; i++ ) {
 digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second;
  
  digitalWrite(SLEEP_PIN, HIGH);
  delay(40);
  digitalWrite(SLEEP_PIN, LOW);
  }
}




