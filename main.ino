#include <EEPROM.h>

int address = 0;

void read();
void erase();
void write();

void setup()
{
    Serial.begin(9600);

    erase();

    write('a');
    write('b');
    write('c');

    read();
}
 
void loop()
{
}

void read()
{
    for (int i = 0; i < EEPROM.length(); i++) {
        byte value = EEPROM.read(i);
        if (value != 0xff) {
            Serial.println(value);
        }
    }
}

void erase()
{
    for (int i = 0; i < EEPROM.length(); i++) {
        if (EEPROM.read(i) != 0xff) {
            EEPROM.write(i, 0xff);
        }
    }

    address = 0;
}

void write(byte value)
{
    EEPROM.write(address, value);
    address++;

    if (address == EEPROM.length()) {
        address = 0;
    }
}
