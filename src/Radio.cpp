#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>

#ifdef  CONFIG_RADIO_UART_INSTANCE
#include "uartone.hpp"

#endif // DEBUG

#ifdef CONFIG_BINZ_ITWOC
#include "Binzitwoc.hpp"
#define I2C_CONTROLLER_NODE DT_NODELABEL(i2c0_binz)
static const struct device *i2c0_dev = DEVICE_DT_GET(I2C_CONTROLLER_NODE);
#endif // DEBUG

#ifdef __cplusplus__
 extern "C" {
#endif

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

const char* i2c_data= "Data fro mbinz itwoc driver\n";

int main(void)
{
  

// uartone_init();

    
    while (true) {
    printk("welcome to the OTA %d \n",k_uptime_get_32());
        k_msleep(1000);
    }
    return 0;
}


#ifdef __cplusplus__

 }
#endif


