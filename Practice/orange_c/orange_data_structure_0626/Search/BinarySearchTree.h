#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData;

// BST의 생성 및 초기화
void BSTMakeAndNodeData(BTreeNode** pRoot);

//노드에 저장된 데이터 변환
BSTData BSTGetNodeData(BTreeNode* bst);

// BST 데이터 저장 (노드 생성도)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// BST 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

#endif