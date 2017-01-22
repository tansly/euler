#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    long data;
    struct node* next;
};

struct node* mklist(long data);

void rmnode(struct node** head_ref, int index);

void rmlist(struct node** head_ref);

void push(struct node** head_ref, long data);

int listlen(struct node* head);

void printlist(struct node* head);

struct node* slicelist(struct node* head, int index);

void insertnode(struct node** head_ref, int index, long data);

void sortlist(struct node** head_ref);

void insert_sorted(struct node** head_ref, long data);

void isort(struct node** head_ref);

void recursive_reverse(struct node** head_ref);

void swap_nodes(struct node *head, int a, int b);

int narayana(struct node *head);
