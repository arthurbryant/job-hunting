#include <iostream>

using namespace std;

typedef int (*fun)(int);

int solution3_f1(int i);
int solution3_f2(int i);
fun f[2]={solution3_f1, solution3_f2};

int solution3_f1(int i) 
{
        return 0;
}

int solution3_f2(int i)
{
        return i+f[!!i](i-1);
}

int main()
{
    int n;
    cin >> n;
    cout << solution3_f2(n) << endl;

    return 0;
}
