#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

struct node* mklist(void)
{
    struct node* head;
    head = malloc(sizeof(struct node));
    if (!head) {
        fputs("mklist(): malloc fail\n", stderr);
        exit(1);
    }
    head -> next = NULL;
    return head;
}

void rmnode(struct node** head_ref, int index)
{
    int i;
    struct node* current = *head_ref;
    struct node* prev = NULL;
    /*  locate the node and the node before it  */
    for (i = 0; i < index && current != NULL; i++) {
        prev = current;
        current = current -> next;
    }
    /*  do the checks if a valid node is found, if found relink and free */
    if (i == 0 && current == NULL) {
        fprintf(stderr, "rmnode: LIST EMPTY\n");
    } else if (current == NULL) {
        fprintf(stderr, "rmnode: OUT OF RANGE\n");
    } else if (i == 0) {
        *head_ref = (*head_ref) -> next;
        free(current);
    } else {
        assert(prev != NULL);
        prev -> next = current -> next;
        free(current);
    }
}

void rmlist(struct node** head_ref)
{
    struct node* current;
    struct node* tmp;
    for (current = *head_ref; current != NULL;) {
        tmp = current;
        current = current -> next;
        free(tmp);
    }
    *head_ref = NULL;
}

/*  push a new node to the head of a list, if the list is NULL, create one */
void push(struct node** head_ref, long data)
{
    struct node* new;
    /*  check if we already have a list, we have to make a new one (mklist) if it does not exist */
    if (*head_ref == NULL) {
        *head_ref = mklist();
        (*head_ref) -> data = data;
    } else {
        new = malloc(sizeof(struct node));
        new -> data = data;
        new -> next = *head_ref;
        *head_ref = new;
    }
}

int listlen(struct node* head)
{
    int cnt;
    for (cnt = 0; head != NULL; head = head -> next) {
        cnt++;
    }
    return cnt;
}

void printlist(struct node* head)
{
    int col;
    printf("\nLIST:\n");
    for (col = 0; head != NULL; head = head -> next, col++) {
        if (col > 4) {
            printf("\n");
            col = 0;
        }
        printf("%ld ", head -> data);
    }
    printf("\nEND LIST\n");
}

/* locate a node in the list by index, return a pointer to it */
struct node* slicelist(struct node* head, int index)
{
    int i;
    struct node* current = head;
    /*  locate the node with the following loop */
    for (i = 0; i < index && current != NULL; i++) {
        current = current -> next;
    }
    /*  check if we have found a valid node */
    if (i == 0 && current == NULL) {
        fprintf(stderr, "slicelist: LIST EMPTY\n");
        return NULL;
    } else if (current == NULL) {
        fprintf(stderr, "slicelist: OUT OF RANGE\n");
        return NULL;
    } else {
        return current;
    }
}

void insertnode(struct node** head_ref, int index, long data)
{
    int i;
    struct node* current = *head_ref;
    struct node* prev = NULL;
    struct node new;
    /*  locate the node at index and the node before it */
    for (i = 0; i < index && current != NULL; i++) {
        prev = current;
        current = current -> next;
    }
    /*  check if we have found a valid node */
    if (i == 0 && current == NULL) {
        fprintf(stderr, "insertnode: LIST EMPTY\n");
    } else if (i == index && current == NULL) {
        /*  we have to append the element to the list (to the very end) */
        new.data = data;
        new.next = NULL;
        assert(prev != NULL);
        prev -> next = malloc(sizeof(struct node));
        memcpy(prev -> next, &new, sizeof(struct node));
    }
    else if (current == NULL) {
        fprintf(stderr, "insertnode: OUT OF RANGE\n");
    } else if (i == 0) {
        /*  insert operation at the head (call push()) */
        push(head_ref, data);
    } else {
        new.data = data;
        new.next = current;
        assert(prev != NULL);
        prev -> next = malloc(sizeof(struct node));
        memcpy(prev -> next, &new, sizeof(struct node));
    }
}

/*  bubble sort (increasing order) */
void bsort(struct node** head_ref)
{
    struct node* current;
    struct node* next;
    int not_sorted;
    long tmp;
    do {
        not_sorted = 0;
        for (current = *head_ref, next = current -> next; next != NULL; current = next, next = next -> next) {
            if (current -> data > next -> data) {
                not_sorted = 1;
                tmp = current -> data;
                current -> data = next -> data;
                next -> data = tmp;
            }
        }
    } while (not_sorted);
}

/*  insert a node before the first value greater than itself (increasing order) */
void insert_sorted(struct node** head_ref, long data)
{
    int i;
    struct node* current = *head_ref;
    /*  find the correct place */
    for (i = 0; data > current -> data; i++) {
        current = current -> next;
        if (current == NULL) {
            insertnode(head_ref, i + 1, data);
            return;
        }
    }
    insertnode(head_ref, i, data);
}

/*  recursive insertion sort (increasing order) */
void isort(struct node** head_ref)
{
    struct node* head;
    struct node* tail;
    long head_data;
    if ((head = *head_ref) == NULL) /*  empty list base case */
        return;
    if ((tail = head -> next) == NULL) /*  one element (empty tail) base case */
        return;
    isort(&tail);
    *head_ref = tail;
    head_data = head -> data;
    free(head);
    insert_sorted(head_ref, head_data);
}

