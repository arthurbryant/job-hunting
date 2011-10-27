#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char * cmpstr(char *s1, char *s2)
{
    if(s1 == NULL || s2 == NULL)
        return NULL;
    char *p, *q;
    while(*s1 != '\0')
    {
        p = s1;
        q = s2;
        while(*p != '\0' && *q != '\0')
        {
            if(*p == *q)
            {
                ++p; ++q;
            }
            else 
                break;
        }
        if(*q == '\0')
        {
            return s1;
        }
        else
        {
            ++s1;
        }
    }
    return NULL;
}
int main()
{
    char str1[] = "have nice a nice day";
    char str2[] = "nice";
    //char * s = strstr(str1, str2);
    char *s = cmpstr(str1, str2);
    printf("%s\n", s);

    return 0;
}
