#include <MsTimer2.h>
#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize interface pins
 char num[7]="100000";
void flash() {
 int i=0;
 while(Serial.available())
 {
  
   num[i++] = Serial.read();
  }
 //*******************************************************
   if(num[0]=='0'&&num[1]=='0'&&num[2]=='0'&&num[3]=='0'&&num[4]=='0'&&num[5]=='0')
    {
       Serial.write("X");
        digitalWrite(13, HIGH);
     }
   else if(num[5]!='0')
   {
   num[5]--;  
   }
   else if(num[5]=='0'&&num[4]!='0')
   {
   num[4]--; num[5]='9';
  }
  else if(num[5]=='0'&&num[4]=='0'&&num[3]!='0')  
   {
   num[3]--;num[4]='5'; num[5]='9';
  }
   else if(num[5]=='0'&&num[4]=='0'&&num[3]=='0'&&num[2]!='0')  
   {
   num[2]--; num[3]='9';num[4]='5'; num[5]='9';
  }
  else if(num[5]=='0'&&num[4]=='0'&&num[3]=='0'&&num[2]=='0'&&num[1]!='0')  
   {
   num[1]--; num[2]='5';num[3]='9';num[4]='5'; num[5]='9';
  }
  else if(num[5]=='0'&&num[4]=='0'&&num[3]=='0'&&num[2]=='0'&&num[1]=='0'&&num[0]!='0')  
   {
   num[0]--; num[1]='9'; num[2]='5';num[3]='9';num[4]='5'; num[5]='9';
  }
  Serial.write(num);
  Serial.println();
  lcd.setCursor(0, 1);
   lcd.write(num[0]); 
    lcd.write(num[1]); 
    lcd.write(":");
    lcd.write(num[2]); 
    lcd.write(num[3]); 
    lcd.write(":");
    lcd.write(num[4]); 
    lcd.write(num[5]); 

 
}

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  MsTimer2::set(1000, flash);
  MsTimer2::start();
  lcd.begin(20, 2);
}
void loop() {
 
}

