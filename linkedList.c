#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

void insertNode(struct node **root, int value);
void printList(struct node *);
void reverseList(struct node **, struct node *, struct node *);

int main(void) {
    int i;

    struct node *root = NULL;

    for (i = 5; i >= 0; --i)
        insertNode(&root, i);

    printList(root);
    reverseList(&root, NULL, root);
    printList(root);
}

void insertNode(struct node **root, int value) {
    struct node *temp = malloc(sizeof(struct node));

    temp->value = value;
    temp->next = *root;
    *root = temp;
}

void printList(struct node *current) {
    for (; current; current = current->next)
        printf("%d\n", current->value);
}

void reverseList(struct node **root, struct node *prev, struct node *current) {
    if (current->next)
        reverseList(root, current, current->next);
    else
        *root = current;
    current->next = prev;
}
