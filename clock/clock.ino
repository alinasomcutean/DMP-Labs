#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

byte up[8] = {B11111, B00000, B00000, B00000, B00000, B00000, B00000};
byte right_up[8] = {B00000, B10000, B01000, B00100, B00010, B00001, B00001, B00001};
byte right_down[8] = {B00001, B00001, B00001, B00010, B00100, B01000, B10000};
byte down[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B11111};
byte left_up[8] = {B00000, B00001, B00010, B00100, B01000, B10000, B10000, B10000};
byte left_down[8] = {B10000, B10000, B10000, B01000, B00100, B00010, B00001};
byte arm_up_down [8] = {B00000, B00100, B00100, B00100, B00100, B00100, B00100, B00100};
byte arm_corner_right_up1[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00001, 0b00010, 0b00100};
byte arm_corner_right_up2[8] = {0b00000, 0b00000, 0b00000, 0b01000, 0b10000, 0b00000, 0b00000, 0b00000};


int count = 0;

void setup() {
  lcd.begin(16, 2);
  
  lcd.createChar(0, up);
  lcd.createChar(1, right_up);
  lcd.createChar(2, right_down);
  lcd.createChar(3, down);
  lcd.createChar(4, left_up);
  lcd.createChar(5, left_down);
  lcd.createChar(6, arm_up_down);
  lcd.createChar(7, arm_corner_right_up1);
  lcd.createChar(8, arm_corner_right_up2);
  
  lcd.setCursor(7, 0);
  lcd.write(byte(0)); 
  lcd.setCursor(8, 0);
  lcd.write(byte(1));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(6, 0);
  lcd.write(byte(4));
  lcd.setCursor(6, 1);
  lcd.write(byte(5));
  
  /* When you are referring the “0” user defined char you must write a cast to the “byte” type,
  otherwise the compiler throws an error. Exception is the case when you are referring a
  varaiable:
  byte zero = 0;
  lcd.write(zero);*/
  
  // Display the second line
  //lcd.setCursor(0, 1);
  //lcd.print("Sad ");
  //lcd.write(1); // when you are referring other characters then “0” it is not necessary to cast
}
  
void loop()
{ 
  if(count == 0)
  {
    lcd.setCursor(7, 0);
    lcd.write(byte(6));
    count++;
  }
  /*if(count == 1)
  {
    lcd.setCursor(7, 0);
    lcd.write(byte(7));
    lcd.setCursor(8, 0);
    lcd.write(byte(8));
    count++;
  }

  count = 0;*/
}
