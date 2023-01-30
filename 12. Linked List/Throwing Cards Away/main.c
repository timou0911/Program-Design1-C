#include<stdio.h>
#include<stdlib.h>

struct Card {
    int num;
    struct Card *next;
};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    struct Card *head = NULL, *tail = NULL;

    for (int i = 1 ; i <= n ; i++) {
        struct Card *card = malloc(sizeof(struct Card));
        card->num = i;
        card->next = NULL;
        if (i == 1) {
            head = card;
        } else {
            tail->next = card;
        }
        tail = card;
    }

    for (int j = 0 ; j < m ; j++) {
        printf("%d ", head->num);
        head = head->next;
        tail->next = head;
        tail = tail->next;
        head = head->next;
    }
}