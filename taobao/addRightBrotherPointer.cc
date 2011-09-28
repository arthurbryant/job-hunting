#include <iostream>
#include <queue>
#include "../../dataStruct/tree.h"

using namespace std;

void addRightBrotherPointer(Tree t)
{
    queue<Tree> q;
    if(NULL == t)
        return;
    q.push(t);
    while(!q.empty())
    {
        Tree tmp = q.front();
        q.push(NULL);
        while(tmp != NULL)
        {
            if(tmp->left != NULL)
                q.push(tmp->left);
            if(tmp->right!= NULL)
                q.push(tmp->right);
            tmp->next = q.front();
            tmp = q.front();
            q.pop();
        }
    }
}

void printTreeAsLevel(Tree t)
{
    if(t == NULL)
        return;
    while(t)
    {
        Tree s = t;
        while(s)
        {
            cout << s->data << endl;
            s = s->next;
        }
        t = t->left;
    }
}
int main()
{
    Tree t = NULL;
    t = createTree(t);
    addRightBrotherPointer(t);
    printTreeAsLevel(t);

    return 0;
}
