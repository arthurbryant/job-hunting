#include <assert.h>
#include <stdio.h>
#include <string.h>

void findPost(char *pre, char *mid, int n)
{
    assert(pre != NULL && mid != NULL);

    if(*pre == '\0' || *mid == '\0')
        return;
    if(n <= 1)
    {
        printf("%c", *pre);
        return;
    }
    char *p = pre;
    char *m = mid;
    while(*m++ != *p);
    --m;
    ++p;
    int d = m-mid;
    if(d > 0 && d <= (n-1))
    {
        //printf("find(%c, %c, %d)\n", *p, *mid, d);
        findPost(p, mid, d);
    }
    //printf("n=%d, d=%d\n", n, d);
    if((d+1) < n)
    {
        //printf("find(%c, %c, %d)\n", *(p+d), *(m+1), n-d-1);
        findPost(p+d, m+1, n-d-1);
    }
    printf("%c", *pre);
}

int main()
{
    char *pre = "1243";
    char *mid = "4213";
    // The following line is wrong!!!! It only return the size of pointer under x64
    //int len = sizeof(pre) / sizeof(char);
    int len = strlen(pre);
    printf("len = %d\n", len);
    printf("find(%c, %c, %d)\n", *pre, *mid, len);
    // Should print 4231 
    findPost(pre, mid, len);
    printf("\n");
    char *p1 = "123";
    char *m1 = "321";
    // Should print 321
    findPost(p1, m1, 3);
    printf("\n");

    char *p2 = "123";
    char *m2 = "123";
    // Should print 321
    findPost(p2, m2, 3);
    printf("\n");

    char *p3 = "abdgcefh";
    char *m3 = "dgbaecfh";
    // Should print gdbehfca
    findPost(p3, m3, 8);
    printf("\n");

    return 0;
}
