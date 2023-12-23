
#include <avr/io.h>

#include "avr-lib/include/math.hpp"
#include "avr-lib/include/devices/usart.hpp"


int main()
{
    Usart usart;
    usart.configure<true, true, 115200, Usart::None, Usart::S1, Usart::D8>();

    while(true);
}
