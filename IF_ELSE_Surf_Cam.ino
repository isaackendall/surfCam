
# define LIGHT          A1
# define HIGHT_LIGHT    800
# define MEDIUM_LIGHT   500
# define LOW_LIGHT      250

int val=0; //used for storing the value input from the sensor
int ledVal = 0; //variable that control the LED output
int light = analogRead(LIGHT);   //reads light level

void setup() {
Serial.begin(9800); //for setting output to the monitor
}
void loop() {
//accept data from the A1 pin of ANALOG IN
val=analogRead(LIGHT);
ledVal = val/4; // assign that value to the LED output variable
Serial.println(ledVal); //display the value on the monitor
//set the four levels of brightness
if(ledVal < 50){
//the light should be off when the values are under 50
analogWrite(3,0); //output is 0
}
else if(ledVal < 100){
// for values between 50 and 100
analogWrite(3,100); //output value is 100
}
else if(ledVal < 150){
//for values between 100 and 150
analogWrite(3,150); //output value is 150
}
else if(ledVal < 200){
//for values between 150 and 200
analogWrite(3,200); //output value is 200
}
else{
//any input above 200 will get the maximum output
analogWrite(3,255); //output value is 255
}
delay(100);
}
