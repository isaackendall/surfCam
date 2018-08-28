
# define LIGHT                      A1
# define HIGH_LIGHT                 800
# define MEDIUM_LIGHT               500
# define LOW_LIGHT                  250
# define BATT_VOLTAGE_PIN           A0
# define DONEPIN                    5
# define BATT_VOLT                  3.2
#define  ENABLE_PHONE_CHARGE_PIN    4

int val=0; //used for storing the value input from the sensor
int ledVal = 0; //variable that control the LED output
int light = analogRead(LIGHT);   //reads light level

void setup() {
  Serial.begin(9600); //for setting output to the monitor
  pinMode(DONEPIN, OUTPUT);
  digitalWrite(DONEPIN, LOW);
}

void loop() {
  
  int voltage = analogRead(BATT_VOLTAGE_PIN);
  float batteryVoltage = (voltage * (0.00488281)); //voltage is 5/1024 
  Serial.print("batteryVoltage: "); // prints the battery voltage
  Serial.println(batteryVoltage); // put it all on one line
  delay(100);
  
  int light = analogRead(LIGHT);   //reads light level 
  float lightLevel = (light * (1));
  Serial.print("lightLevel: "); // prints light level
  Serial.println(lightLevel); // puts it all on one line
  delay(500);
  
if((light > HIGH_LIGHT), (batteryVoltage > BATT_VOLT)){ //checks light level and battery voltage
  Serial.println("voltage and light OK");
  delay(1000);
}

else if((light < HIGH_LIGHT), (batteryVoltage > BATT_VOLT)){
//checks light level and battery voltage
  Serial.println("voltage OK, light not");
  delay(1000);
}

else if((light < LOW_LIGHT), (batteryVoltage > BATT_VOLT)){
//checks light level and battery voltage
  Serial.println("voltage OK, light level low");
  delay(1000);
}

else if((light > LOW_LIGHT), (batteryVoltage > BATT_VOLT)){
//checks light level and battery voltage
  Serial.println("voltage OK, light level above low");
  delay(1000);
}

else{
//any input above 200 will get the maximum output
Serial.println("no items matched"); // test to drop out. 
}
delay(100);
}
