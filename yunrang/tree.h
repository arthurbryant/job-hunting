#ifndef TREE_H
#define TREE_H

#include <vector>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node * Tree;
typedef Tree Position;

Tree init(Tree t);
void PreOrder(Tree t);
bool findPath(Tree t, char p, std::vector<Tree>& path);
void printPath(std::vector<Tree>& v);
Tree findFatherofTwoNode(Tree t, char a, char b);

#endif
