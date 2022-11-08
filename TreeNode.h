#include <iostream>

#ifndef TREENODE

#define TREENODE 1

using namespace std;

template <typename T>
class TreeNode
{
public:
    int *data;
    int poci;
    int n;
    T *content;
    bool leaf;

    TreeNode(int dato, T *pContent) // Node containing infomration about itself
    {
        this->content = content;
        this->poci = dato;
        this->content = pContent;
        this->n = 0;
        this->leaf = true;
    }

    void father()
    {
        this->leaf = false;
    }
};

#endif