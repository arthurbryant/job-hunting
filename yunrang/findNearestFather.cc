#include <iostream>
#include <sstream>
#include <stack>
#include "tree.h"

using namespace std;


int main()
{
    streambuf * buf;
    string s = "1240003500600";
    stringstream stream(s);
    buf = cin.rdbuf();
    cin.rdbuf(stream.rdbuf());

    Tree root = NULL;
    root = init(root);
    PreOrder(root);
    cin.rdbuf(buf);
    //dfs(root);
    vector<Tree> v;
    Tree father;
    father = findFatherofTwoNode(root, '2', '6');
    cout << father->data << endl;

    return 0;
}

