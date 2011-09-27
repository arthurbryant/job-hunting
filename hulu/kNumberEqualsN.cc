#include <iostream>
#include <list>

using namespace std;

std::list<int> l; // 存放中间结果
void PrintSolution(); //打印结果

int NKSolution(int n, int k, int max)
{
    if (k > n) return 0;

    if (k == 1)
    {
        if(n > max)
            return 0;
        // found solution, print it
        else
        {
            l.push_back(n);
            PrintSolution();
            l.pop_back();
            return 1;
        }
    }

    int count = 0;
    for(int i = 1; n-k*i >= 0 && i <= max; i++)
    {
        cout << i << "<=" << max << endl;
        l.push_back(i);
        count += NKSolution(n-i-(k-1)*(i-1), k-1, max-(i-1));
        l.pop_back();
    }

    return count;
}

void PrintSolution()
{
    std::list<int>::iterator it = l.begin();
    int previous = 1;
    while(it != l.end())
    {
        previous = *it + previous - 1;
        cout << previous << "  ";
        it++;
    }
    cout << endl;
    return;
}

int main()
{
    int result;
    int n, k, m;
    //cin >> n >> k >> m;
    //cout << n << k << m << endl;
    //result = NKSolution(n, k, m);
    result = NKSolution(6, 2, 4);
    cout << result << endl;

    return 0;
}
