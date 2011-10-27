#include <stdio.h>

struct node
{
    int a;
    short b;
    char c;
};
struct b
{
    int i;
    char c;
    int j;
    short d;
    char f;
};

int main()
{
    printf("%d\n", sizeof(struct node));
    printf("%d\n", sizeof(struct b));

    return 0;
}
