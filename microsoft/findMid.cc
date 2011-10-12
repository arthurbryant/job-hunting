#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int findMid(list<int> l)
{
    list<int>::iterator cur = l.begin(), mid = l.begin();
    while(cur++ != l.end())
    {
        if(cur != l.end())
        {
            ++cur;
            if(cur != l.end())
                ++mid;
        }
    }
    return *mid;
}

void print(int i)
{
    cout << i << " ";
}
int main()
{
    int arr[] = {2, 34, 1, 5,  9, 2, 2};
    list<int> l(arr, arr+sizeof(arr)/sizeof(int));
    for_each(l.begin(), l.end(), print);
    cout << endl;

    cout << findMid(l) << endl;

    return 0;
}
