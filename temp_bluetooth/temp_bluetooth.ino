float resolutionADC = .0049;
float resolutionSensor = .01;
int wait = 500;
String r;

void setup()
{
  Serial.begin(9600); // Interfata Serial 0, pentru PC
  Serial1.begin(9600); // Interfata Serial 1, pentru Bluetooth
  //Serial.print("Temp [C]: ");
  //float temp = readTempInCelsius(10, 0); // read temp. 10 times and returns the average
  //Serial.println(temp); // display the result
  //delay(200);
}

float readTempInCelsius(int count, int pin) {
  // read temp. count times from the analog pin
  float sumTemp = 0;
  
  for (int i =0; i < count; i++) {
    int reading = analogRead(pin);
    float voltage = reading * resolutionADC;
    // subtract the DC offset and converts the value in degrees (C)
    float tempCelsius = (voltage - 0.5) / resolutionSensor ;
    sumTemp = sumTemp + tempCelsius; // accumulates the readings
  }
  
  return sumTemp / (float)count; // return the average value
}

void loop()
{
  float temp = readTempInCelsius(10, 0);
  //if (Serial1.available())
  //{
    //Serial.println(temp);
  Serial1.println(temp);
  //}
  if (Serial1.available()) // Citire de la PC, trimite la Bluetooth
  {
      r = Serial1.readString();
      if(r.startsWith("r+")){
        wait = wait + 100;
      }
      if(r.startsWith("r-"))
      {
        wait = wait - 100;
      }
  }
    
  delay(wait);
}
