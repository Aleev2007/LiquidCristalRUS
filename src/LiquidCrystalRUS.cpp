#include "LiquidCrystalRUS.h"
#include <inttypes.h>
#include "Arduino.h"

size_t LiquidCrystalRUS::write(const uint8_t* buffer, size_t size)
{
    size_t n = 0;
    while (size--) {
        uint8_t ch = *buffer++;
        if (ch == 0xD0) {
            ch = *buffer++;
            --size;
            if (ch == 0x81) 
                ch = 0xA2;                                  // Ё     UTF‑8 0xD081
            else if (ch >= 0x90 && ch <= 0xBF)             // А..п  UTF‑8 0xD090..0xD0BF
                ch = pgm_read_byte(&_RUS[ch - offset_D0]); 
        }
        else if (ch == 0xD1) {
            ch = *buffer++;
            --size;
            if (ch == 0x91)
                ch = 0xB5;                                  // ё     UTF‑8 0xD191
            else if (ch >= 0x80 && ch <= 0x8F)             // р..я  UTF‑8 0xD180..0xD08F
                ch = pgm_read_byte(&_RUS[ch - offset_D1]); 
        }
        else if (ch == 0x7E)
            ch = 0xE9;                                      // ~     UTF‑8 0x7E
        else if (ch == 0xE2) {
            ch = 0xCC;                                      // №     UTF‑8 0xE28496
            size -= 2;
            buffer += 2;
        }
        else if (ch == 10 || ch == 13) 
            continue;                                       // skip "\r\n", for tolerant of writeln()
        if (write(ch)) n++;
        else break;
    }
    return n;
}

size_t LiquidCrystalRUS::print(const __FlashStringHelper* ifsh)
{
    PGM_P p = reinterpret_cast<PGM_P>(ifsh);
    uint8_t buff[strlen_P(p)];
    for (uint8_t i = 0; i < strlen_P(p); i++)
        buff[i] = pgm_read_byte(p + i);
    return this->write(buff, strlen_P(p));

}

