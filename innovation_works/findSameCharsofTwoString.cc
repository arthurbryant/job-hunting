#include <iostream>
#include <string>
#include <map>

using namespace std;

void switchString(string& s1, string& s2) 
{
        string tmp;
        if(s1.size() > s2.size())
        {   
            tmp = s1; 
            s1 = s2; 
            s2 = tmp;
        }
        cout << s1 << endl;
}

void printMap(map<char, int> m)
{
    map<char , int>::iterator iter = m.begin();
    while(iter != m.end())
    {
        cout << iter->first;
        ++iter;
    }
    cout << endl;
}

int findSameCharsofTwoString(string str1, string str2)
{
    int i = 0;
    int count = 0;
    char c;
    map<char, int> m1;

    switchString(str1, str2);

    for(string::size_type ix = 0; ix < str1.size(); ++ix)
    {
        if(m1.find(c) != m1.end())
            break;
        else
            m1.insert(make_pair(str1[ix], 0));
    }
    printMap(m1);
    map<char, int>::iterator iter;
    for(string::size_type ix = 0; ix < str2.size(); ++ix)
    {
        iter = m1.find(str2[ix]);
        if(iter != m1.end())
        {
            if(iter->second == 0)
            {
                iter->second = 1;
                ++count;
            }
        }
    }

    return count;
}


int main()
{
    string s1 = "ahellot, world";
    string s2 = "whatol";
    int count;
    count = findSameCharsofTwoString(s1, s2);
    cout << count << endl;
    

    return 0;
}
