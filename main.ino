#include <EEPROM.h>

int address = 0;

void read();
void erase();
void write();

void setup()
{
    Serial.begin(9600);

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
        if (value != 0) {
            Serial.println(value);
        }
    }
}

void erase()
{
    for (int i = 0; i < EEPROM.length(); i++) {
        if (EEPROM.read(i) != 0) {
            EEPROM.write(i, 0);
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
