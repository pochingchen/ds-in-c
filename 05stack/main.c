#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* init() {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = 0;
    new_node->next = NULL;
    return new_node;
}

int is_empty(Node* s) {
    return !s->next;
}

int top(Node* s) {
    if (is_empty(s)) {
        return -1;
    } else {
        return s->next->data;
    }
}

int pop(Node *s) {
    Node *pos = s->next;
    if (pos) {
        int elem = s->data;
        s->next = pos->next;
        free(pos);
        s->data--;
        return elem;
    }

    return -1;
}

void push(Node *s, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = s->next;
    s->next = new_node;

    s->data++;
}

void print_stack(Node *s) {
    Node* pos = s->next;
    while (pos) {
        printf("%d ", pos->data);
        pos = pos->next;
    }
    printf("\n");
}


int main() {
    Node* s = init();
    printf("top: %d\n", top(s));
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    printf("top: %d\n", top(s));
    print_stack(s);
    int res = pop(s);
    printf("pop: %d\n", res);
    res = pop(s);
    printf("pop: %d\n", res);
    res = pop(s);
    printf("pop: %d\n", res);
    res = pop(s);
    printf("pop: %d\n", res);
    print_stack(s);
    return 0;
}
