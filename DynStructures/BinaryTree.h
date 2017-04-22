#pragma once

struct TreeNode
{
    char NodeData;
    struct TreeNode* Left;
    struct TreeNode* Right;
};

struct TreeNode* CreateTree(char data);
void DestroyTree(struct TreeNode* root);
struct TreeNode* InsertData(struct TreeNode* node, char data);
struct TreeNode* RemoveData(struct TreeNode* node, char data);
struct TreeNode* Find(struct TreeNode* root, char data);
struct TreeNode* Minimum(struct TreeNode* root);
struct TreeNode* Maximum(struct TreeNode* root);
void PrintInorder(struct TreeNode* root);
void PrintPreorder(struct TreeNode* root);
void PrintPostorder(struct TreeNode* root);