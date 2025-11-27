#ifndef __BINZITWOC_HPP__
#define __BINZITWOC_HPP__
#ifdef __cplusplus__
extern "C" {
#endif

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>

extern const char *i2c_data;

typedef uint8_t (*status)(const struct device *dev);

typedef uint8_t (*binz_configure)(const struct device *dev);
//  typedef    uint8_t    (*get_status)(const  struct device *dev);

__subsystem struct binz_i2c_public_api {
	status get_status;
	binz_configure configure;
};

struct binzitwoc_config {
	uint16_t i2c_addr;
	uint16_t sample_rate_hz;
};

struct binzitwoc_data {
	uint8_t tx_buf[4];
	struct k_mutex lock;
	uint8_t current_mode;
};

#ifdef __cplusplus__
}
#endif

#endif // !  __BINZITWOC_HPP__
