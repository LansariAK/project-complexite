#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"

/* Structure to store timing results */
typedef struct {
    int size;
    double insertion_iterative_time;
    double insertion_recursive_time;
    double quick_iterative_time;
    double quick_recursive_time;
    double merge_iterative_time;
    double merge_recursive_time;
} TimingResult;

/* Get current time in seconds */
static double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

/* Flush CPU cache by allocating and accessing large memory buffer */
static void flush_cache() {
    /* Allocate ~256MB buffer to flush L3 cache */
    size_t cache_size = 256 * 1024 * 1024;
    char *cache_buffer = (char*)malloc(cache_size);
    
    if (cache_buffer != NULL) {
        /* Sequential access to force cache eviction */
        for (size_t i = 0; i < cache_size; i += 4096) {
            cache_buffer[i] = (char)(i % 256);
        }
        free(cache_buffer);
    }
}

/* Test all sorting algorithms */
void test_sorts(int size, TimingResult *result) {
    result->size = size;
    
    printf("\n");
    printf("================================================\n");
    printf("  Testing with list size: %d\n", size);
    printf("================================================\n");
    
    /* Seed random number generator for reproducible tests */
    srand(12345 + size);  /* Fixed seed ensures same data for each size, but reproducible across runs */
    
    /* Create random list */
    Node *original = create_random_list(size);
    
    /* Display unsorted list (for sizes up to 100, or first 100 elements if larger) */
    if (size <= 100) {
        printf("\n--- UNSORTED LIST ---\n");
        print_list(original);
        printf("\n");
    } else {
        printf("\n--- UNSORTED LIST (first 100 of %d elements) ---\n", size);
        Node *current = original;
        int count = 0;
        while (current != NULL && count < 100) {
            printf("%d", current->data);
            current = current->next;
            count++;
            if (current != NULL && count < 100) {
                printf(" -> ");
            }
        }
        if (count == 100 && current != NULL) {
            printf(" -> ...\n");
        } else {
            printf("\n");
        }
        printf("\n");
    }
    
    /* Insertion Sort Iterative */
    printf("\n[1] Insertion Sort (Iterative)\n");
    flush_cache();
    Node *list_copy = copy_list(original);
    double start = get_time();
    list_copy = insertion_sort_iterative(list_copy);
    result->insertion_iterative_time = get_time() - start;
    printf("    Time: %.6f seconds\n", result->insertion_iterative_time);
    if (size <= 100) {
        printf("    Result: ");
        print_list(list_copy);
        printf("\n");
    }
    free_list(list_copy);
    
    /* Insertion Sort Recursive */
    printf("\n[2] Insertion Sort (Recursive)\n");
    flush_cache();
    list_copy = copy_list(original);
    start = get_time();
    list_copy = insertion_sort_recursive(list_copy);
    result->insertion_recursive_time = get_time() - start;
    printf("    Time: %.6f seconds\n", result->insertion_recursive_time);
    if (size <= 100) {
        printf("    Result: ");
        print_list(list_copy);
        printf("\n");
    }
    free_list(list_copy);
    
    /* Quick Sort Iterative */
    printf("\n[3] Quick Sort (Iterative)\n");
    flush_cache();
    list_copy = copy_list(original);
    start = get_time();
    list_copy = quick_sort_iterative(list_copy);
    result->quick_iterative_time = get_time() - start;
    printf("    Time: %.6f seconds\n", result->quick_iterative_time);
    if (size <= 100) {
        printf("    Result: ");
        print_list(list_copy);
        printf("\n");
    }
    free_list(list_copy);
    
    /* Quick Sort Recursive */
    printf("\n[4] Quick Sort (Recursive)\n");
    flush_cache();
    list_copy = copy_list(original);
    start = get_time();
    list_copy = quick_sort_recursive(list_copy);
    result->quick_recursive_time = get_time() - start;
    printf("    Time: %.6f seconds\n", result->quick_recursive_time);
    if (size <= 100) {
        printf("    Result: ");
        print_list(list_copy);
        printf("\n");
    }
    free_list(list_copy);
    
    /* Merge Sort Iterative */
    printf("\n[5] Merge Sort (Iterative)\n");
    flush_cache();
    list_copy = copy_list(original);
    start = get_time();
    list_copy = merge_sort_iterative(list_copy);
    result->merge_iterative_time = get_time() - start;
    printf("    Time: %.6f seconds\n", result->merge_iterative_time);
    if (size <= 100) {
        printf("    Result: ");
        print_list(list_copy);
        printf("\n");
    }
    free_list(list_copy);
    
    /* Merge Sort Recursive */
    printf("\n[6] Merge Sort (Recursive)\n");
    flush_cache();
    list_copy = copy_list(original);
    start = get_time();
    list_copy = merge_sort_recursive(list_copy);
    result->merge_recursive_time = get_time() - start;
    printf("    Time: %.6f seconds\n", result->merge_recursive_time);
    if (size <= 100) {
        printf("    Result: ");
        print_list(list_copy);
        printf("\n");
    }
    free_list(list_copy);
    
    free_list(original);
}

