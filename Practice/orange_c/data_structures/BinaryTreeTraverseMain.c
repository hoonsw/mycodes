#include <stdio.h>
#include "BinaryTree.h"
#include "BinaryTree.c"

void Inorder(BTreeNode* bt)
{
    if(bt==NULL)
        return;
    
    Inorder(bt->left);
    printf("%d \n",bt->data);
    Inorder(bt->right);
}

void Preorder(BTreeNode* bt)
{
    if(bt==NULL)
        return;
    
    printf("%d \n",bt->data);
    Preorder(bt->left);
    Preorder(bt->right);
}

void Postorder(BTreeNode* bt)
{
    if(bt==NULL)
        return;
    
    Postorder(bt->left);
    Postorder(bt->right);
    printf("%d \n",bt->data);
}

int main(void)
{
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();
    BTreeNode* bt5 = MakeBTreeNode();
    BTreeNode* bt6 = MakeBTreeNode();
    BTreeNode* bt7 = MakeBTreeNode();
    BTreeNode* bt8 = MakeBTreeNode();
    BTreeNode* bt9 = MakeBTreeNode();
    BTreeNode* bt10 = MakeBTreeNode();


    SetData(bt1,1);
    SetData(bt2,2);
    SetData(bt3,3);
    SetData(bt4,4);
    SetData(bt5,5);
    SetData(bt6,6);
    SetData(bt7,7);
    SetData(bt8,8);
    SetData(bt9,9);
    SetData(bt10,0);


    MakeLeftSubTree(bt1,bt2);
    MakeRightSubTree(bt1,bt3);
    MakeLeftSubTree(bt2,bt4);
    MakeRightSubTree(bt2,bt5);
    MakeLeftSubTree(bt4,bt7);
    MakeRightSubTree(bt5,bt8);
    MakeRightSubTree(bt3,bt6);
    MakeLeftSubTree(bt6,bt9);
    MakeRightSubTree(bt9,bt10);

    Inorder(bt1);
    printf("\n");
    Preorder(bt1);
    printf("\n");
    Postorder(bt1);
    
    return 0;
}