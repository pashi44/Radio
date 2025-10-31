    #include <zephyr/kernel.h>
    #include <zephyr/logging/log.h>
    #include <zephyr/drivers/gpio.h>
    #include <errno.h>
	#include  <threads.h>
    #include <zephyr/sys/printk.h> // Include printk for the main loop




	
    LOG_MODULE_REGISTER(radio, LOG_LEVEL_DBG);


    int main(void)
    {

		

        // Your main thread loop
        while (1) {
            printk("in the main loop\n");
            k_msleep(1000);
        }
    }
