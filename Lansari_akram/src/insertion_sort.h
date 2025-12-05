#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "linked_list.h"

/*
 * Insertion Sort - Iterative Version
 * 
 * Complexity Analysis:
 * - Best Case: O(n)     - when list is already sorted
 * - Average Case: O(n²) - random data
 * - Worst Case: O(n²)   - when list is reverse sorted
 * 
 * Space Complexity: O(1) - in-place sorting
 * 
 * Algorithm:
 * 1. Start from the second node
 * 2. For each node, compare with previous nodes
 * 3. Find correct position and insert
 */
Node* insertion_sort_iterative(Node *head);

/*
 * Insertion Sort - Recursive Version
 * 
 * Complexity Analysis:
 * - Best Case: O(n)     - when list is already sorted
 * - Average Case: O(n²) - random data
 * - Worst Case: O(n²)   - when list is reverse sorted
 * 
 * Space Complexity: O(n) - due to recursion stack
 * 
 * Algorithm:
 * 1. Recursively sort the rest of the list
 * 2. Insert current node in correct position
 */
Node* insertion_sort_recursive(Node *head);

#endif
