#include <zephyr/kernel.h>
#include "ThreadOne.hpp"
#include "threadone_heap.hpp"








//

// K_THread_STACK_DEFINE(t1_stack, 1024);

K_THREAD_STACK_DEFINE(t1_stack, 1024);
K_THREAD_STACK_DEFINE(t2_stack, 1024);

struct k_thread thread_one;
struct k_thread thread_two;


struct k_thread thread_three_dynamic;

// atomic_t shared_variable = ATOMIC_INIT(0);

volatile int shared_variable = 0;

extern "C" void thread_entry_point(  void *arg1, void *, void *)
{
    // Only set and use custom data if arg1 is not null
    if (arg1 != nullptr) {
       k_thread_custom_data_set(arg1);
    } else {
        k_thread_custom_data_set(nullptr);
    }

    datapass *retrieved_ctx = (datapass *)k_thread_custom_data_get();


printk("Thread ID: %d, Name: %s\n",
	retrieved_ctx->age,
	retrieved_ctx->name);


    // Protect against null dereference
//     if (retrieved_ctx != nullptr) {
        // for (int i = 0; i < 10000; i++) {
        //     ++shared_variable;

//
	// }
// }else {
	// printk("No thread-specific data set for this thread.\n");
// }

k_msleep(100);
while(1)
k_usleep(20);

}


extern "C" k_thread_stack_t *get_t1_stack()
{
	return t1_stack;
}
extern "C" size_t get_t1_stack_size()
{
	return K_THREAD_STACK_SIZEOF(t1_stack);
}
extern "C" k_thread_stack_t *get_t2_stack()
{
	return t2_stack;
}
extern "C" size_t get_t2_stack_size()
{
	return K_THREAD_STACK_SIZEOF(t2_stack);
}



k_thread_stack_t *stack = nullptr;
size_t stack_size_bytes = 0;

bool alloc_dynamic_stack(size_t size_bytes, uint32_t flags)
{
    if (stack) return true;  // already allocated
    stack = k_thread_stack_alloc(size_bytes, flags);
    if (!stack) {
        stack_size_bytes = 0;
        return -ENOMEM;
    }
    stack_size_bytes = size_bytes;
    return true;
}

void free_dynamic_stack(void)
{
    if (stack) {
        k_thread_stack_free(stack);
        stack = nullptr;
        stack_size_bytes = 0;
    }
}
