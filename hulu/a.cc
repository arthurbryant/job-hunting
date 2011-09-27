#include <iostream>

using namespace std;

int kNumberEqualsN(int k, int n)
{
    if(k > n)
        return 0;
    if(k == 1)
        return 1;
    int max = n-k+1;
    int min = (n-k+1) / k;
    cout << "max=" << max << ", min=" << min << endl;
    int sum = 0;
    for(int i = max; i >= min; --i)
    {
        printf("(%d, %d)\n", k-1, n-i);
        sum = sum + kNumberEqualsN(k-1, n-i);
    }
    cout << "sum=" << sum << endl;
    return sum;
}

int main()
{
    int res;
    res = kNumberEqualsN(3, 5);
    cout << res << endl;

    return 0;
}
