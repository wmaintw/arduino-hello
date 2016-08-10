#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1); 
unsigned long delaytime = 500;

byte number0[] = {B11111100,
                  B10000100,
                  B11111100};
byte number1[] = {B11111100,
                  B00000000,
                  B00000000};
byte number2[] = {B10011100,
                  B10010100,
                  B11110100};
byte number3[] = {B11111100,
                  B10010100,
                  B10010100};
byte number4[] = {B11111100,
                  B00100000,
                  B00111100};
byte number5[] = {B11110100,
                  B10010100,
                  B10011100};
byte number6[] = {B11110000,
                  B10010000,
                  B11111100};
byte number7[] = {B11111100,
                  B00000100,
                  B00000100};
byte number8[] = {B11111100,
                  B10010100,
                  B11111100};
byte number9[] = {B11111100,
                  B00010100,
                  B00011100};
byte dashline = B00001110;
byte rawNumbers[30];
int padding = 3;
                  
void registerRawNumber(int index, byte number[]) {
  rawNumbers[index] = number[2];
  rawNumbers[index + 1] = number[1];
  rawNumbers[index + 2] = number[0];
}

void setupRawNumbers() {
  registerRawNumber(0, number0);
  registerRawNumber(1 * padding, number1);
  registerRawNumber(2 * padding, number2);
  registerRawNumber(3 * padding, number3);
  registerRawNumber(4 * padding, number4);
  registerRawNumber(5 * padding, number5);
  registerRawNumber(6 * padding, number6);
  registerRawNumber(7 * padding, number7);
  registerRawNumber(8 * padding, number8);
  registerRawNumber(9 * padding, number9);
}
                  
void displayNumber(int columnIndex, int number) {
  int basePosition = number * padding;
  lc.setColumn(0, columnIndex, rawNumbers[basePosition]);
  lc.setColumn(0, columnIndex + 1, rawNumbers[basePosition + 1]);
  lc.setColumn(0, columnIndex + 2, rawNumbers[basePosition + 2]);
}

void displayDashLine() {
  lc.setRow(0, 7, dashline);
}

void clearScreen() {
  lc.clearDisplay(0);
}

void displaySpeed(int currentSpeed) {
  clearScreen();
  
  if (currentSpeed <= 9) {
    displayNumber(4, currentSpeed);
    return;
  }
  
  if (currentSpeed >= 10 && currentSpeed <= 99) {
    displayNumber(0, currentSpeed / 10);
    displayNumber(4, currentSpeed % 10);
    return;
  }
  
  if (currentSpeed >= 100) {
    displayNumber(0, (currentSpeed / 10) % 10);
    displayNumber(4, currentSpeed % 10);
    displayDashLine();
    return;
  }
}

void setup()
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  
  setupRawNumbers();
}

void loop()
{
  while(true) {
    for (int i = 90; i <= 120; i += 1) {
      displaySpeed(i);
      delay(500);
    }
    delay(5000);
  }
}


