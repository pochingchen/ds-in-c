#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
}Node;

Node* init() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->prev = head;
    head->next = head;
    head->data = 0;

    return head;
}

void head_insert(Node* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = data;

    if (!list->next) {
        // 链表为空
        list->next = new_node;
        list->prev = new_node;
        new_node->prev = list;
        new_node->next = list;
    } else {
        // 链表非空
        new_node->next = list->next;
        new_node->prev = list;
        list->next->prev = new_node;
        list->next = new_node;
    }

    list->data++;
}

void tail_insert(Node* list, int data) {
    Node* tail = list->prev;

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;

    new_node->prev = tail;
    new_node->next = list;
    tail->next = new_node;
    list->prev = new_node;

    list->data++;
}

void delete_elem(Node* list, int data) {
    Node* cur = list->next;
    while (cur != list) {
        if (cur->data == data) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
            return;
        }
        cur = cur->next;
    }

    list->data--;
}


void print_list(Node *list) {
    Node* pos = list->next;
    while(pos != list) {
        printf("%d->", pos->data);
        pos = pos->next;
    }
    printf("NULL\n");
}

void reverse_print(Node *list) {
    Node* pos = list->prev;

    while(pos != list) {
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
    print_list(list);
    reverse_print(list);
    tail_insert(list,4);
    tail_insert(list,4);
    tail_insert(list,5);
    tail_insert(list,6);
    print_list(list);
    reverse_print(list);
    delete_elem(list,4);
    print_list(list);
    reverse_print(list);
    return 0;
}
