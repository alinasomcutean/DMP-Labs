#include <LiquidCrystal.h> 
 
// include I2C library 
#include <Wire.h> 
String data = "";
String inputString = "";
boolean stringComplete = false; 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
 
void setup() {   
  Serial.begin(9600); 
  Wire.begin(9);       
  Wire.onReceive(receiveEvent);  
  lcd.begin(16,2);   
  inputString.reserve(200); 
} 
 
void receiveEvent(int bytes) {   
  data = "";
  while( Wire.available()){
    data += (char)Wire.read();
  }
  lcd.clear();
  lcd.setCursor(0,1); // display received character   
  lcd.print(data);
  Serial.println(">"+data);
   
}

 
void loop() {   
  if (stringComplete) {     
  lcd.clear();
  lcd.setCursor(0,1);  // display sent character on LCD    
  lcd.print(inputString);     
  Serial.println(inputString);
  Wire.beginTransmission(10); // transmit to device #9    
  Wire.write(inputString.c_str());                
  Wire.endTransmission();    // stop transmission 
  inputString = "";   
    stringComplete = false;
  }  
}

void serialEvent() {   
  while (Serial.available()) {        
    char inChar = (char)Serial.read();     
    if (inChar != '\n')     
      inputString += inChar;    
    if (inChar == '\n') {       
      stringComplete = true;    
        }   
  } 
}

