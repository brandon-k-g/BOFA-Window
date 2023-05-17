// Code for potetntiometer
int valor_pot = 0;
int Valor_2 = 0;

 

// code for temp sense 
const int tempSensor = A0;
int tempSensorRead = 0;
float millivolts=0;
float temp=0;

 

// Code for LDR
const int LDR = A2;
int LDRRead = 0;
float mv = 0;
float lumens =0;

 

void setup()
{
// Code for potentiometer   
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  
  // Code for temp sense 
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  
  // Code for LDR
  pinMode(A2,INPUT); 
  pinMode(10,OUTPUT);
}

 

void loop()
{
  if (digitalRead(5) == HIGH) {
    // Code for Potentiometer
    ((analogRead(A1)/1000));
    valor_pot = analogRead(A1);
    Serial.println(valor_pot);
    valor_pot += map(valor_pot, 0, 1023, 0, 100);
    analogWrite(10, valor_pot);
    delay(100);
  }
  else {
    // Code for LDR
    LDRRead = analogRead(LDR);
    mv = map(LDRRead , 0 , 1023 , 0 , 5000);
    lumens = mv /10;
  // Display the reading on the serial Monitor 
    Serial.print("light in lumens : ");
    Serial.println(lumens);
    delay(200);

 

    if (lumens > 50) {
      analogWrite(10,1000);
    }
    if ( lumens < 50) {
      analogWrite(10,50);
    }
  }
  
  // Code for Temp Sense 
  tempSensorRead = analogRead(tempSensor);
  millivolts = map(tempSensorRead , 0 , 1023 , 0 , 5000);
  temp = millivolts /10;
// Display the reading on the serial Monitor 
  Serial.print("temp in celsius : ");
  Serial.println(temp);
  delay(200);
  
  if (temp >100){
    delay(100);
    analogWrite(9,1000);
    analogWrite(11,1000);
  }  
  if (temp <100) {
    delay(100);
    analogWrite(9,50);
    analogWrite(11,50);
  }  
  
}