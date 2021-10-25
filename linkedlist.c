#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} node_t;

void printlist(node_t* head){
    node_t* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp -> value);
        temp = temp -> next;
    }
}

node_t* node(int value){
    node_t* result = malloc(sizeof(node_t));
    result -> value = value;
    result -> next = NULL;
    return result;
}

node_t* add_to_head(node_t** head, int value){
    node_t* new_node = malloc(sizeof(node_t));
    new_node -> value = value;
    new_node -> next = NULL;

    new_node -> next = *head;
    *head = new_node;
    return new_node;
}

node_t* append(node_t** head, int value){
    node_t* new_node = node(value);

    if (*head == NULL) {
        *head = new_node;
    }
    else{
        node_t* lastNode = *head;

        while (lastNode -> next != NULL) {
            lastNode = lastNode -> next;
        }

        lastNode -> next = new_node;
    }
}

node_t* find(node_t* head, int target){
    node_t* temp = head;

    while (temp != NULL) {
        if (temp -> value == target) return temp;
        temp = temp -> next;
    }

    return NULL;
}

void delete_node(node_t** head, int target) {
    node_t* temp = *head;
    node_t* prev = NULL;

    if (&target == NULL) {
        return;
    }

    while (temp != NULL) {
        if (temp -> value == target) {
            prev -> next = temp -> next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp -> next;
    }

}
