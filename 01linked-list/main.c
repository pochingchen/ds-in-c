#include <stdio.h>
#include <stdlib.h>
// 顺序表：分配一块连续的内存存放元素
// 链表：内存不连续，元素各自被分配到一块内存，内存之间用指针相连

// 节点
typedef struct Node {
    int data;
    struct Node * next;
} Node, *pNode;

// 初始化
Node* init_list() {
    Node* head = (Node*) malloc(sizeof (Node));
    head->next = NULL;
    head->data = 0;

    return head;
}

// 头部插入
void head_insert(Node* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = list->next;
    list->next = new_node;

    list->data++;
}

// 尾部插入
void tail_insert(Node* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node* pos = list;
    while (pos->next) {
        pos = pos->next;
    }
    pos->next = new_node;

    list->data++;
}

// 删除第一个值为data的节点
void delete_elem(Node* list, int data) {
    Node* prev = list;
    Node* pos = list->next;
    while(pos) {
        if (pos->data == data) {
            prev->next = pos->next;
            free(pos);
            list->data--;
            return;
        }
        prev = prev->next;
        pos = pos->next;
    }
}

// 删除重复元素
void delete_multi_elem(Node* list, int data) {
    Node* prev = list;
    Node* current = list->next;
    while (current) {
        if (current->data == data) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
            list->data--;
            continue;
        }
        prev = prev->next;
        current = current->next;
    }
}

// 链表长度
int len(Node* list) {
    return list->data;
}

// 链表为空
int empty(Node* list) {
    return len(list) == 0 ? 0 : 1;
}

// 打印链表
void print_list(Node* list) {
    Node* pos = list->next;
    while (pos) {
        printf("%d ", pos->data);
        pos = pos->next;
    }
    printf(", len=%d", len(list));
    printf("\n");
}

int main() {
    Node* list = init_list();
    tail_insert(list,3);
    head_insert(list,1);
    tail_insert(list,3);
    head_insert(list,2);
    print_list(list);
    tail_insert(list,3);
    tail_insert(list,3);
    tail_insert(list,4);
    print_list(list);
    delete_multi_elem(list,3);
    print_list(list);
    delete_elem(list,1);
    print_list(list);

    return 0;
}
