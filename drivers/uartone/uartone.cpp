#include "uartone.hpp"

#include <zephyr/logging/log.h>



LOG_MODULE_REGISTER(uartone, CONFIG_LOG_DEFAULT_LEVEL);



const    struct device *uart_dev1 = DEVICE_DT_GET(UART1_node);
 const struct  device *uart_dev2 = DEVICE_DT_GET(UART2_node);




   uint8_t  uartone_init(){


    if (!device_is_ready(uart_dev1)  || !device_is_ready(uart_dev2)) {
        LOG_ERR("UART1  or uart2 (serial1 alias) not ready");
        return -ENODEV;

    }else  return 0;

 }
