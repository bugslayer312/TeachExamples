#include "BinaryTree.h"

#include <cstdlib>
#include <iostream>

/*struct TreeNode* RecursiveTree(struct TreeNode* root, struct TreeNode* r, char data)
{
    if(!r)
    {
        r = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        r->Left = NULL;
        r->Right = NULL;
        r->NodeData = data;
        if(!root)
        {
            return r;
        }
        if(data < root->NodeData)
        {
            root->Left = r;
        }
        else
        {
            root->Right = r;
        }
        return r;
    }
    if(data < r->NodeData)
    {
        RecursiveTree(r, r->Left, data);
    }
    else
    {
        RecursiveTree(r, r->Right, data);
    }
    return root; 
}

struct TreeNode* InsertData(struct TreeNode* root, char data)
{
    return RecursiveTree(root, root, data);
}

struct TreeNode* CreateTree(char data)
{
    return RecursiveTree(NULL, NULL, data);
}

struct TreeNode* InsertData(struct TreeNode* root, char data)
{
    return RecursiveTree(root, root, data);
} */

struct TreeNode* CreateTree(char data)
{
    return InsertData(NULL, data);
}

void DestroyTree(struct TreeNode* node)
{
    if (node)
    {
        DestroyTree(node->Left);
        DestroyTree(node->Right);
        free(node);
    }
}

struct TreeNode* InsertData(struct TreeNode* node, char data)
{
    if (!node)
    {
        node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        node->Left = NULL;
        node->Right = NULL;
        node->NodeData = data;
        return node;
    }
    if (data < node->NodeData)
    {
        node->Left = InsertData(node->Left, data);
    }
    else
    {
        node->Right = InsertData(node->Right, data);
    }
    return node;
}

struct TreeNode* RemoveData(struct TreeNode* node, char data)
{
    if (!node)
    {
        return NULL;
    }
    if (data < node->NodeData)
    {
        node->Left = RemoveData(node->Left, data);
    }
    else if (data > node->NodeData)
    {
        node->Right = RemoveData(node->Right, data);
    }
    else
    {
        struct TreeNode* left = node->Left;
        struct TreeNode* right = node->Right;
        free(node);
        if (left)
        {
            node = left;
        }
        else
        {
            node = right;
        }
    }
    return node;
}

struct TreeNode* Find(struct TreeNode* root, char data)
{
    if (!root || data == root->NodeData)
    {
        return root;
    }
    
    if (data < root->NodeData)
    {
        return Find(root->Left, data);
    }
    else
    {
        return Find(root->Right, data);
    }
}

struct TreeNode* Minimum(struct TreeNode* root)
{
    if (!root->Left)
    {
        return root;
    }
    return Minimum(root->Left);
}

struct TreeNode* Maximum(struct TreeNode* root)
{
    if (!root->Right)
    {
        return root;
    }
    return Maximum(root->Right);
}

void PrintInorder(struct TreeNode* root)
{
    if (root)
    {
        PrintInorder(root->Left);
        std::cout << root->NodeData << ' ';
        PrintInorder(root->Right);
    }
}

void PrintPreorder(struct TreeNode* root)
{
    if (root)
    {
        std::cout << root->NodeData << ' ';
        PrintInorder(root->Left);
        PrintInorder(root->Right);
    }
}

void PrintPostorder(struct TreeNode* root)
{
    if (root)
    {
        PrintInorder(root->Left);
        PrintInorder(root->Right);
        std::cout << root->NodeData << ' ';
    }
}