#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "linked_list.h"

/*
 * Quick Sort - Iterative Version
 * 
 * Complexity Analysis:
 * - Best Case: O(n log n)   - balanced partitions
 * - Average Case: O(n log n) - random data
 * - Worst Case: O(n²)       - pivot is always min/max (unbalanced)
 * 
 * Space Complexity: O(log n) - using stack for intervals
 * 
 * Algorithm:
 * 1. Use explicit stack to store intervals (low, high)
 * 2. For each interval: partition and push sub-intervals
 * 3. Continue until stack is empty
 */
Node* quick_sort_iterative(Node *head);

/*
 * Quick Sort - Recursive Version
 * 
 * Complexity Analysis:
 * - Best Case: O(n log n)   - balanced partitions
 * - Average Case: O(n log n) - random data
 * - Worst Case: O(n²)       - pivot is always min/max (unbalanced)
 * 
 * Space Complexity: O(log n) average, O(n) worst - recursion stack
 * 
 * Algorithm:
 * 1. Choose pivot (here: middle element)
 * 2. Partition: move smaller to left, larger to right
 * 3. Recursively sort left and right partitions
 */
Node* quick_sort_recursive(Node *head);

#endif
