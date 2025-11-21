#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>

#ifdef CONFIG_RADIO_UART_INSTANCE
#include "uart.hpp"
#endif



LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

#define UART1_NODE DT_ALIAS(serial1)
#define UART2_NODE DT_NODELABEL(uart2)

int main(void)
{
    const struct device *uart_dev1 = DEVICE_DT_GET(UART1_NODE);
    const struct device *uart_dev2 = DEVICE_DT_GET(UART2_NODE);

    if (!device_is_ready(uart_dev1)) {
        LOG_ERR("UART1 (serial1 alias) not ready");
        return -ENODEV;
    } else {
        LOG_INF("UART1 device is ready");
    }

    if (!device_is_ready(uart_dev2)) {
        LOG_ERR("UART2 (uart2 node) not ready");
        return -ENODEV;
    } else {
        LOG_INF("UART2 device is ready");
    }

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
