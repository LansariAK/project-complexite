#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/* Node structure for singly linked list */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Function prototypes for linked list operations */
Node* create_node(int data);
Node* append_node(Node *head, int data);
Node* create_random_list(int size);
void print_list(Node *head);
void free_list(Node *head);
Node* copy_list(Node *head);
int get_list_length(Node *head);
Node* concatenate_lists(Node *left, Node *mid, Node *right);

#endif
