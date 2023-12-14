
#include <avr/io.h>

void setupUSART()
{
    int baud = 8;
    /* Set baud rate */
    UBRRH = (unsigned char)(baud>>8);
    UBRRL = (unsigned char)baud;
    /* Enable receiver and transmitter */
    UCSRB = (1<<RXEN)|(1<<TXEN);
    /* Set frame format: 8data, 2stop bit */
    UCSRC = (1<<USBS)|(3<<UCSZ0);
}


int main()
{
    setupUSART();
}
