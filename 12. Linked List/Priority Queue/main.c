#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t * const queue, int value, int weight);
node_t *dequeue(prio_queue_t * const queue);
void print_nodes(const prio_queue_t * const queue);

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		}
		else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
        }
		print_nodes(&queue);
	}
	return 0;
}

void print_nodes(const prio_queue_t *const queue) {
	if (!queue->head) {
		printf("EMPTY\n");
		return;
	}
	for (node_t *node = queue->head; node; node = node->next) {
		printf(" -> %d", node->value);
    }
	printf("\n");
    return;
}

void enqueue(prio_queue_t *const queue, int value, int weight) {
    if (queue->head == NULL) { // linked list is empty
        node_t *head = malloc(sizeof(node_t));
        queue->head = head;
        head->weight = weight;
        head->value = value;
        head->next = NULL;
    } else if (queue->head->next == NULL) { // only one element in the linked list
        node_t *node = malloc(sizeof(node_t));
        node_t *temp = NULL;
        if (weight < queue->head->weight) {
            temp = queue->head;
            queue->head = node;
            queue->head->weight = weight;
            queue->head->value = value;
            queue->head->next = temp;
            return;
        } else {
            queue->head->next = node;
            node->weight = weight;
            node->value = value;
            node->next = NULL;
            return;
        }
    } else { // more than two elements in the linked list
        node_t *node = malloc(sizeof(node_t));
        node_t *temp = NULL;
        if (weight < queue->head->weight) { // weight is smallest -> become head
            temp = queue->head;
            queue->head = node;
            node->weight = weight;
            node->value = value;
            queue->head->next = temp;
            return;
        }
        node_t *curr = queue->head->next, *pre = queue->head;
        while (curr->next != NULL) {
            if (weight >= curr->weight) {
                pre = curr;
                curr = curr->next;
                continue;
            }
            temp = pre->next;
            pre->next = node;
            node->weight = weight;
            node->value = value;
            node->next = temp;
            return;
        }
        if (weight < curr->weight) { // become the pre of tail
            temp = pre->next;
            pre->next = node;
            node->weight = weight;
            node->value = value;
            node->next = temp;
            return;
        } else { // become the tail
            curr->next = node;
            node->weight = weight;
            node->value = value;
            node->next = NULL;
            return;
        }
    }
}

node_t *dequeue(prio_queue_t *const queue) {
    if (queue->head == NULL) {
        return NULL;
    } else {
        node_t *temp = NULL;
        temp = queue->head;
        queue->head = queue->head->next;
        return temp;
    }
}