struct node {
    long data;
    struct node* next;
};

struct node* mklist(void);

void rmnode(struct node** head_ref, int index);

void rmlist(struct node** head_ref);

void push(struct node** head_ref, long data);

int listlen(struct node* head);

void printlist(struct node* head);

struct node* slicelist(struct node* head, int index);

void insertnode(struct node** head_ref, int index, long data);

void bsort(struct node** head_ref);

void insert_sorted(struct node** head_ref, long data);

void isort(struct node** head_ref);

void recursive_reverse(struct node** head_ref);

void swap_nodes(struct node *head, int a, int b);

int narayana(struct node *head);

struct node *shuffle_merge(struct node *list1, struct node *list2);

struct node *rec_shuffle_merge(struct node *list1, struct node *list2);

struct node *rec_sorted_merge(struct node *list1, struct node *list2);

struct node *sorted_merge(struct node *list1, struct node *list2);

void front_back_split(struct node *orig, struct node **front_ref, struct node **back_ref);

void merge_sort(struct node **head_ref);
