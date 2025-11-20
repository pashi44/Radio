#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>
#include "uart.hpp"

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

#define UART1_NODE DT_ALIAS(serial1)
#define UART2_NODE DT_NODELABEL(uart2)

int main(void)
{
    

    

    while(1){k_msleep(5);}






    return 0;
}
