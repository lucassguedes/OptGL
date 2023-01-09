#ifndef __TREE_H__
#define __TREE_H__

#include "point.h"
#include <vector>
#include <string>

class Node{
    public:
    char* name;
    int level;  
    std::vector<Node *> children;
    Node * father = nullptr;
    int n_descendants;

    Node(char* name, int level, std::vector<Node*> children);

    void add_child(Node * node);
};


class Tree{
    public:

    Node * root;
    tPoint origin;

    Tree(tPoint origin, Node * root);

    void set_origin(tPoint origin);
    Node * get_node(Node * node, const int level, const int sibling, bool isthesibling);
};



#endif 