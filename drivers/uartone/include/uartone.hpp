#ifndef UARTONE_HPP
#define UARTONE_HPP

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>


#define DT_DRV_COMPAT espressif_esp32_uart
#ifdef __cplusplus__
extern "C"{
#endif // DEBUG

// #define UART1_NODE DT_ALIAS(serial1)
// #define UART2_NODE DT_NODELABEL(uart2)

#define UART1_node DT_INST(1,espressif_esp32_uart)
#define UART2_node DT_INST(2,espressif_esp32_uart)

extern const struct device *uart_dev1;
extern const struct device *uart_dev2;


extern     uint8_t uartone_init();

#ifdef __cplusplus__
}
#endif


#endif