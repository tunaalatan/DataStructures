#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    int value;
    struct node* next;
} node_t;

void printlist(node_t* head);

node_t* node(int value);

node_t* add_to_head(node_t** head, int value);

node_t* append(node_t** head, int value);

node_t* find(node_t* head, int target);

void delete_node(node_t** head, int target);


#endif /* end of include guard: LINKEDLIST_H */
