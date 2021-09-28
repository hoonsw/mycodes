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
    if(root->getNodeType==ROOT)
}

void BTree::insert(long long value)
{
    BTreeInternalNode rootinernal;
    

}

void BTree::printLeafNode(long long value)
{
// find the leaf node that contains 'value' and print all values in the leaf no$
}

void BTree::pointQuery(long long value)
{
// print the found value or "NOT FOUND" if there is no value in the index
}

void BTree::rangeQuery(long long low, long long high)
{
// print all found keys (low <= keys < high), separated by comma (e.g., 10, 11, 13, 15\n)

}
