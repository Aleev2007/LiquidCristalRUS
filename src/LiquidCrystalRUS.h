#ifndef LiquidCrystalRUS_h
#define LiquidCrystalRUS_h

#ifndef LiquidCrystal_I2C_h
#include "LiquidCrystal.h"
#endif

static const unsigned char offset_D0 = 0x90;
static const unsigned char offset_D1 = 0x50;


static const char _RUS[] PROGMEM = {            // character encoding table from UTF‑8 to chines LCD "WINSTAR", e.g. WH1602-##-CT#, whis russian simbols 
 0x41,0xA0,0x42,0xA1,0xE0,0x45,0xA3,0xA4,       // <-- offset -0x90 for 0xD0## chars
 0xA5,0xA6,0x4B,0xA7,0x4D,0x48,0x4F,0xA8,
 0x50,0x43,0x54,0xA9,0xAA,0x58,0xE1,0xAB,
 0xAC,0xE2,0xAD,0xAE,0x62,0xAF,0xB0,0xB1,
 0x61,0xB2,0xB3,0xB4,0xE3,0x65,0xB6,0xB7,
 0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0x6F,0xBE,
 0x70,0x63,0xBF,0x79,0xE4,0x78,0xE5,0xC0,       // <-- offset -0x50 for 0xD1## chars
 0xC1,0xE6,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7 };

class LiquidCrystalRUS : public 
#ifndef LiquidCrystal_I2C_h 
    LiquidCrystal 
{
public:
    LiquidCrystalRUS(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
        LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) {}

    LiquidCrystalRUS(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) :
        LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) {}

    LiquidCrystalRUS(uint8_t rs, uint8_t rw, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) :
        LiquidCrystal(rs, rw, enable, d0, d1, d2, d3) {}

    LiquidCrystalRUS(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) :
        LiquidCrystal(rs, enable, d0, d1, d2, d3) {}
#else
    LiquidCrystal_I2C
{
public:
    LiquidCrystalRUS(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows) :
        LiquidCrystal_I2C(lcd_Addr, lcd_cols, lcd_rows) {}
#endif

  virtual size_t write(const uint8_t*, size_t);
  size_t LiquidCrystalRUS::print(const __FlashStringHelper*);
  
#ifndef LiquidCrystal_I2C_h 
  using LiquidCrystal::write;
#else
  using LiquidCrystal_I2C::write;
#endif
  using Print::print;
};

#endif
