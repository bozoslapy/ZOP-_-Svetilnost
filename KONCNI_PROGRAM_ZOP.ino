#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  

int sensorValue = 0;
unsigned int curOutputValue = 0;
unsigned int lastOutputValue;

void setup(void)
{
  Serial.begin(9600);
  lastOutputValue = ~curOutputValue;

  if (u8g.getMode() == U8G_MODE_R3G3B2)
  {
    u8g.setColorIndex(255);     
  }
  else if (u8g.getMode() == U8G_MODE_GRAY2BIT)
  {
    u8g.setColorIndex(1);         
  }
  else if (u8g.getMode() == U8G_MODE_BW)
  {
    u8g.setColorIndex(3);         
  }
  else if (u8g.getMode() == U8G_MODE_HICOLOR)
  {
    u8g.setHiColorByRGB(255, 255, 255);
  }
}
void LightMeter(uint16_t percentLight)
{
  u8g.setFont(u8g_font_fub17);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
  u8g.drawStr(4, 0, "Lux");
  u8g.drawStr(4, 20,"");
  u8g.drawFrame(4, 40, 122, 24);

  u8g.drawBox(8, 44, (114 * percentLight / 140 ), 16);

 
  if (percentLight > 99)
  {
    u8g.setPrintPos(90, 15);
  }
  else
  {
    u8g.setPrintPos(90, 15);
  }
  percentLight = percentLight * 7.705 -100;
  u8g.print(percentLight);
}
void loop(void)
{
  sensorValue = analogRead(A1);
  Serial.print("input :");
  Serial.println(sensorValue);
  curOutputValue = map(sensorValue, 0, 690, 0, 100);

  if (curOutputValue > 100)
  {
    curOutputValue = 100;
  }

  if (lastOutputValue != curOutputValue)
  {
    lastOutputValue = curOutputValue;
    u8g.firstPage();

    do
    {
      LightMeter(curOutputValue);
    }
    while (u8g.nextPage());
  }

}
