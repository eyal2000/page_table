#include "os.h"

/*functions*/
void page_table_update(uint64_t pt, uint64_t vpn, uint64_t ppn);
uint64_t page_table_query(uint64_t pt, uint64_t vpn);

/*helper functions*/
uint64_t get_key_5(uint64_t vpn, int level);
int handle_node(uint64_t *address, uint64_t ppn, int i);

void page_table_update(uint64_t pt, uint64_t vpn, uint64_t ppn)
{
    uint64_t key, physical_address = pt << 13, *node;

    for (int i = 0; i < 5; i++)
    {
        key = get_key_5(vpn, i); /*10 relevant bits*/
        node = phys_to_virt(physical_address); /*access array of relevant node*/
        if (handle_node(&(node[key]), ppn, i)) {return;}
        physical_address = (node[key] >> 13) << 13; /*13 bottom bits are set to 0*/
    }
    return;
}

uint64_t page_table_query(uint64_t pt, uint64_t vpn)
{
    uint64_t key, physical_address = pt << 13, *node;

    for (int i = 0; i < 5; i++)
    {
        key = get_key_5(vpn, i);
        node = phys_to_virt(physical_address);
        if ((node[key] & 1) == 0) {return NO_MAPPING;} /*if not valid return no mapping*/
        physical_address = (node[key] >> 13) << 13;
    }
    return node[key] >> 13; /*return ppn*/
}

/*split into 5 parts of 10 bits*/
uint64_t get_key_5(uint64_t vpn, int level)
{
    /*shift bits and mask (take only relevant bits)*/
    uint64_t key = (vpn >> (10 * (4 - level))) & 0x3ff;
    return key;
}

int handle_node(uint64_t *address, uint64_t ppn, int i)
{
    if (i < 4)
    {
        if ((*address & 1) == 0)
        {
            if (ppn == NO_MAPPING)
            {
                return 1;
            }
            *address = (alloc_page_frame() << 13) | 1;
        }
    }

    else
    {
        *address = (ppn == NO_MAPPING) ? 0 : ((ppn << 13) | 1);
    }
    return 0;
}