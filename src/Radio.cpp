#include <zephyr/kernel.h>
#include <iostream>
#include <algorithm>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include  <zephyr/drivers/uart.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

#define UART1_CONSOLE DT_ALIAS(serial1)

const  struct device *uart_dev1= DEVICE_DT_GET(UART1_CONSOLE);
using namespace std;
int main()
{

  if (!device_is_ready(uart_dev1)) {
    LOG_ERR("UART device not ready");
    return -ENODEV;
  }else {
    LOG_INF("UART device is ready");
  }


   uart_poll_out(uart_dev1,   'p');

	while (1) {

		k_msleep(1000);
	}

	return 0;
}
