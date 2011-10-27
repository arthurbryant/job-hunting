#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int LastRemaining_Solution2(int n, unsigned int m)
{
	// invalid input
	if(n <= 0 || m < 0)
		return -1;

	// if there are only one integer in the circle initially,
	// of course the last remaining one is 0
	int lastinteger = 0;

	// find the last remaining one in the circle with n integers
	for (int i = 2; i <= n; ++i)
		lastinteger = (lastinteger + m) % i;

	return lastinteger;
}
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
	// invalid input
	if(n < 1 || m < 1)
		return -1;

	unsigned int i = 0;

	// initiate a list with n integers (0, 1, ... n - 1)
	list<int> integers;
	for(i = 0; i < n; ++ i)
		integers.push_back(i);

	list<int>::iterator curinteger = integers.begin();
	while(integers.size() > 1)
	{
		// find the mth integer. Note that std::list is not a circle
		// so we should handle it manually
		for(int i = 1; i < m; ++ i)
		{
			curinteger ++;
			if(curinteger == integers.end())
				curinteger = integers.begin();
		}

		// remove the mth integer. Note that std::list is not a circle
		// so we should handle it manually
		list<int>::iterator nextinteger = ++ curinteger;
		if(nextinteger == integers.end())
			nextinteger = integers.begin();

		-- curinteger;
		integers.erase(curinteger);
		curinteger = nextinteger;
	}

	return *(curinteger);
}
int main()
{
    int n, m;

    cin >> n >> m;
    cout << LastRemaining_Solution2(n, m) << endl;
    cout << LastRemaining_Solution1(n, m) << endl;
    return 0;
}
