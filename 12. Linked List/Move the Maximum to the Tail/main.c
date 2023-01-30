#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->val);
    }
    return 0;
}

void MoveToTail() {
    int max = head->val > head->next->val ? head->val : head->next->val;
    struct node *preNode = head, *max_preLocation = NULL;

    while (preNode->next->next != NULL) {
        preNode = preNode->next;
        if (preNode->next->val > max) {
            max = preNode->next->val;
            max_preLocation = preNode;
        }
    }
    if (max == head->val) {
        tail->next = head;
        tail = tail->next;
        head = head->next;
        return;
    }
    tail->next = max_preLocation->next;
    tail = tail->next;
    max_preLocation->next = max_preLocation->next->next;
}