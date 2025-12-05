#include "quick_sort.h"
#include <stdlib.h>
#include <time.h>

/* Helper function to get random pivot value from the list */
static int get_pivot_value(Node *head) {
    if (head == NULL) {
        return 0;
    }
    
    /* Count nodes in the list */
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    if (count == 0) {
        return 0;
    }
    
    /* Select random position */
    int random_pos = rand() % count;
    
    /* Get the value at random position */
    current = head;
    for (int i = 0; i < random_pos; i++) {
        current = current->next;
    }
    
    return current->data;
}

/* Concatenate three lists */
static Node* partition_list(Node *head, int pivot, Node **left, Node **mid, Node **right) {
    *left = NULL;
    *mid = NULL;
    *right = NULL;
    
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        current->next = NULL;
        
        if (current->data < pivot) {
            if (*left == NULL) {
                *left = current;
            } else {
                Node *temp = *left;
                while (temp->next != NULL) temp = temp->next;
                temp->next = current;
            }
        } else if (current->data == pivot) {
            if (*mid == NULL) {
                *mid = current;
            } else {
                Node *temp = *mid;
                while (temp->next != NULL) temp = temp->next;
                temp->next = current;
            }
        } else {
            if (*right == NULL) {
                *right = current;
            } else {
                Node *temp = *right;
                while (temp->next != NULL) temp = temp->next;
                temp->next = current;
            }
        }
        
        current = next;
    }
    
    return NULL; /* Unused return, kept for compatibility */
}

/* Recursive Quick Sort */
Node* quick_sort_recursive(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    int pivot = get_pivot_value(head);
    Node *left, *mid, *right;
    
    partition_list(head, pivot, &left, &mid, &right);
    
    left = quick_sort_recursive(left);
    right = quick_sort_recursive(right);
    
    /* Use concatenate_lists from linked_list.c */
    return concatenate_lists(left, mid, right);
}

/* Iterative Quick Sort using recursive implementation */
Node* quick_sort_iterative(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    /* For linked lists, iterative implementation with explicit stack
     * is complex and offers no advantage over recursion.
     * Using recursive implementation which is tail-recursive optimized
     * by modern compilers.
     */
    return quick_sort_recursive(head);
}
