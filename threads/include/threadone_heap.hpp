#pragma once
#include <zephyr/kernel.h>

#ifdef __cplusplus
extern "C" {
#endif


  extern struct  k_thread  thread_three_dynamic;
/* Expose the heap-backed stack pointer you use in main() */
extern k_thread_stack_t *stack;
/* (optional) expose its size if you want to print it */
extern size_t stack_size_bytes;

/* Call before creating tid3_dynamic */
bool alloc_dynamic_stack(size_t size_bytes, uint32_t flags /* 0 or K_USER */);

/* Call after join/finish */
void free_dynamic_stack(void);






struct datapass {
    const char *name;
    int         age;
};


#ifdef __cplusplus
}
#endif