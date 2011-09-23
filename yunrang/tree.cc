#include <iostream>
#include <sstream>
#include <stack>
#include <iterator>
#include <cmath>
#include "tree.h"

using namespace std;

Tree init(Tree t)
{
    char c;
    Tree t1 = NULL;
    cin >> c;
    if('0' == c)
    {
        t = NULL;
    }
    else
    {
        t = (Tree)malloc(sizeof(struct Node));
        if(NULL == t)
        {
            cerr << "Heap overflow";
            exit(-1);
        }
        t->data = c;
        t->left = NULL;
        t->right = NULL;
        t->left = init(t1);
        t->right = init(t1); 
    }
    return t;
}
void PreOrder(Tree t)
{
    if(NULL == t)
        return;
    else
    {
        cout << t->data << endl;
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void dfs(Tree t)
{
    stack<Tree> s;
    Tree tmp;
    if(NULL == t)
        return;
    s.push(t);
    while(!s.empty())
    {
        tmp = s.top();
        cout << tmp->data << endl;
        s.pop();
        if(NULL != tmp->right)
            s.push(tmp->right);
        if(NULL != tmp->left)
            s.push(tmp->left);
    }
}

bool findPath(Tree t, char p, vector<Tree>& path)
{
    if(NULL == t)
        return false;
    if(p == t->data)
    {
        return true;
    }
    else
    {
        if(findPath(t->left, p, path))
        {
            path.push_back(t);
            return true;
        }
        if(findPath(t->right, p, path))
        {
            path.push_back(t);
            return true;
        }
    }
    return false;
}
void printPath(vector<Tree>& v)
{
    cout << "path:" << endl;
    vector<Tree>::iterator i = v.begin();
    while(i != v.end())
        cout << (*i++)->data << endl;
    cout << "------------------" << endl;
}
Tree findFatherofTwoNode(Tree t, char a, char b)
{
    if(NULL == t)
        return NULL;
    vector<Tree> path1, path2;
    findPath(t, a, path1);
    printPath(path1);
    findPath(t, b, path2);
    printPath(path2);

    int len1 = path1.size();
    int len2 = path2.size();

    int min = len1 > len2 ? len1 : len2;
    for(size_t i = len1 - min, j = len2 - min; i < len1 && j < len2; ++i, ++j)
    {
        if(path1[i] == path2[j])
            return path1[i];
    }
    return t;
}
