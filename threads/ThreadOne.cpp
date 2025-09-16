#include <zephyr/kernel.h>
#include "ThreadOne.hpp"

// Each stack is defined once here
K_THREAD_STACK_DEFINE(t1_stack, 1024);
K_THREAD_STACK_DEFINE(t2_stack, 1024);

// Thread control blocks defined here
struct k_thread thread_one;
struct k_thread thread_two;

extern "C" void thread_entry_point(void*, void*, void*)
{
    while (true) {
        k_msleep(200);
    }
}

// Optional helpers (so main doesn't need the macro names)
extern "C" k_thread_stack_t* get_t1_stack() { return t1_stack; }
extern "C" size_t get_t1_stack_size()       { return K_THREAD_STACK_SIZEOF(t1_stack); }
extern "C" k_thread_stack_t* get_t2_stack() { return t2_stack; }
extern "C" size_t get_t2_stack_size()       { return K_THREAD_STACK_SIZEOF(t2_stack); }
