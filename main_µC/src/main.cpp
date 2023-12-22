
#include <avr/io.h>

#include "avr-lib/include/math.hpp"

#ifndef F_CPU
#error "F_CPU is not set"
#endif


template<long baud, bool speed_mode, int stop_bits>
void setupUSART()
{
    static_assert(stop_bits == 1 || stop_bits == 2);
    constexpr int mul = speed_mode? 8 : 16;

    constexpr double exact_ubrr = static_cast<double>(F_CPU) / (mul * baud) - 1;
    constexpr long rounded_ubrr = round<long>(exact_ubrr);
    static_assert(rounded_ubrr < 65536);

    constexpr long  real_baud = F_CPU / (mul * (rounded_ubrr + 1));
    constexpr long diff = abs(real_baud - baud);
    constexpr auto error = diff/static_cast<double>(baud) * 100;

    // based on https://stackoverflow.com/questions/65092264/how-to-set-atmega64a-au-usart-speed-to-115200
    static_assert(error <= 4.5, "Too big frequency error for USART. Adjust F_CPU and/or baud rate");

    // setup usart module
    UBRRH = (baud >> 8) & 0xff;
    UBRRL = baud & 0xff;

    UCSRB = (1 << RXEN) | (1 << TXEN);

    UCSRC = (3<<UCSZ0);
    if (stop_bits == 2)
        UCSRC |= (1<<USBS);
}


int main()
{
    setupUSART<115200, true, 1>();
    while(true);
}
