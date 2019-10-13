#include <iostream>
#include <queue>
#include "graphs_1.h"

using namespace std;

// given a binary tree, print its nodes in level-order manner
void traverseLevelOrder(struct TreeNode *node)
{
    // find out the height of the tree
    int h = height(node);
    for (int i = 1; i <= h; i++)
        traverseGivenLevel(node, i);
}

// given a binary tree, traverse given level of depth
void traverseGivenLevel(struct TreeNode *node, int depth)
{
    if (node == nullptr)
        return;
    
    if (depth == 1)
        cout << node->data << " ";
    else if (depth > 1)
    {
        traverseGivenLevel(node->left, depth-1);
        traverseGivenLevel(node->right, depth-1);
    }
}

// calc height of a tree
int height(struct TreeNode *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        // compute height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // find max
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

// given a binary tree, print its nodes in-order manner
void traverseInOrder(struct TreeNode *node)
{
    // check if node is a leaf
    if (node == nullptr)
        return;

    // traverse left
    traverseInOrder(node->left);

    cout << node->data << " ";

    // traverse right
    traverseInOrder(node->right);
}

// given a binary tree, print its nodes in preorder manner
void traversePostOrder(struct TreeNode *node)
{
    // check if node is a leaf
    if (node == nullptr)
        return;

    // traverse left
    traversePostOrder(node->left);

    // traverse right
    traversePostOrder(node->right);

    cout << node->data << " ";
}

// given a binary tree, print its nodes in preorder manner
void traversePreorder(struct TreeNode *node)
{
    // check if node is a leaf (no branches)
    if (node == nullptr)
        return;
    
    // print data
    cout << node->data << " ";

    // traverse left
    traversePreorder(node->left);

    // traverse right
    traversePreorder(node->right);
}

// insert a node with specific data when a node has an unused branch
void insert(struct TreeNode *node, int data)
{
    queue<struct TreeNode *> q;
    q.push(node);

    // do (alternative) level-order traversal (BFS)
    while (!q.empty())
    {
        // create a temp equal to first in the queue
        struct TreeNode *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = new TreeNode(data);
            break;
        } else
            q.push(temp->left);

        if (!temp->right)
        {
            temp->right = new TreeNode(data);
            break;
        } else
            q.push(temp->right);
    }
}

void wrapper_tree_preorder_traversal() 
{
    struct TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->left->left = new TreeNode(6);
    root->left->left->left->left = new TreeNode(7);
    root->left->left->left->right = new TreeNode(8);

    // print its nodes in preorder traversal
    cout << "Traversing Pre-order (DFS)" << endl;
    traversePreorder(root);

    cout << "\nTraversing Post-order (DFS)" << endl;
    traversePostOrder(root);

    cout << "\nTraversing In-order (DFS)" << endl;
    traverseInOrder(root);

    // print its nodes in bfs
    cout << "\nTraversing Level-order (BFS)" << endl;
    traverseLevelOrder(root);

    cout << endl;
}

void wrapper_tree_insertion(){
    struct TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->left->left = new TreeNode(6);
    root->left->left->left->left = new TreeNode(7);

    /* it used to be this branch, but now we insert it
       root->left->left->left->right = new TreeNode(8); */
    
    // traverse before
    cout << "before insertion: " << endl;
    traverseLevelOrder(root);

    insert(root, 8);
    insert(root, 9);

    // traverse after
    cout << "\nafter insertion: " << endl;
    traverseLevelOrder(root);

    cout << endl;
}