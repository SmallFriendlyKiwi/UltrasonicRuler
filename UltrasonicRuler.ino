#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

// Sonar stuff
const int sonar_trigger_pin = 12;
const int sonar_echo_pin = 11;
const int sonar_max_distance = 200;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
NewPing sonar(sonar_trigger_pin, sonar_echo_pin, sonar_max_distance);

int get_distance(NewPing sonar)
  {
    int micro_seconds = sonar.ping_median(10);
    int distance = sonar.convert_cm(micro_seconds);
    // Serial.println(distance); 
    return distance;
  }

void setup()
{
  // Initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.begin(20, 4);
  // Turn on the backlight
  lcd.backlight();

  // Write characters on the display
  // NOTE: Cursor Position: Lines and Characters start at 0
  lcd.setCursor(0, 0);
  lcd.print("Sonar Ruler: v1.05");
  lcd.setCursor(0, 2);
  lcd.print("Distance:");
}

// loop: RUNS CONSTANTLY
void loop()
{
  // Update the LCD display with the current distance in cm
    lcd.setCursor(10, 2);
    lcd.print(String(get_distance(sonar)) + " cm  ");
    delay(100);
}
