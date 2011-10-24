#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char * findLongestRepeatSub(char * str)
{
    if(str == NULL) return NULL;
    int len = strlen(str);
    char *strp[len];
    int i;
    for(i = 0; i < len; ++i)
    {
        strp[i] = str + i;
    }
    for(i = 0; i < len; ++i)
        cout << strp[i] << endl;
}
int main()
{
    char str[] = "Ask not what your country can do for you; ask what you can do for your country";
    findLongestRepeatSub(str);

    return 0;
}
