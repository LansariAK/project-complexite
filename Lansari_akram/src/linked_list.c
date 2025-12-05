#include "linked_list.h"
#include <time.h>

/* Create a new node with given data */
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Append a node to the end of the list */
Node* append_node(Node *head, int data) {
    Node *new_node = create_node(data);
    
    if (head == NULL) {
        return new_node;
    }
    
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

/* Create a random linked list of given size */
Node* create_random_list(int size) {
    Node *head = NULL;
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < size; i++) {
        int random_value = rand() % 1000; /* Random values 0-999 */
        head = append_node(head, random_value);
    }
    
    return head;
}

/* Print all elements in the list */
void print_list(Node *head) {
    Node *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Free all memory allocated for the list */
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

/* Create a deep copy of the list */
Node* copy_list(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node *new_head = create_node(head->data);
    Node *current = head->next;
    Node *new_current = new_head;
    
    while (current != NULL) {
        new_current->next = create_node(current->data);
        new_current = new_current->next;
        current = current->next;
    }
    
    return new_head;
}

/* Get the length of the list */
int get_list_length(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* Concatenate three lists: left + mid + right */
Node* concatenate_lists(Node *left, Node *mid, Node *right) {
    /* If left is empty, try mid then right */
    if (left == NULL) {
        if (mid == NULL) {
            return right;  /* Only right list */
        }
        /* mid exists, find its end and attach right */
        Node *temp = mid;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = right;
        return mid;
    }
    
    /* left exists, find its end and attach mid */
    Node *temp = left;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = mid;
    
    /* If mid exists, find its end and attach right */
    if (mid != NULL) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }
    
    temp->next = right;
    return left;
}
