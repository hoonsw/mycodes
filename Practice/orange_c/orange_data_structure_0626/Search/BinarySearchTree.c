#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

// BST의 생성 및 초기화
void BSTMakeAndNodeData(BTreeNode** pRoot)
{
    *pRoot = NULL;
}

//노드에 저장된 데이터 변환
BSTData BSTGetNodeData(BTreeNode* bst)
{
    return GetData(bst);
}

// BST 데이터 저장 (노드 생성도)
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
    BTreeNode* pNode = NULL; // parent node
    BTreeNode* cNode = *pRoot; // current node
    BTreeNode* nNode = NULL; // new node

    //새로운 노드 추가될 위치 찾기
    while(cNode!=NULL)
    {
        if(data==GetData(cNode))
            return;
        
        pNode = cNode;

        if(GetData(cNode)>data)
            cNode=GetLeftSubTree(cNode);
        else 
            cNode=GetRightSubTree(cNode);
    }

    //pnode의 자식 노드 생성
    nNode=MakeBTreeNode();
    SetData(nNode,data);

    if(pNode!=NULL)
    {
        if(data<GetData(pNode))
            MakeLeftSubTree(pNode,nNode);
        else 
            MakeRightSubTree(pNode,nNode);
    }
    else
    {
        *pRoot = nNode;
    }
}

// BST 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
    BTreeNode* cNode = bst;
    BSTData cd;

    while(cNode!=NULL)
    {
        cd=GetData(cNode);

        if(target==cd)
            return cNode;
        else if(target<cd)
            cNode=GetLeftSubTree(cNode);
        else 
            cNode=GetRightSubTree(cNode);
    }

    return NULL;
}