#ifndef _VHL_ELF_PARSER_H_
#define _VHL_ELF_PARSER_H_

#include "vhl.h"

#include "elf_headers.h"
#include "exports.h"
#include "nid_table.h"
#include "utils/bithacks.h"

typedef struct {
        void *data_mem_loc;
        SceUID data_mem_uid;
        int data_mem_size;

        void *exec_mem_loc;
        SceUID exec_mem_uid;
        int exec_mem_size;

        void *elf_mem_loc;
        SceUID elf_mem_uid;
        int elf_mem_size;

        char path[MAX_PATH_LENGTH];
        int (*entryPoint)(int, char**);
        SceUID thid;
} allocData;


int block_manager_initialize(VHLCalls *calls);
int block_manager_free_old_data(VHLCalls *calls, int curSlot);

int elf_parser_start(VHLCalls *calls, int curSlot, int wait);
int elf_parser_load(VHLCalls *calls, int priority, int curSlot, const char* file, void** entryPoint);


#endif
