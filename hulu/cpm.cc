#include <iostream>

#define MAX 20

using namespace std;

void printArray(int arr[], int n)
{
		for(int i = 0; i < n; ++i)
			cout << arr[i] << "\t";
		cout << endl;
}
int cpm()
{
		int n, max, min;
		int x, y, w;
		int i, j;
		int r[MAX][MAX];
		int eet[MAX], et[MAX]; 

		cin >> n;
		for(i = 0; i < n; ++i)
				for(j = 0; j < n; ++j)
						r[i][j] = -1;
		cin >> x >> y >> w;
		while(x != 0)
		{
				r[x-1][y-1] = w;
				cout << "(" << x-1 << "," << y-1 << ")=" << w << endl; 
				cin >> x >> y >> w;
		}
		eet[0] = 0;
		for(i = 1; i < n; ++i)
		{
				max = 0;
				for(j = 0; j < n; ++j)
				{
						if(r[j][i] != -1)
						{
							if(r[j][i] + eet[j] > max)
									max = r[j][i] + eet[j];
							eet[i] = max;
							cout << "eet[" << i << "]=" << max << endl;
						}
				}
//				cout << "eet[" << i << "]=" << eet[i] << endl;
		}
		printArray(eet, n);
		for(i = n-2; i >= 0; --i)
		{
				min = 10000;
				for(j = 0; j < n; ++j)
				{
						if(r[i][j] != -1)
							{
								if(eet[i+1] - r[j][i] < min)
										min = eet[i+1] - r[i][j];
								et[i] = min;
							}
				}
		}
		printArray(et, n-1);
		cout << eet[n-1] << "\t";

		cout << "path" << endl;
		for(i = 0; i < n-1; ++i)
				if(eet[i] == et[i])
						cout << i << "->";
		cout << n << endl;

}
int main()
{
		cpm();
    return 0;
}
