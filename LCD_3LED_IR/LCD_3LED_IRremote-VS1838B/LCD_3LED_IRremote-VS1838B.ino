#include <IRremote.h>
#include <LiquidCrystal.h>

const int IRRECV_PIN = 2;

const int RED_LED = 3;
const int YELLOW_LED = 4;
const int GREEN_LED = 5;

const int LCD_RS = 8;
const int LCD_E = 9;
const int LCD_D4 = 10;
const int LCD_D5 = 11;
const int LCD_D6 = 12;
const int LCD_D7 = 13;

boolean state_RED = false;
boolean state_YELLOW = false;
boolean state_GREEN = false;

IRrecv irrecv(IRRECV_PIN);
decode_results results;

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("STATUS: ");

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}
void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value);
    
    switch (results.value)
    {
      case 16748655:
        if (state_RED == true && state_YELLOW == true && state_GREEN == true)
        {
          lcd.clear();
          state_RED = !state_RED;
          state_YELLOW = !state_YELLOW;
          state_GREEN = !state_GREEN;
          digitalWrite(RED_LED, state_RED);
          digitalWrite(YELLOW_LED, state_YELLOW);
          digitalWrite(GREEN_LED, state_GREEN);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("3-DEN: OFF");
          delay(1000);
          lcd.clear();
          break;
        }
        if (state_RED != true && state_YELLOW != true && state_GREEN != true)
        {
          lcd.clear();
          state_RED = !state_RED;
          state_YELLOW = !state_YELLOW;
          state_GREEN = !state_GREEN;
          digitalWrite(RED_LED, state_RED);
          digitalWrite(YELLOW_LED, state_YELLOW);
          digitalWrite(GREEN_LED, state_GREEN);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("3-DEN: ON");
          delay(1000);
          lcd.clear();
          break;
        }
        break;
      case 16753245:
        if (state_RED == true)
        {
          lcd.clear();
          state_RED = !state_RED;
          digitalWrite(RED_LED, state_RED);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("LED DO: OFF");
          delay(1000);
          lcd.clear();
        }
        else
        {
          lcd.clear();
          state_RED = !state_RED;
          digitalWrite(RED_LED, state_RED);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("LED DO: ON");
          delay(1000);
          lcd.clear();
        }
        break;
      case 16736925:
        if (state_YELLOW == true)
        {
          lcd.clear();
          state_YELLOW = !state_YELLOW;
          digitalWrite(YELLOW_LED, state_YELLOW);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("LED VANG: OFF");
          delay(1000);
          lcd.clear();
        }
        else
        {
          lcd.clear();
          state_YELLOW = !state_YELLOW;
          digitalWrite(YELLOW_LED, state_YELLOW);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("LED VANG: ON");
          delay(1000);
          lcd.clear();
        }
        break;
      case 16769565:
        if (state_GREEN == true)
        {
          lcd.clear();
          state_GREEN = !state_GREEN;
          digitalWrite(GREEN_LED, state_GREEN);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("LED XANH: OFF");
          delay(1000);
          lcd.clear();
        }
        else
        {
          lcd.clear();
          state_GREEN = !state_GREEN;
          digitalWrite(GREEN_LED, state_GREEN);
          lcd.setCursor(0, 0);
          lcd.print("STATUS: ");
          lcd.setCursor(0, 1);
          lcd.print("LED XANH: ON");
          delay(1000);
          lcd.clear();
        }
        break;
      default:
        break;
    }
    delay(200);
    irrecv.resume();
    lcd.print("Dang cho lenh...");
  }
}
