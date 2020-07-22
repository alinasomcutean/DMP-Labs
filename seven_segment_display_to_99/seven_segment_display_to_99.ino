// Display on SSD
// connected at PORTA
// Table of values, or look up table (LUT) with the BCD codes for every digit from 0 to 9. Every bit
//corresponds to a LED, 1 means the LED is lit and 0 means it is not giving light.

const unsigned char unit[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
const unsigned char decimal[] = {0b10111111, 0b10000110, 0b11011011, 0b11001111, 0b11100110, 0b11101101, 0b11111101, 0b10000111, 0b11111111, 0b11101111};

// the size of the lut
const int unit_size = 10, decimal_size = 10;

void setup() {
  // setting port A as output
  DDRA = 0b11111111;
}

void loop() {
  
}
