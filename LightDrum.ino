/*
* Ultrasonic Light Drum
* Created by Mahmood Al-Akwaa and Mustafa Shareef  and Mohammed Sawas
* During the refugees{code} Hackathon of 15.7.2017, intake #2
* The Set-Up can be found here: 
*/


// the input and output connectors from sensor
int trig = 5 ;
int echo = 6;

// the output for the RGB LED pins
int red = 8;
int green = 9;
int blue = 10;

// variables for communicating distance to Ultrasonic sensor HC-SR04
long duration;
int distance;



void setup() 
{
// put your setup code here, to run once:
pinMode(trig, OUTPUT);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);

pinMode(echo, INPUT);
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  delay(200);
digitalWrite(trig,LOW);
delayMicroseconds(2);

digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

// calculate the distance deducted from the duration of sending and receiving a ultrasonic soundwave. 
duration = pulseIn(echo,HIGH);
distance = duration * 0.034/2;

// from 0-5 cm distance, the colors are:
if(distance<=5)
 {
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);  
 }
else if(distance<=10)
 {
	// distance between 5 and 10cm
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);  
 }
else if(distance<=15)
 {
  // distance between 10 and 15cm
	digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);  
 }
else if(distance<=20)
 {
	// distance between 15 and 20cm
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);  
 }
else 
 {
	// distance larger than 20cm
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);  
 }
 // development aid, not relevant for output
Serial.print("Distance: ");
Serial.println(distance);

}
