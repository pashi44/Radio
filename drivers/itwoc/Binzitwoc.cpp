#include "Binzitwoc.hpp"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Binzitwoc, CONFIG_LOG_DEFAULT_LEVEL);

#define DT_DRV_COMPAT binz_custom_i2c



const struct  device * i2c0_dev = DEVICE_DT_GET(I2C0_NODE);
int binzitwoc_init()
{
    if (!device_is_ready(i2c0_dev)) {
        LOG_ERR("I2C0 device not ready");
        return -ENODEV;
    }

    LOG_INF("I2C0 device initialized successfully");
    return 0;
}