
#include <devices/usart.hpp>
#include <delay.hpp>

int main()
{
    Usart usart;
    usart.configure<true, true, 115200, Usart::Parity::None, Usart::StopBits::S1, Usart::DataSize::D8>();

    Delay::ms(500);

    usart.write(P_STR("$$$\r"));

    while(true);
}

