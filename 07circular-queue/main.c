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

void enqueue(Node *q, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node* pos = q;
    while(pos->next && pos->next != q) {
        pos = pos->next;
    }

    pos->next = new_node;
    new_node->next = q;

    q->data++;
}

int dequeue(Node *q) {
    if (q->next) {
        Node* temp = q->next;
        int data = temp->data;

        q->next = temp->next;
        free(temp);
        q->data--;
        return data;
    }

    return -1;
}

void print_queue(Node *q) {
    printf("queue: ");
    Node* pos = q->next;
    while (pos && pos != q) {
        printf("%d ", pos->data);
        pos = pos->next;
    }
    printf("\n");
}


int main() {
    Node* q = init();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    print_queue(q);
    int res = dequeue(q);
    printf("%d\n", res);
    res = dequeue(q);
    printf("%d\n", res);
    res = dequeue(q);
    printf("%d\n", res);
    print_queue(q);
    return 0;
}

