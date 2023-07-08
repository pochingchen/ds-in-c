#include <stdio.h>
#include <stdlib.h>

#define SUCCEED 1
#define FAILED 0

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* init() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 0;
    head->next = head;

    return head;
}

void head_insert(Node* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = list->next;
    list->next = new_node;
    list->data++;
}

void tail_insert(Node* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    Node* pos = list;
    while(pos->next != list) {
        pos = pos->next;
    }
    printf("pos: %d\n", pos->data);
    new_node->next = pos->next;
    pos->next = new_node;
    list->data++;
}

int delete(Node* list, int data) {
    Node* pos = list->next;
    Node* prev = list;
    while(pos->next != list) {
        if (pos->data == data) {
            prev->next = pos->next;
            free(pos);
            list->data--;
            return SUCCEED;
        }
        prev = prev->next;
        pos = pos->next;
    }

    return FAILED;
}

int len(Node* list) {
    return list->data;
}

void print_list(Node* list) {
    Node* pos = list->next;
    while (pos != list) {
        printf("%d ", pos->data);
        pos = pos->next;
    }
    printf("\n");
}

int main() {
    Node* list = init();
    head_insert(list,1);
    head_insert(list,2);
    head_insert(list,3);
    tail_insert(list,4);
    tail_insert(list,5);
    tail_insert(list,6);
    print_list(list);

    int res = delete(list,5);
    if (!res) {
        printf("failed to delete\n");
    }else{
        printf("delete succeeded\n");
    }
    print_list(list);
    res = delete(list,40);
    if (!res) {
        printf("failed to delete\n");
    }else{
        printf("ok\n");
    }
    return 0;
}
