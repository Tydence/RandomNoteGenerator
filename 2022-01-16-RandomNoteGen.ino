/*
 * Random Note Generator
 * 
 * This builds quick sequences of random notes, within a set key
 * 
 * 

# Pin Setup
/*
 * Pot 1 A01 - Goes to Center Pin + and - go to the outside pins 
 * Pot 2 A02 - Goes to Center Pin + and - go to the outside pins 
 * Pot 3 A03 - Goes to Center Pin + and - go to the outside pins 
 * 
 * Reset Button
 * Trigger Button
 *
 * 
 */


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int KeyPin = A1;    // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int SpacesPin = A2; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int GatePin = A3;   // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V                    
                    
float PotIn = 0; // The variable for the Pot input reads  0 to 1023
int KeyPotValue;
int Major;
char CurrentKey[2]="A";  // Current Key



void setup() {
  Serial.begin(9600);



  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  // display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  // display.display();
  // delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...



}

void loop() {
ReadPots(); // Read the Pots and assign variables

KeyCalc(); // Key calculation subroutine
ShowInfo(); // Put info on the screen
  
}


void ReadPots(){
  KeyPotValue = analogRead(KeyPin);  // read The Key Pot
  Serial.println(CurrentKey);       // debug value
  }

// if (x > 120) {digitalWrite(LEDpin1, HIGH); digitalWrite(LEDpin2, HIGH);}


 // Calculates the Key based on the Pot position
void KeyCalc(void) {
  if (KeyPotValue > 0 && KeyPotValue < 85)       {CurrentKey == "C"; Major = 1;}
  if (KeyPotValue > 0 && KeyPotValue < 85)       {CurrentKey == "C"; Major = 0;}
  if (KeyPotValue > 85 && KeyPotValue < 170)     {CurrentKey == "Db"; Major = 1;}
  if (KeyPotValue > 85 && KeyPotValue < 170)     {CurrentKey == "Db"; Major = 0;}
  if (KeyPotValue > 170 && KeyPotValue < 255)    {CurrentKey == "D"; Major = 1;}
  if (KeyPotValue > 170 && KeyPotValue < 255)    {CurrentKey == "D"; Major = 0;}
  if (KeyPotValue > 255 && KeyPotValue < 341)    {CurrentKey == "Eb"; Major = 1;}
  if (KeyPotValue > 255 && KeyPotValue < 341)    {CurrentKey == "Eb"; Major = 0;}
  if (KeyPotValue > 341 && KeyPotValue < 427)    {CurrentKey == "E"; Major = 1;}
  if (KeyPotValue > 341 && KeyPotValue < 427)    {CurrentKey == "E"; Major = 0;}
  if (KeyPotValue > 428 && KeyPotValue < 513)    {CurrentKey == "F"; Major = 1;}
  if (KeyPotValue > 428 && KeyPotValue < 513)    {CurrentKey == "F"; Major = 0;}
  if (KeyPotValue > 514 && KeyPotValue < 599)    {CurrentKey == "Fs"; Major = 1;}
  if (KeyPotValue > 514 && KeyPotValue < 599)    {CurrentKey == "Fs"; Major = 0;}
  if (KeyPotValue > 599 && KeyPotValue < 685)    {CurrentKey == "G"; Major = 1;}
  if (KeyPotValue > 599 && KeyPotValue < 685)    {CurrentKey == "G"; Major = 0;}
  if (KeyPotValue > 685 && KeyPotValue < 771)    {CurrentKey == "Ab"; Major = 1;}
  if (KeyPotValue > 685 && KeyPotValue < 771)    {CurrentKey == "Ab"; Major = 0;}
  if (KeyPotValue > 771 && KeyPotValue < 857)    {CurrentKey == "A"; Major = 1;}
  if (KeyPotValue > 771 && KeyPotValue < 857)    {CurrentKey == "A"; Major = 0;}
  if (KeyPotValue > 857 && KeyPotValue < 943)    {CurrentKey == "Bb"; Major = 1;}
  if (KeyPotValue > 857 && KeyPotValue < 943)    {CurrentKey == "Bb"; Major = 0;} 
  if (KeyPotValue > 943 && KeyPotValue < 1029)   {CurrentKey == "B"; Major = 1;}
  if (KeyPotValue > 943 && KeyPotValue < 1029)   {CurrentKey == "B"; Major = 0;}
}


void ShowInfo() {
  display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(("Current Key"));
    display.setCursor(85,0);             // Start after Current Key
  display.println(KeyPotValue);
  display.display();
  // delay(20);
}
