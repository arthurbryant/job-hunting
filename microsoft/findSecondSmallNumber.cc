#include <iostream>

using namespace std;

int findSecondSmall(int arr[], int len)
{
    assert(arr != NULL);
    if(len < 2)
    {
        perror("at least two elements");
        exit(-1);
    }
    int small[2];
    if(arr[0] < arr)
}
int main()
{
    int arr[] = {31, 45, 20, 421, 9, 19, 23};
    int len = sizeof(arr) / sizeof(int);
    int res;
    res = findSecondSmall(arr, len);
    cout << res << endl;

    return 0;
}
