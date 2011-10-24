#include <iostream>
#include <cstdio>

#define MAX 256 

using namespace std;

int compstr(string s1, string s2)
{
    int i = 0;
    while(s1[i] == s2[i]) ++i;
    
    return i;
}
void findLongest()
{
    char str[256][1024];
    int i = 0, j;
    while(gets(str[i++]));
    int len = i;
    for(i = 0; i < len; ++i)
       cout << str[i] << endl; 
    int maxi, maxlen = 0, maxl;
    for(i = 0; i < len-1; ++i)
    {
        maxl = compstr(str[i], str[i+1]);
        if(maxl > maxlen)
        {
            maxlen = maxl;
            maxi = i;
        }
    }
    for(j = 0; j < maxlen; ++j)
        cout << str[maxi][j];
    cout << endl;
}
int main()
{
    findLongest();

    return 0;
}
