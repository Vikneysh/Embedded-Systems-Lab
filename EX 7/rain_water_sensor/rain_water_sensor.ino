const int D = 4;
const int A = A0;

int val_analog;

void setup()
{
  pinMode(D, INPUT);
  pinMode(A, INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
if(digitalRead(D) == LOW) 
  {
    digitalWrite(2,HIGH);
    Serial.println("Raining"); 
    delay(10); 
  }
else
  {
    digitalWrite(2,LOW);
    Serial.println("Not Raining");
    delay(10); 
  }
val_analog=analogRead(A); 
 Serial.print("Analog value : ");
 Serial.println(val_analog); 
 Serial.println("");
  delay(1000);
}