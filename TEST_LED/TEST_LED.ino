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

IRrecv irrecv(IRRECV_PIN);
decode_results results;

LiquidCrystal lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  lcd.begin(16,2);
  lcd.print("Duy Ne");
    
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(YELLOW_LED,OUTPUT);

}
void loop()
{

   if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX); 
    delay(200);
    irrecv.resume();
  }
  
  digitalWrite(RED_LED,HIGH);
  delay(1000);
  digitalWrite(RED_LED,LOW);
  delay(1000);

  digitalWrite(YELLOW_LED,HIGH);
  delay(1000);
  digitalWrite(YELLOW_LED,LOW);
  delay(1000);

  digitalWrite(GREEN_LED,HIGH);
  delay(1000);
  digitalWrite(GREEN_LED,LOW);
  delay(1000);
}
