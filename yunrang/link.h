#ifndef LINKLIST
#define LINKLIST

typedef int ElementType;
typedef struct node* Position;
typedef Position List;

struct node 
{
    ElementType data;
    Position next;
};

extern void insert(List head, ElementType x);
extern void createList(ElementType arr[], int len, List head);
extern List init();
extern void display(List);

#endif
