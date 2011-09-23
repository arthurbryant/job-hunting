#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/*
 *  Reverse: 1->2->3->4->5 ====> 2->1->4->3->5  
 */
Position reverseLink(List str)
{
    if(NULL == str)
        return NULL;
    Position p = str;
    Position q = p->next;
    if(NULL == q)
        return p;
    else
    {
        Position next = q->next;
        q->next = p;
        p->next = reverseLink(next);
    }

    return q;
}

int main()
{
    int str[] = {1, 2, 3, 4, 5};
    int len = sizeof(str) / sizeof(int);
    List head = init();
    createList(str, len, head);
    display(head);
    head->next = reverseLink(head->next);
    /*
    if(l != NULL)
        printf("%d\n", l->data);
        */
    display(head);

    return 0;
}
