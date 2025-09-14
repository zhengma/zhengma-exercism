#include "intergalactic_transmission.h"

static void add_pbit(uint8_t *byte)
{
    uint8_t tmp = *byte;
    uint8_t counter = 0;
    while (tmp > 0) {
        counter ^= (tmp & 1);
        tmp >>= 1;
    }
    *byte += counter;
}

static int check_pbit(uint8_t *byte)
{
    uint8_t tmp = *byte;
    uint8_t counter = 0;
    while (tmp > 0) {
        counter ^= (tmp & 1);
        tmp >>= 1;
    }
    return counter;
}

int transmit_sequence(uint8_t *buffer, const uint8_t *message,
                      int message_length)
{
    int mindex = 0;
    int bindex = 0;
    while (mindex < message_length) {
        if (mindex % 7 == 0) {
            buffer[bindex] = message[mindex] & 254;
        } else {
            buffer[bindex] = message[mindex - 1] << (8 - mindex % 7);
            buffer[bindex] += message[mindex] >> (mindex % 7);
            buffer[bindex] &= 254;
            if (mindex % 7 == 6) {
                add_pbit(buffer + bindex);
                bindex++;
                buffer[bindex] = message[mindex] << 1;
            }
        }
        add_pbit(buffer + bindex);
        bindex++;
        mindex++;
    }
    if (mindex % 7 != 0) {
        buffer[bindex] = message[mindex - 1] << (8 - mindex % 7);
        add_pbit(buffer + bindex);
        bindex++;
    }
    return bindex;
}

int decode_message(uint8_t *buffer, const uint8_t *message, int message_length)
{
    uint8_t *mbase = (uint8_t*)message;
    int mindex = 0;
    int bindex = 0;

    for (int i = 0; i < message_length; ++i) {
        if (check_pbit(mbase + i) == 1) {
            return WRONG_PARITY;
        }
    }

    while (mindex < message_length - 1) {
        buffer[bindex] = message[mindex] >> 1 << (1 + mindex % 8);
        buffer[bindex] += message[mindex+1] >> (7 - mindex % 8);
        bindex++;
        mindex++;
        if (mindex % 8 == 7) {
            mindex++;
        }
    }
    return bindex;
}