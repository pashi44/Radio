#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>

#ifdef  CONFIG_RADIO_UART_INSTANCE
#include "uartone.hpp"
#endif // DEBUG


#ifdef __cplusplus__
 extern "C" {
#endif

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);



int main(void)
{
  

uartone_init();

    
    LOG_INF("Starting UART TX on UART1 and RX on UART2");
    unsigned char tx[] =   {'p', 'r','a', 's', 'h','i', '\n'};

    // unsigned char* tx  = "prashanth";
size_t len = sizeof(tx) / sizeof(tx[0]);

    while (true) {


for (size_t i = 0; i < len; i++) {
        uart_poll_out(uart_dev1, tx[i]);
        k_msleep(50);
    }


        unsigned char rx;
        int ret = uart_poll_in(uart_dev2, &rx);
        if (ret == 0) {
            printk("UART2 RX: '%c' (0x%02x)\n",
                   (rx >= 32 && rx <= 126) ? rx : '.',
                   rx);
        }

        k_msleep(5);
    }

    return 0;
}


#ifdef __cplusplus__

 }
#endif


