#include <stdio.h>

struct node
{
    int a;
    short b;
    char c;
};

int main()
{
    printf("%d\n", sizeof(struct node));

    return 0;
}
