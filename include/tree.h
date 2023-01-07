#ifndef __TREE_H__
#define __TREE_H__

#include "point.h"
#include <vector>
#include <string>

class Node{
    public:
    std::string name;
    int level;  
    std::vector<Node *> children;
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