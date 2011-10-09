#include <iostream>

using namespace std;

int splitNintoKNumber(int n, int k, int max)
{
		int counter = 0;
		int min, i;
		min = (n+k-1)/k;
		if(k == 1 || k == n)
				return 1;
		else
		{
				for(i = min; i <= n-k+1 && i <= max; ++i)
				{
						cout << "split(" << n-i<<", " << k-1 << ", " << i << ")" << endl;
						counter += splitNintoKNumber(n-i, k-1, i);
				}
		}
		return counter;
}

int main()
{
		int n, k, result;
		cin >> n >> k;
		cout << n << "\t" << k << endl;
	result = splitNintoKNumber(n, k, n);
	cout << result << endl;

    return 0;
}
