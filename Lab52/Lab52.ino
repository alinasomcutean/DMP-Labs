#include <LiquidCrystal.h> 
 
// include I2C library 
#include <Wire.h> 
 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
String inputString = "";
String data = "";
boolean stringComplete = false; 
 
void setup() {   
  // Open I2C bus as master   
  Serial.begin(9600); //implicit serial frame format   
  Wire.begin(10);    
  lcd.begin(16,2);   
  Wire.onReceive(receiveEvent); 
  inputString.reserve(200); 
  //lcd.print("Master");  
}
 
void loop() {  
  if (stringComplete) {     
  lcd.clear();
  lcd.setCursor(0,1);  // display sent character on LCD    
  lcd.print(inputString);     
  Serial.println(inputString);     
  Wire.beginTransmission(9); // transmit to device #9    
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
