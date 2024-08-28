#ifndef WAMR_VM_H_
#define WAMR_VM_H_
#include <stdio.h<
#include <stdint.h>
#include <string.h>

#include "wasm_c_api.h"
#include "wasm_export.h"
#include "bh_platform.h"
#include "bh_read_file.h"

typedef struct TWamrVm {
	wasm_module_t           module;
	wasm_module_inst_t      module_inst;
	wasm_exec_env_t         exec_env;
	uint32_t                stack_size;
	uint32_t                heap_size;
	uint8_t*                global_heap_buffer;
	char*                   error_buf;
	RuntimeInitArgs         args;
} TWamrVm;

int create_vm(TWamrVm* vm, const char* filename);
int destroy_vm(TWamrVm* vm);

#endif //WAMR_VM_H_