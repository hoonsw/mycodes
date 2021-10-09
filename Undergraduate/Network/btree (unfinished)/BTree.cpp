#include <iostream>
#include <fstream>
#include "BTree.h"

using namespace std;

NodeType BTreeNode::getNodeType()
{
    return this->type;
}

BTreeNode::BTreeNode()
{
    type=ROOT;
    level=0;
}

BTreeInternalNode::BTreeInternalNode()
{
    type=INTERNAL;
    
}

BTreeLeafNode::BTreeLeafNode()
{
    type=LEAF;
}

void BTreeLeafNode::printLeafNode()
{
    for(int i=0;i<NUM_KEYS;i++)
        cout<<keys[i]<<"$";
}

BTree::BTree()
{
 
}

void BTree::insert(long long value)
{
    int i=0;
    if(root->getNodeType()==ROOT)
    {
        BTreeLeafNode* leafroot;
        for(i=0;i<NUM_KEYS;i++)
            if(leafroot->keygetter(i)==NULL||i==NUM_KEYS)
            break;
        leafroot->keysetter(value,i);
        this->root=leafroot;
    }
    else if(root->getNodeType()==LEAF)
    {

    }

}

void BTree::printLeafNode(long long value)
{
// find the leaf node that contains 'value' and print all values in the leaf no$
}

void BTree::pointQuery(long long value)
{
// print the found value or "NOT FOUND" if there is no value in the index
    int i;
    for(i=0;i<root->getlevel();i++)
    {
        if(root->getNodeType()==ROOT)
        {
            pointQuery()
        }
    }
}

void BTree::rangeQuery(long long low, long long high)
{
// print all found keys (low <= keys < high), separated by comma (e.g., 10, 11, 13, 15\n)

}

