#include <iostream>

// create a tree node using a struct
struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
    TreeNode(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

/* Breadth First Search (BFS) */

// given a binary tree, print its nodes in level-order manner
void traverseLevelOrder(struct TreeNode *node);

// given a binary tree, traverse given level of depth
void traverseGivenLevel(struct TreeNode *node, int depth);

// calc height of a tree
int height(struct TreeNode *node);

/* Depth First Search (DFS) */

// given a binary tree, print its nodes in-order manner
void traverseInOrder(struct TreeNode *node);

// given a binary tree, print its nodes in postorder manner
void traversePostOrder(struct TreeNode *node);

// given a binary tree, print its nodes in preorder mannerl
void traversePreorder(struct TreeNode *node);

/* Insertion */

// insert a node with specific data when a node has an unused branch
void insert(struct TreeNode *node, int data);

/* all test wrappers */

void wrapper_tree_preorder_traversal();
void wrapper_tree_insertion();