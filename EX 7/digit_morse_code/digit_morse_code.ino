//Morse Code for digits

int ledPin = 13;
char inp = 0;
int morseArr[][5] = {{1000,1000,1000,1000,1000}, {400,1000,1000,1000,1000}, {400,400,1000,1000,1000}, {400,400,400,1000,1000}, {400,400,400,400,1000}, {400,400,400,400,400}, {1000,400,400,400,400}, {1000,1000,400,400,400}, {1000,1000,1000,400,400}, {1000,1000,1000,1000,400}};
void setup()
{
pinMode(ledPin, OUTPUT);

Serial.begin(9600);
}
void flash(int duration)
{
digitalWrite(ledPin, HIGH);
delay(duration);
digitalWrite(ledPin, LOW);
delay(duration);
}

void loop()
{
  if(Serial.available()>0){
    inp=Serial.read();  
    if(inp!=10){
      if(inp>=48 && inp<=57){
        Serial.println((int)inp-48);
        for(int i=0;i<5;i++){
          flash(morseArr[(int)inp-48][i]); 
        }
      }
      else{
        Serial.println("Not a valid number!");
      }
    }
  }
}
