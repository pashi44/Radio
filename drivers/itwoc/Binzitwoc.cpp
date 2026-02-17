#include "Binzitwoc.hpp"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Binzitwoc, CONFIG_LOG_DEFAULT_LEVEL);

#define DT_DRV_COMPAT binz_custom_i2c



int binzitwoc_get_status(const struct device *dev)
{

    LOG_INF("Getting status from Binzitwoc device: %s", dev->name);
    return 0;
}



// --- Driver Initialization and Instantiation ---

static  int binzitwoc_init(const struct device *dev)
{
    const struct binzitwoc_config *config = 
        (const struct binzitwoc_config *)dev->config;

    


    return 0;
}




struct  binz_i2c_public_api binzitwoc_api = {
    .get_status = binzitwoc_get_status,
    .configure = binzitwoc_init
};


// This is typical for drivers that don't use 'inst' in their compatible string.
#define BINZITWOC_INIT(n)                                                       \
                                                                                \
    static const struct binzitwoc_config binzitwoc_config_##n = {               \
        .i2c_addr = 0x41,                                                       \
        .sample_rate_hz = 1000,                                                 \
    };                                                                          \
                                                                                \
                                                                                \
    DEVICE_DT_DEFINE(DT_NODELABEL(n),                                            \
                     binzitwoc_init,                                            \
                     NULL,                                                      \
                     NULL,                                       \
                     &binzitwoc_config_##n,                                        \
                     POST_KERNEL,                                               \
                     CONFIG_KERNEL_INIT_PRIORITY_DEVICE,                        \
                     &binzitwoc_api);                                           \
                                                                                \
    /* Note: We use DT_NODELABEL(n) which expects the node to have a label. */ \

BINZITWOC_INIT(i2c0_binz)