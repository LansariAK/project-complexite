#include "insertion_sort.h"

/* Helper function to insert a node at correct position in sorted list */
static Node* insert_sorted(Node *head, Node *node) {
    if (head == NULL || head->data >= node->data) {
        node->next = head;
        return node;
    }
    
    Node *current = head;
    while (current->next != NULL && current->next->data < node->data) {
        current = current->next;
    }
    
    node->next = current->next;
    current->next = node;
    return head;
}

/* Iterative Insertion Sort */
Node* insertion_sort_iterative(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *sorted = NULL;
    Node *current = head;
    
    while (current != NULL) {
        Node *next = current->next;
        current->next = NULL;
        sorted = insert_sorted(sorted, current);
        current = next;
    }
    
    return sorted;
}

/* Helper function for recursive insertion sort - insert node into sorted list */
static Node* insert_sorted_recursive(Node *head, Node *node) {
    if (head == NULL || head->data >= node->data) {
        node->next = head;
        return node;
    }
    
    head->next = insert_sorted_recursive(head->next, node);
    return head;
}

/* Recursive Insertion Sort */
Node* insertion_sort_recursive(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *next = head->next;
    head->next = NULL;
    
    Node *sorted = insertion_sort_recursive(next);
    return insert_sorted_recursive(sorted, head);
}
