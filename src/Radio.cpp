#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "ThreadOne.hpp"

#define PRIORITY 5

extern "C"   int  main(void)
{
    k_tid_t tid1 = k_thread_create(
        &thread_one, get_t1_stack(), get_t1_stack_size(),
        thread_entry_point, nullptr, nullptr, nullptr,
        PRIORITY, 0, K_NO_WAIT);

    k_tid_t tid2 = k_thread_create(
        &thread_two, get_t2_stack(), get_t2_stack_size(),
        thread_entry_point, nullptr, nullptr, nullptr,
        PRIORITY, 0, K_NO_WAIT);

    k_thread_name_set(tid1, "t1");
    k_thread_name_set(tid2, "t2");

printk(" tid1 stack regin  %p size ", (void*)get_t1_stack());
printk(" tid2 stack regin  %p size ", (void*)get_t2_stack());


    // demo: end them so join completes
    k_msleep(1000);
    k_thread_abort(tid1);
    k_thread_abort(tid2);
    (void)k_thread_join(tid1, K_FOREVER);
    (void)k_thread_join(tid2, K_FOREVER);

    while (1) k_msleep(1000);
return 0;

}

