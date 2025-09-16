#pragma once
#include <zephyr/kernel.h>

extern "C" void thread_entry_point(void*, void*, void*);

// Thread control blocks are defined in the .cpp
extern struct k_thread thread_one;
extern struct k_thread thread_two;

// Expose stack objects via helpers (optional)
extern "C" k_thread_stack_t* get_t1_stack();
extern "C" size_t            get_t1_stack_size();
extern "C" k_thread_stack_t* get_t2_stack();
extern "C" size_t            get_t2_stack_size();
