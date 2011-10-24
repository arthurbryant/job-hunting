#include <iostream>
#include <algorithm>

using namespace std;

void print(int i)
{
    cout << i << " ";
}
int main()
{
    const int max = 256;
    int arr[max];
    for(int i = 0; i < max; ++i)
        arr[i] = 0;
    arr['a'] = 2;
    arr['b'] = 2;
    for_each(arr, arr+sizeof(arr)/sizeof(int), print);

    return 0;
}
