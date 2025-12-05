#include "merge_sort.h"

/* Helper function to merge two sorted lists */
static Node* merge_sorted_lists(Node *left, Node *right) {
    Node random;
    random.data = 0;
    random.next = NULL;
    Node *tail = &random;
    
    while (left != NULL && right != NULL) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    
    tail->next = (left != NULL) ? left : right;
    return random.next;
}

/* Helper function to split list into two halves */
static void split_list(Node *head, Node **left, Node **right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }
    
    Node *slow = head;
    Node *fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

/* Recursive Merge Sort */
Node* merge_sort_recursive(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *left, *right;
    split_list(head, &left, &right);
    
    left = merge_sort_recursive(left);
    right = merge_sort_recursive(right);
    
    return merge_sorted_lists(left, right);
}

/* Iterative Merge Sort (Bottom-up approach) */
Node* merge_sort_iterative(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    /* Get the length of list */
    int length = get_list_length(head);
    
    /* Create array to hold sub-lists */
    Node **lists = (Node**)malloc((length + 1) * sizeof(Node*));
    
    /* Break list into individual nodes (sub-lists of size 1) */
    Node *current = head;
    for (int i = 0; i < length; i++) {
        Node *next = current->next;
        current->next = NULL;
        lists[i] = current;
        current = next;
    }
    
    /* Merge sub-lists bottom-up */
    int current_size = 1;
    while (current_size < length) {
        int index = 0;
        
        while (index < length - current_size) {
            lists[index] = merge_sorted_lists(lists[index], lists[index + current_size]);
            index += 2 * current_size;
        }
        
        current_size *= 2;
    }
    
    Node *result = lists[0];
    free(lists);
    return result;
}
