# Multi-Level Page Table Simulator

A C module that simulates a 64-bit, trie-based 5-level page table for an x86-like processor.  It lets an OS:

- **Create and destroy mappings**  
  Map any virtual page to a physical page, or remove an existing mapping, automatically allocating or tearing down intermediate page-table levels as needed.

- **Lookup translations**  
  Given a virtual page number, determine which physical page it maps to (or report “no mapping”).

- **Handle sparse address spaces efficiently**  
  Only the portion of the page-table trie needed by active mappings is ever allocated.

- **Integrate with a simulated physical-memory manager**  
  Uses provided helpers to allocate new page frames for page-table nodes and to translate physical addresses into usable pointers.

---

# build & run
1. Using **make**
   - `make`
2. Without **make**
   - `gcc -O3 -Wall -std=c11 os.c pt.c -o page_table`
