# Sorting Algorithms Analysis - Part 1

## Project Overview

Comprehensive analysis of three fundamental sorting algorithms implemented in C using singly linked lists.

**Algorithms Analyzed:**
- **Insertion Sort** (Iterative and Recursive)
- **Quick Sort** (Iterative and Recursive)  
- **Merge Sort** (Iterative and Recursive)

## Project Structure

```
.
├── src/                           # C Source Code
│   ├── main.c                    # Main program with timing measurements
│   ├── linked_list.h/c           # Singly linked list implementation
│   ├── insertion_sort.h/c        # Insertion sort (2 versions)
│   ├── quick_sort.h/c            # Quick sort (2 versions)
│   └── merge_sort.h/c            # Merge sort (2 versions)
├── bin/                          # Compiled executable
│   └── sort_analyzer.exe         # Program binary
├── analysis/                     # Analysis and Reports
│   ├── Rapport_Final.pdf         # FINAL REPORT (19 pages, 2.06 MB)
│   ├── 01_comparison_all.png     # Complete algorithm comparison
│   ├── 02_iterative_vs_recursive.png  # Iterative vs Recursive analysis
│   ├── 03_complexity_analysis.png    # Theory vs Practice
│   ├── 04_performance_ranking.png    # Performance ranking at n=43000
│   └── 05_summary_table.png          # Timing summary table
├── results.csv                   # Raw timing data (11 test sizes)
└── README.md                     # This file
```


## Building & Running

### Compilation

```bash
gcc -O2 -Wall -Wextra -lm src/main.c src/linked_list.c src/insertion_sort.c src/quick_sort.c src/merge_sort.c -o bin/sort_analyzer.exe
```

Or using wildcard:
```bash
gcc -O2 -Wall -Wextra -lm src/*.c -o bin/sort_analyzer.exe
```

### Running Tests

```bash
# Default: test all sizes (200, 500, 1000, 2000, 3500, 5000, 10000, 20000, 30000, 40000, 43000)
./bin/sort_analyzer.exe

# Custom size (e.g., 5000)
./bin/sort_analyzer.exe 5000

# Maximum safe size
./bin/sort_analyzer.exe 43000
```

### Visualizations


Generates 5 PNG graphs (1.9 MB total):
1. **01_comparison_all.png** - All algorithms on log scale
2. **02_iterative_vs_recursive.png** - Implementation comparison
3. **03_complexity_analysis.png** - Theory vs Practice validation
4. **04_performance_ranking.png** - Performance hierarchy at n=43,000
5. **05_summary_table.png** - Timing data table



## Technical Details

- **Language:** C 
- **Data Structure:** Singly linked list (Node: data + next pointer)
- **Timing:** clock_gettime(CLOCK_MONOTONIC) - nanosecond precision
- **Compiler:** GCC with -O2 optimization
- **Range:** n = 200 to 43,000 (11 test points)
- **Optimization:** Cache flushing (256MB per algorithm run)
- **RNG:** Fixed seeding (12345 + size) for reproducibility
- **Pivot Strategy:** Randomized for Quick Sort (improves performance)

## Testing Methodology

### Cache Optimization
- 256 MB buffer allocation after each algorithm
- Sequential memory access to evict L1/L2/L3 caches
- Ensures fair comparison between algorithms

### Data Generation
- Fixed RNG seed (12345 + size) for reproducibility
- Each algorithm tests on independent copy
- Random integers [0, 999]

### Pivot Selection (Quick Sort)
- Randomized pivot to avoid degenerate cases
- Improves average-case performance
- Still shows O(n²) degradation on linked lists


---

**Last Updated:** December 2, 2025  

