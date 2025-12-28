#define DT_DRV_COMPAT binz_custom_i2c
#include "CustomItwoc.hpp"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(binz_custom_i2c, CONFIG_LOG_DEFAULT_LEVEL);


static int itwoc_init(const struct device *dev) {
    const struct CustomItwoc_config_t *config = (const struct CustomItwoc_config_t *)dev->config;
    gpio_pin_configure_dt(&config->scl, (GPIO_OUTPUT  |  GPIO_PULL_UP));
    gpio_pin_configure_dt(&config->sda, (GPIO_OUTPUT |  GPIO_PULL_UP));
    return 0;
}

static int itwoc_start(const struct device *dev) {
    const struct CustomItwoc_config_t *cfg = (const struct CustomItwoc_config_t *)dev->config;
    gpio_pin_set_dt(&cfg->sda, 1); gpio_pin_set_dt(&cfg->scl, 1); k_busy_wait(10);
    gpio_pin_set_dt(&cfg->sda, 0); k_busy_wait(10);
    gpio_pin_set_dt(&cfg->scl, 0);
    return 0;
}

static int itwoc_stop(const struct device *dev) {
    const struct CustomItwoc_config_t *cfg = (const struct CustomItwoc_config_t *)dev->config;
    gpio_pin_set_dt(&cfg->sda, 0); k_busy_wait(10);
    gpio_pin_set_dt(&cfg->scl, 1); k_busy_wait(10);
    gpio_pin_set_dt(&cfg->sda, 1);
    return 0;
}

static int itwoc_write_bit(const struct device *dev, bool bit) {
    const struct CustomItwoc_config_t *cfg = (const struct CustomItwoc_config_t *)dev->config;
    gpio_pin_set_dt(&cfg->sda, bit ? 1 : 0);
    k_busy_wait(5);
    gpio_pin_set_dt(&cfg->scl, 1); k_busy_wait(5);
    gpio_pin_set_dt(&cfg->scl, 0);
    return 0;
}

static int itwoc_write_byte(const struct device *dev, uint8_t byte) {
    for (int i = 7; i >= 0; i--) {
        itwoc_write_bit(dev, (byte >> i) & 0x01);
    }
    itwoc_write_bit(dev, true); 
    return 0;
}

static void itwoc_visual_pulse(const struct device *dev, uint32_t count, uint32_t delay_ms) {
    const struct CustomItwoc_config_t *cfg = (const struct CustomItwoc_config_t *)dev->config;
    for (uint32_t i = 0; i < count; i++) {
        gpio_pin_set_dt(&cfg->sda, 1); gpio_pin_set_dt(&cfg->scl, 1);
        k_msleep(delay_ms);
        gpio_pin_set_dt(&cfg->sda, 0); gpio_pin_set_dt(&cfg->scl, 0);
        k_msleep(delay_ms);
    }
}

static const struct CustomItwoc_public_api_t custom_api = {
    .write_to_bus = itwoc_write_bit,
    .start = itwoc_start,
    .stop = itwoc_stop,
    .write_byte = itwoc_write_byte,
    .pulse = itwoc_visual_pulse,
};

#define ITWOC_DEFINE(inst)                                        \
    static const struct CustomItwoc_config_t itwoc_cfg_##inst = { \
        .scl = GPIO_DT_SPEC_INST_GET(inst, scl_gpios),            \
        .sda = GPIO_DT_SPEC_INST_GET(inst, sda_gpios),            \
        .device_id = inst,                                        \
        .clock_speed = DT_INST_PROP(inst, clock_frequency),       \
    };                                                            \
    DEVICE_DT_INST_DEFINE(inst, itwoc_init, NULL, NULL,           \
                          &itwoc_cfg_##inst, POST_KERNEL,         \
                          CONFIG_I2C_INIT_PRIORITY, &custom_api);

DT_INST_FOREACH_STATUS_OKAY(ITWOC_DEFINE)