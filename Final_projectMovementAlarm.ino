/**********************************************************************
  Filename    : Ultrasonic Ranging
  Description : Use the ultrasonic module to measure the distance.
  Auther      : www.freenove.com
  Modification: 2022/10/25
**********************************************************************/
#define trigPin 13 // define TrigPin
#define echoPin 14 // define EchoPin.
#define MAX_DISTANCE 700 // Maximum sensor distance is rated at 400-500cm.
#define PIN_BUZZER 18 // Trigger buzzer

int SET_DISTANCE; //The original range found 
int NEW_DISTANCE; //The trigger range found 
int distance = 0;   //the distance found
int track = 0;

//timeOut= 2*MAX_DISTANCE /100 /340 *1000000 = MAX_DISTANCE*58.8
float timeOut = MAX_DISTANCE * 60; 
int soundVelocity = 340; // define sound speed=340m/s

void setup() {
  pinMode(trigPin,OUTPUT);// set trigPin to output mode
  pinMode(echoPin,INPUT); // set echoPin to input mode

  pinMode(PIN_BUZZER, OUTPUT); 

  Serial.begin(115200);   // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(1000); // Wait 100ms between pings (about 20 pings/sec). 

  if (track < 2){
    SET_DISTANCE = distance;
    track = track + 1;
  }

  Serial.printf("Distance: ");
  Serial.print(getSonar()); // Send ping, get distance in cm and print result 
  Serial.println("cm");
  NEW_DISTANCE = distance;
  if (SET_DISTANCE <= NEW_DISTANCE - 10) {
    digitalWrite(PIN_BUZZER,HIGH);
    delay(1000);
    digitalWrite(PIN_BUZZER,LOW);
  }
  if (SET_DISTANCE >= NEW_DISTANCE + 20 ) {
    digitalWrite(PIN_BUZZER,HIGH);
    delay(1000);
    digitalWrite(PIN_BUZZER,LOW);
  }
}

float getSonar() {
  unsigned long pingTime;
  // make trigPin output high level lasting for 10μs to triger HC_SR04
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Wait HC-SR04 returning to the high level and measure out this waitting time
  pingTime = pulseIn(echoPin, HIGH, timeOut); 
  // calculate the distance according to the time
  distance = (float)pingTime * soundVelocity / 2 / 10000;
  return distance; // return the distance value
}