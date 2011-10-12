#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef multiset<int, greater<int> >  IntHeap;

///////////////////////////////////////////////////////////////////////
// find k least numbers in a vector
///////////////////////////////////////////////////////////////////////
void FindKLeastNumbers
(
	const vector<int>& data,               // a vector of data
	IntHeap& leastNumbers,                 // k least numbers, output
	unsigned int k                              
)
{
	leastNumbers.clear();

	if(k == 0 || data.size() < k)
		return;

	vector<int>::const_iterator iter = data.begin();
	for(; iter != data.end(); ++ iter)
	{
		// if less than k numbers was inserted into leastNumbers
		if((leastNumbers.size()) < k)
			leastNumbers.insert(*iter);

		// leastNumbers contains k numbers and it's full now
		else
		{
			// first number in leastNumbers is the greatest one
			IntHeap::iterator iterFirst = leastNumbers.begin();

			// if is less than the previous greatest number 
			if(*iter < *(leastNumbers.begin()))
			{
				// replace the previous greatest number
				leastNumbers.erase(iterFirst);
				leastNumbers.insert(*iter);
			}
		}
	}
}
void print(int i)
{
		cout << " " << i;
}
int main()
{
		int arr[] = {3, 1, 5, 8, 9, 2, 4, 6, 7};
		int len = sizeof(arr) / sizeof(int);
		vector<int> iv(arr, arr+len);
		IntHeap heap;
		int k;
		cin >> k;
		FindKLeastNumbers(iv, heap, k);
		//multiset<int, greater<int> >::iterator iter = heap.begin();
		for_each(heap.begin(), heap.end(), print);
		return 0;
}

