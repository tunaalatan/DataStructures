#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    node_t* head = NULL;

    append(&head, 35);
    append(&head, 10);
    append(&head, 8);
    append(&head, 5);
    append(&head, 7);

    delete_node(&head, 5);

    printlist(head);

    return 0;
}