void recursive_reverse(struct node** head_ref)
{
    struct node* head;
    struct node* tail;
    if (*head_ref == NULL) /*  empty list base case */
        return;
    head = *head_ref;
    tail = head -> next;
    if (tail == NULL) /*  one element (empty tail) base case */
        return;
    recursive_reverse(&tail);
    *head_ref = tail;
    head -> next -> next = head;
    head -> next = NULL;
}

/*  given indices, swap two elements */
void swap_nodes(struct node *head, int a, int b)
{
    long tmpdata;
    struct node *n1, *n2;
    if ( a > b ) {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    n1 = slicelist(head, a);
    n2 = slicelist(n1, b - a);
    tmpdata = n1 -> data;
    n1 -> data = n2 -> data;
    n2 -> data = tmpdata;
}

/*  GENERATING PERMUTATIONS
 *  Algorithm: Narayana Pandit
 *  Source: https://en.wikipedia.org/wiki/Permutation
 *  The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.
 *  1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
 *  2. Find the largest index i greater than k such that a[k] < a[i].
 *  3. Swap the value of a[k] with that of a[i].
 *  4. Reverse the sequence from a[k + 1] up to and including the final element a[n]. */
int narayana(struct node *head)
{
    struct node *curr, *node_k = NULL, *node_i = NULL;
    struct node *node_k_next = NULL; /*  will use for step 4 (reversing) */
    long tmp;
    /*  step 1 */
    for ( curr = head; curr -> next != NULL; curr = curr -> next) {
        if ( curr -> data < curr -> next -> data )
            node_k = curr;
    }
    if ( node_k == NULL ) /*  no such index exists, last permutation */
        return 0;
    /*  step 2 */
    for ( curr = head; curr != NULL; curr = curr -> next ) {
        if ( node_k -> data < curr -> data )
            node_i = curr;
    }
    /*  step 3 */
    tmp = node_k -> data;
    node_k -> data = node_i -> data;
    node_i -> data = tmp;
    /*  step 4 */
    node_k_next = node_k -> next;
    recursive_reverse(&node_k_next); /*  reversed from k+1 */
    node_k -> next = node_k_next; /*  fix the pointer of k */
    return 1;
}

struct node *shuffle_merge(struct node *list1, struct node *list2)
{
    struct node **tail_ref;
    struct node *new, *next1, *next2;
    tail_ref = &list1;
    new = list1;
    while (list1 != NULL && list2 != NULL) {
        next1 = list1->next;
        next2 = list2->next;
        tail_ref = &next1;
        list1->next = list2;
        list2->next = next1;
        list1 = next1;
        list2 = next2;
    }
    if (list1 == NULL && list2 != NULL) {
        *tail_ref = list2;
    }
    return new;
}

struct node *rec_shuffle_merge(struct node *list1, struct node *list2)
{
    if (list1 == NULL && list2 == NULL)
        return NULL;
    else if (list1 == NULL && list2 != NULL)
        return list2;
    else if (list1 != NULL && list2 == NULL)
        return list1;
    else {
        struct node *next1 = list1->next;
        struct node *next2 = list2->next;
        next1 = rec_shuffle_merge(next1, next2);
        list1->next = list2;
        list2->next = next1;
        return list1;
    }
}

struct node *rec_sorted_merge(struct node *list1, struct node *list2)
{
    if (list1 == NULL && list2 == NULL)
        return NULL;
    else if (list1 == NULL && list2 != NULL)
        return list2;
    else if (list1 != NULL && list2 == NULL)
        return list1;
    else {
        struct node *next1 = list1->next;
        struct node *next2 = list2->next;
        if (list1->data < list2->data) {
            next1 = rec_sorted_merge(next1, list2);
            list1->next = next1;
            return list1;
        } else {
            next2 = rec_sorted_merge(list1, next2);
            list2->next = next2;
            return list2;
        }
    }
}

struct node *sorted_merge(struct node *list1, struct node *list2)
{
    struct node **tail_ref;
    struct node *new, *next1, *next2;
    if (list1->data < list2->data) {
        new = list1;
        tail_ref = &(list1->next);
    } else {
        new = list2;
        tail_ref = &(list2->next);
    }
    while (list1 != NULL && list2 != NULL) {
        next1 = list1->next;
        next2 = list2->next;
        if (list1->data < list2->data) {
            *tail_ref = list1;
            tail_ref = &(list1->next);
            list1->next = list2;
            list1 = next1;
        } else {
            *tail_ref = list2;
            tail_ref = &(list2->next);
            list2->next = list1;
            list2 = next2;
        }
    }
    return new;
}

void front_back_split(struct node *orig, struct node **front_ref, struct node **back_ref)
{
    struct node *fast, *slow;
    fast = orig;
    slow = orig;
    *front_ref = orig;
    *back_ref = NULL;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != NULL && slow->next != NULL) {
        *back_ref = slow->next;
        slow->next = NULL;
    }
}

void merge_sort(struct node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        return;
    } else {
        struct node *front, *back;
        front_back_split(*head_ref, &front, &back);
        merge_sort(&front);
        merge_sort(&back);
        *head_ref = sorted_merge(front, back);
    }
}
