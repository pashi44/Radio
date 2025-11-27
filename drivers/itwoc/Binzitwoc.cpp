#include "Binzitwoc.hpp"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Binzitwoc, CONFIG_LOG_DEFAULT_LEVEL);

#define DT_DRV_COMPAT binz_custom_i2c



uint8_t binzitwoc_get_status(const struct device *dev)
{
    LOG_INF("Getting status from Binzitwoc device");
    return 0;
}


uint8_t binzitwoc_configure(const struct device *dev)
{

const  struct binzitwoc_config *config =
 (const struct binzitwoc_config *)dev->config;





    return 0;
}



struct  binz_i2c_public_api binzitwoc_api = {
    .get_status = binzitwoc_get_status,
    .configure = binzitwoc_configure,
};



