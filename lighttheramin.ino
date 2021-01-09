#include <Tone.h>

int photopin=0;// initialize analog pin 0, connected with photovaristor
int buzzpin=11;// initialize digital pin 11, output regulating the brightness of LED
//set IO pin for each light segment
int a=9;
int b=2;
int c=3;
int d=5;
int e=4;
int f=7;
int g=6;
int h=8;

int val=0;// initialize variable va
int note;
int scale[] = { 
                NOTE_C3,
                NOTE_DS3,
                NOTE_F3,
                NOTE_FS3,
                NOTE_G3,
                NOTE_AS3,
                NOTE_B3,
                NOTE_C4,
                };
char letter;
Tone tone1;

void note_A(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}
void note_AS(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, HIGH);
}

void note_B(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}

void note_C(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void note_CS(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, HIGH);
}

void note_D(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void note_DS(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(h, HIGH);
}

void note_E(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}

void note_F(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}

void note_FS(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, HIGH);
}

void note_G(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, LOW);
}

void note_GS(){
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(h, HIGH);
}



void setup()
{
  pinMode(buzzpin,OUTPUT);// set digital pin 11 as “output”
  Serial.begin(9600);// set baud rate at “9600”
  tone1.begin(11);
  for (int i = 2; i<10;i++){
   pinMode(i, OUTPUT);
  }
}
void loop()
{
  
  
val=analogRead(photopin);// read the analog value of the sensor and assign it to val
// display the value of val
      if ((val>=0) && (val<100))  {                   // Discretization of the pot intervals - in order to assign the note
        note = scale[0];    
        letter = "c";
        note_C();
      }
      if ((val>=150) && (val<210)) {
        note = scale[0];
        letter = "c";
        note_C();
      }
      if ((val>=210) && (val<270)) {
        note = scale[1];
        letter = "ds";
        note_DS();
      }
      if ((val>=270) && (val<330)) {
        note = scale[2];
        letter = "f";
        note_F();
      }
      if ((val>=330) && (val<390)) {
        note = scale[3];
        letter = "fs";
        note_FS();
      }
      if ((val>=390) && (val<450)) {
        note = scale[4];
        letter = "g";
        note_G();
      }
      if ((val>=450) && (val<510)) {
        note = scale[5];
        letter = "as";
        note_AS();
      }
      if ((val>=510) && (val<570)) {
        note = scale[6];
        letter = "b";
        note_B();
      }
      if (val>=570) {
        note = scale[7];
        letter = "c";
        note_C();
      }
      
Serial.println(letter);
tone1.play(note);// turn on the LED and set up brightness（maximum output value 255）
delay(10);// wait for 0.01*/
}              
