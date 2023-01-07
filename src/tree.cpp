#include "../include/tree.h"


Tree::Tree(tPoint origin, Node * root)
{
    this->origin = origin;
    this->root = root;
}

void Tree::set_origin(tPoint origin)
{
    this->origin = origin;
}

Node * Tree::get_node(Node * node, const int level, const int sibling, bool isthesibling)
{
    if(node == nullptr)
        return nullptr;
    else if(node->level == level && isthesibling)
        return node;
    else if(!node->children.empty())
    {
        Node * ret = nullptr;
        Node * result;
        for(int i = 0; i < node->children.size(); i++)
        { 
            result = get_node(node->children[i], level, sibling,i == sibling);
            if(result != nullptr)
                ret = result;
        }
        return ret;
    }else{
        return nullptr;
    }
}