#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "ThreadOne.hpp"
#include "threadone_heap.hpp"

#define K_JOIN_WAIT BIT(0)

#define PRIORITY 2



 int  main(void)
{
//     k_tid_t tid1 = k_thread_create(
//         &thread_one,  //thread
// 	 get_t1_stack(), //stack offset
// 	 get_t1_stack_size(),  //size
//         thread_entry_point,  //entry point
// 	 nullptr, nullptr, nullptr,
//         PRIORITY,
// 0,

// 	K_NO_WAIT);

//     k_tid_t tid2 = k_thread_create(
//         &thread_two, get_t2_stack(), get_t2_stack_size(),
//         thread_entry_point, nullptr, nullptr, nullptr,
//         PRIORITY,

// 0	, K_NO_WAIT);

// if (!alloc_dynamic_stack(2048, 0)) {
//     printk("dynamic stack alloc failed (increase CONFIG_HEAP_MEM_POOL_SIZE)\n");
//     return 0;
// }

// //k_tid_t tid3_dynamic = k_thread_create(
// //    &thread_three_dynamic,
// //    (k_thread_stack_t*)stack,
// //    sizeof(stack) /* <-- replace with the same size you passed to alloc (e.g., 2048) */,
// //    thread_entry_point, nullptr, nullptr, nullptr,
// //    PRIORITY, 0,
// //    K_NO_WAIT
// //);

//     k_thread_name_set(tid1, "t1");
//     k_thread_name_set(tid2, "t2");



// //     // demo: end them so join completes


// //     k_thread_abort(tid1);
// //     k_thread_abort(tid2);
//     (void)k_thread_join(tid1, K_FOREVER);
//     (void)k_thread_join(tid2, K_FOREVER);


// printk("  %d \n", shared_variable);




while (1){

	k_msleep(1000);

    }





return 0;

}
