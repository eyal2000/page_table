# Multi-Level Page Table Simulator

A C module that simulates a 64-bit, trie-based 5-level page table, providing:

- **Create & destroy mappings**
  Map or unmap any virtual page number (VPN) to a physical page number (PPN), automatically allocating or tearing down intermediate page-table levels as needed.
- **Lookup translations**
  Given a VPN, return its mapped PPN or report `NO_MAPPING`.
- **Efficient memory usage**
  Only the portions of the page-table trie containing active mappings are ever allocated.

---

- **os.c**       — *(provided)* OS physical‐memory manager simulation (`alloc_page_frame()`, `phys_to_virt()`, `NO_MAPPING`)
- **os.h**       — *(provided)* Declarations for the simulated OS API
- **pt.c**       — Implementation of `page_table_update()` and `page_table_query()`
- **Makefile**   — Rules to compile the `page_table` executable
- **README.md**  

---

# build & run
1. Using **make**
   - `make`
2. Without **make**
   - `gcc -O3 -Wall -std=c11 os.c pt.c -o page_table`
  
# Feed commands from a file
./page_table < commands.txt
