#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>
#include <zephyr/modem/backend/uart.h>
#include <zephyr/modem/backend/tty.h>

#include <zephyr/modem/pipe.h>




#ifdef  CONFIG_RADIO_UART_INSTANCE
#include "uartone.hpp"

#endif // DEBUG
static uint8_t uart_backend_receive_buf[512];

static uint8_t uart_backend_transmit_buf[512];



#ifdef CONFIG_BINZ_ITWOC
#include "Binzitwoc.hpp"
#define I2C_CONTROLLER_NODE DT_NODELABEL(i2c0_binz)
static const struct device *i2c0_dev = DEVICE_DT_GET(I2C_CONTROLLER_NODE);
#endif // DEBUG
LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);
static struct modem_backend_uart uart_backend;
static struct  modem_pipe *modem_pipe;

#define  UART_DEVICE  DT_NODELABEL(uart1)
//OUR  UART mdoem cumminication
const struct device *uart_modem_dev = DEVICE_DT_GET(UART_DEVICE); 

#ifdef  MODEM_BACKEND_UART
#endif // MODEM_BACKEND_UART


/*
//notes here
modem_backend_uart has modem_pipe which acts a standard connector 
for various high-level to low-level communication.
modem_pipe inturn  has a pointer member  of  modem_pipe_api(that handles the
open,close receive, transmit of data).

*/
const static struct modem_backend_uart_config uart_modem_config ={

.uart = uart_modem_dev,
.receive_buf = uart_backend_receive_buf,

.receive_buf_size =sizeof( uart_backend_receive_buf),
.transmit_buf = uart_backend_transmit_buf,
.transmit_buf_size = sizeof(uart_backend_transmit_buf),



};



#ifdef __cplusplus__
 extern "C" {
#endif


const char* i2c_data= "Data fro mbinz itwoc driver\n";

int main(void)
{
  

if(!device_is_ready(uart_modem_dev)) {

LOG_ERR("Uart mdoem dev is not ready");
return -ENODEV;

}   



modem_pipe = modem_backend_uart_init(&uart_backend, &uart_modem_config);



    while (true) {
    printk("welcome to the OTA %d \n",k_uptime_get_32());
        k_msleep(1000);
    }
    return 0;
}


#ifdef __cplusplus__

 }
#endif


