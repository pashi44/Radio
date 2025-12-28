#ifndef CUSTOM_ITWOC_HPP
#define CUSTOM_ITWOC_HPP

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*api_status_fn)(const struct device *dev, int *data);
typedef int (*api_write_bit_fn)(const struct device *dev, bool bit);
typedef int (*api_start_stop_fn)(const struct device *dev);
typedef int (*api_write_byte_fn)(const struct device *dev, uint8_t byte);
typedef void (*api_pulse_fn)(const struct device *dev, uint32_t count, uint32_t delay_ms);

struct CustomItwoc_public_api_t {
    api_status_fn driver_status;
    api_write_bit_fn write_to_bus;
    api_start_stop_fn start;
    api_start_stop_fn stop;
    api_write_byte_fn write_byte;
    api_pulse_fn pulse; 
};

struct CustomItwoc_config_t {
    struct gpio_dt_spec scl;
    struct gpio_dt_spec sda;
    uint32_t device_id;
    uint32_t clock_speed;
};

#ifdef __cplusplus
}
#endif

#endif