/* Save results to CSV file */
void save_results_to_csv(TimingResult *results, int num_results) {
    FILE *fp = fopen("results.csv", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening results.csv\n");
        return;
    }
    
    fprintf(fp, "Size,InsertionIter,InsertionRecur,QuickIter,QuickRecur,MergeIter,MergeRecur\n");
    
    for (int i = 0; i < num_results; i++) {
        fprintf(fp, "%d,%.6f,%.6f,%.6f,%.6f,%.6f,%.6f\n",
                results[i].size,
                results[i].insertion_iterative_time,
                results[i].insertion_recursive_time,
                results[i].quick_iterative_time,
                results[i].quick_recursive_time,
                results[i].merge_iterative_time,
                results[i].merge_recursive_time);
    }
    
    fclose(fp);
    printf("\nResults saved to results.csv\n");
}

int main(int argc, char *argv[]) {
    printf("\n");
    printf("====================================================\n");
    printf("  SORTING ALGORITHMS ANALYSIS - LINKED LISTS\n");
    printf("====================================================\n");
    
    if (argc > 1) {
        /* Single test with specified size */
        int size = atoi(argv[1]);
        if (size <= 0) {
            fprintf(stderr, "List size must be positive\n");
            return 1;
        }
        
        TimingResult result;
        test_sorts(size, &result);
        
    } else {
        /* Multiple tests with different sizes */
        int sizes[] = {200, 500, 1000, 2000, 3500, 5000, 10000, 20000, 30000, 40000, 43000};
        int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
        TimingResult *results = (TimingResult*)malloc(num_sizes * sizeof(TimingResult));
        
        for (int i = 0; i < num_sizes; i++) {
            test_sorts(sizes[i], &results[i]);
        }
        
        /* Print summary table */
        printf("\n");
        printf("====================================================\n");
        printf("      SUMMARY TABLE - EXECUTION TIMES (seconds)\n");
        printf("====================================================\n\n");
        printf("%-10s | %-13s | %-13s | %-13s | %-13s | %-13s | %-13s\n",
               "Size", "Ins.Iter", "Ins.Recur", "Quick.Iter", "Quick.Recur", "Merge.Iter", "Merge.Recur");
        printf("-----------|-------------|-------------|-------------|-------------|-------------|-------------\n");
        
        for (int i = 0; i < num_sizes; i++) {
            printf("%-10d | %13.6e | %13.6e | %13.6e | %13.6e | %13.6e | %13.6e\n",
                   results[i].size,
                   results[i].insertion_iterative_time,
                   results[i].insertion_recursive_time,
                   results[i].quick_iterative_time,
                   results[i].quick_recursive_time,
                   results[i].merge_iterative_time,
                   results[i].merge_recursive_time);
        }
        
        printf("-----------|-------------|-------------|-------------|-------------|-------------|-------------\n");
        
        save_results_to_csv(results, num_sizes);
        free(results);
    }
    
    printf("\n");
    return 0;
}
