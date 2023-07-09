#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev, *next;
}Node;

Node* init() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

void head_insert(Node *list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;

    if (!list->next) {
        new_node->prev = list;
        new_node->next = NULL;
        list->next = new_node;
    } else {
        new_node->next = list->next;
        new_node->prev = list;

        list->next->prev = new_node;
        list->next = new_node;
    }

    list->data++;
}

void tail_insert(Node* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node* pos = list->next;
    while(pos->next) {
        pos = pos->next;
    }

    pos->next = new_node;
    new_node->prev = pos;

    list->data++;
}

void delete_elem(Node* list, int data) {
    Node* pos = list->next;
    while(pos) {
        if (pos->data == data) {
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;
            free(pos);
        }
        pos = pos->next;
    }

    list->data--;
}

void print_list(Node *list) {
    Node* pos = list->next;
    while(pos) {
        printf("%d->", pos->data);
        pos = pos->next;
    }
    printf("NULL\n");
}

void reverse_print(Node *list) {
    Node* pos = list;
    while(pos->next) {
        pos = pos->next;
    }

    while(pos->prev) {
        printf("%d->", pos->data);
        pos = pos->prev;
    }
    printf("NULL\n");
}


int main() {
    Node* list = init();
    head_insert(list,1);
    head_insert(list,2);
    head_insert(list,3);
    head_insert(list,3);
    head_insert(list,4);
    head_insert(list,5);
    tail_insert(list,6);
    tail_insert(list,7);
    tail_insert(list,8);
    tail_insert(list,9);
    print_list(list);
    reverse_print(list);
    delete_elem(list, 3);
    print_list(list);
    reverse_print(list);
    return 0;
}
