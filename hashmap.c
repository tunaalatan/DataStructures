#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME 100
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    char lesson[MAX_NAME];
    int age;
} student;

char* hash_table[TABLE_SIZE];

unsigned int hash(char* name){
    int len = strnlen(name, MAX_NAME);
    int hash_value = 0;

    for (int i = 0; i < len; i++) {
        hash_value += name[i];
        hash_value = hash_value % TABLE_SIZE;
    }

    return hash_value;
}

void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("%d\t---\n", i);
        }
        else {
            printf("%d\t%s\n", i, hash_table[i]);
        }
    }
}

bool insert(student* p, char* to_insert) {
    if (p == NULL) return false;

    int index = hash(p -> name);

    if (hash_table[index] == NULL) {
        hash_table[index] = to_insert;
    }
    else {
        return false;
    }
}

int main() {
    student tuna = {.name = "Tuna", .lesson = "Math", .age = 16};
    student batu = {.name = "Batu", .lesson = "Geo", .age = 16};
    student kerem = {.name = "Kerem", .lesson = "History", .age = 16};

    init_table();

    insert(&tuna, tuna.lesson);
    insert(&batu, batu.lesson);
    insert(&kerem, kerem.lesson);

    print_table();

    printf("\n%s\n", hash_table[hash(tuna.name)]);
}
