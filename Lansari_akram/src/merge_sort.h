#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "linked_list.h"

/*
 * Merge Sort - Iterative Version
 * 
 * Complexity Analysis:
 * - Best Case: O(n log n)   - consistent regardless of data
 * - Average Case: O(n log n) - consistent
 * - Worst Case: O(n log n)   - consistent
 * 
 * Space Complexity: O(n) - requires temporary space for merging
 * 
 * Algorithm:
 * 1. Start with sub-lists of size 1, then 2, 4, 8, etc.
 * 2. Merge adjacent sub-lists bottom-up
 * 3. Continue until entire list is sorted
 */
Node* merge_sort_iterative(Node *head);

/*
 * Merge Sort - Recursive Version
 * 
 * Complexity Analysis:
 * - Best Case: O(n log n)   - consistent regardless of data
 * - Average Case: O(n log n) - consistent
 * - Worst Case: O(n log n)   - consistent
 * 
 * Space Complexity: O(n) + O(log n) - merge space + recursion stack
 * 
 * Algorithm:
 * 1. Divide list into two halves recursively
 * 2. Recursively sort both halves
 * 3. Merge the two sorted halves
 */
Node* merge_sort_recursive(Node *head);

#endif
