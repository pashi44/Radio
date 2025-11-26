#ifndef   __BINZITWOC_HPP__
#define  __BINZITWOC_HPP__
#ifdef __cplusplus__
extern "C" {
    #endif


#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>


#define I2C0_NODE DT_NODELABEL(i2c0_binz)

extern  const struct device *i2c0_dev;
extern  int binzitwoc_init();


extern  const char* i2c_data;

#ifdef __cplusplus__

}
#endif

#endif // !  __BINZITWOC_HPP__