#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>

#ifdef  CONFIG_RADIO_UART_INSTANCE
#include "uartone.hpp"

#endif // DEBUG


#include "Binzitwoc.hpp"

#ifdef __cplusplus__
 extern "C" {
#endif

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

const char* i2c_data= "Data fro mbinz itwoc driver\n";

int main(void)
{
  

uartone_init();
binzitwoc_init();

    
    while (true) {


int ret = i2c_write(i2c0_dev, (const uint8_t*)i2c_data, strlen(i2c_data), 0x40);

        k_msleep(5);
    }

    return 0;
}


#ifdef __cplusplus__

 }
#endif


