#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "ThreadOne.hpp"
#include "threadone_heap.hpp"
#include<stdlib.h>

#define K_JOIN_WAIT BIT(0)

#define PRIORITY 5


 int  main(void)
{



      datapass pashi = { .name = "pashi", .age = 29 };
     datapass mouni= { .name = "mouni", .age = 25 };


    k_tid_t tid1 = k_thread_create(
        &thread_one,  //thread
	 get_t1_stack(), //stack offset
	 get_t1_stack_size(),  //size
        thread_entry_point,  //entry point
	  (  (void*) &pashi), nullptr, nullptr,
        PRIORITY,
 K_ESSENTIAL ,

	K_NO_WAIT);

    k_tid_t tid2 = k_thread_create(
        &thread_two,
	get_t2_stack(),
	 get_t2_stack_size(),
        thread_entry_point,
	 ((void*) &mouni) , nullptr, nullptr,
        PRIORITY,
 K_ESSENTIAL ,

 K_NO_WAIT);

if(tid1  ==  nullptr  && tid2  ==  nullptr ){

return  -ENOMEM;
}


    k_thread_name_set(tid1, "t1");
    k_thread_name_set(tid2, "t2");

    (void)k_thread_join(tid1, K_FOREVER);
    (void)k_thread_join(tid2, K_FOREVER);
//      k_thread_abort(tid1);
//      k_thread_abort(tid2);
    while (1){
	k_msleep(1000);

    }
return 0;

}

