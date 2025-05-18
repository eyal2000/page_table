# page-table
5-level page-table implementation.

- Hierarchical 5-level page table (`page_table_update` & `page_table_query`)
- Frame allocation and free via `mmap`/`munmap` in `os.c`
- Virtual-to-physical address translation

# build & run
1. Using **make**
   - `make`
   - `./page_table`
2. Without **make**
   - `gcc -O3 -Wall -std=c11 os.c pt.c -o page_table`
   - `./page_table`
