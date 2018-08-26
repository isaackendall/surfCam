/*
Test program to see if the TPL_5110 is working
*/
# define DONEPIN                  5
# define BATT_VOLTAGE_PIN         A0
# define BATTERY_VOLTAGE          4
# define ENABLE_PHONE_CHARGE_PIN  6

void setup() {
  pinMode(DONEPIN, OUTPUT);
  digitalWrite(DONEPIN, LOW); //Set the output of the pin to low keeping the TPL on. 
  pinMode(ENABLE_PHONE_CHARGE_PIN, OUTPUT); //Pulls the enable pin of the powerBoost low, which disables 5v output
  
  Serial.begin(9600);
  Serial.println("Program starting");

}

void loop() {
{
  digitalWrite(ENABLE_PHONE_CHARGE_PIN, LOW);       // Turns the Power boost board off by setting the LB pin to High
  delay(1000);                                      // waits for a second
  Serial.println("turn off power boost");           // print turn off powerboost
}

  int sensorValue = analogRead(BATT_VOLTAGE_PIN);   //reads battery voltage 
  delay(20);
  //batteryVoltage = analogRead(BATT_VOLTAGE_PIN);
  float batteryVoltage = (sensorValue * (0.00488281));
  Serial.println(batteryVoltage);
  
 
 if (batteryVoltage >= BATTERY_VOLTAGE) //checks to see if the voltage is OK.
{
  Serial.println("voltage OK");
  delay(1000);
  digitalWrite(ENABLE_PHONE_CHARGE_PIN, HIGH);       // Turns the Power boost on
  Serial.println("Power boost on!");
  delay(1000);
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

