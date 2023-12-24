
#include <devices/usart.hpp>

int main()
{
    Usart usart;
    usart.configure<true, true, 115200, Usart::Parity::None, Usart::StopBits::S1, Usart::DataSize::D8>();
    usart.write_PString(PSTR("$$$\r"));

    while(true);
}

