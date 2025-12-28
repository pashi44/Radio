#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include "CustomItwoc.hpp"

int main(void) {
    const struct device *const dev0 = DEVICE_DT_GET(DT_NODELABEL(binz_i2c_one));
    const struct device *const dev1 = DEVICE_DT_GET(DT_NODELABEL(binz_i2c_two));

    if (!device_is_ready(dev0) || !device_is_ready(dev1)) {
        printk("One or more I2C drivers not ready\n");
        return -1;
    }

    const struct CustomItwoc_public_api_t *api0 = (const struct CustomItwoc_public_api_t *)dev0->api;
    const struct CustomItwoc_public_api_t *api1 = (const struct CustomItwoc_public_api_t *)dev1->api;

    while (1) {
        printk("Pulsing BUS 0 (GPIO 4/5)...\n");
        api0->pulse(dev0,1000, 3);

        printk("Pulsing BUS 1 (GPIO 18/19)...\n");
        api1->pulse(dev1,1000, 3);

        api0->start(dev0);
        api0->write_byte(dev0, 0x3C << 1);
        api0->stop(dev0);


k_msleep(1000);
	}
    return 0;
}