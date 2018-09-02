#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <keypadc.h>

static const char* KEYS[52] = {
                "graph", "trace", "zoom", "window",
                "yequals", "2nd", "mode", "del",
                "", "sto", "ln", "log",
                "square", "recip", "math", "alpha",
                "0", "1", "4", "7",
                "comma", "sin", "apps", "x",
                "dec", "2", "5", "8",
                "lparen", "cos", "prgm", "stat",
                "neg", "3", "6", "9",
                "rparen", "tan", "vars", "",
                "enter", "add", "sub", "mult",
                "div", "power", "clear", "",
                "down", "left", "right", "up"
                };

static uint16_t KB_DATA_COPY[8];

void kc_update()
{
    memcpy(KB_DATA_COPY, kb_Data, 16);
    kb_Scan();
}

static bool current_state(uint16_t* data, char* key)
{
    uint8_t i;
    uint8_t keyByte;
    for(i = 0; i < 52; i++)
    {
        if(strcmp(KEYS[i], key) == 0)
        {
            break;
        }
    }

    if(i == 52)
    {
        return false;
    }

    keyByte = 1 << (i % 8);

    return data[i / 8 + 1] & keyByte;
}

bool kc_state(char* key)
{
    return current_state(kb_Data, key);
}

bool kc_pressed(char* key)
{
    return current_state(kb_Data, key) && !current_state(KB_DATA_COPY, key);
}

bool kc_released(char* key)
{
    return !current_state(kb_Data, key) && current_state(KB_DATA_COPY, key);
}

