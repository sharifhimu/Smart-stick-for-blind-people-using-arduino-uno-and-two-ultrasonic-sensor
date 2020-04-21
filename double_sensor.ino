// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;

const int trigPin1 = 12;
const int echoPin1 = 13;
const int buzzer1 = 8;


// defines variables
long duration;
long duration1;

int distance;
int safetyDistance;

int distance1;
int safetyDistance1;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);

Serial.begin(9600); // Starts the serial communication

pinMode(trigPin1, OUTPUT); // Sets the trigPin1 as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin1 as an Input
pinMode(buzzer1, OUTPUT);

Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);


// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);



// Calculating the distance
distance= duration*0.034/2;



safetyDistance = distance;



if (safetyDistance <= 50){
  digitalWrite(buzzer, HIGH);

  Serial.println("Distance of obstacle: ");
  Serial.println(duration);
  Serial.println("       Obstacle ahead"); 
}
else{
  digitalWrite(buzzer, LOW);
  
  Serial.println("Distance1: ");
  Serial.println(duration);
  
}


duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;
safetyDistance1 = distance1 + 10 ;

 if (safetyDistance1 > 70  ){
  digitalWrite(buzzer1, HIGH);

  Serial.println("depth of manhole: ");
  Serial.println( duration1);
  Serial.println("        manhole Alert!");
}
else{
 digitalWrite(buzzer1, LOW);

  Serial.println("         Distance2: ");
  Serial.println(           duration1);
  
}


delay(50);
// Prints the distance on the Serial Monitor



}
