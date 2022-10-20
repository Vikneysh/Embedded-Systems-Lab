
#define A 8
#define B 7
#define C 6
#define D 5
#define E 4
#define F 3
#define G 2
#define DP 9 
#define common_cathode 0
#define common_anode 1
bool segMode = common_cathode; 
int seg[] {A,B,C,D,E,F,G,DP};
byte chars = 35;
char inp=0;
byte Chars[35][9] { 
            {'0',1,1,1,1,1,1,0,0},
            {'1',0,1,1,0,0,0,0,0},
            {'2',1,1,0,1,1,0,1,0},
            {'3',1,1,1,1,0,0,1,0},
            {'4',0,1,1,0,0,1,1,0},
            {'5',1,0,1,1,0,1,1,0},
            {'6',1,0,1,1,1,1,1,0},
            {'7',1,1,1,0,0,0,0,0},
            {'8',1,1,1,1,1,1,1,0},
            {'9',1,1,1,1,0,1,1,0},
            {'a',1,1,1,0,1,1,1,0},
            {'b',0,0,1,1,1,1,1,0},
            {'c',1,0,0,1,1,1,0,0},
            {'d',0,1,1,1,1,0,1,0},
            {'e',1,0,0,1,1,1,1,0},
            {'f',1,0,0,0,1,1,1,0},
            {'g',1,0,1,1,1,1,0,0},
            {'h',0,1,1,0,1,1,1,0},
            {'i',0,0,0,0,1,1,0,0},
            {'j',0,1,1,1,1,0,0,0},
            {'l',0,0,0,1,1,1,0,0},
            {'n',0,0,1,0,1,0,1,0},
            {'o',0,0,1,1,1,0,1,0},
            {'p',1,1,0,0,1,1,1,0},
            {'q',1,1,1,0,0,1,1,0},
            {'r',0,0,0,0,1,0,1,0},
            {'s',1,0,1,1,0,1,1,0},
            {'t',0,0,0,1,1,1,1,0},
            {'u',0,1,1,1,1,1,0,0},
            {'y',0,1,1,1,0,1,1,0},
            {'-',0,0,0,0,0,0,1,0},
            {'.',0,0,0,0,0,0,0,1},
            {']',1,1,1,1,0,0,0,0},
            {'[',1,0,0,1,1,1,0,0},
            {'_',0,0,0,1,0,0,0,0},
            };
void setup() {
pinMode(seg[0],OUTPUT);
pinMode(seg[1],OUTPUT);
pinMode(seg[2],OUTPUT);
pinMode(seg[3],OUTPUT);
pinMode(seg[4],OUTPUT);
pinMode(seg[5],OUTPUT);
pinMode(seg[6],OUTPUT);
pinMode(seg[7],OUTPUT);
Serial.begin(9600);
}

void lightsOut() {
  for(int i=0; i<8; i++) {
    digitalWrite(seg[i],LOW);
  }
  delay(525);
}

void loop() {
 if(Serial.available()>0){
  inp=Serial.read();
  for(int i=0;i<35;i++)
    {
       delay(15);
      if(inp==Chars[i][0]){
        lightsOut();
        for(int j=1;j<9;j++){
          if(Chars[i][j]==1){
            digitalWrite(seg[j-1],HIGH);
          }
          else{
            digitalWrite(seg[j-1],LOW);
          }  
        } 
      }
    }
 }
}
