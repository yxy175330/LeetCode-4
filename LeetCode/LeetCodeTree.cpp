﻿#pragma once
#include <ctype.h>  /* is space */
#include <stdio.h>     /* printf */
#include <stdlib.h>  
#include <time.h>  
#include <functional>
#include <algorithm> 
#include <unordered_map> 
#include <unordered_set> 
#include <map> 
#include <numeric>
#include <stack>
#include <set>
#include <queue> 
#include <vector>
#include <iostream>
#include <fstream>
#include "Leetcode.h"
#include "LeetCodeTree.h"

#pragma region BinaryTree

/// <summary>
/// Free nodes
/// </summary>
void LeetCodeTree::freeNodes(Node* root)
{
    queue<Node*> search;
    search.push(root);
    while (!search.empty())
    {
        Node* node = search.front();
        search.pop();
        if (node == nullptr) break;
        for (auto child : node->children)
        {
            if (child == nullptr) search.push(child);
        }
        delete node;
    }
}

/// <summary>
/// Find a tree node with value
/// </summary>
TreeNode* LeetCodeTree::findTreeNode(TreeNode* root, int value)
{
    vector<TreeNode*> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeNode* node = stack.back();
        if (node->val == value) return node;
        stack.pop_back();

        if (node != NULL)
        {
            if (node->left != NULL)
            {
                stack.push_back(node->left);
            }
            if (node->right != NULL)
            {
                stack.push_back(node->right);
            }
        }
    }
    return nullptr;
}

/// <summary>
/// Free tree nodes
/// </summary>
void LeetCodeTree::freeTreeNodes(TreeNode* root)
{
    vector<TreeNode*> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeNode* node = stack.back();
        stack.pop_back();

        if (node != NULL)
        {
            if (node->left != NULL)
            {
                stack.push_back(node->left);
            }
            if (node->right != NULL)
            {
                stack.push_back(node->right);
            }

            delete node;
        }
    }
}

/// <summary>
/// Free link tree nodes
/// </summary>
void LeetCodeTree::freeLinkTreeNodes(TreeLinkNode* root)
{
    vector<TreeLinkNode*> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeLinkNode* node = stack.back();
        stack.pop_back();

        if (node != NULL)
        {
            if (node->left != NULL)
            {
                stack.push_back(node->left);
            }
            if (node->right != NULL)
            {
                stack.push_back(node->right);
            }

            delete node;
        }
    }
}

/// <summary>
/// Leet code 297. Serialize and Deserialize Binary Tree
/// Serialization is the process of converting a data structure or object 
/// into a sequence of bits so that it can be stored in a file or memory 
/// buffer, or transmitted across a network connection link to be 
/// reconstructed later in the same or another computer environment. 
///
/// Design an algorithm to serialize and deserialize a binary tree. There 
/// is no restriction on how your serialization/deserialization algorithm 
/// should work. You just need to ensure that a binary tree can be 
/// serialized to a string and this string can be deserialized to the 
/// original tree structure.
///
/// For example, you may serialize the following tree 
///    1
///   / \
///  2   3
///     / \
///    4   5
///
/// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes
/// a binary tree. 
/// You do not necessarily need to follow this format, so please be 
/// creative and come up with different approaches yourself. 
/// Note: Do not use class member/global/static variables to store states. 
/// Your serialize and deserialize algorithms should be stateless. 
/// </summary>
/// <summary>
/// Encodes a tree to a single string.
/// </summary>
/// <param name="root">the root</param>
/// <returns>The string</returns>
string LeetCodeTree::serialize(TreeNode* root)
{
    string result = "";
    queue<TreeNode *> queue;
    if (root != nullptr) queue.push(root);
    while (!queue.empty())
    {
        TreeNode * node = queue.front();
        queue.pop();
        if (!result.empty()) { result.push_back(','); }
        if (node == nullptr)
        {
            result.append("null");
        }
        else
        {
            result.append(std::to_string(node->val));
            queue.push(node->left);
            queue.push(node->right);
        }
    }
    while (true)
    {
        if ((result.size() > 4) && (result.substr(result.size() - 4) == "null"))
        {
            result.erase(result.size() - 4);
        }
        else if ((result.size() > 1) && (result.substr(result.size() - 1) == ","))
        {
            result.erase(result.size() - 1);
        }
        else
        {
            break;
        }
    }
    return "[" + result + "]";
}


/// <summary>
/// Encodes a linktree to a single string.
/// </summary>
/// <param name="root">the root</param>
/// <returns>The string</returns>
string LeetCodeTree::serializeLinkTree(TreeLinkNode* root)
{
    string result;
    queue<TreeLinkNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeLinkNode * node = queue.front();
        queue.pop();
        if (!result.empty()) { result.push_back(','); }
        if (node == nullptr)
        {
            result.append("null");
        }
        else
        {
            result.append(std::to_string(node->val));
            queue.push(node->left);
            queue.push(node->right);
        }
    }
    while (true)
    {
        if ((result.size() > 4) && (result.substr(result.size() - 4) == "null"))
        {
            result.erase(result.size() - 4);
        }
        else if ((result.size() > 1) && (result.substr(result.size() - 1) == ","))
        {
            result.erase(result.size() - 1);
        }
        else
        {
            break;
        }
    }
    return "[" + result + "]";
}

/// <summary>
/// Decodes your encoded data to tree.
/// </summary>
/// <param name="data">the string data</param>
/// <returns>The root</returns> 
TreeLinkNode* LeetCodeTree::deserializeLinkTree(string data)
{
    queue<TreeLinkNode *> input_queue;
    queue<TreeLinkNode *> output_queue;
    string number;
    for (size_t i = 0; i < data.size(); i++)
    {
        if ((data[i] == '[') || (data[i] == ',') || data[i] == ']' || isspace(data[i]))
        {
            if (number.size() != 0)
            {
                if (number == "null")
                {
                    input_queue.push(nullptr);
                }
                else
                {
                    input_queue.push(new TreeLinkNode(std::stoi(number)));
                }
                number.clear();
            }
        }
        else
        {
            number.push_back(data[i]);
        }
    }
    TreeLinkNode *root = nullptr;
    TreeLinkNode *node = nullptr;
    while (!input_queue.empty())
    {
        if (output_queue.empty())
        {
            root = input_queue.front();
            input_queue.pop();
            node = root;
            output_queue.push(node);
        }
        else
        {
            node = output_queue.front();
            output_queue.pop();
            if (node != nullptr)
            {
                if (!input_queue.empty())
                {
                    node->left = input_queue.front();
                    input_queue.pop();
                }
                if (!input_queue.empty())
                {
                    node->right = input_queue.front();
                    input_queue.pop();
                }
                output_queue.push(node->left);
                output_queue.push(node->right);
            }
        }
    }
    return root;
}

/// <summary>
/// Leet code #144. Binary Tree Preorder Traversal 
/// <summary>
void LeetCodeTree::preorderTraversal(TreeNode* root, vector<int>& output)
{
    if (root == nullptr) return;
    output.push_back(root->val);
    preorderTraversal(root->left, output);
    preorderTraversal(root->right, output);
}

/// <summary>
/// Leet code #144. Binary Tree Preorder Traversal 
/// Given a binary tree, return the preorder traversal of its nodes' values.
///
/// For example:
/// Given binary tree {1,#,2,3},
///   1
///    \
///     2
///    /
///   3
///  return [1,2,3]. 
///  Note: Recursive solution is trivial, could you do it iteratively?
/// <summary>
vector<int> LeetCodeTree::preorderTraversal(TreeNode* root)
{
    stack<TreeNode *> stack;
    vector<int> result;
    stack.push(root);
    while (!stack.empty())
    {
        TreeNode * node = stack.top();
        stack.pop();
        if (node != nullptr)
        {
            result.push_back(node->val);
            stack.push(node->right);
            stack.push(node->left);
        }
    }
    return result;
}

/// <summary>
/// Leet code #94. Binary Tree Inorder Traversal
/// 
/// Given a binary tree, return the inorder traversal of its nodes' values. 
/// For example: 
/// Given binary tree [1,null,2,3], 
/// 1
///  \
///   2
///  /
/// 3
/// return [1,3,2].
/// Note: Recursive solution is trivial, could you do it iteratively?
/// </summary>
std::vector<int> LeetCodeTree::inorderTraversal(TreeNode* root)
{
    std::vector<int> outputList;
    std::stack<TreeNode *> stack;
    TreeNode * iterator = root;

    while (true)
    {
        if (iterator != nullptr)
        {
            stack.push(iterator);
            iterator = iterator->left;
        }
        else
        {
            if (stack.empty())
            {
                break;
            }
            iterator = stack.top();
            stack.pop();
            outputList.push_back(iterator->val);
            iterator = iterator->right;
        }
    }
    return outputList;
}

/// <summary>
/// Generate tree based on id list.
/// </summary>
vector<TreeNode*> LeetCodeTree::generateTrees(vector<int>& id_list)
{
    vector<TreeNode*> result;
    if (id_list.size() == 0)
    {
        result.push_back(nullptr);
        return result;
    }
    if (id_list.size() == 1)
    {
        result.push_back(new TreeNode(id_list[0]));
        return result;
    }
    for (size_t i = 0; i < id_list.size(); i++)
    {
        vector<int> left;
        vector<int> right;
        for (size_t j = 0; j < i; j++)
        {
            left.push_back(id_list[j]);
        }
        for (size_t j = i + 1; j < id_list.size(); j++)
        {
            right.push_back(id_list[j]);
        }
        vector<TreeNode*> left_list = generateTrees(left);
        vector<TreeNode*> right_list = generateTrees(right);
        for (size_t l = 0; l < left_list.size(); l++)
        {
            for (size_t r = 0; r < right_list.size(); r++)
            {
                TreeNode* root = new TreeNode(id_list[i]);
                root->left = left_list[l];
                root->right = right_list[r];
                result.push_back(root);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #95. Unique Binary Search Trees II     
/// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.  
/// For example,
/// Given n = 3, there are a total of 5 unique BST's.
///   1         3     3      2      1
///    \       /     /      / \      \
///     3     2     1      1   3      2
///    /     /       \                 \
///   2     1         2                 3
/// </summary>
vector<TreeNode*> LeetCodeTree::generateTrees(int n)
{
    vector<TreeNode*> result;
    if (n > 0)
    {
        vector<int> id_list;
        for (int i = 0; i < n; i++)
        {
            id_list.push_back(i + 1);
        }
        result = generateTrees(id_list);
    }
    return result;
}

/// <summary>
/// Leet code #145. Binary Tree Postorder Traversal
/// 
/// Given a binary tree, return the postorder traversal of its nodes' values. 
/// For example: 
/// Given binary tree {1,#,2,3},
/// 1
///  \
///   2
///  /
/// 3
/// return [3,2,1]. 
/// Note: Recursive solution is trivial, could you do it iteratively?
vector<int> LeetCodeTree::postorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    std::stack<pair<int, TreeNode *>> node_stack;
    node_stack.push(make_pair(0, root));
    // When we start the stack is empty
    while (!node_stack.empty())
    {
        pair<int, TreeNode*> p = node_stack.top();
        node_stack.pop();
        if (p.second == nullptr) continue;
        if (p.first == 0)
        {
            node_stack.push(make_pair(1, p.second));
            node_stack.push(make_pair(0, p.second->right));
            node_stack.push(make_pair(0, p.second->left));
        }
        else
        {
            result.push_back(p.second->val);
        }
    }

    return result;
}

/// <summary>
/// Leet code #102. Binary Tree Level Order Traversal 
/// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
/// For example:
/// Given binary tree [3,9,20,null,null,15,7],
///    3
///   / \
///  9  20
///    /  \
///   15   7
/// return its level order traversal as:
/// [
///   [3],
///   [9,20],
///   [15,7]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::levelOrder(TreeNode* root)
{
    vector<int> level;
    vector<vector<int>> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            level.push_back(node->val);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        result.push_back(level);
    }
    return result;
}

/// <summary>
/// Leet code #103. Binary Tree Zigzag Level Order Traversal   
/// Given a binary tree, return the zigzag level order traversal of its nodes' values. 
/// (ie, from left to right, then right to left for the next level and alternate between).
///
/// For example:
/// Given binary tree [3,9,20,null,null,15,7],
///    3
///   / \
///  9  20
///    /  \
///   15   7
///
/// return its zigzag level order traversal as:
/// [
///   [3],
///   [20,9],
///   [15,7]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::zigzagLevelOrder(TreeNode* root)
{
    deque<int> level;
    vector<vector<int>> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    int index = 0;
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if (index % 2 == 0)
            {
                level.push_back(node->val);
            }
            else
            {
                level.push_front(node->val);
            }
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        vector<int> one_level;
        for (size_t i = 0; i < level.size(); i++)
        {
            one_level.push_back(level[i]);
        }
        result.push_back(one_level);
        index++;
    }
    return result;
}


/// <summary>
/// Leet code #107. Binary Tree Level Order Traversal II 
/// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
/// For example:
/// Given binary tree [3,9,20,null,null,15,7],
///    3
///   / \
///  9  20
///    /  \
///   15   7
/// return its bottom-up level order traversal as:
///	[
///   [15,7],
///   [9,20],
///   [3]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::levelOrderBottom(TreeNode* root)
{
    vector<int> level;
    stack<vector<int>> tree_stack;
    vector<vector<int>> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            level.push_back(node->val);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        tree_stack.push(level);
    }
    while (!tree_stack.empty())
    {
        result.push_back(tree_stack.top());
        tree_stack.pop();
    }
    return result;
}

/// <summary>
/// Leet code #111. Minimum Depth of Binary Tree 
/// Given a binary tree, find its minimum depth.
/// The minimum depth is the number of nodes along the shortest path from the 
/// root node down to the nearest leaf node.
/// </summary>
int LeetCodeTree::minDepth(TreeNode* root)
{
    int level = 0;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level++;;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if ((node->left == nullptr) && (node->right == nullptr))
            {
                return level;
            }
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return level;
}

/// <summary>
/// Leet code #104. Maximum Depth of Binary Tree 
/// Given a binary tree, find its maximum depth.
/// The maximum depth is the number of nodes along the longest path from the 
/// root node down to the farthest leaf node.
/// </summary>
int LeetCodeTree::maxDepth(TreeNode* root)
{
    int level = 0;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level++;;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return level;
}

/// <summary>
/// Leet code #257. Binary Tree Paths  
/// </summary>
void LeetCodeTree::binaryTreePaths(TreeNode* root, vector<int>&path, vector<string>&result)
{
    if (root == nullptr)
    {
        return;
    }
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        string str = "";
        for (size_t i = 0; i < path.size(); i++)
        {
            str.append(to_string(path[i]) + "->");
        }
        str.append(to_string(root->val));
        result.push_back(str);
    }
    path.push_back(root->val);
    binaryTreePaths(root->left, path, result);
    binaryTreePaths(root->right, path, result);
    path.pop_back();
}

/// <summary>
/// Leet code #257. Binary Tree Paths  
/// Given a binary tree, return all root-to-leaf paths.
/// For example, given the following binary tree: 
///     1
///   /   \
///  2     3
///   \
///    5
/// All root-to-leaf paths are: 
/// ["1->2->5", "1->3"]
/// </summary>
vector<string> LeetCodeTree::binaryTreePaths(TreeNode* root)
{
    vector<string> result;
    vector<int> path;
    binaryTreePaths(root, path, result);
    return result;
}

/// <summary>
/// Leet code #226. Invert Binary Tree   
/// Invert a binary tree. 
///      4
///    /   \
///   2     7
///  / \   / \
/// 1   3 6   9
/// to 
///      4
///    /   \
///   7     2
///  / \   / \
/// 9   6 3   1
/// Trivia:
/// This problem was inspired by this original tweet by Max Howell: 
/// Google: 90% of our engineers use the software you wrote (Homebrew), 
/// but you can’t invert a binary tree on a whiteboard so fuck off.	
/// </summary>
TreeNode* LeetCodeTree::invertTree(TreeNode* root)
{
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            swap(node->left, node->right);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return root;
}

/// <summary>
/// Leet code #199. Binary Tree Right Side View 
/// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom. 
/// For example:
/// Given the following binary tree,
///     1            <---
///   /   \
///  2     3         <---
///   \     \
///    5     4       <---
/// You should return [1, 3, 4]. 
/// </summary> 
vector<int> LeetCodeTree::rightSideView(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode*> tree_queue;
    if (root != nullptr) tree_queue.push(root);
    while (!tree_queue.empty())
    {
        int last_int;
        size_t size = tree_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* tree_node = tree_queue.front();
            tree_queue.pop();
            if (tree_node->left != nullptr)
            {
                tree_queue.push(tree_node->left);
            }
            if (tree_node->right != nullptr)
            {
                tree_queue.push(tree_node->right);
            }
            last_int = tree_node->val;
        }
        result.push_back(last_int);
    }
    return result;
}

/// <summary>
/// Leet code #98. Validate Binary Search Tree
/// Given a binary tree, determine if it is a valid binary search tree (BST).
/// Assume a BST is defined as follows: 
/// The left subtree of a node contains only nodes with keys less than the node's key.
/// The right subtree of a node contains only nodes with keys greater than the node's key.
/// Both the left and right subtrees must also be binary search trees.
/// Example 1:
///    2
///   / \
///  1   3
/// Binary tree [2,1,3], return true. 
/// Example 2:
///    1
///   / \
///  2   3
/// Binary tree [1,2,3], return false. 
/// </summary> 
bool LeetCodeTree::isValidBST(TreeNode* root)
{
    vector<int> value_list;
    stack<TreeNode *> search_stack;
    TreeNode * node = root;

    while (true)
    {
        if (node != nullptr)
        {
            search_stack.push(node);
            node = node->left;
            continue;
        }
        if (search_stack.empty())
        {
            break;
        }
        node = search_stack.top();
        value_list.push_back(node->val);
        search_stack.pop();
        node = node->right;
    }

    for (size_t i = 1; i < value_list.size(); i++)
    {
        if (value_list[i - 1] >= value_list[i])
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #331. Verify Preorder Serialization of a Binary Tree
/// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, 
/// we record the node's value. If it is a null node, we record using a sentinel value such as #.
///       _9_
///      /   \
///     3     2
///    / \   / \
///   4   1  #  6
///  / \ / \   / \
///  # # # #   # #	
/// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node. 
/// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. 
/// Find an algorithm without reconstructing the tree.
/// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
/// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
/// Example 1:
/// "9,3,4,#,#,1,#,#,2,#,6,#,#"
/// Return true
/// Example 2:
/// "1,#"
/// Return false
/// Example 3:
/// "9,#,#,1"
/// Return false
/// </summary>
bool LeetCodeTree::isValidPreorderSerialization(string preorder)
{
    vector<string> tree_stack;
    string node;
    for (size_t i = 0; i <= preorder.size(); i++)
    {
        if ((i == preorder.size()) || (preorder[i] == ','))
        {
            if (!node.empty()) tree_stack.push_back(node);
            while ((tree_stack.size() > 2) &&
                (tree_stack[tree_stack.size() - 1] == "#") &&
                (tree_stack[tree_stack.size() - 2] == "#") &&
                (tree_stack[tree_stack.size() - 3] != "#"))
            {
                tree_stack.pop_back();
                tree_stack.pop_back();
                tree_stack.pop_back();
                tree_stack.push_back("#");
            }
            node.clear();
        }
        else
        {
            node.push_back(preorder[i]);
        }
    }
    if (tree_stack.size() == 1 && tree_stack.back() == "#") return true;
    else return false;
}

/// <summary>
/// Leet code #110. Balanced Binary Tree
/// </summary>
bool LeetCodeTree::isBalanced(TreeNode* root, int& depth)
{
    if (root == nullptr)
    {
        depth = 0;
        return true;
    }
    else
    {
        int left_depth = 0;
        int right_depth = 0;

        if (!isBalanced(root->left, left_depth) || 
            !isBalanced(root->right, right_depth))
        {
            depth = max(left_depth, right_depth) + 1;
            return false;
        }
        else
        {
            depth = max(left_depth, right_depth) + 1;
            if (abs(left_depth - right_depth) <= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

/// <summary>
/// Leet code #110. Balanced Binary Tree
/// Given a binary tree, determine if it is height-balanced.
/// For this problem, a height-balanced binary tree is defined as a binary 
/// tree in which the depth of the 
/// two subtrees of every node never differ by more than 1. 
/// </summary>
bool LeetCodeTree::isBalanced(TreeNode* root)
{
    int depth;
    return isBalanced(root, depth);
}

/// <summary>
/// Leet code #236. Lowest Common Ancestor of a Binary Tree
/// </summary>
int LeetCodeTree::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, 
    TreeNode* &result)
{
    int count = 0;
    if (root == nullptr) return 0;

    if (root == p || root == q) count = 1;

    count += lowestCommonAncestor(root->left, p, q, result);
    if (count < 2)
    {
        count += lowestCommonAncestor(root->right, p, q, result);
    }
    // if first time we see 2 node found, this is the answer.
    if (count == 2 && result == nullptr) result = root;

    return count;
}

/// <summary>
/// Leet code #236. Lowest Common Ancestor of a Binary Tree
/// Given a binary tree, find the lowest common ancestor (LCA) of two given 
/// nodes in the tree. 
/// According to the definition of LCA on Wikipedia: “The lowest common 
/// ancestor is defined between two 
/// nodes v and w as the lowest node in T that has both v and w as descendants 
/// (where we allow a node to be a descendant of itself).” 
///         _______3______
///        /              \
///     ___5__          ___1__
///    /      \        /      \
///    6       2       0       8
///           / \
///          7   4
/// For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
/// Another example is LCA of nodes 5 and 4 is 5, 
///  since a node can be a descendant of itself according to the LCA definition.
/// </summary>
TreeNode* LeetCodeTree::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode * result = nullptr;
    int count = lowestCommonAncestor(root, p, q, result);
    
    return result;
}

/// <summary>
/// Leet code #235. Lowest Common Ancestor of a Binary Search Tree
/// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST. 
/// According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes 
/// v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)." 
///        _______6______
///       /              \
///    ___2__          ___8__
///   /      \        /      \
///   0       4      7        9
///          / \
///         3   5
/// For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
/// since a node can be a descendant of itself according to the LCA definition.
/// </summary>
TreeNode* LeetCodeTree::lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q)
{
    while (true)
    {
        if ((root == nullptr) || (p == nullptr) || (q == nullptr))
        {
            return nullptr;
        }
        if ((root->val > p->val) && (root->val > q->val))
        {
            root = root->left;
        }
        else if ((root->val < p->val) && (root->val < q->val))
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
}

/// <summary>
/// Leet code #114. Flatten Binary Tree to Linked List
/// Given a binary tree, flatten it to a linked list in-place. 
/// For example,
/// Given 
///     1
///    / \
///   2   5
///  / \   \
/// 3   4   6
/// The flattened tree should look like:
///    1
///     \
///      2
///       \
///        3
///         \
///          4
///           \
///            5
///             \
///              6
/// </summary>
void LeetCodeTree::flatten(TreeNode* root)
{
    TreeNode * tree_first = nullptr;
    TreeNode * tree_last = nullptr;
    stack<TreeNode*> tree_stack;
    if (root != nullptr)
    {
        tree_stack.push(root);
    }
    while (!tree_stack.empty())
    {
        TreeNode * treeNode = tree_stack.top();
        tree_stack.pop();
        if (treeNode->right != nullptr)
        {
            tree_stack.push(treeNode->right);
        }
        if (treeNode->left != nullptr)
        {
            tree_stack.push(treeNode->left);
        }
        if (tree_first == nullptr)
        {
            tree_first = treeNode;
            tree_last = treeNode;
        }
        else
        {
            tree_last->right = treeNode;
            tree_last = treeNode;
        }
        if (treeNode != nullptr) treeNode->left = nullptr;
        if (treeNode != nullptr) treeNode->right = nullptr;
    }
}

/// <summary>
/// Leet code #112. Path Sum
/// Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
/// such that adding up all the values along the path equals the given sum. 
/// For example:
/// Given the below binary tree and sum = 22,               
///          5
///         / \
///        4   8
///       /   / \
///      11  13  4
///     /  \      \
///    7    2      1
/// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
/// </summary>
bool LeetCodeTree::hasPathSum(TreeNode* root, int sum)
{
    if (root == nullptr) return false;
    if (root != nullptr)
    {
        if ((root->left == nullptr) && (root->right == nullptr) && (root->val == sum))
        {
            return true;
        }
        if ((root->left != nullptr) && hasPathSum(root->left, sum - root->val))
        {
            return true;
        }
        if ((root->right != nullptr) && hasPathSum(root->right, sum - root->val))
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #113. Path Sum II
/// </summary>
void LeetCodeTree::pathSum(TreeNode* root, int sum, vector<int>&path, vector<vector<int>> &result)
{
    if (root == nullptr)
    {
        return;
    }
    path.push_back(root->val);
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        if (root->val == sum) result.push_back(path);
    }
    else
    {
        if (root->left != nullptr) pathSum(root->left, sum - root->val, path, result);
        if (root->right != nullptr) pathSum(root->right, sum - root->val, path, result);
    }
    path.pop_back();
}

/// <summary>
/// Leet code #113. Path Sum II
/// Given a binary tree and a sum, find all root-to-leaf paths where each 
/// path's sum equals the given sum.  
/// For example:
/// Given the below binary tree and sum = 22,              
///          5
///         / \
///        4   8
///       /   / \
///      11  13  4
///     /  \    / \
///    7    2  5   1
/// return
/// [
///   [5,4,11,2],
///   [5,8,4,5]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::pathSum(TreeNode* root, int sum)
{
    vector<int>path;
    vector<vector<int>> result;
    pathSum(root, sum, path, result);
    return result;
}

/// <summary>
/// Preorder traverse with the path passed on the way to check the sum.
/// </summary>
int LeetCodeTree::pathSumIII(TreeNode* root, vector<int>& path, int sum)
{
    int count = 0;
    if (root == nullptr) return 0;
    path.push_back(root->val);
    int total = 0;
    // from bottom to search up is to make sure we do not
    // have duplicate
    for (int i = (int)path.size() - 1; i >= 0; i--)
    {
        total += path[i];
        if (total == sum) count++;
    }
    count += pathSumIII(root->left, path, sum);
    count += pathSumIII(root->right, path, sum);
    path.pop_back();
    return count;
}

/// <summary>
/// Leet code #437. Path Sum III     
/// You are given a binary tree in which each node contains an integer value. 
/// Find the number of paths that sum to a given value.
/// The path does not need to start or end at the root or a leaf, 
/// but it must go downwards (traveling only from parent nodes to child nodes).
/// The tree has no more than 1,000 nodes and the values are in the range 
/// -1,000,000 to 1,000,000. 
/// Example: 
/// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
///        10
///       /  \
///      5   -3
///     / \    \
///    3   2   11
///   / \   \
///  3  -2   1
///
/// Return 3. The paths that sum to 8 are:
///
/// 1.  5 -> 3
/// 2.  5 -> 2 -> 1
/// 3. -3 -> 11
/// </summary>
int LeetCodeTree::pathSumIII(TreeNode* root, int sum)
{
    vector<int> path;
    return pathSumIII(root, path, sum);
}

/// <summary>
/// Leet code #129. Sum Root to Leaf Numbers    
/// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.  
/// An example is the root-to-leaf path 1->2->3 which represents the number 123.
/// Find the total sum of all root-to-leaf numbers.
/// For example, 
///   1
///  / \
/// 2   3
/// The root-to-leaf path 1->2 represents the number 12.
/// The root-to-leaf path 1->3 represents the number 13.
/// Return the sum = 12 + 13 = 25.
/// </summary>
int LeetCodeTree::sumNumbers(TreeNode* root)
{
    int result = 0;
    vector<pair<TreeNode *, int>> tree_list;
    if (root != nullptr)
    {
        tree_list.push_back(make_pair(root, 0));
    }

    while (!tree_list.empty())
    {
        pair<TreeNode *, int> pair = tree_list.back();
        if (pair.second == 0)
        {
            TreeNode * left = pair.first->left;
            if (left == nullptr)
            {
                tree_list[tree_list.size() - 1].second++;
            }
            else
            {
                tree_list.push_back(make_pair(left, 0));
            }
        }
        else if (pair.second == 1)
        {
            TreeNode * right = pair.first->right;
            if (right == nullptr)
            {
                tree_list[tree_list.size() - 1].second++;
            }
            else
            {
                tree_list.push_back(make_pair(right, 0));
            }
        }
        else
        {
            if ((pair.first->left == nullptr) && (pair.first->right == nullptr))
            {
                int path_sum = 0;
                for (size_t i = 0; i < tree_list.size(); i++)
                {
                    path_sum *= 10;
                    path_sum += tree_list[i].first->val;
                }
                result += path_sum;
            }
            tree_list.pop_back();
            if (tree_list.empty()) continue;
            tree_list[tree_list.size() - 1].second++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #105. Build binary tree from preoder and inorder travesal
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromPreorderandInorder(
    vector<int>& preorder, vector<int>& inorder,
    size_t start_preorder, size_t start_inorder,
    size_t length)
{
    if (length == 0)
    {
        return nullptr;
    }
    TreeNode *root;
    root = new TreeNode(preorder[start_preorder]);
    size_t index;
    for (index = 0; index < length; index++)
    {
        if (inorder[start_inorder + index] == preorder[start_preorder])
        {
            break;
        }
    }
    TreeNode *left = buildTreeFromPreorderandInorder(preorder, inorder, start_preorder + 1,
        start_inorder, index);
    TreeNode *right = buildTreeFromPreorderandInorder(preorder, inorder,
        start_preorder + 1 + index, start_inorder + index + 1, length - index - 1);
    root->left = left;
    root->right = right;
    return root;
}

/// <summary>
/// Leet code #105. Construct Binary Tree from Preorder and Inorder Traversal
///
/// Medium
///
/// Given preorder and inorder traversal of a tree, construct the binary tree.
///
/// Note:
/// You may assume that duplicates do not exist in the tree.
///
/// For example, given
///
/// preorder = [3,9,20,15,7]
/// inorder = [9,3,15,20,7]
/// Return the following binary tree:
///
///    3
///   / \
///  9  20
///    /  \
///   15   7    
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromPreorderandInorder(vector<int>& preorder, vector<int>& inorder)
{
    if ((preorder.size() == 0) || (inorder.size() == 0))
    {
        return nullptr;
    }
    TreeNode *root = 
        buildTreeFromPreorderandInorder(preorder, inorder, 0, 0, preorder.size());
    return root;
}

/// <summary>
/// Leet code #106. Construct Binary Tree from Inorder and Postorder Traversal
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromInorderAndPostorder(
    vector<int>& inorder, vector<int>& postorder,
    size_t start_inorder, size_t start_postorder,
    size_t length)
{
    if (length == 0)
    {
        return nullptr;
    }
    TreeNode *root;
    root = new TreeNode(postorder[start_postorder + length - 1]);
    size_t index;
    for (index = 0; index < length; index++)
    {
        if (inorder[start_inorder + index] == postorder[start_postorder + length - 1])
        {
            break;
        }
    }
    TreeNode *left = buildTreeFromInorderAndPostorder(inorder, postorder,
        start_inorder, start_postorder, index);
    TreeNode *right = buildTreeFromInorderAndPostorder(inorder, postorder,
        start_inorder + index + 1, start_postorder + index, length - index - 1);
    root->left = left;
    root->right = right;
    return root;
}

/// <summary>
/// Leet code #106. Construct Binary Tree from Inorder and Postorder Traversal
///
/// Medium
///
/// Given inorder and postorder traversal of a tree, construct the binary tree.
///
/// Note:
/// You may assume that duplicates do not exist in the tree.
///
/// For example, given
///
/// preorder = [3,9,20,15,7]
/// postorder = [9,15,7,20,3]
/// Return the following binary tree:
///
///    3
///   / \
///  9  20
///    /  \
///   15   7    
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromInorderAndPostorder(vector<int>& inorder, vector<int>& postorder)
{
    if ((inorder.size() == 0) || (postorder.size() == 0))
    {
        return nullptr;
    }
    TreeNode *root = 
        buildTreeFromInorderAndPostorder(inorder, postorder, 0, 0, inorder.size());
    return root;
}

/// <summary>
/// Leet code #100. Same Tree
///
/// Easy
///
/// Given two binary trees, write a function to check if they are the same 
/// or not.
///
/// Two binary trees are considered the same if they are structurally 
/// identical and the nodes have the same value.
///
/// Example 1:
///
/// Input:     1         1
///           / \       / \
    ///          2   3     2   3
    ///
    ///        [1,2,3],   [1,2,3]
    ///
    /// Output: true
    /// Example 2:
    ///
    /// Input:     1         1
    ///           /           \
    ///          2             2
    ///
    ///        [1,2],     [1,null,2]
    ///
    /// Output: false
    /// Example 3:
    ///
    /// Input:     1         1
    ///           / \       / \
    ///          2   1     1   2
    ///
    ///        [1,2,1],   [1,1,2]
    ///
    /// Output: false
    /// </summary>
bool LeetCodeTree::isSameTree(TreeNode* p, TreeNode* q)
{
    if ((p == nullptr) && (q == nullptr))
    {
        return true;
    }
    else if (((p == nullptr) && (q != nullptr)) || ((p != nullptr) && (q == nullptr)))
    {
        return false;
    }
    else
    {
        if (p->val != q->val) return false;
        if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Find the two disordered nodes in the binary search tree 
/// </summary>
void LeetCodeTree::recoverTree(TreeNode* root, TreeNode* &min_node, TreeNode* &max_node,
    TreeNode* &first, TreeNode* &second)
{
    if (root == nullptr) return;
    TreeNode* left_min = root;
    TreeNode* left_max = root;
    TreeNode* right_min = root;
    TreeNode* right_max = root;
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        min_node = root;
        max_node = root;
        return;
    }
    if (root->left != nullptr)
    {
        recoverTree(root->left, left_min, left_max, first, second);
    }
    if (root->right != nullptr)
    {
        recoverTree(root->right, right_min, right_max, first, second);
    }

    if (left_max->val > root->val)
    {
        first = left_max;
        second = root;
    }
    if (root->val > right_min->val)
    {
        if (left_max->val <= root->val) first = root;
        second = right_min;
    }

    min_node = left_min;
    if (root->val < min_node->val) min_node = root;
    if (right_min->val < min_node->val) min_node = right_min;

    max_node = left_max;
    if (root->val > max_node->val) max_node = root;
    if (right_max->val > max_node->val) max_node = right_max;
}

/// <summary>
/// Leet code #99. Recover Binary Search Tree 
/// Two elements of a binary search tree (BST) are swapped by mistake.
/// Recover the tree without changing its structure.
/// Note:
/// A solution using O(n) space is pretty straight forward. Could you devise 
/// a constant space solution?
/// </summary>
void LeetCodeTree::recoverTree(TreeNode* root)
{
    TreeNode *min_node = nullptr, *max_node = nullptr;
    TreeNode *first = nullptr, *second = nullptr;
    recoverTree(root, min_node, max_node, first, second);
    if ((first != nullptr) && (second != nullptr))
    {
        swap(first->val, second->val);
    }
}

/// <summary>
/// Find the two disordered nodes in the binary search tree 
/// </summary>
void LeetCodeTree::recoverTreeII(TreeNode* root, TreeNode* &prev,
    TreeNode* &first, TreeNode* &second)
{
    if (root == nullptr) return;
    if (root->left != nullptr)
    {
        recoverTreeII(root->left, prev, first, second);
    }
    if ((prev != nullptr) && (prev->val > root->val))
    {
        if (first == nullptr)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    if (root->right != nullptr)
    {
        recoverTreeII(root->right, prev, first, second);
    }
}

/// <summary>
/// Leet code #99. Recover Binary Search Tree 
/// Two elements of a binary search tree (BST) are swapped by mistake.
/// Recover the tree without changing its structure.
/// Note:
/// A solution using O(n) space is pretty straight forward. 
/// Could you devise a constant space solution?
/// </summary>
void LeetCodeTree::recoverTreeII(TreeNode* root)
{
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    recoverTreeII(root, prev, first, second);
    if ((first != nullptr) && (second != nullptr))
    {
        swap(first->val, second->val);
    }
}

/// <summary>
/// Leet code #101. Symmetric Tree 
/// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). 
/// For example, this binary tree [1,2,2,3,4,4,3] is symmetric: 
///     1
///    / \
///   2   2
///  / \ / \
/// 3  4 4  3
/// But the following [1,2,2,null,3,null,3] is not:
///    1
///   / \
///  2   2
///   \   \
///   3    3
/// Note:
/// Bonus points if you could solve it both recursively and iteratively.
/// </summary>
bool LeetCodeTree::isSymmetric(TreeNode* root)
{
    vector<TreeNode*> tree_list;
    queue<TreeNode*> tree_queue;
    TreeNode * node = root;
    tree_queue.push(root);

    while (!tree_queue.empty())
    {
        size_t size = tree_queue.size();
        tree_list.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = tree_queue.front();
            tree_list.push_back(node);
            tree_queue.pop();
            if (node != nullptr)
            {
                tree_queue.push(node->left);
                tree_queue.push(node->right);
            }
        }
        int first = 0, last = tree_list.size() - 1;
        while (first < last)
        {
            if (((tree_list[first] == nullptr) && (tree_list[last] != nullptr)) ||
                ((tree_list[first] != nullptr) && (tree_list[last] == nullptr)))
            {
                return false;
            }
            if ((tree_list[first] != nullptr) && (tree_list[last] != nullptr) &&
                (tree_list[first]->val != tree_list[last]->val))
            {
                return false;
            }
            first++; last--;
        }
    }
    return true;
}

/// <summary>
/// Build Binary Search Tree from sorted array 
/// </summary>
TreeNode* LeetCodeTree::buildBSTFromSortedArray(vector<int>& nums, int first, int last)
{
    int middle = first + (last - first) / 2;
    TreeNode * root = new TreeNode(nums[middle]);
    if (first != middle)
    {
        root->left = buildBSTFromSortedArray(nums, first, middle - 1);
    }
    if (last != middle)
    {
        root->right = buildBSTFromSortedArray(nums, middle + 1, last);
    }
    return root;
}

/// <summary>
/// Leet code #108. Convert Sorted Array to Binary Search Tree 
/// Given an array where elements are sorted in ascending order, convert it to a height 
/// balanced BST.
/// </summary>
TreeNode* LeetCodeTree::sortedArrayToBST(vector<int>& nums)
{
    if (nums.empty()) return nullptr;
    return buildBSTFromSortedArray(nums, 0, nums.size() - 1);
}

/// <summary>
/// Leet code #109. Convert Sorted List to Binary Search Tree
/// Given a singly linked list where elements are sorted in ascending order, 
/// convert it to a height balanced BST.
/// </summary>
TreeNode* LeetCodeTree::sortedListToBST(ListNode* head)
{
    if (head == nullptr) return nullptr;
    ListNode *head_new = nullptr, *prev = nullptr;

    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        ListNode * node = new ListNode(ptr->val);
        if (head_new == nullptr)
        {
            head_new = node;
            prev = node;
        }
        else
        {
            prev->next = node;
            prev = prev->next;
        }
        ptr = ptr->next;
    }

    head = head_new;
    ListNode *slow = head, *fast = head;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast == nullptr) break;
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    TreeNode * root = new TreeNode(slow->val);
    if (prev != slow)
    {
        prev->next = nullptr;
        root->left = sortedListToBST(head);
    }
    if (slow->next != nullptr)
    {
        root->right = sortedListToBST(slow->next);
    }
    // Please remove this line when you submit to LeetCode, because it will delete list 
    delete slow;
    return root;
}

/// <summary>
/// Leet code #404. Sum of Left Leaves 
/// Find the sum of all left leaves in a given binary tree.
/// Example: 
///     3
///    / \
///   9  20
///     /  \
///    15   7 
/// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
/// </summary>
int LeetCodeTree::sumOfLeftLeaves(TreeNode* root)
{
    queue<TreeNode*> tree_queue;
    tree_queue.push(root);
    int sum = 0;
    while (!tree_queue.empty())
    {
        TreeNode * tree_node = tree_queue.front();
        tree_queue.pop();
        if (tree_node == nullptr) continue;

        TreeNode * left = tree_node->left;
        tree_queue.push(left);
        // if the node is leaf, sum the value, it must be left leaf
        if ((left != nullptr) && (left->left == nullptr) && (left->right == nullptr))
        {
            sum += left->val;
        }
        TreeNode * right = tree_node->right;
        tree_queue.push(right);
    }
    return sum;
}

/// <summary>
/// Leet code #124. Binary Tree Maximum Path Sum
/// </summary>
void LeetCodeTree::maxPathSum(TreeNode* root, int &max_path_sum, int&max_path_loop)
{
    if (root == nullptr)
    {
        max_path_sum = 0;
        max_path_loop = INT_MIN;
    }
    else
    {
        int max_path_sum_left, max_path_loop_left;
        maxPathSum(root->left, max_path_sum_left, max_path_loop_left);
        int max_path_sum_right, max_path_loop_right;
        maxPathSum(root->right, max_path_sum_right, max_path_loop_right);

        max_path_sum = max(max_path_sum_left + root->val, max_path_sum_right + root->val);
        max_path_sum = max(max_path_sum, root->val);
        max_path_loop = max(max_path_loop_left, max_path_loop_right);
        max_path_loop = max(max_path_loop, root->val + max_path_sum_left + max_path_sum_right);
        max_path_loop = max(max_path_loop, max_path_sum);
    }
}

/// <summary>
/// Leet code #124. Binary Tree Maximum Path Sum 
///
/// Given a binary tree, find the maximum path sum. 
/// For this problem, a path is defined as any sequence of nodes from some 
/// starting node to any node in the tree along the parent-child connections. 
/// The path must contain at least 
/// one node and does not need to go through the root.
/// For example:
/// Given the below binary tree, 
///     1
///    / \
///   2   3
/// Return 6.
/// Explanation:
/// The max_path must come from the left direct path + self, the right direct 
/// path + self and the maximum left loop path and maximum right loop path. 
/// </summary>
int LeetCodeTree::maxPathSum(TreeNode* root)
{
    int max_path_loop = 0;
    int max_path_sum = 0;
    maxPathSum(root, max_path_sum, max_path_loop);
    return max_path_loop;
}

/// <summary>
/// Leet code #337. House Robber III 
/// </summary>
void LeetCodeTree::robIII(TreeNode* root, int& rob_with_root, int& rob_without_root)
{
    rob_with_root = 0;
    rob_without_root = 0;
    if (root != nullptr)
    {
        int left_rob_with_root = 0, left_rob_without_root = 0;
        robIII(root->left, left_rob_with_root, left_rob_without_root);
        int right_rob_with_root = 0, right_rob_without_root = 0;
        robIII(root->right, right_rob_with_root, right_rob_without_root);
        rob_with_root = root->val + left_rob_without_root + right_rob_without_root;
        rob_without_root = left_rob_with_root + right_rob_with_root;
        rob_with_root = max(rob_with_root, rob_without_root);
    }
}

/// <summary>
/// Leet code #337. House Robber III 
/// The thief has found himself a new place for his thievery again. 
/// There is only one entrance to this area, 
/// called the "root." Besides the root, each house has one and only 
/// one parent house. After a tour, the smart 
/// thief realized that "all houses in this place forms a binary tree". 
/// It will automatically contact the police 
/// if two directly-linked houses were broken into on the same night. 
/// Determine the maximum amount of money the thief can rob tonight 
/// without alerting the police.
/// Example 1:	
///     3
///    / \
///   2   3
///    \   \ 
///     3   1
/// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
/// Example 2:
///	     3
///     / \
///    4   5
///   / \   \ 
///  1   3   1
/// Maximum amount of money the thief can rob = 4 + 5 = 9. 
/// </summary>
int LeetCodeTree::robIII(TreeNode* root)
{
    int rob_with_root = 0;
    int rob_without_root = 0;
    robIII(root, rob_with_root, rob_without_root);
    return rob_with_root;
}

/// <summary>
/// Append the tree linked node to end
/// </summary>
void LeetCodeTree::connectRight(TreeLinkNode *&head, TreeLinkNode *&ptr, TreeLinkNode * node)
{
    if (node == nullptr) return;
    node->next = nullptr;
    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        ptr->next = node;
    }
    ptr = node;
}

/// <summary>
/// Leet code #116. Populating Next Right Pointers in Each Node           
/// struct TreeLinkNode {
///    int val;
///    TreeLinkNode *left, *right, *next;
///    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
/// };  
/// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
///
/// Initially, all next pointers are set to NULL.
///
/// Note: 
/// You may only use constant extra space.
/// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
///
/// For example,
/// Given the following perfect binary tree,
///         1
///       /   \
///      2     3
///     / \   / \
///    4   5 6   7
/// After calling your function, the tree should look like:
/// 
///         1 -> NULL
///       /   \
///      2 ->  3 -> NULL
///     / \   / \
///    4-> 5->6 ->7 -> NULL
/// </summary>
void LeetCodeTree::connectRight(TreeLinkNode *root)
{
    TreeLinkNode* prev_head = nullptr, *prev_ptr = nullptr;
    TreeLinkNode* curr_head, *curr_ptr;
    prev_head = root;
    while (prev_head)
    {
        prev_ptr = prev_head;
        curr_head = nullptr;
        curr_ptr = nullptr;
        while (prev_ptr != nullptr)
        {
            connectRight(curr_head, curr_ptr, prev_ptr->left);
            connectRight(curr_head, curr_ptr, prev_ptr->right);
            prev_ptr = prev_ptr->next;
        }
        prev_head = curr_head;
    }
    return;
}

/// <summary>
/// Leet code #117. Populating Next Right Pointers in Each Node II           
/// Given a binary tree 
/// struct TreeLinkNode {
///    int val;
///    TreeLinkNode *left, *right, *next;
///    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
/// };  
///
/// Follow up for problem "Populating Next Right Pointers in Each Node".
///
/// What if the given tree could be any binary tree? Would your previous solution still work?
///
/// Note: 
/// You may only use constant extra space.
///
/// For example,
/// Given the following binary tree,
///
///         1
///       /  \
///      2    3
///     / \    \
///    4   5    7
/// After calling your function, the tree should look like:
///
///         1 -> NULL
///       /  \
///      2 -> 3 -> NULL
///     / \    \
///    4-> 5 -> 7 -> NULL
/// </summary>
void LeetCodeTree::connectRightII(TreeLinkNode *root)
{
    TreeLinkNode* prev_head = nullptr, *prev_ptr = nullptr;
    TreeLinkNode* curr_head, *curr_ptr;
    prev_head = root;
    while (prev_head)
    {
        prev_ptr = prev_head;
        curr_head = nullptr;
        curr_ptr = nullptr;
        while (prev_ptr != nullptr)
        {
            connectRight(curr_head, curr_ptr, prev_ptr->left);
            connectRight(curr_head, curr_ptr, prev_ptr->right);
            prev_ptr = prev_ptr->next;
        }
        prev_head = curr_head;
    }
    return;
}

/// <summary>
/// Leet code #222. Count Complete Tree Nodes               
/// Given a complete binary tree, count the number of nodes.
/// Definition of a complete binary tree from Wikipedia:
/// In a complete binary tree every level, except possibly the last, is completely filled, 
/// and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes 
/// inclusive at the last level h. 
/// </summary>
int LeetCodeTree::countCompleteTreeNodes(TreeNode* root)
{
    int left_height = 0, right_height = 0;
    TreeNode * node = root;
    while (node != nullptr)
    {
        left_height += 1;
        node = node->left;
    }
    node = root;
    while (node != nullptr)
    {
        right_height += 1;
        node = node->right;
    }

    int count = 0;
    if (left_height == right_height)
    {
        count = (1 << left_height) - 1;
    }
    else
    {
        count = 1;
        count += countCompleteTreeNodes(root->left);
        count += countCompleteTreeNodes(root->right);
    }

    return count;
}

/// <summary>
/// Return kth smallest node in BST
/// </summary>
int LeetCodeTree::findKthSmallest(TreeNode* root, int &k)
{
    if (root == nullptr) return 0;
    int value = findKthSmallest(root->left, k);
    if (k == 0) return value;
    k--;
    if (k == 0) return root->val;
    value = findKthSmallest(root->right, k);
    return value;
}

/// <summary>
/// Leet code #230. Kth Smallest Element in a BST
/// Given a binary search tree, write a function kthSmallest to find the kth 
/// smallest element in it.
/// Note: 
/// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
/// Follow up:
/// What if the BST is modified (insert/delete operations) often and you need to find the 
/// kth smallest frequently? How would you optimize the kthSmallest routine?
/// Hint:
/// Try to utilize the property of a BST.
/// What if you could modify the BST node's structure?
/// The optimal runtime complexity is O(height of BST).
/// </summary>
int LeetCodeTree::kthSmallest(TreeNode* root, int k)
{
    return findKthSmallest(root, k);
}

/// <summary>
/// Leet code #450. Delete Node in a BST 
/// Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
/// Return the root node reference (possibly updated) of the BST.
///
/// Basically, the deletion can be divided into two stages: 
/// 1.Search for a node to remove.
/// 2.If the node is found, delete the node.
///
/// Note: Time complexity should be O(height of tree).
/// Example: 
/// root = [5,3,6,2,4,null,7]
/// key = 3
///     5
///    / \
///   3   6
///  / \   \
/// 2   4   7
/// Given key to delete is 3. So we find the node with value 3 and delete it.
/// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
///     5
///    / \
///   4   6
///  /     \
/// 2       7
/// Another valid answer is [5,2,6,null,4,null,7].
///     5
///    / \
///   2   6
///    \   \
///     4   7
/// </summary>
TreeNode* LeetCodeTree::deleteNode(TreeNode* root, int key)
{
    if (root == nullptr) return nullptr;
    if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode* node = root->right;
            delete root;
            return node;
        }
        else if (root->right == nullptr)
        {
            TreeNode* node = root->left;
            delete root;
            return node;
        }
        else
        {
            TreeNode * child = root->left;
            while (child->right != nullptr)
            {
                child = child->right;
            }
            root->val = child->val;
            root->left = deleteNode(root->left, child->val);
        }
    }
    return root;
}

/// <summary>
/// Leet code #366. Find Leaves of Binary Tree      
/// </summary>
int LeetCodeTree::findLeaves(TreeNode* root, vector<vector<int>> &result)
{
    if (root == nullptr) return 0;
    int left_depth = 0;
    int right_depth = 0;
    if (root->left != nullptr)
    {
        left_depth = findLeaves(root->left, result);
    }
    if (root->right != nullptr)
    {
        right_depth = findLeaves(root->right, result);
    }
    int depth = max(left_depth, right_depth) + 1;
    if (depth > (int)result.size())
    {
        result.push_back(vector<int>());
    }
    result[depth - 1].push_back(root->val);
    return depth;
}

/// <summary>
/// Leet code #366. Find Leaves of Binary Tree      
/// 
/// Given a binary tree, collect a tree's nodes as if you were doing this: 
/// Collect and remove all leaves, repeat until the tree is empty.
/// Example:
/// Given binary tree 
///          1
///         / \
///        2   3
///       / \     
///      4   5    
///
/// Returns [4, 5, 3], [2], [1]. 
/// Explanation:
/// 1. Removing the leaves [4, 5, 3] would result in this tree: 
///          1
///         / 
///        2          
///
/// 2. Now removing the leaf [2] would result in this tree: 
///          1          
/// 3. Now removing the leaf [1] would result in the empty tree: 
///          []         
///
/// Returns [4, 5, 3], [2], [1]. 
/// </summary>
vector<vector<int>> LeetCodeTree::findLeaves(TreeNode* root)
{
    vector<vector<int>> result;
    findLeaves(root, result);
    return result;
}

/// <summary>
/// Leet code #156. Binary Tree Upside Down  
/// </summary>
void LeetCodeTree::upsideDownBinaryTree(TreeNode* &root, TreeNode* &right)
{
    if (root == nullptr) return;
    if (root->left == nullptr)
    {
        right = root;
        return;
    }
    else
    {
        TreeNode * left = root->left;
        upsideDownBinaryTree(left, right);
        right->left = root->right;
        right->right = root;
        root->left = nullptr;
        root->right = nullptr;
        right = root;
        root = left;
    }
}

/// <summary>
/// Leet code #156. Binary Tree Upside Down  
/// 
/// Given a binary tree where all the right nodes are either leaf nodes with a sibling 
/// (a left node that shares the same parent node) or empty, flip it upside down and 
/// turn it into a tree where the original right nodes turned into left leaf nodes. 
/// Return the new root. 
/// For example:
/// Given a binary tree {1,2,3,4,5},
///     1
///    / \
///   2   3
///  / \
/// 4   5
/// return the root of the binary tree [4,5,2,#,#,3,1].
///     4
///    / \
///   5   2
///      / \
///     3   1  
/// </summary>
TreeNode* LeetCodeTree::upsideDownBinaryTree(TreeNode* root)
{
    TreeNode * right;
    upsideDownBinaryTree(root, right);
    return root;
}

/// <summary>
/// Leet code #250. Count Univalue Subtrees  
/// </summary>
bool LeetCodeTree::countUnivalSubtrees(TreeNode* root, int& value, int& count)
{
    if (root == nullptr) return true;
    int left_value = 0, left_count = 0;
    bool left_unival = true;
    if (root->left != nullptr)
    {
        left_unival = countUnivalSubtrees(root->left, left_value, left_count);
        if (root->val != left_value)
        {
            left_unival = false;
        }
    }

    int right_value = 0, right_count = 0;
    bool right_unival = true;
    if (root->right != nullptr)
    {
        right_unival = countUnivalSubtrees(root->right, right_value, right_count);
        if (root->val != right_value)
        {
            right_unival = false;
        }
    }
    count = left_count + right_count;
    value = root->val;
    if (left_unival && right_unival)
    {
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #250. Count Univalue Subtrees  
/// 
/// Given a binary tree, count the number of uni-value subtrees.
/// A Uni-value subtree means all nodes of the subtree have the same value.
///
/// For example:
/// Given binary tree,
///              5
///             / \
///            1   5
///           / \   \
///          5   5   5
///
/// return 4. 
/// </summary>
int LeetCodeTree::countUnivalSubtrees(TreeNode* root)
{
    int value = 0;
    int count = 0;
    countUnivalSubtrees(root, value, count);
    return count;
}

/// <summary>
/// Leet code #298. Binary Tree Longest Consecutive Sequence  
/// </summary>
int LeetCodeTree::longestConsecutive(TreeNode* root, int& max_length)
{
    if (root == nullptr)
    {
        max_length = max(0, max_length);
        return 0;
    }
    else if ((root->left == nullptr) && (root->right == nullptr))
    {
        max_length = max(1, max_length);
        return 1;
    }
    int left_count = 0, right_count = 0;
    if (root->left != nullptr)
    {
        left_count = longestConsecutive(root->left, max_length);
        if (root->val + 1 == root->left->val)
        {
            left_count = left_count + 1;
            max_length = max(max_length, left_count);
        }
        else
        {
            left_count = 1;
        }
    }
    if (root->right != nullptr)
    {
        right_count = longestConsecutive(root->right, max_length);
        if (root->val + 1 == root->right->val)
        {
            right_count = right_count + 1;
            max_length = max(max_length, right_count);
        }
        else
        {
            right_count = 1;
        }
    }
    return max(left_count, right_count);
}

/// <summary>
/// Leet code #298. Binary Tree Longest Consecutive Sequence  
/// 
/// Given a binary tree, find the length of the longest consecutive sequence path. 
/// The path refers to any sequence of nodes from some starting node to any node in the tree 
/// along the parent-child connections. The longest consecutive path need to be from parent to 
/// child (cannot be the reverse).  
/// For example,
///    1
///     \
///      3
///     / \
///    2   4
///         \
///          5
///
/// Longest consecutive sequence path is 3-4-5, so return 3.    
///    2
///     \
///      3
///     / 
///    2    
///   / 
///  1
///
/// Longest consecutive sequence path is 2-3,not3-2-1, so return 2. 
/// </summary>
int LeetCodeTree::longestConsecutive(TreeNode* root)
{
    int max_length = 0;
    longestConsecutive(root, max_length);
    return max_length;
}

/// <summary>
/// Leet code #255. Verify Preorder Sequence in Binary Search Tree  
/// 
/// Given an array of numbers, verify whether it is the correct preorder traversal 
/// sequence of a binary search tree.
/// You may assume each number in the sequence is unique.
/// Follow up:
/// Could you do it using only constant space complexity?
/// </summary>
bool LeetCodeTree::verifyPreorder(vector<int>& preorder, int start, int end)
{
    if (start >= end) return true;
    int root_value = preorder[start];
    int index = start;
    for (index = start + 1; index < end; index++)
    {
        if (preorder[index] > root_value) break;
    }
    if (start + 1 < index)
    {
        if (!verifyPreorder(preorder, start + 1, index))
        {
            return false;
        }
    }
    start = index;
    for (index = start; index < end; index++)
    {
        if (preorder[index] < root_value) return false;
    }
    if (start < end)
    {
        if (!verifyPreorder(preorder, start, end))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #255. Verify Preorder Sequence in Binary Search Tree  
/// 
/// Given an array of numbers, verify whether it is the correct preorder traversal 
/// sequence of a binary search tree.
/// You may assume each number in the sequence is unique.
/// Follow up:
/// Could you do it using only constant space complexity?
/// </summary>
bool LeetCodeTree::verifyPreorder(vector<int>& preorder)
{
    return verifyPreorder(preorder, 0, preorder.size());
}

/// <summary>
/// Leet code #314. Binary Tree Vertical Order Traversal  
/// 
/// Given a binary tree, return the vertical order traversal of its nodes' values. 
/// (ie, from top to bottom, column by column).
/// If two nodes are in the same row and column, the order should be from left to right.
/// Examples:
/// 1.Given binary tree [3,9,20,null,null,15,7],
///    3
///   / \
///  9  20
///    /  \
///   15   7
/// return its vertical order traversal as:
///
/// [
///   [9],
///   [3,15],
///   [20],
///   [7]
/// ]
///
/// 2.Given binary tree [3,9,8,4,0,1,7],
///     3
///    / \
///   9   8
///  / \ / \
/// 4  01   7
/// return its vertical order traversal as:
/// [
///  [4],
///  [9],
///  [3,0,1],
///  [8],
///  [7]
/// ]
///
/// 3.Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
///     3
///    / \
///   9   8
///  / \ / \
/// 4   01  7
///    / \
///   5   2
/// return its vertical order traversal as:
/// [
///  [4],
///  [9,5],
///  [3,0,1],
///  [8,2],
///  [7]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::verticalOrder(TreeNode* root)
{
    vector<vector<int>> result;
    // since index can be negative, use map to remember it
    map<int, vector<int>> node_map;
    queue<pair<TreeNode*, int>> process_queue;
    process_queue.push(make_pair(root, 0));

    // BFS to traverse tree
    while (!process_queue.empty())
    {
        pair<TreeNode*, int> node_info = process_queue.front();
        process_queue.pop();
        TreeNode * node = node_info.first;
        int index = node_info.second;
        if (node == nullptr) continue;
        else node_map[index].push_back(node->val);
        process_queue.push(make_pair(node->left, index - 1));
        process_queue.push(make_pair(node->right, index + 1));
    }
    for (map<int, vector<int>>::iterator itr = node_map.begin(); itr != node_map.end(); ++itr)
    {
        result.push_back(itr->second);
    }
    return result;
}

/// <summary>
/// Leet code #333. Largest BST Subtree  
/// </summary>
bool LeetCodeTree::checkBSTSubtree(TreeNode* root, int& min_val, int& max_val, int& size)
{
    if (root == nullptr)
    {
        size = 0;
        return true;
    }
    int left_min = root->val, left_max = root->val, left_size = 0;
    bool left_BSTSubtree = true;
    if (root->left != nullptr)
    {
        left_BSTSubtree = checkBSTSubtree(root->left, left_min, left_max, left_size);
        if (left_BSTSubtree) left_BSTSubtree = root->val > left_max;
    }
    int right_min = root->val, right_max = root->val, right_size = 0;
    bool right_BSTSubtree = true;
    if (root->right != nullptr)
    {
        right_BSTSubtree = checkBSTSubtree(root->right, right_min, right_max, right_size);
        if (right_BSTSubtree) right_BSTSubtree = root->val < right_min;
    }
    min_val = min(left_min, right_min); max_val = max(right_min, right_max);
    if (left_BSTSubtree && right_BSTSubtree)
    {
        size = 1 + left_size + right_size;
        return true;
    }
    else
    {
        size = max(left_size, right_size);
        return false;
    }
}

/// <summary>
/// Leet code #333. Largest BST Subtree  
/// 
/// Given a binary tree, find the largest subtree which is a Binary Search Tree 
/// (BST), where largest means subtree with largest number of nodes in it.
/// Note:
/// A subtree must include all of its descendants.
/// Here's an example:
///
///     10
///    /  \
///   5   15
///  / \    \ 
/// 1   8    7
/// The Largest BST Subtree in this case is the highlighted one. 
/// The return value is the subtree's size, which is 3. 
/// Hint:
/// 1. You can recursively use algorithm similar to 98. Validate Binary 
/// Search Tree at each node of the tree, 
/// which will result in O(nlogn) time complexity. 
/// Follow up:
/// Can you figure out ways to solve it with O(n) time complexity? 
/// </summary>
int LeetCodeTree::largestBSTSubtree(TreeNode* root)
{
    int min_val, max_val, size;
    checkBSTSubtree(root, min_val, max_val, size);
    return size;
}

/// <summary>
/// Leet code #285. Inorder Successor in BST 
/// 
/// Given a binary search tree and a node in it, find the in-order successor of that node in the BST. 
/// Note: If the given node has no in-order successor in the tree, return null. 
/// </summary>
TreeNode* LeetCodeTree::inorderSuccessor(TreeNode* root, TreeNode* p)
{
    stack<TreeNode*> process_stack;
    TreeNode *node = root;
    while (node != nullptr && node->val != p->val)
    {
        if (p->val < node->val)
        {
            process_stack.push(node);
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    if (node == nullptr) return nullptr;
    node = node->right;
    while (node != nullptr)
    {
        process_stack.push(node);
        node = node->left;
    }
    if (!process_stack.empty()) return process_stack.top();
    else return nullptr;
}

/// <summary>
/// Leet code #501. Find Mode in Binary Search Tree         
/// </summary>
void LeetCodeTree::findMode(TreeNode* root, unordered_map<int, int>& node_map, map<int, unordered_set<int>> &frequency)
{
    if (root == nullptr) return;
    if (node_map.count(root->val) > 0)
    {
        frequency[node_map[root->val]].erase(root->val);
    }
    node_map[root->val]++;
    frequency[node_map[root->val]].insert(root->val);
    findMode(root->left, node_map, frequency);
    findMode(root->right, node_map, frequency);
}

/// <summary>
/// Leet code #501. Find Mode in Binary Search Tree         
/// 
/// Given a binary search tree (BST) with duplicates, find all the mode(s) 
/// (the most frequently occurred element) in the given BST.
///
/// Assume a BST is defined as follows:
/// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
/// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
/// Both the left and right subtrees must also be binary search trees.
/// For example:
/// Given BST [1,null,2,2],
///
///   1
///    \
///     2
///    /
///   2
/// return [2]. 
/// Note: If a tree has more than one mode, you can return them in any order. 
/// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space 
/// incurred due to recursion does not count). 
/// </summary>
vector<int> LeetCodeTree::findMode(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr) return result;

    unordered_map<int, int> node_map;
    map<int, unordered_set<int>> frequency;
    findMode(root, node_map, frequency);

    map<int, unordered_set<int>>::reverse_iterator itr = frequency.rbegin();
    for (auto value : itr->second)
    {
        result.push_back(value);
    }
    return result;
}

/// <summary>
/// Leet code #508. Most Frequent Subtree Sum          
/// </summary>
int LeetCodeTree::findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& sum_map, map<int, unordered_set<int>> &frequency)
{
    int sum = root->val;
    if (root->left != nullptr)
    {
        sum += findFrequentTreeSum(root->left, sum_map, frequency);
    }
    if (root->right != nullptr)
    {
        sum += findFrequentTreeSum(root->right, sum_map, frequency);
    }
    if (sum_map.count(sum) > 0)
    {
        frequency[sum_map[sum]].erase(sum);
    }
    sum_map[sum]++;
    frequency[sum_map[sum]].insert(sum);
    return sum;
}

/// <summary>
/// Leet code #508. Most Frequent Subtree Sum          
/// 
/// Given the root of a tree, you are asked to find the most frequent subtree sum. 
/// The subtree sum of a node is defined as the sum of all the node values formed 
/// by the subtree rooted at that node (including the node itself). So what is 
/// the most frequent subtree sum value? If there is a tie, return all the 
/// values with the highest frequency in any order. 
///
/// Examples 1
/// Input: 
///   5
///  /  \
/// 2   -3
/// return [2, -3, 4], since all the values happen only once, return all of them in any order. 
///
/// Examples 2
/// Input: 
///   5
///  /  \
/// 2   -5
/// return [2], since 2 happens twice, however -5 only occur once. 
/// Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer. 
/// </summary>
vector<int> LeetCodeTree::findFrequentTreeSum(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr) return result;

    unordered_map<int, int> sum_map;
    map<int, unordered_set<int>> frequency;
    findFrequentTreeSum(root, sum_map, frequency);
    map<int, unordered_set<int>>::reverse_iterator itr = frequency.rbegin();
    for (auto value : itr->second)
    {
        result.push_back(value);
    }
    return result;
}

/// <summary>
/// Leet code #515. Find Largest Value in Each Tree Row         
/// 
/// You need to find the largest value in each row of a binary tree. 
/// Example:
///
/// Input: 
///
///          1
///         / \
///        3   2
///       / \   \  
///      5   3   9 
///
/// Output: [1, 3, 9]
/// </summary>
vector<int> LeetCodeTree::largestValues(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        int max_value = INT_MIN;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            max_value = max(max_value, node->val);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        result.push_back(max_value);
    }
    return result;
}

/// <summary>
/// Leet code #513. Find Bottom Left Tree Value         
/// 
/// Given a binary tree, find the leftmost value in the last row of the tree. 
/// Example 1:
///
/// Input: 
///    2
///   / \
///  1   3
///
/// Output:
/// 1
///
/// Example 2: 
/// Input:
///
///        1
///       / \
///      2   3
///     /   / \
///    4   5   6
///       /
///      7
///
/// Output:
/// 7
/// Note: You may assume the tree (i.e., the given root node) is not NULL. 
/// </summary>
int LeetCodeTree::findBottomLeftValue(TreeNode* root)
{
    int result = 0;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        bool first = true;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if (first == true)
            {
                first = false;
                result = node->val;
            }
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #270. Closest Binary Search Tree Value    
/// 
/// Given a non-empty binary search tree and a target value, find the 
/// value in the BST that is closest to the target. 
/// Note:
/// Given target value is a floating point.
/// You are guaranteed to have only one unique value in the BST that is closest to the target.
/// </summary>
int LeetCodeTree::closestValue(TreeNode* root, double target)
{
    TreeNode * left = nullptr, *right = nullptr;
    TreeNode * node = root;
    while (node != nullptr)
    {
        if (target < node->val)
        {
            right = node;
            node = node->left;
        }
        else if (target > node->val)
        {
            left = node;
            node = node->right;
        }
        else
        {
            return node->val;
        }
    }

    int result = 0;
    if (left == nullptr && right == nullptr)
    {
        return result;
    }

    if (left == nullptr && right != nullptr)
    {
        result = right->val;
    }
    else if (right == nullptr && left != nullptr)
    {
        result = left->val;
    }
    else if (target - left->val < right->val - target)
    {
        result = left->val;
    }
    else
    {
        result = right->val;
    }
    return result;
}

/// <summary>
/// Leet code #272. Closest Binary Search Tree Value II   
/// </summary>
vector<int> LeetCodeTree::getPredecessor(stack<TreeNode*> left_stack, int k)
{
    vector<int> result;
    while (!left_stack.empty())
    {
        TreeNode * node = left_stack.top();
        left_stack.pop();
        result.push_back(node->val);

        if (result.size() == k) break;
        node = node->left;
        while (node != nullptr)
        {
            left_stack.push(node);
            node = node->right;
        }
    }
    return result;
}

/// <summary>
/// Leet code #272. Closest Binary Search Tree Value II   
/// </summary>
vector<int> LeetCodeTree::getSuccessor(stack<TreeNode*> right_stack, int k)
{
    vector<int> result;
    while (!right_stack.empty())
    {
        TreeNode * node = right_stack.top();
        right_stack.pop();
        result.push_back(node->val);

        if (result.size() == k) break;
        node = node->right;
        while (node != nullptr)
        {
            right_stack.push(node);
            node = node->left;
        }
    }
    return result;
}

/// <summary>
/// Leet code #272. Closest Binary Search Tree Value II   
/// 
/// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target. 
/// Note:
/// Given target value is a floating point.
/// You may assume k is always valid, that is: k ≤ total nodes.
/// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
/// Follow up:
/// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)? 
/// Hint:
/// 1.Consider implement these two helper functions: 
/// i.getPredecessor(N), which returns the next smaller node to N.
/// ii.getSuccessor(N), which returns the next larger node to N.
/// 2.Try to assume that each node has a parent pointer, it makes the problem much easier.
/// 3.Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
/// 4.You would need two stacks to track the path in finding predecessor and successor node separately.
/// </summary>
vector<int> LeetCodeTree::closestKValues(TreeNode* root, double target, int k)
{
    vector<int> result;
    stack<TreeNode*> left_stack;
    stack<TreeNode*> right_stack;
    TreeNode *node = root;
    while (node != nullptr)
    {
        if (target <= node->val)
        {
            right_stack.push(node);
            node = node->left;
        }
        else if (target > node->val)
        {
            left_stack.push(node);
            node = node->right;
        }
    }
    vector<int> left_values = getPredecessor(left_stack, k);
    vector<int> right_values = getSuccessor(right_stack, k);
    int left_index = 0, right_index = 0;
    while (left_index < (int)left_values.size() || right_index < (int)right_values.size())
    {
        if (result.size() == k) break;
        if (left_index == left_values.size())
        {
            result.push_back(right_values[right_index]);
            right_index++;
        }
        else if (right_index == right_values.size())
        {
            result.push_back(left_values[left_index]);
            left_index++;
        }
        else if (abs(left_values[left_index] - target) < abs(right_values[right_index] - target))
        {
            result.push_back(left_values[left_index]);
            left_index++;
        }
        else
        {
            result.push_back(right_values[right_index]);
            right_index++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #530. Minimum Absolute Difference in BST 
/// </summary>
int LeetCodeTree::getMinimumDifference(TreeNode* root, vector<int>& inorderList)
{
    int min_absolute = INT_MAX;
    if (root == nullptr) return min_absolute;
    vector<int> nodeList;
    if (root->left != nullptr)
    {
        min_absolute = min(min_absolute, getMinimumDifference(root->left, inorderList));
        min_absolute = min(min_absolute, root->val - inorderList.back());
    }
    inorderList.push_back(root->val);
    int size = inorderList.size();
    if (root->right != nullptr)
    {
        min_absolute = min(min_absolute, getMinimumDifference(root->right, inorderList));
        min_absolute = min(min_absolute, inorderList[size] - root->val);
    }
    return min_absolute;
}

/// <summary>
/// Leet code #530. Minimum Absolute Difference in BST 
///
/// Given a binary search tree with non-negative values, find the 
/// minimum absolute difference between values of any two nodes.
/// 
/// Example:
///
/// Input:
///
///   1
///    \
///     3
///    /
///   2
///
/// Output:
/// 1
///
/// Explanation:
/// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
/// Note: There are at least two nodes in this BST.
/// </summary>
int LeetCodeTree::getMinimumDifference(TreeNode* root)
{
    vector<int> inorderList;
    return getMinimumDifference(root, inorderList);
}

/// <summary>
/// Leet code #536. Construct Binary Tree from String
/// </summary>
TreeNode* LeetCodeTree::str2tree(string s, size_t& index)
{
    TreeNode * root = nullptr;
    string str;
    while (index < s.size() && ((s[index] == '-') || isdigit(s[index])))
    {
        str.push_back(s[index]);
        index++;
    }
    if (!str.empty())
    {
        root = new TreeNode(atoi(str.c_str()));
        str.clear();
    }
    if (root != nullptr)
    {
        if (index < s.size() && s[index] == '(')
        {
            index++;
            root->left = str2tree(s, index);
        }
        if (index < s.size() && s[index] == '(')
        {
            index++;
            root->right = str2tree(s, index);
        }
    }
    if (index < s.size() && s[index] == ')')
    {
        index++;
    }
    return root;
}

/// <summary>
/// Leet code #536. Construct Binary Tree from String
///
/// You need to construct a binary tree from a string consisting 
/// of parenthesis and integers.
/// The whole input represents a binary tree. It contains an 
/// integer followed by zero, one or two pairs of parenthesis. 
/// The integer represents the root's value and a pair of parenthesis 
/// contains a child binary tree with the same structure.
/// 
/// You always start to construct the left child node of the parent 
/// first if it exists.
///
/// Example:
/// Input: "4(2(3)(1))(6(5))"
/// Output: return the tree root node representing the following tree:
///       4
///     /   \
///    2     6
///   / \   / 
///  3   1 5   
/// Note:
/// There will only be '(', ')', '-' and '0' ~ '9' in the input string.
/// An empty tree is represented by "" instead of "()".
/// </summary>
TreeNode* LeetCodeTree::str2tree(string s)
{
    size_t index = 0;
    return str2tree(s, index);
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// </summary>
void LeetCodeTree::findLeftBoundary(TreeNode* root, vector<int> &leftBoundary)
{
    if (root == nullptr) return;
    leftBoundary.push_back(root->val);
    if (root->left != nullptr)
    {
        findLeftBoundary(root->left, leftBoundary);
    }
    else if (root->right != nullptr)
    {
        findLeftBoundary(root->right, leftBoundary);
    }
    return;
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// </summary>
void LeetCodeTree::findRightBoundary(TreeNode* root, vector<int> &rightBoundary)
{
    if (root == nullptr) return;
    rightBoundary.push_back(root->val);
    if (root->right != nullptr)
    {
        findRightBoundary(root->right, rightBoundary);
    }
    else if (root->left != nullptr)
    {
        findRightBoundary(root->left, rightBoundary);
    }
    return;
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// </summary>
void LeetCodeTree::findLeaves(TreeNode* root, vector<int> &leaves)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        leaves.push_back(root->val);
    }
    if (root->left != nullptr)
    {
        findLeaves(root->left, leaves);
    }
    if (root->right != nullptr)
    {
        findLeaves(root->right, leaves);
    }
    return;
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// 
/// Given a binary tree, return the values of its boundary in 
/// anti-clockwise direction starting from root. Boundary includes left 
/// boundary, leaves, and right boundary in order without duplicate nodes.
/// Left boundary is defined as the path from root to the left-most node. 
/// Right boundary is defined as the path from root to the right-most 
/// node. If the root doesn't have left subtree or right subtree, then 
/// the root itself is left boundary or right boundary. 
/// Note this definition only applies to the input binary tree, 
/// and not applies to any subtrees.
/// The left-most node is defined as a leaf node you could reach when you 
/// always firstly travel to the left subtree if exists. If not, travel to 
/// the right subtree. Repeat until you reach a leaf node.
///
/// The right-most node is also defined by the same way with left and right exchanged.
/// 
/// Example 1
/// Input:
///  1
///   \
///    2 
///   / \
///  3   4
///
/// Ouput:
/// [1, 3, 4, 2]
///
/// Explanation:
/// The root doesn't have left subtree, so the root itself is left boundary.
/// The leaves are node 3 and 4.
/// The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
/// So order them in anti-clockwise without duplicates and we have [1,3,4,2].
/// Example 2
/// Input:
///     ____1_____
///    /          \
///   2            3
///  / \          / 
/// 4   5        6   
///    / \      / \
///   7   8    9  10  
/// Ouput:
/// [1,2,4,7,8,9,10,6,3]
///
/// Explanation:
/// The left boundary are node 1,2,4. (4 is the left-most node according to definition)
/// The leaves are node 4,7,8,9,10.
/// The right boundary are node 1,3,6,10. (10 is the right-most node).
/// So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
/// </summary>
vector<int> LeetCodeTree::boundaryOfBinaryTree(TreeNode* root)
{
    vector<int> leftBoundary;
    vector<int> rightBoundary;
    vector<int> leaves;
    vector<int> result;
    if (root == nullptr) return result;
    if (root->left != nullptr)
    {
        findLeftBoundary(root->left, leftBoundary);
    }
    if (root->right != nullptr)
    {
        findRightBoundary(root->right, rightBoundary);
    }
    findLeaves(root, leaves);
    if (root->left != nullptr || root->right != nullptr) result.push_back(root->val);
    for (int i = 0; i < (int)leftBoundary.size() - 1; i++)
    {
        result.push_back(leftBoundary[i]);
    }
    // skip left most and right most leaves
    for (int i = 0; i < (int)leaves.size(); i++)
    {
        result.push_back(leaves[i]);
    }
    for (int i = rightBoundary.size() - 2; i >= 0; i--)
    {
        result.push_back(rightBoundary[i]);
    }
    return result;
}

/// <summary>
/// Leet code #543. Diameter of Binary Tree       
/// </summary>
void LeetCodeTree::diameterOfBinaryTree(TreeNode* root, int &max_depth, int &diameter)
{
    max_depth = 0;
    diameter = 0;
    if (root != nullptr)
    {
        int left_max_depth = 0, left_diameter = 0;
        if (root->left != nullptr)
        {
            diameterOfBinaryTree(root->left, left_max_depth, left_diameter);
            left_max_depth++;

        }
        int right_max_depth = 0, right_diameter = 0;
        if (root->right != nullptr)
        {
            diameterOfBinaryTree(root->right, right_max_depth, right_diameter);
            right_max_depth++;
        }
        max_depth = max(left_max_depth, right_max_depth);
        diameter = max(left_diameter, right_diameter);
        diameter = max(diameter, left_max_depth + right_max_depth);
    }
}

/// <summary>
/// Leet code #543. Diameter of Binary Tree       
/// 
/// Given a binary tree, you need to compute the length of the diameter of 
/// the tree. The diameter of a binary tree is the length of the longest 
/// path between any two nodes in a tree. This path may or may not pass 
/// through the root.
/// Example:
/// Given a binary tree 
///      1
///     / \
///    2   3
///   / \     
///  4   5    
/// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
/// Note: The length of path between two nodes is represented by the 
/// number of edges between them.
/// </summary>
int LeetCodeTree::diameterOfBinaryTree(TreeNode* root)
{
    int max_depth, diameter;
    diameterOfBinaryTree(root, max_depth, diameter);
    return diameter;
}

/// <summary>
/// Leet code #538. Convert BST to Greater Tree       
/// </summary>
TreeNode* LeetCodeTree::convertBST(TreeNode* root, int &sum)
{
    if (root == nullptr) return root;
    TreeNode * new_root = new TreeNode(0);
    if (root->left == nullptr && root->right == nullptr)
    {
        new_root->val = root->val + sum;
        sum = new_root->val;
        return new_root;
    }
    if (root->right != nullptr)
    {
        new_root->right = convertBST(root->right, sum);
    }
    new_root->val = root->val + sum;
    sum = new_root->val;
    if (root->left != nullptr)
    {
        new_root->left = convertBST(root->left, sum);
    }
    return new_root;
}

/// <summary>
/// Leet code #538. Convert BST to Greater Tree       
/// 
/// Given a Binary Search Tree (BST), convert it to a Greater Tree such 
/// that every key of the original BST is changed to the original key plus
/// sum of all keys greater than the original key in BST.
/// 
/// Example:
/// Input: The root of a Binary Search Tree like this:
///          5
///        /   \
///       2     13
/// Output: The root of a Greater Tree like this:
///         18
///        /  \
///      20    13
/// </summary>
TreeNode* LeetCodeTree::convertBST(TreeNode* root)
{
    int sum = 0;
    return convertBST(root, sum);
}

/// <summary>
/// Leet code #549. Binary Tree Longest Consecutive Sequence II  
/// </summary>
int LeetCodeTree::longestConsecutiveII(TreeNode* root, int& asc_size, int& desc_size)
{
    if (root == nullptr)
    {
        asc_size = 0;
        desc_size = 0;
        return 0;
    }

    // parse left sub stree
    int left_asc_size, left_desc_size;
    int left_max_size = longestConsecutiveII(root->left, left_asc_size, left_desc_size);
    // if value is decreasing
    if (root->left == nullptr)
    {
        left_asc_size = 1;
        left_desc_size = 1;
    }
    else if (root->val == root->left->val - 1)
    {
        left_asc_size = 1;
        left_desc_size++;
    }
    // if value is increasing
    else if (root->val == root->left->val + 1)
    {
        left_desc_size = 1;
        left_asc_size++;
    }
    else
    {
        left_asc_size = 1;
        left_desc_size = 1;
    }

    // parse right sub stree
    int right_asc_size, right_desc_size;
    int right_max_size = longestConsecutiveII(root->right, right_asc_size, right_desc_size);
    if (root->right == nullptr)
    {
        right_asc_size = 1;
        right_desc_size = 1;
    }
    else if (root->val == root->right->val - 1)
    {
        right_asc_size = 1;
        right_desc_size++;
    }
    else if (root->val == root->right->val + 1)
    {
        right_desc_size = 1;
        right_asc_size++;
    }
    else
    {
        right_asc_size = 1;
        right_desc_size = 1;
    }
    asc_size = max(left_asc_size, right_asc_size);
    desc_size = max(left_desc_size, right_desc_size);
    int max_path_size = max(left_max_size, right_max_size);
    max_path_size = max(max_path_size, (left_asc_size + right_desc_size - 1));
    max_path_size = max(max_path_size, (right_asc_size + left_desc_size - 1));
    return max_path_size;
}

/// <summary>
/// Leet code #549. Binary Tree Longest Consecutive Sequence II  
/// 
/// Given a binary tree, you need to find the length of Longest 
/// Consecutive Path in Binary Tree. 
/// Especially, this path can be either increasing or decreasing. 
/// For example, [1,2,3,4] and [4,3,2,1] are both considered valid, 
/// but the path [1,2,4,3] is not valid. On the other hand, the path 
/// can be in the child-Parent-child order, where not necessarily be 
/// parent-child order.
/// Example 1:
/// Input:
///        1
///       / \
///      2   3
/// Output: 2
/// Explanation: The longest consecutive path is [1, 2] or [2, 1].
/// Example 2:
/// Input:
///        2
///       / \
///      1   3
/// Output: 3
/// Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
/// </summary>
int LeetCodeTree::longestConsecutiveII(TreeNode* root)
{
    int asc_size, desc_size;
    return longestConsecutiveII(root, asc_size, desc_size);
}

/// <summary>
/// Leet code #563. Binary Tree Tilt      
/// </summary>
int LeetCodeTree::findTilt(TreeNode* root, int& sum)
{
    int tilt = 0;
    if (root == nullptr)
    {
        sum = 0;
        return 0;
    }

    int left_sum;
    tilt += findTilt(root->left, left_sum);

    int right_sum;
    tilt += findTilt(root->right, right_sum);

    sum = root->val + left_sum + right_sum;
    tilt += abs(left_sum - right_sum);
    return tilt;
}

/// <summary>
/// Leet code #563. Binary Tree Tilt      
/// 
/// Given a binary tree, return the tilt of the whole tree. 
/// The tilt of a tree node is defined as the absolute difference 
/// between the sum of all left subtree node values and the sum of 
/// all right subtree node values. Null node has tilt 0.
///
/// The tilt of the whole tree is defined as the sum of all nodes' tilt.
///
/// Example:
/// Input: 
///         1
///       /   \
///      2     3
/// Output: 1
/// Explanation: 
/// Tilt of node 2 : 0
/// Tilt of node 3 : 0
/// Tilt of node 1 : |2-3| = 1
/// Tilt of binary tree : 0 + 0 + 1 = 1
/// Note:
/// The sum of node values in any subtree won't exceed the range of 
/// 32-bit integer.
/// All the tilt values won't exceed the range of 32-bit integer.
/// </summary>
int LeetCodeTree::findTilt(TreeNode* root)
{
    int sum;
    return findTilt(root, sum);
}

/// <summary>
/// Leet code #572. Subtree of Another Tree       
/// </summary>
void LeetCodeTree::preOrderTraversal(TreeNode* root, string &result)
{
    result.push_back(',');
    if (root == nullptr)
    {
        result.append("null");
    }
    else
    {
        result.append(to_string(root->val));
        preOrderTraversal(root->left, result);
        preOrderTraversal(root->right, result);
    }
}

/// <summary>
/// Leet code #572. Subtree of Another Tree       
/// 
/// Given two non-empty binary trees s and t, check whether tree t has 
/// exactly the same structure and node values with a subtree of s. 
/// A subtree of s is a tree consists of a node in s and all of this 
/// node's descendants. The tree s could also be considered as a subtree 
/// of itself.
/// Example 1:
/// Given tree s:
///      3
///     / \
///    4   5
///   / \
///  1   2
/// Given tree t:
///    4 
///   / \
///  1   2
/// Return true, because t has the same structure and node values with a subtree of s.
/// Example 2:
/// Given tree s:
///     3
///    / \
///   4   5
///  / \
/// 1   2
///    /
///   0
/// Given tree t:
///   4
///  / \
/// 1   2
/// Return false.
/// </summary>
bool LeetCodeTree::isSubtree(TreeNode* s, TreeNode* t)
{
    string str_s, str_t;
    preOrderTraversal(s, str_s);
    preOrderTraversal(t, str_t);
    if (strstr(str_s.c_str(), str_t.c_str()) == nullptr) return false;

    return true;
}

/// <summary>
/// Leet code #606. Construct String from Binary Tree
/// 
/// You need to construct a string consists of parenthesis and integers 
/// from a binary tree with the preorder traversing way.
/// The null node needs to be represented by empty parenthesis pair "()". 
/// And you need to omit all the empty parenthesis pairs that don't affect 
/// the one-to-one mapping relationship between the string and the original 
/// binary tree.
///
/// Example 1:
/// Input: Binary tree: [1,2,3,4]
///       1
///     /   \
///    2     3
///   /    
///  4     
/// Output: "1(2(4))(3)"
/// Explanation: Originallay it needs to be "1(2(4)())(3()())", 
/// but you need to omit all the unnecessary empty parenthesis pairs. 
/// And it will be "1(2(4))(3)".
///
/// Example 2:
/// Input: Binary tree: [1,2,3,null,4]
///       1
///     /   \
///    2     3
///     \  
///      4 
/// Output: "1(2()(4))(3)"
/// Explanation: Almost the same as the first example, except we can't 
/// omit the first parenthesis pair to break the one-to-one mapping 
/// relationship between the input and the output.
/// </summary>
string LeetCodeTree::tree2str(TreeNode* t)
{
    string result;
    if (t == nullptr)
    {
        return result;
    }
    result = to_string(t->val);
    if (t->left != nullptr)
    {
        result += "(" + tree2str(t->left) + ")";
    }
    else if (t->right != nullptr)
    {
        result += "()";
    }

    if (t->right != nullptr)
    {
        result += "(" + tree2str(t->right) + ")";
    }
    return result;
}

/// <summary>
/// Leet code 617. Merge Two Binary Trees
/// 
/// Given two binary trees and imagine that when you put one of them to 
/// cover the other, some nodes of the two trees are overlapped while the 
/// others are not. 
/// You need to merge them into a new binary tree. The merge rule is that 
/// if two nodes overlap, then sum node values up as the new value of the 
/// merged node. Otherwise, the NOT null node will be used as the node of 
/// new tree. 
/// Example 1:
/// Input: 
///	Tree 1                    Tree 2                  
///          1                         2                             
///         / \                       / \                            
///        3   2                     1   3                        
///       /                           \   \                      
///      5                             4   7                  
/// Output: 
/// Merged tree:
///      3
///     / \
///    4   5
///   / \   \ 
///  5   4   7
///
/// Note: The merging process must start from the root nodes of both trees.
/// </summary>
TreeNode* LeetCodeTree::mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if ((t1 == nullptr) && (t2 == nullptr))
    {
        return nullptr;
    }

    int value = 0;
    TreeNode *left_t1 = nullptr, *left_t2 = nullptr;
    TreeNode *right_t1 = nullptr, *right_t2 = nullptr;

    if (t1 != nullptr)
    {
        value += t1->val;
        left_t1 = t1->left;
        right_t1 = t1->right;
    }
    if (t2 != nullptr)
    {
        value += t2->val;
        left_t2 = t2->left;
        right_t2 = t2->right;
    }

    TreeNode * node = new TreeNode(value);
    node->left = mergeTrees(left_t1, left_t2);
    node->right = mergeTrees(right_t1, right_t2);

    return node;
}

/// <summary>
/// Leet code #623. Add One Row to Tree 
/// </summary>
TreeNode* LeetCodeTree::addOneRow(TreeNode* node, int v, int depth, int target_depth)
{
    if (target_depth == depth)
    {
        TreeNode * root = new TreeNode(v);
        root->left = node;
        return root;
    }
    else if (node == nullptr)
    {
        return node;
    }
    else if (depth == target_depth - 1)
    {
        TreeNode * left_node = new TreeNode(v);
        left_node->left = node->left;
        node->left = left_node;

        TreeNode * right_node = new TreeNode(v);
        right_node->right = node->right;
        node->right = right_node;
        return node;
    }
    else
    {
        addOneRow(node->left, v, depth + 1, target_depth);
        addOneRow(node->right, v, depth + 1, target_depth);
        return node;
    }
}

/// <summary>
/// Leet code #623. Add One Row to Tree 
/// 
/// Given the root of a binary tree, then value v and depth d, you need to 
/// add a row of nodes with value v at the given depth d. The root node is 
/// at depth 1. 
///
/// The adding rule is: given a positive integer depth d, for each NOT null 
/// tree nodes N in depth d-1, create two tree nodes with value v as N's 
/// left subtree root and right subtree root. And N's original left subtree 
/// should be the left subtree of the new left subtree root, its original 
/// right subtree should be the right subtree of the new right subtree 
/// root. If depth d is 1 that means there is no depth d-1 at all, then 
/// create a tree node with value v as the new root of the whole original 
/// tree, and the original tree is the new root's left subtree.
///
/// Example 1:
/// Input: 
/// A binary tree as following:
///       4
///     /   \
///    2     6
///   / \   / 
///  3   1 5   
///
/// v = 1
/// d = 2
///
/// Output: 
///       4
///      / \
///     1   1
///    /     \
///   2       6
///  / \     / 
/// 3   1   5   
///
/// Example 2:
/// Input: 
/// A binary tree as following:
///      4
///     /   
///    2    
///   / \   
///  3   1    
///
/// v = 1
/// d = 3
///
/// Output: 
///       4
///      /   
///     2
///    / \    
///   1   1
///  /     \  
/// 3       1
///
///
///
/// Note:
///
/// 1.The given d is in range [1, maximum depth of the given tree + 1].
/// 2.The given binary tree has at least one tree node.
/// </summary>
TreeNode* LeetCodeTree::addOneRow(TreeNode* root, int v, int d)
{
    return addOneRow(root, v, 1, d);
}

/// <summary>
/// Leet code #637. Average of Levels in Binary Tree 
/// 
/// Given a non-empty binary tree, return the average value of the nodes on 
/// each level in the form of an array. 
/// Example 1:
/// Input:
///     3
///    / \
///   9  20
///     /  \
///    15   7
/// Output: [3, 14.5, 11]
/// Explanation:
/// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on 
/// level 2 is 11. Hence return [3, 14.5, 11].
/// 
/// Note:
/// The range of node's value is in the range of 32-bit signed integer.
/// </summary>
vector<double> LeetCodeTree::averageOfLevels(TreeNode* root)
{
    vector<double> result;
    queue<TreeNode *> process_queue;
    if (root != nullptr) process_queue.push(root);

    while (!process_queue.empty())
    {
        double sum = 0;
        size_t size = process_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = process_queue.front();
            process_queue.pop();
            sum += node->val;
            if (node->left != nullptr) process_queue.push(node->left);
            if (node->right != nullptr) process_queue.push(node->right);
        }
        result.push_back(sum / size);
    }

    return result;
}

/// <summary>
/// Leet code #652. Find Duplicate Subtrees
/// </summary>
string LeetCodeTree::findDuplicateSubtrees(TreeNode* root, unordered_map<string, vector<TreeNode*>> &cache)
{
    // The starting , is to avoid partial match, for example [8, null, null] mapping to [18, null, null]
    string traverse = ",";
    if (root == nullptr)
    {
        traverse.append("null");
        return traverse;
    }
    traverse.append(to_string(root->val));
    string sub_tree = findDuplicateSubtrees(root->left, cache);
    traverse.append(sub_tree);
    sub_tree = findDuplicateSubtrees(root->right, cache);
    traverse.append(sub_tree);
    cache[traverse].push_back(root);
    return traverse;
}

/// <summary>
/// Leet code #652. Find Duplicate Subtrees
/// 
/// Given a binary tree, return all duplicate subtrees. For each kind of 
/// duplicate subtrees, you only need to return the root node of any one 
/// of them.
///
/// Two trees are duplicate if they have the same structure with same node 
/// values.
///
/// Example 1: 
///        1
///       / \
///      2   3
///     /   / \
///    4   2   4
///       /
///      4
/// The following are two duplicate subtrees:
///      2
///     /
///    4
/// and
///    4
/// Therefore, you need to return above trees' root in the form of a list.
/// </summary>
vector<TreeNode*> LeetCodeTree::findDuplicateSubtrees(TreeNode* root)
{
    vector<TreeNode*> result;
    unordered_map<string, vector<TreeNode*>> cache;
    string subTree = findDuplicateSubtrees(root, cache);
    for (auto subtree : cache)
    {
        if (subtree.second.size() > 1)
        {
            result.push_back(subtree.second[0]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #653. Two Sum IV - Input is a BST
/// </summary>
bool LeetCodeTree::findTarget(TreeNode* root, unordered_set<int> &hash_table, int k)
{
    if (root == nullptr) return false;
    if (hash_table.count(k - root->val) > 0) return true;
    hash_table.insert(root->val);
    if (findTarget(root->left, hash_table, k)) return true;
    return  (findTarget(root->right, hash_table, k));
}

/// <summary>
/// Leet code #653. Two Sum IV - Input is a BST
/// 
/// Given a Binary Search Tree and a target number, return true if there 
/// exist two elements in the BST such that their sum is equal to the given 
/// target.
///
/// Example 1:
/// Input: 
///     5
///    / \
///   3   6
///  / \   \
/// 2   4   7
/// 
///
/// Target = 9
///
/// Output: True
///
/// Example 2:
/// Input: 
///     5
///    / \
///   3   6
///  / \   \
/// 2   4   7
///
/// Target = 28
///
/// Output: False
/// </summary>
bool LeetCodeTree::findTarget(TreeNode* root, int k)
{
    unordered_set<int> hash_table;
    return findTarget(root, hash_table, k);
}

/// <summary>
/// Leet code #654. Maximum Binary Tree
/// </summary>
void LeetCodeTree::constructMaximumBinaryTree(TreeNode* &root, int val)
{
    if (root == nullptr || root->val < val)
    {
        TreeNode* left = root;
        root = new TreeNode(val);
        root->left = left;
    }
    else if (root->val > val)
    {
        constructMaximumBinaryTree(root->right, val);
    }
}


/// <summary>
/// Leet code #654. Maximum Binary Tree
/// 
/// Given an integer array with no duplicates. A maximum tree building on 
/// this array is defined as follow:
///
/// The root is the maximum number in the array.
/// The left subtree is the maximum tree constructed from left part 
/// subarray divided by the maximum number.
/// The right subtree is the maximum tree constructed from right part 
/// subarray divided by the maximum number.
/// Construct the maximum tree by the given array and output the root node 
/// of this tree.
///
/// Example 1:
/// Input: [3,2,1,6,0,5]
/// Output: return the tree root node representing the following tree:
///
///      6
///    /   \
///   3     5
///    \    /  
///     2  0   
///      \
///       1
/// Note:
/// 1. The size of the given array will be in the range [1,1000].
/// </summary>
TreeNode* LeetCodeTree::constructMaximumBinaryTree(vector<int>& nums)
{
    TreeNode * root = nullptr;
    for (int val : nums)
    {
        constructMaximumBinaryTree(root, val);
    }
    return root;
}

/// <summary>
/// Leet code #655. Print Binary Tree
/// </summary>
void LeetCodeTree::printTree(TreeNode* root, vector<vector<string>> &matrix, 
    int row, int col, int window)
{
    if (root == nullptr) return;
    matrix[row][col] = to_string(root->val);
    window = (window - 1) / 2;
    if (window >= 0)
    {
        printTree(root->left, matrix, row + 1, col - window - 1, window);
        printTree(root->right, matrix, row + 1, col + window + 1, window);
    }
}

/// <summary>
/// Leet code #655. Print Binary Tree
/// 
/// Print a binary tree in an m*n 2D string array following these rules: 
/// The row number m should be equal to the height of the given binary 
/// tree.
/// The column number n should always be an odd number.
/// The root node's value (in string format) should be put in the exactly 
/// middle of the first row it can be put. The column and the row where 
/// the root node belongs will separate the rest space into two parts 
/// (left-bottom part and right-bottom part). You should print the left 
/// subtree in the left-bottom part and print the right subtree in the 
/// right-bottom part. The left-bottom part and the right-bottom part 
/// should have the same size. Even if one subtree is none while the other 
/// is not, you don't need to print anything for the none subtree but 
/// still need to leave the space as large as that for the other subtree. 
/// However, if two subtrees are none, then you don't need to leave space 
/// for both of them.
/// Each unused space should contain an empty string "". 
/// Print the subtrees following the same rules.
/// Example 1:
/// Input:
///     1
///    /
///   2
/// Output:
/// [["", "1", ""],
/// ["2", "", ""]]
///
/// Example 2:
/// Input:
///     1
///    / \
///   2   3
///    \
///     4
/// Output:
/// [["", "", "", "1", "", "", ""],
/// ["", "2", "", "", "", "3", ""],
/// ["", "", "4", "", "", "", ""]]
///
/// Example 3:
/// Input:
///       1
///      / \
///     2   5
///    / 
///   3 
///  / 
/// 4 
/// Output:
///
/// [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
/// ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
/// ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
/// ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
/// 1. Note: The height of binary tree is in the range of [1, 10].
/// </summary>
vector<vector<string>> LeetCodeTree::printTree(TreeNode* root)
{
    int rows = maxDepth(root);
    int columns = (int)pow(2, rows) - 1;
    vector<vector<string>> result(rows, vector<string>(columns, ""));

    printTree(root, result, 0, 0 + columns / 2, columns / 2);
    return result;
}

/// <summary>
/// Leet code #663. Equal Tree Partition 
/// </summary>
int LeetCodeTree::checkEqualTree(TreeNode* root, unordered_map<int, int> &sub_sum)
{
    if (root == nullptr) return 0;
    int sum = 0;
    sum += checkEqualTree(root->left, sub_sum);
    sum += checkEqualTree(root->right, sub_sum);
    sum += root->val;
    sub_sum[sum]++;
    return sum;
}

/// <summary>
/// Leet code #663. Equal Tree Partition 
/// 
/// Given a binary tree with n nodes, your task is to check if it's 
/// possible to partition the tree to two trees which have the equal sum 
/// of values after removing exactly one edge on the original tree. 
/// Example 1:
/// Input:     
///    5
///   / \
///  10 10
///    /  \
///   2    3
///
/// Output: True    
/// Explanation: 
///    5
///   / 
///  10
///      
/// Sum: 15
///
///   10
///  /  \
/// 2    3
///
/// Sum: 15
///
/// Example 2:
/// Input:     
///    1
///   / \
///  2  10
///    /  \
///   2   20
///
/// Output: False
/// Explanation: You can't split the tree into two trees with equal sum 
/// after removing exactly one edge on the tree.
///
/// Note:
/// 1. The range of tree node value is in the range of [-100000, 100000].
/// 2. 1 <= n <= 10000
/// </summary>
bool LeetCodeTree::checkEqualTree(TreeNode* root)
{
    unordered_map<int, int> sub_sum;
    int sum = checkEqualTree(root, sub_sum);
    if (sum % 2 != 0) return false;
    if (sum == 0 && sub_sum[sum] == 1) return false;
    if (sub_sum.count(sum / 2) == 0) return false;
    return true;
}

/// <summary>
/// Leet code #662. Maximum Width of Binary Tree 
/// 
/// Given a binary tree, write a function to get the maximum width of the 
/// given tree. The width of a tree is the maximum width among all levels. 
/// The binary tree has the same structure as a full binary tree, but some 
/// nodes are null. 
/// The width of one level is defined as the length between the end-nodes 
/// (the leftmost and right most non-null nodes in the level, where the 
/// null nodes between the end-nodes are also counted into the length 
/// calculation.
/// Example 1:
/// Input: 
///
///           1
///         /   \
///        3     2
///       / \     \  
///      5   3     9 
///
/// Output: 4
/// Explanation: The maximum width existing in the third level with the 
/// length 4 (5,3,null,9).
/// Example 2:
/// Input: 
///
///          1
///         /  
///        3    
///       / \       
///      5   3     
///
/// Output: 2
/// Explanation: The maximum width existing in the third level with the 
/// length 2 (5,3).
/// Example 3:
/// Input: 
///
///          1
///         / \
///        3   2 
///       /        
///      5      
///
/// Output: 2
/// Explanation: The maximum width existing in the second level with the 
/// length 2 (3,2).
/// Example 4:
/// Input: 
///
///          1
///         / \
///        3   2
///       /     \  
///      5       9 
///     /         \
///    6           7
/// Output: 8
/// Explanation:The maximum width existing in the fourth level with the 
/// length 8 (6,null,null,null,null,null,null,7).
///
/// Note: Answer will in the range of 32-bit signed integer. 
/// </summary>
int LeetCodeTree::widthOfBinaryTree(TreeNode* root)
{
    if (root == nullptr) return 0;
    queue<pair<TreeNode *, int>> process_queue;
    int width = 0;
    process_queue.push(make_pair(root, 0));
    while (!process_queue.empty())
    {
        size_t size = process_queue.size();
        int left = INT_MAX, right = INT_MIN;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = process_queue.front().first;
            int pos = process_queue.front().second;
            process_queue.pop();
            left = min(left, pos);
            right = max(right, pos);
            if (node->left != nullptr)
            {
                process_queue.push(make_pair(node->left, 2 * pos));
            }
            if (node->right != nullptr)
            {
                process_queue.push(make_pair(node->right, 2 * pos + 1));
            }
        }
        width = max(width, right - left + 1);
    }
    return width;
}

/// <summary>
/// Leet code #666. Path Sum IV 
/// </summary>
bool LeetCodeTree::pathSumIV(int level, int position, unordered_map<int, unordered_map<int, int>>& node_map, int &subtotal, int &sum)
{
    if (node_map.count(level) == 0 || node_map[level].count(position) == 0) return false;
    // add the current node;
    subtotal += node_map[level][position];
    // check if this is leaf
    bool left_child = pathSumIV(level + 1, 2 * position, node_map, subtotal, sum);
    bool right_child = pathSumIV(level + 1, 2 * position + 1, node_map, subtotal, sum);
    if (left_child == false && right_child == false)
    {
        sum += subtotal;
    }

    // rollback the current node
    subtotal -= node_map[level][position];
    return true;
}

/// <summary>
/// Leet code #666. Path Sum IV 
/// 
/// If the depth of a tree is smaller than 5, then this tree can be 
/// represented by a list of three-digits integers. 
/// For each integer in this list:
/// The hundreds digit represents the depth D of this node, 1 <= D <= 4.
/// The tens digit represents the position P of this node in the level it 
/// belongs to, 1 <= P <= 8. The position is the same as that in a full 
/// binary tree. 
/// The units digit represents the value V of this node, 0 <= V <= 9.
///
/// Given a list of ascending three-digits integers representing a binary 
/// with the depth smaller than 5. You need to return the sum of all paths 
/// from the root towards the leaves. 
/// Example 1:
/// Input: [113, 215, 221]
/// Output: 12
/// Explanation: 
/// The tree that the list represents is:
///    3
///   / \
///  5   1
///
/// The path sum is (3 + 5) + (3 + 1) = 12.
///
/// Example 2:
/// Input: [113, 221]
/// Output: 4
/// Explanation: 
/// The tree that the list represents is: 
///    3
///     \
///      1
///
/// The path sum is (3 + 1) = 4.
/// </summary>
int LeetCodeTree::pathSumIV(vector<int>& nums)
{
    unordered_map<int, unordered_map<int, int>> node_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        node_map[nums[i] / 100 - 1][(nums[i] % 100) / 10 - 1] = nums[i] % 10;
    }
    int subtotal = 0, sum = 0;
    pathSumIV(0, 0, node_map, subtotal, sum);
    return sum;
}

/// <summary>
/// Leet code #669. Trim a Binary Search Tree 
/// 
/// Given a binary search tree and the lowest and highest boundaries as L 
/// and R, trim the tree so that all its elements lies in [L, R] (R >= L). 
/// You might need to change the root of the tree, so the result should 
/// return the new root of the trimmed binary search tree.
///
/// Example 1:
/// Input: 
///    1
///   / \
///  0   2
///
///  L = 1
///  R = 2
///
/// Output: 
///    1
///      \
///       2
///
/// Example 2:
/// Input: 
///    3
///   / \
///  0   4
///   \
///    2
///   /
///  1
///
///  L = 1
///  R = 3
///
/// Output: 
///      3
///     / 
///   2   
///  /
/// 1
/// </summary>
TreeNode* LeetCodeTree::trimBST(TreeNode* root, int L, int R)
{
    TreeNode *result = nullptr;
    if (root == nullptr) return result;

    if (root->val < L)
    {
        result = trimBST(root->right, L, R);
    }
    else if (root->val > R)
    {
        result = trimBST(root->left, L, R);
    }
    else
    {
        result = new TreeNode(root->val);
        result->left = trimBST(root->left, L, R);
        result->right = trimBST(root->right, L, R);
    }
    return result;
}

/// <summary>
/// Leet code #671. Second Minimum Node In a Binary Tree 
/// </summary>
void LeetCodeTree::findSecondMinimumValue(TreeNode* root, set<int, greater<int>>&heap)
{
    if (root == nullptr) return;
    heap.insert(root->val);
    if (heap.size() > 2)
    {
        heap.erase(heap.begin());
    }
    findSecondMinimumValue(root->left, heap);
    findSecondMinimumValue(root->right, heap);
    return;
}

/// <summary>
/// Leet code #671. Second Minimum Node In a Binary Tree 
/// 
/// Given a non-empty special binary tree consisting of nodes with the 
/// non-negative value, where each node in this tree has exactly two or 
/// zero sub-node. If the node has two sub-nodes, then this node's value 
/// is the smaller value among its two sub-nodes.
/// 
/// Given such a binary tree, you need to output the second minimum value 
/// in the set made of all the nodes' value in the whole tree.
///
/// If no such second minimum value exists, output -1 instead.
///
/// Example 1:
/// Input: 
///    2
///   / \
///  2   5
///     / \
///    5   7
///
/// Output: 5
/// Explanation: The smallest value is 2, the second smallest value is 5.
/// Example 2:
/// Input: 
///    2
///   / \
///  2   2
///
/// Output: -1
/// Explanation: The smallest value is 2, but there isn't any second 
/// smallest value.
/// </summary>
int LeetCodeTree::findSecondMinimumValue(TreeNode* root)
{
    set<int, greater<int>> heap;
    findSecondMinimumValue(root, heap);
    if (heap.size() == 2) return (*heap.begin());
    else return -1;
}


/// <summary>
/// Leet code #687. Longest Univalue Path
/// </summary>
int LeetCodeTree::longestUnivaluePath(TreeNode* root, int &path_length)
{
    int result = 0;
    if (root == nullptr)
    {
        return 0;
    }
    path_length = 0;
    int max_left_path_size = 0;
    int left_path_size = 0;
    if (root->left != nullptr)
    {
        max_left_path_size = longestUnivaluePath(root->left, left_path_size);
    }
    int max_right_path_size = 0;
    int right_path_size = 0;
    if (root->right != nullptr)
    {
        max_right_path_size = longestUnivaluePath(root->right, right_path_size);
    }
    result = 0;
    if (root->left != nullptr && root->val == root->left->val)
    {
        path_length = max(path_length, 1 + left_path_size);
        result += 1 + left_path_size;
    }
    if (root->right != nullptr && root->val == root->right->val)
    {
        path_length = max(path_length, 1 + right_path_size);
        result += 1 + right_path_size;
    }
    result = max(max_left_path_size, result);
    result = max(max_right_path_size, result);
    return result;
}

/// <summary>
/// Leet code #687. Longest Univalue Path
/// 
/// Given a binary tree, find the length of the longest path where each 
/// node in the path has the same value. This path may or may not pass 
/// through the root.
///
/// Note: The length of path between two nodes is represented by 
/// the number of edges between them.
///
/// Example 1:
///
/// Input:
///
///              5
///             / \
///            4   5
///           / \   \
///          1   1   5
/// Output: 2
///
/// Example 2:
///
/// Input:
///
///              1
///             / \
///            4   5
///           / \   \
///          4   4   5
/// Output: 2
/// Note: The given binary tree has not more than 10000 nodes. The height 
/// of the tree is not more than 1000.
/// </summary>
int LeetCodeTree::longestUnivaluePath(TreeNode* root)
{
    int path_length;
    return longestUnivaluePath(root, path_length);
}

/// <summary>
/// Leet code #742. Closest Leaf in a Binary Tree
/// </summary>
void LeetCodeTree::findClosestLeaf(TreeNode* root, int target, int &target_distance, int &leaf_distance, int &value)
{
    if (root == nullptr) return;
    if (root->val == target) target_distance = 0;
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        leaf_distance = 0;
        value = root->val;
    }
    else
    {
        int left_target_distance = -1;
        int left_leaf_distance = -1;
        int right_target_distance = -1;
        int right_leaf_distance = -1;
        int left_value = -1;
        int right_value = -1;
        findClosestLeaf(root->left, target, left_target_distance, left_leaf_distance, left_value);
        findClosestLeaf(root->right, target, right_target_distance, right_leaf_distance, right_value);
        if (left_target_distance != -1)
        {
            leaf_distance = left_leaf_distance;
            value = left_value;
            if ((root->right != nullptr) && (left_leaf_distance > left_target_distance + 1 + right_leaf_distance + 1))
            {
                leaf_distance = (left_target_distance + 1 + right_leaf_distance + 1);
                value = right_value;
            }
            target_distance = left_target_distance + 1;
        }
        else if (right_target_distance != -1)
        {
            leaf_distance = right_leaf_distance;
            value = right_value;
            if ((root->left != nullptr) && (right_leaf_distance > right_target_distance + 1 + left_leaf_distance + 1))
            {
                leaf_distance = (right_target_distance + 1 + left_leaf_distance + 1);
                value = left_value;
            }
            target_distance = right_target_distance + 1;
        }
        else
        {
            if (root->left != nullptr)
            {
                leaf_distance = left_leaf_distance;
                value = left_value;
            }
            else
            {
                leaf_distance = right_leaf_distance;
                value = right_value;
            }
            if ((root->right != nullptr) && (left_leaf_distance > right_leaf_distance))
            {
                leaf_distance = right_leaf_distance;
                value = right_value;
            }
            leaf_distance += 1;
        }
    }
}

/// <summary>
/// Leet code #742. Closest Leaf in a Binary Tree
///
/// Given a binary tree where every node has a unique value, and a target 
/// key k, find the value of the closest leaf node to target k in the tree.
///
/// Here, closest to a leaf means the least number of edges travelled on 
/// the binary tree to reach any leaf of the tree. Also, a node is called 
/// a leaf if it has no children.
///
/// In the following examples, the input tree is represented in flattened 
/// form row by row. The actual root tree given will be a TreeNode object.
///
/// Example 1:
///
/// Input:
/// root = [1, 3, 2], k = 1
/// Diagram of binary tree:
///      1
///     / \
///    3   2
///
/// Output: 2 (or 3)
///
/// Explanation: Either 2 or 3 is the closest leaf node to the target of 1.
/// Example 2:
/// 
/// Input:
/// root = [1], k = 1
/// Output: 1
///
/// Explanation: The closest leaf node is the root node itself.
/// Example 3:
///
/// Input:
/// root = [1,2,3,4,null,null,null,5,null,6], k = 2
/// Diagram of binary tree:
///         1
///        / \
///       2   3
///      /
///     4
///    /
///   5
///  /
/// 6
///
/// Output: 3
/// Explanation: The leaf node with value 3 (and not the leaf node with 
/// value 6) is closest to the node with value 2.
/// Note:
/// root represents a binary tree with at least 1 node and at most 1000 
/// nodes.
/// Every node has a unique node.val in range [1, 1000].
/// There exists some node in the given binary tree for which 
/// node.val == k. 
/// </summary>
int LeetCodeTree::findClosestLeaf(TreeNode* root, int k)
{
    int target_distance = -1, leaf_distance = -1, value = -1;
    findClosestLeaf(root, k, target_distance, leaf_distance, value);
    return value;
}

/// <summary>
/// Leetcode #776. Split BST
///
/// Given a Binary Search Tree (BST) with root node root, and a target 
/// value V, split the tree into two subtrees where one subtree has 
/// nodes that are all smaller or equal to the target value, while the 
/// other subtree has all nodes that are greater than the target value.  
/// It's not necessarily the case that the tree contains a node with 
/// value V.
///
/// Additionally, most of the structure of the original tree should 
/// remain.  Formally, for any child C with parent P in the original 
/// tree, if they are both in the same subtree after the split, then 
/// node C should still have the parent P.
///
/// You should output the root TreeNode of both subtrees after splitting, 
/// in any order.
///
/// Example 1:
///
/// Input: root = [4,2,6,1,3,5,7], V = 2
/// Output: [[2,1],[4,3,6,null,null,5,7]]
/// Explanation:
/// Note that root, output[0], and output[1] are TreeNode objects, not 
/// arrays.
/// 
/// The given tree [4,2,6,1,3,5,7] is represented by the following diagram:
///
///      4
///    /    \
///   2      6
///  / \    / \
/// 1   3  5   7
///
/// while the diagrams for the outputs are:
///
///       4
///      /  \
///     3    6      and    2
///         / \           /
///        5   7         1
/// Note:
/// 1. The size of the BST will not exceed 50.
/// 2. The BST is always valid and each node's value is different.
/// </summary>
vector<TreeNode*> LeetCodeTree::splitBST(TreeNode* root, int V)
{
    vector<TreeNode *> result;
    if (root == nullptr)
    {
        result.push_back(nullptr);
        result.push_back(nullptr);
    }
    else if (root->val <= V)
    {
        vector<TreeNode *> children = splitBST(root->right, V);
        root->right = children[0];
        result.push_back(root);
        result.push_back(children[1]);
    }
    else
    {
        vector<TreeNode *> children = splitBST(root->left, V);
        root->left = children[1];
        result.push_back(children[0]);
        result.push_back(root);
    }
    return result;
}

/// <summary>
/// Leetcode #783. Minimum Distance Between BST Nodes
/// </summary>
void LeetCodeTree::minDiffInBST(TreeNode* node, TreeNode* &prev_node, int &min_diff)
{
    if (node == nullptr) return;
    minDiffInBST(node->left, prev_node, min_diff);
    if (prev_node != nullptr)
    {
        if (min_diff >= 0) min_diff = min(node->val - prev_node->val, min_diff);
        else min_diff = node->val - prev_node->val;
    }
    prev_node = node;
    minDiffInBST(node->right, prev_node, min_diff);
}

/// <summary>
/// Leetcode #783. Minimum Distance Between BST Nodes
///
/// Given a Binary Search Tree (BST) with the root node root, return the 
/// minimum difference between the values of any two different nodes in 
/// the tree.
/// 
/// Example :
///
/// Input: root = [4,2,6,1,3,null,null]
/// Output: 1
/// Explanation:
/// Note that root is a TreeNode object, not an array.
///
/// The given tree [4,2,6,1,3,null,null] is represented by the following 
/// diagram:
///         4
///        /  \
///       2    6
///      / \    
///     1   3  
/// while the minimum difference in this tree is 1, it occurs between 
/// node 1 and node 2, also between node 3 and node 2.
/// Note:
///
/// 1. The size of the BST will be between 2 and 100.
/// 2. The BST is always valid, each node's value is an integer, and each 
///    node's value is different.
/// </summary>
int LeetCodeTree::minDiffInBST(TreeNode* root)
{
    TreeNode * prev_node = nullptr;
    int min_diff = -1;
    minDiffInBST(root, prev_node, min_diff);
    return min_diff;
}

/// <summary>
/// Leet code #814. Binary Tree Pruning
/// 
/// We are given the head node root of a binary tree, where additionally 
/// every node's value is either a 0 or a 1. 
/// 
/// Return the same tree where every subtree (of the given tree) not 
/// containing a 1 has been removed.
///
/// (Recall that the subtree of a node X is X, plus every node that is a 
/// descendant of X.)
/// 
/// Example 1:
/// Input: [1,null,0,0,1]
/// Output: [1,null,0,null,1]
///  1               1
///   \               \ 
///    0      =>       0
///   / \               \
///  0   1               1
/// Explanation: 
/// Only the red nodes satisfy the property "every subtree not containing 
/// a 1".
/// The diagram on the right represents the answer.
///
/// Example 2:
/// Input: [1,0,1,0,0,0,1]
/// Output: [1,null,1,null,1]
///      1               1
///    /   \              \ 
///   0     1      =>      1
///  / \   / \              \
/// 0   0 0   1              1
/// 
/// Example 3:
/// Input: [1,1,0,1,1,0,1,0]
/// Output: [1,1,0,1,1,null,1]
///        1                 1
///      /   \             /   \ 
///     1     0    =>     1     0
///    / \   / \         / \     \
///   1   1 0   1       1   1     1 
///  /
/// 0
/// 
/// Note:
///
/// 1. The binary tree will have at most 100 nodes.
/// 2. The value of each node will only be 0 or 1.
/// </summary>
TreeNode* LeetCodeTree::pruneTree(TreeNode* root)
{
    if (root == nullptr) return root;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == nullptr && root->right == nullptr && root->val == 0)
    {
        return nullptr;
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #863. All Nodes Distance K in Binary Tree
/// </summary>
int LeetCodeTree::distanceK(TreeNode* root, TreeNode* target, int K, int distance, vector<int>& result)
{
    if (root == nullptr) return distance;
    if (root->val == target->val) distance = 0;
    if (distance >= 0)
    {
        distanceK(root->left, target, K, distance + 1, result);
        distanceK(root->right, target, K, distance + 1, result);
    }
    else
    {
        int left_distance = distanceK(root->left, target, K, distance, result);
        if (left_distance >= 0)
        {
            distance = left_distance + 1;
            distanceK(root->right, target, K, distance + 1, result);
        }
        else
        {
            int right_distance = distanceK(root->right, target, K, distance, result);
            if (left_distance < 0 && right_distance >= 0)
            {
                distance = right_distance + 1;
                distanceK(root->left, target, K, distance + 1, result);
            }
        }
    }

    if (distance == K) result.push_back(root->val);
    return distance;
}

/// <summary>
/// Leet code #863. All Nodes Distance K in Binary Tree
/// 
/// We are given a binary tree (with root node root), a target node, and an 
/// integer value `K`.
///
/// Return a list of the values of all nodes that have a distance K from the 
/// target node.  The answer can be returned in any order.
///
/// 
///
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
/// Output: [7,4,1]
/// Explanation: 
/// The nodes that are a distance 2 from the target node (with value 5)
/// have values 7, 4, and 1.
///
/// Note that the inputs "root" and "target" are actually TreeNodes.
/// The descriptions of the inputs above are just serializations of these objects.
///
/// Note:
///
/// 1. The given tree is non-empty.
/// 2. Each node in the tree has unique values 0 <= node.val <= 500.
/// 3. The target node is a node in the tree.
/// 4. 0 <= K <= 1000.
/// </summary>
vector<int> LeetCodeTree::distanceK(TreeNode* root, TreeNode* target, int K)
{
    vector<int> result;
    distanceK(root, target, K, -1, result);

    return result;
}

/// <summary>
/// Leet code #865. Smallest Subtree with all the Deepest Nodes
/// </summary>
pair<TreeNode*, int> LeetCodeTree::subtreeWithAllDeepest(TreeNode* root, int depth)
{
    pair<TreeNode *, int> result;
    if (root == nullptr)
    {
        result = make_pair(root, 0);
    }
    else
    {
        pair<TreeNode *, int> left_result = subtreeWithAllDeepest(root->left, depth + 1);
        pair<TreeNode *, int> right_result = subtreeWithAllDeepest(root->right, depth + 1);
        if (left_result.second == right_result.second)
        {
            if (left_result.first == nullptr)
            {
                result = make_pair(root, depth);
            }
            else
            {
                result = make_pair(root, left_result.second);
            }
        }
        else if (left_result.second > right_result.second)
        {
            result = left_result;
        }
        else
        {
            result = right_result;
        }
    }
    return result;
}

/// <summary>
/// Leet code #865. Smallest Subtree with all the Deepest Nodes
/// 
/// Given a binary tree rooted at root, the depth of each node is the 
/// shortest distance to the root.
///
/// A node is deepest if it has the largest depth possible among any node 
/// in the entire tree. 
/// 
/// The subtree of a node is that node, plus the set of all descendants of 
/// that node.
///
/// Return the node with the largest depth such that it contains all the 
/// deepest nodes in it's subtree.
///
/// 
///
/// Example 1:
///
/// Input: [3,5,1,6,2,0,8,null,null,7,4]
/// Output: [2,7,4]
///
/// Explanation:
/// 
/// We return the node with value 2, colored in yellow in the diagram.
/// The nodes colored in blue are the deepest nodes of the tree.
/// The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization 
/// of the given tree.
/// The output "[2, 7, 4]" is a serialization of the subtree rooted at the 
/// node with value 2.
/// Both the input and output have TreeNode type.
/// 
/// Note:
/// 1. The number of nodes in the tree will be between 1 and 500.
/// 2. The values of each node are unique.
/// </summary>
TreeNode* LeetCodeTree::subtreeWithAllDeepest(TreeNode* root)
{
    pair<TreeNode *, int> result = subtreeWithAllDeepest(root, 1);
    return result.first;
}

/// <summary>
/// Leet code #872. Leaf-Similar Trees
/// </summary>
void LeetCodeTree::getLeaves(TreeNode* root, vector<int> &leaves)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        leaves.push_back(root->val);
    }
    else
    {
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
}

/// <summary>
/// Leet code #872. Leaf-Similar Trees
/// 
/// Consider all the leaves of a binary tree.  From left to right order, 
/// the values of those leaves form a leaf value sequence.
///
/// For example, in the given tree above, the leaf value sequence is 
/// (6, 7, 4, 9, 8).
///
/// Two binary trees are considered leaf-similar if their leaf value 
/// sequence is the same.
///
/// Return true if and only if the two given trees with head nodes root1 
/// and root2 are leaf-similar.
///
/// Note:
/// 1. Both of the given trees will have between 1 and 100 nodes.
/// </summary>
bool LeetCodeTree::leafSimilar(TreeNode* root1, TreeNode* root2)
{
    vector<int> leaves1, leaves2;
    getLeaves(root1, leaves1);
    getLeaves(root2, leaves2);
    return (leaves1 == leaves2);
}

/// <summary>
/// Leet code #700. Search in a Binary Search Tree
/// 
/// Given the root node of a binary search tree (BST) and a value. You 
/// need to find the node in the BST that the node's value equals the 
/// given value. Return the subtree rooted with that node. If such node 
/// doesn't exist, you should return NULL.
///
/// For example, 
///
/// Given the tree:
///        4
///       / \
///      2   7
///     / \
///    1   3
///
/// And the value to search: 2
/// You should return this subtree:
///
///      2     
///     / \   
///    1   3
/// In the example above, if we want to search the value 5, since there 
/// is no node with value 5, we should return NULL.
///
/// Note that an empty tree is represented by NULL, therefore you would 
/// see the expected output (serialized tree format) as [], not null.
/// </summary>
TreeNode* LeetCodeTree::searchBST(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    else if (root->val < val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #701. Insert into a Binary Search Tree
/// 
/// Given the root node of a binary search tree (BST) and a value to be 
/// inserted into the tree, insert the value into the BST. Return the 
/// root node of the BST after the insertion. It is guaranteed that the 
/// new value does not exist in the original BST.
///
/// Note that there may exist multiple valid ways for the insertion, as 
/// long as the tree remains a BST after insertion. You can return any of 
/// them.
///
/// For example, 
///
/// Given the tree:
///        4
///       / \
///      2   7
///     / \
///    1   3
/// And the value to insert: 5
/// You can return this binary search tree:
///
///         4
///       /   \
///      2     7
///     / \   /
///    1   3 5
/// This tree is also valid:
///
///         5
///       /   \
///      2     7
///     / \   
///    1   3
///         \
///          4
/// </summary>
TreeNode* LeetCodeTree::insertIntoBST(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
    }
    else if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

/// <summary>
/// Leet code #559. Maximum Depth of N-ary Tree
/// 
/// Given a n-ary tree, find its maximum depth.
///
/// The maximum depth is the number of nodes along the longest path from 
/// the root node down to the farthest leaf node.
///
/// For example, given a 3-ary tree:
///  
/// We should return its max depth, which is 3.
/// 
/// Note:
/// 
/// The depth of the tree is at most 1000.
/// The total number of nodes is at most 5000.
/// </summary>
int LeetCodeTree::maxDepth(Node* root)
{
    int result = 0;
    queue<Node *> search;
    search.push(root);
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            Node* node = search.front();
            search.pop();
            if (node == nullptr) return result;
            for (auto child : node->children)
            {
                if (child != nullptr) search.push(child);
            }
        }
        result++;
    }
    return result;
}

/// <summary>
/// Leet code #589. N-ary Tree Preorder Traversal
/// 
/// Given an n-ary tree, return the preorder traversal of its 
/// nodes' values.
///
/// For example, given a 3-ary tree:
///   
/// Return its preorder traversal as: [1,3,5,6,2,4].
///
/// Note: Recursive solution is trivial, could you do it iteratively?
/// </summary>
vector<int> LeetCodeTree::preorder(Node* root)
{
    vector<int> result;

    stack<Node *> search;
    search.push(root);
    while (!search.empty())
    {
        Node * node = search.top();
        search.pop();
        if (node == nullptr) continue;
        result.push_back(node->val);
        for (int i = node->children.size() - 1; i >= 0; i--)
        {
            search.push(node->children[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #429. N-ary Tree Level Order Traversal
/// 
/// Given an n-ary tree, return the level order traversal of its 
/// nodes' values. (ie, from left to right, level by level).
///
/// For example, given a 3-ary tree:
/// We should return its level order traversal:
/// [
///   [1],
///   [3,2,4],
///   [5,6]
/// ]
/// Note:
/// The depth of the tree is at most 1000.
/// The total number of nodes is at most 5000.
/// </summary>
vector<vector<int>> LeetCodeTree::levelOrder(Node* root)
{
    vector<vector<int>> result;
    queue<Node *> search;
    search.push(root);
    while (!search.empty())
    {
        size_t size = search.size();
        vector<int> level;
        for (size_t i = 0; i < size; i++)
        {
            Node* node = search.front();
            search.pop();
            if (node == nullptr) return result;
            for (auto child : node->children)
            {
                if (child != nullptr) search.push(child);
            }
            level.push_back(node->val);
        }
        result.push_back(level);
    }
    return result;
}

/// <summary>
/// Leet code #590. N-ary Tree Postorder Traversal
/// 
/// Given an n-ary tree, return the postorder traversal of its 
/// nodes' values.
/// 
/// For example, given a 3-ary tree:
/// 
/// Return its postorder traversal as: [5,6,3,2,4,1].
///
/// Note: Recursive solution is trivial, could you do it iteratively?
/// </summary>
vector<int> LeetCodeTree::postorder(Node* root)
{
    vector<int> result;

    stack<Node *> search;
    unordered_set<Node *> visited;
    search.push(root);
    while (!search.empty())
    {
        Node * node = search.top();
        search.pop();
        if (node == nullptr) continue;
        if (visited.count(node) > 0)
        {
            result.push_back(node->val);
        }
        else
        {
            visited.insert(node);
            search.push(node);
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                search.push(node->children[i]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #426. Convert Binary Search Tree to Sorted Doubly Linked List
/// </summary>
void LeetCodeTree::treeToDoublyList(TreeNode* root, TreeNode*& head, TreeNode *&tail)
{
    if (root == nullptr) return;

    treeToDoublyList(root->right, head, tail);
    if (head == nullptr)
    {
        head = new TreeNode(root->val);
        head->left = head;
        head->right = head;
        tail = head;
    }
    else
    {
        TreeNode * node = new TreeNode(root->val);
        node->right = head;
        node->left = tail;
        head->left = node;
        tail->right = node;
        head = node;
    }
    treeToDoublyList(root->left, head, tail);
}

/// <summary>
/// Leet code #426. Convert Binary Search Tree to Sorted Doubly Linked List
/// 
/// Convert a BST to a sorted circular doubly-linked list in-place. Think of 
/// the left and right pointers as synonymous to the previous and next 
/// pointers in a doubly-linked list.
///
/// Let's take the following BST as an example, it may help you understand 
/// the problem better:
///
/// We want to transform this BST into a circular doubly linked list. Each 
/// node in a doubly linked list has a predecessor and successor. For a 
/// circular doubly linked list, the predecessor of the first element is the 
/// last element, and the successor of the last element is the first element.
///
/// The figure below shows the circular doubly linked list for the BST above. 
/// The "head" symbol means the node it points to is the smallest element of 
/// the linked list.
///
/// Specifically, we want to do the transformation in place. After the 
/// transformation, the left pointer of the tree node should point to its 
/// predecessor, and the right pointer should point to its successor. We 
/// should return the pointer to the first element of the linked list.
///
/// The figure below shows the transformed BST. The solid line indicates the 
/// successor relationship, while the dashed line means the predecessor 
/// relationship.
/// </summary>
TreeNode* LeetCodeTree::treeToDoublyList(TreeNode* root)
{
    TreeNode * head = nullptr;
    TreeNode * tail = nullptr;
    treeToDoublyList(root, head, tail);
    return head;
}

/// <summary>
/// Leet code #889. Construct Binary Tree from Preorder and Postorder Traversal
/// </summary>
TreeNode* LeetCodeTree::constructFromPrePost(
    vector<int>::iterator pre_begin, 
    vector<int>::iterator pre_end,
    vector<int>::iterator post_begin, 
    vector<int>::iterator post_end)
{
    TreeNode * result = nullptr;
    
    if (pre_begin == pre_end) return result;
    int val = *pre_begin;
    result = new TreeNode(val);
    pre_begin++;
    post_end--;
    if (pre_begin == pre_end) return result;
    int left_child = *pre_begin;
    vector<int>::iterator post_itr = find(post_begin, post_end, left_child);
    post_itr++;
    int left_len = post_itr - post_begin;
    int right_len = post_end - post_itr;
    result->left = constructFromPrePost(pre_begin, pre_begin + left_len, post_begin, post_begin + left_len);
    result->right = constructFromPrePost(pre_begin + left_len, pre_end, post_begin + left_len, post_end);
    return result;
}

/// <summary>
/// Leet code #889. Construct Binary Tree from Preorder and Postorder Traversal
/// 
/// Return any binary tree that matches the given preorder and postorder 
/// traversals.
///
/// Values in the traversals pre and post are distinct positive integers.
///
/// Example 1:
/// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
/// Output: [1,2,3,4,5,6,7]
/// 
/// Note:
/// 1 <= pre.length == post.length <= 30
/// pre[] and post[] are both permutations of 1, 2, ..., pre.length.
/// It is guaranteed an answer exists. If there exists multiple answers, 
/// you can return any of them.
/// </summary>
TreeNode* LeetCodeTree::constructFromPrePost(vector<int>& pre, vector<int>& post)
{
    return constructFromPrePost(pre.begin(), pre.end(), post.begin(), post.end());
}

/// <summary>
/// Leet code #894. All Possible Full Binary Trees
/// </summary>
TreeNode* LeetCodeTree::clone(TreeNode * root)
{
    TreeNode * result = nullptr;
    if (root == nullptr) return result;
   
    result = new TreeNode(root->val);
    result->left = clone(root->left);
    result->right = clone(root->right);
    
    return result;
}

/// <summary>
/// Leet code #894. All Possible Full Binary Trees
/// 
/// A full binary tree is a binary tree where each node has exactly 0 or 2 
/// children.
///
/// Return a list of all possible full binary trees with N nodes.  Each 
/// element of the answer is the root node of one possible tree.
///
/// Each node of each tree in the answer must have node.val = 0.
///
/// You may return the final list of trees in any order.
///
/// Example 1:
///
/// Input: 7
/// Output: 
/// [
///  [0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],
///  [0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]
/// ]
/// Explanation:
/// 
/// Note:
/// 1 <= N <= 20
/// </summary>
vector<TreeNode*> LeetCodeTree::allPossibleFBT(int N)
{
    vector<TreeNode *> result;
    if (N == 0) return result;	
    if (N == 1)
    {
        result.push_back(new TreeNode(0));
        return result;
    }
    N--;
    for (int left = 1; left < N; left += 2)
    {
        vector<TreeNode *> left_array = allPossibleFBT(left);
        vector<TreeNode *> right_array = allPossibleFBT(N - left);

        for (auto left_tree : left_array)
        {
            for (auto right_tree : right_array)
            {
                TreeNode * root = new TreeNode(0);
                root->left = clone(left_tree);
                root->right = clone(right_tree);
                result.push_back(root);
            }
        }

        for (auto tree : left_array) freeTreeNodes(tree);
        for (auto tree : right_array) freeTreeNodes(tree);
    }

    return result;
}

/// <summary>
/// Leet code #897. Increasing Order Search Tree 
/// </summary>
void LeetCodeTree::increasingBST(TreeNode *& new_root, TreeNode *&new_child, TreeNode* root)
{
    if (root == nullptr) return;
    increasingBST(new_root, new_child, root->left);
    if (new_root == nullptr)
    {
        new_root = root;
        root->left = nullptr;
    }
    else
    {
        new_child->right = root;
        root->left = nullptr;
    }
    new_child = root;
    increasingBST(new_root, new_child, root->right);
}

/// <summary>
/// Leet code #897. Increasing Order Search Tree 
/// 
/// Given a tree, rearrange the tree in in-order so that the leftmost node in 
/// the tree is now the root of the tree, and every node has no left child 
/// and only 1 right child.
///
/// Example 1:
/// Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
///
///       5
///      / \
///     3   6
///    / \   \
///   2   4   8
///  /       / \ 
/// 1       7   9
///
/// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
///
/// 1
///  \
///   2
///    \
///     3
///      \
///       4
///        \
///         5
///          \
///           6
///            \
///             7
///              \
///               8
///                \
///                 9  
/// Note:
///
/// 1. The number of nodes in the given tree will be between 1 and 100.
/// 2. Each node will have a unique integer value from 0 to 1000.
/// </summary>
TreeNode* LeetCodeTree::increasingBST(TreeNode* root)
{
    TreeNode * new_root = nullptr;
    TreeNode * new_child = nullptr;
    increasingBST(new_root, new_child, root);
    return new_root;
}

/// <summary>
/// Leet code #938. Range Sum of BST
/// 
/// Given the root node of a binary search tree, return the sum of values of 
/// all nodes with value between L and R (inclusive).
///
/// The binary search tree is guaranteed to have unique values.
///
/// Example 1:
///
/// Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
/// Output: 32
/// Example 2:
///
/// Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
/// Output: 23
///  
///
/// Note:
///
/// The number of nodes in the tree is at most 10000.
/// The final answer is guaranteed to be less than 2^31.
///
/// </summary>
int LeetCodeTree::rangeSumBST(TreeNode* root, int L, int R)
{
    int result = 0;
    if (root == nullptr) return result;
    if (root->val >= L && root->val <= R)
    {
        result = root->val;
        result += rangeSumBST(root->left, L, R);
        result += rangeSumBST(root->right, L, R);
    }
    else if (root->val < L)
    {
        result += rangeSumBST(root->right, L, R);
    }
    else if (root->val > R)
    {
        result += rangeSumBST(root->left, L, R);
    }
    return result;
}

/// <summary>
/// Leet code #951. Flip Equivalent Binary Trees
/// 
/// For a binary tree T, we can define a flip operation as follows: choose 
/// any node, and swap the left and right child subtrees.
/// 
/// A binary tree X is flip equivalent to a binary tree Y if and only if 
/// we can make X equal to Y after some number of flip operations.
///
/// Write a function that determines whether two binary trees are flip 
/// equivalent.  The trees are given by root nodes root1 and root2.
/// 
/// 
/// Example 1:
///
/// Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], 
///        root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
/// Output: true
/// Explanation: We flipped at nodes with values 1, 3, and 5.
/// Flipped Trees Diagram
/// 
/// Note:
/// 
/// 1. Each tree will have at most 100 nodes.
/// 2. Each value in each tree will be a unique integer in the range 
/// [0, 99].
/// </summary>
bool LeetCodeTree::flipEquiv(TreeNode* root1, TreeNode* root2)
{
    if (root1 == root2) return true;
    if ((root1 == nullptr) || (root2 == nullptr)) return false;
 
    if (root1 != nullptr && root2 != nullptr && root1->val != root2->val) return false;
    if (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
    {
        return true;
    }
    else if (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #958. Check Completeness of a Binary Tree
/// 
/// Given a binary tree, determine if it is a complete binary tree.
///
/// Definition of a complete binary tree from Wikipedia:
/// In a complete binary tree every level, except possibly the last, is 
/// completely filled, and all nodes in the last level are as far left as 
/// possible. It can have between 1 and 2h nodes inclusive at the last level h.
///
/// 
///
/// Example 1:
///
/// Input: [1,2,3,4,5,6]
/// Output: true
/// Explanation: Every level before the last is full (ie. levels with 
/// node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) 
/// are as far left as possible.
///
/// Example 2:
///
/// Input: [1,2,3,4,5,null,7]
/// Output: false
/// Explanation: The node with value 7 isn't as far left as possible.
/// 
/// Note:
///
/// 1. The tree will have between 1 and 100 nodes.
/// </summary>
bool LeetCodeTree::isCompleteTree(TreeNode* root)
{
    bool meetNull = false;
    queue<TreeNode*> search;
    search.push(root);

    while (!search.empty())
    {
        TreeNode * node = search.front();
        search.pop();
        if (node == nullptr)
        {
            meetNull = true;
        }
        else
        {
            if (meetNull) return false;
            search.push(node->left);
            search.push(node->right);
        }
    }
    return true;
}

/// <summary>
/// Leet code #968. Binary Tree Cameras
/// </summary>
int LeetCodeTree::minCameraCover(TreeNode* root, int &result)
{
    // the child is null or covered
    if (root == nullptr) return 1;
    int left = minCameraCover(root->left, result);
    int right = minCameraCover(root->right, result);

    // if left and right are all covered, but no camera, return 0 
    // means myself not covered.
    if (left == 1 && right == 1) return 0;
    // either left or right not covered, we need a camera here
    if (left == 0 || right == 0)
    {
        result++;
        return 2;
    }
    else // either left or right contains a camera
    {
        return 1;
    }
}

/// <summary>
/// Leet code #968. Binary Tree Cameras
/// 
/// Given a binary tree, we install cameras on the nodes of the tree. 
///
/// Each camera at a node can monitor its parent, itself, and its immediate 
/// children.
///
/// Calculate the minimum number of cameras needed to monitor all nodes of 
/// the tree.
///
/// Example 1:
/// Input: [0,0,null,0,0]
/// Output: 1
/// Explanation: One camera is enough to monitor all nodes if placed as shown.
///
/// Example 2:
/// Input: [0,0,null,0,null,0,null,null,0]
/// Output: 2
/// Explanation: At least two cameras are needed to monitor all nodes of the 
/// tree. The above image shows one of the valid configurations of camera 
/// placement.
///
/// Note:
/// 
/// 1. The number of nodes in the given tree will be in the range [1, 1000].
/// 2. Every node has value 0.
/// </summary>
int LeetCodeTree::minCameraCover(TreeNode* root)
{
    int result = 0;
    if (minCameraCover(root, result) == 0)
    {
        result++;
    }
    return result;
}

/// <summary>
/// Leet code #965. Univalued Binary Tree
/// 
/// A binary tree is univalued if every node in the tree has the same value.
///
/// Return true if and only if the given tree is univalued.
///
/// Example 1:
/// Input: [1,1,1,1,1,null,1]
/// Output: true
///
/// Example 2:
/// Input: [2,2,2,5,2]
/// Output: false
/// 
/// Note:
/// 
/// 1. The number of nodes in the given tree will be in the range [1, 100].
/// 2. Each node's value will be an integer in the range [0, 99].
/// </summary>
bool LeetCodeTree::isUnivalTree(TreeNode* root)
{
    int prev_val = -1;
    queue<TreeNode *> search;
    search.push(root);

    while (!search.empty())
    {
        TreeNode * node = search.front();
        search.pop();
        if (prev_val == -1)
        {
            prev_val = node->val;
        }
        else if (prev_val != node->val)
        {
            return false;
        }
        if (node->left != nullptr)
        {
            search.push(node->left);
        }
        if (node->right != nullptr)
        {
            search.push(node->right);
        }
    }
    return true;
}

/// <summary>
/// Leet code #971. Flip Binary Tree To Match Preorder Traversal
/// </summary>
void LeetCodeTree::flipMatchVoyage(TreeNode* root, vector<int>& voyage, int& index, vector<int>& result)
{
    // fail to match
    if (root->val != voyage[index])
    {
        result.clear();
        result.push_back(-1);
        return;
    }
    
    // failed already
    if (!result.empty() && result[0] == -1)
    {
        return;
    }
    index++;
    if (root->left != nullptr && root->right != nullptr)
    {
        if (root->left->val != voyage[index])
        {
            std::swap(root->left, root->right);
            result.push_back(root->val);
        }
        flipMatchVoyage(root->left, voyage, index, result);
        flipMatchVoyage(root->right, voyage, index, result);
    }
    else if (root->left != nullptr)
    {
        flipMatchVoyage(root->left, voyage, index, result);
    }
    else if (root->right != nullptr)
    {
        flipMatchVoyage(root->right, voyage, index, result);
    }
    return;
}

/// <summary>
/// Leet code #971. Flip Binary Tree To Match Preorder Traversal
/// 
/// Given a binary tree with N nodes, each node has a different value from 
/// {1, ..., N}.
///
/// A node in this binary tree can be flipped by swapping the left child 
/// and the right child of that node.
///
/// Consider the sequence of N values reported by a preorder traversal starting 
/// from the root.  Call such a sequence of N values the voyage of the tree.
///
/// (Recall that a preorder traversal of a node means we report the current 
/// node's value, then preorder-traverse the left child, then preorder-traverse
/// the right child.)
///
/// Our goal is to flip the least number of nodes in the tree so that the 
/// voyage of the tree matches the voyage we are given.
///
/// If we can do so, then return a list of the values of all nodes flipped.  
/// You may return the answer in any order.
///
/// If we cannot do so, then return the list [-1].
///
/// 
/// Example 1:
/// Input: root = [1,2], voyage = [2,1]
/// Output: [-1]
///
/// Example 2:
/// Input: root = [1,2,3], voyage = [1,3,2]
/// Output: [1]
///
/// Example 3:
/// Input: root = [1,2,3], voyage = [1,2,3]
/// Output: []
///  
/// Note:
/// 
/// 1. 1 <= N <= 100
/// </summary>
vector<int> LeetCodeTree::flipMatchVoyage(TreeNode* root, vector<int>& voyage)
{
    vector<int> result;
    int index = 0;
    flipMatchVoyage(root, voyage, index, result);
    return result;
}

/// <summary>
/// Leet code #979. Distribute Coins in Binary Tree
/// </summary>
int LeetCodeTree::distributeCoins(TreeNode* root, vector<int>& missingPaths, int &result)
{
    if (root == nullptr)
    {
        return 0;
    }
    vector<int> leftMissingPaths, rightMissingPaths;
    root->val += distributeCoins(root->left, leftMissingPaths, result);
    root->val += distributeCoins(root->right, rightMissingPaths, result);

    for (auto path : leftMissingPaths) missingPaths.push_back(path);
    for (auto path : rightMissingPaths) missingPaths.push_back(path);
    while (root->val > 0 && !missingPaths.empty())
    {
        result += missingPaths.back();
        root->val--;
        missingPaths.pop_back();
    }
    if (root->val == 0)
    {
        missingPaths.push_back(0);
    }
    for (size_t i = 0; i < missingPaths.size(); i++)
    {
        missingPaths[i]++;
    }
    if (root->val > 1)
    {
        result += root->val - 1;
        return root->val - 1;
    }
    else
    {
        return 0;
    }
}

/// <summary>
/// Leet code #979. Distribute Coins in Binary Tree
/// 
/// Given the root of a binary tree with N nodes, each node in the tree 
/// has node.val coins, and there are N coins total.
/// In one move, we may choose two adjacent nodes and move one coin from 
/// one node to another.  (The move may be from parent to child, or from 
/// child to parent.)
/// Return the number of moves required to make every node have exactly 
/// one coin.
///
/// Example 1:
///
/// Input: [3,0,0]
/// Output: 2
/// Explanation: From the root of the tree, we move one coin to its left 
/// child, and one coin to its right child.
///   
/// Example 2:
/// 
/// Input: [0,3,0]
/// Output: 3
/// Explanation: From the left child of the root, we move two coins to 
/// the root [taking two moves].  Then, we move one coin from the root of 
/// the tree to the right child.
///
/// Example 3:
///
/// Input: [1,0,2]
/// Output: 2
///
/// Example 4:
///
/// Input: [1,0,0,null,3]
/// Output: 4
///
/// Note:
/// 1. 1<= N <= 100
/// 2. 0 <= node.val <= N
/// </summary>
int LeetCodeTree::distributeCoins(TreeNode* root)
{
    int result = 0;
    vector<int> missingPaths;
    distributeCoins(root, missingPaths, result);
    return result;
}

/// <summary>
/// Leet code #987. Vertical Order Traversal of a Binary Tree
/// 
/// Given a binary tree, return the vertical order traversal of its nodes 
/// values.
/// For each node at position (X, Y), its left and right children 
/// respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
/// 
/// Running a vertical line from X = -infinity to X = +infinity, whenever 
/// the vertical line touches some nodes, we report the values of the 
/// nodes in order from top to bottom (decreasing Y coordinates).
///
/// If two nodes have the same position, then the value of the node that 
/// is reported first is the value that is smaller.
///
/// Return an list of non-empty reports in order of X coordinate.  Every 
/// report will have a list of values of nodes.
///
/// Example 1:
/// 
/// Input: [3,9,20,null,null,15,7]
/// Output: [[9],[3,15],[20],[7]]
/// Explanation: 
/// Without loss of generality, we can assume the root node is at 
/// position (0, 0):
/// Then, the node with value 9 occurs at position (-1, -1);
/// The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
/// The node with value 20 occurs at position (1, -1);
/// The node with value 7 occurs at position (2, -2).
///
/// Example 2:
/// 
/// Input: [1,2,3,4,5,6,7]
/// Output: [[4],[2],[1,5,6],[3],[7]]
/// Explanation: 
/// The node with value 5 and the node with value 6 have the same position 
/// according to the given scheme.
/// However, in the report "[1,5,6]", the node value of 5 comes first since
/// 5 is smaller than 6.
/// 
///
/// Note:
///
/// 1. The tree will have between 1 and 1000 nodes.
/// 2. Each node's value will be between 0 and 1000.
/// </summary>
vector<vector<int>> LeetCodeTree::verticalTraversal(TreeNode* root)
{
    vector<vector<int>> result;
    map<int, map<int, set<int>>> node_map;
    int position = 0;
    queue<pair<TreeNode *, vector<int>>> search;
    vector<int> pos = vector<int>(2);
    search.push(make_pair(root, pos));
    int level = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<TreeNode *, vector<int>> node = search.front();
            search.pop();
            if (node.first == nullptr) continue;
            node_map[node.second[0]][node.second[1]].insert(node.first->val);
            vector<int> pos = node.second;
            pos[0] = node.second[0] - 1;
            pos[1] = level;
            search.push(make_pair(node.first->left, pos));
            pos[0] = node.second[0] + 1;
            pos[1] = level;
            search.push(make_pair(node.first->right, pos));
        }
        level++;
    }
    for (auto itr = node_map.begin(); itr != node_map.end(); ++itr)
    {
        result.push_back(vector<int>());
        for (auto itr1 = itr->second.begin(); itr1 != itr->second.end(); ++itr1)
        {
            result.back().insert(result.back().end(), itr1->second.begin(), itr1->second.end());
        }
    }
    return result;
}

/// <summary>
/// Leet code #988. Smallest String Starting From Leaf
/// </summary>
void LeetCodeTree::smallestFromLeaf(TreeNode* root, string& str, string &result)
{
    str.push_back(root->val + 'a');
    if (root->left == nullptr && root->right == nullptr)
    {
        string rev_str = str;
        std::reverse(rev_str.begin(), rev_str.end());
        if (result.empty()) result = rev_str;
        else result = min(rev_str, result);
    }
    else
    {
        if (root->left != nullptr)
        {
            smallestFromLeaf(root->left, str, result);
        }
        if (root->right != nullptr)
        {
            smallestFromLeaf(root->right, str, result);
        }
    }
    str.pop_back();
}

/// <summary>
/// Leet code #988. Smallest String Starting From Leaf
/// 
/// Given the root of a binary tree, each node has a value from 0 to 25 
/// representing the letters 'a' to 'z': a value of 0 represents 'a', 
/// a value of 1 represents 'b', and so on.
///
/// Find the lexicographically smallest string that starts at a leaf of 
/// this tree and ends at the root.
///
/// (As a reminder, any shorter prefix of a string is lexicographically 
/// smaller: for example, "ab" is lexicographically smaller than "aba".  
/// A leaf of a node is a node that has no children.)
///
/// Example 1:
/// Input: [0,1,2,3,4,3,4]
/// Output: "dba"
///
/// Example 2:
/// Input: [25,1,3,1,3,0,2]
/// Output: "adz"
///
/// Example 3:
/// Input: [2,2,1,null,1,0,null,0]
/// Output: "abc"
///
/// Note:
/// 1. The number of nodes in the given tree will be between 1 and 1000.
/// 2. Each node in the tree will have a value between 0 and 25.
/// </summary>
string LeetCodeTree::smallestFromLeaf(TreeNode* root)
{
    string str, result;
    smallestFromLeaf(root, str, result);
    return result;
}

/// <summary>
/// Leet code #510. Inorder Successor in BST II
/// 
/// Given a binary search tree and a node in it, find the in-order 
/// successor of that node in the BST.
///
/// The successor of a node p is the node with the smallest key greater 
/// than p.val.
///
/// You will have direct access to the node but not to the root of the 
/// tree. Each node will have a reference to its parent node.
///
///
///
/// Example 1:
/// Input: 
/// root = {"$id":"1","left":{"$id":"2","left":null,"parent":{"$ref":"1"},
/// "right":null,"val":1}, "parent":null,"right": {"$id":"3","left":null,
/// "parent":{"$ref":"1"}, "right":null,"val":3},"val":2}
/// p = 1
/// Output: 2
/// Explanation: 1's in-order successor node is 2. Note that both p and 
/// the return value is of Node type.
///
/// Example 2:
///
/// Input:
/// root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":
/// "4","left":null,"parent":{"$ref":"3"},"right":null,"val":1},"parent":
/// {"$ref":"2"},"right":null,"val":2},"parent":{"$ref":"1"},"right":
/// {"$id":"5","left":null,"parent":{"$ref":"2"},"right":null,"val":4},
/// "val":3},"parent":null,"right":{"$id":"6","left":null,"parent":
/// {"$ref":"1"},"right":null,"val":6},"val":5}
/// p = 6
/// Output: null
/// Explanation: There is no in-order successor of the current node, so 
/// the answer is null.
///
/// Example 3:
/// Input: 
/// root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":
/// {"$id":"4","left":null,"parent":{"$ref":"3"},"right":null,"val":2},
/// "parent":{"$ref":"2"},"right":{"$id":"5","left":null,"parent":
/// {"$ref":"3"},"right":null,"val":4},"val":3},"parent":{"$ref":"1"},
/// "right":{"$id":"6","left":null,"parent":{"$ref":"2"},"right":
/// {"$id":"7","left":{"$id":"8","left":null,"parent":{"$ref":"7"},
/// "right":null,"val":9},"parent":{"$ref":"6"},"right":null,"val":13},
/// "val":7},"val":6},"parent":null,"right":{"$id":"9","left":
/// {"$id":"10","left":null,"parent":{"$ref":"9"},"right":null,
/// "val":17},"parent":{"$ref":"1"},"right":{"$id":"11","left":null,
/// "parent":{"$ref":"9"},"right":null,"val":20},"val":18},"val":15}
/// p = 15
/// Output: 17
///
/// Example 4:
/// Input: 
/// root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":
/// "4","left":null,"parent":{"$ref":"3"},"right":null,"val":2},"parent":
/// {"$ref":"2"},"right":{"$id":"5","left":null,"parent":{"$ref":"3"},
///	"right":null,"val":4},"val":3},"parent":{"$ref":"1"},"right":
/// {"$id":"6","left":null,"parent":{"$ref":"2"},"right":{"$id":"7","left":
/// {"$id":"8","left":null,"parent":{"$ref":"7"},"right":null,"val":9},
/// "parent":{"$ref":"6"},"right":null,"val":13},"val":7},"val":6},
/// "parent":null,"right":{"$id":"9","left":{"$id":"10","left":null,
/// "parent":{"$ref":"9"},"right":null,"val":17},"parent":{"$ref":"1"},
/// "right":{"$id":"11","left":null,"parent":{"$ref":"9"},"right":null,
/// "val":20},"val":18},"val":15}
/// p = 13
/// Output: 15
/// Note:
/// If the given node has no in-order successor in the tree, return null.
/// It's guaranteed that the values of the tree are unique.
/// Remember that we are using the Node type instead of TreeNode type so 
/// their string representation are different.
/// </summary>
TreeNode* LeetCodeTree::inorderSuccessor(TreeNode* node)
{
    TreeNode * result = nullptr;

    if (node->right != nullptr)
    {
        result = node->right;
        while (result->left != nullptr) result = result->left;
    }
    else
    {
        while (node->parent != nullptr)
        {
            TreeNode * parent = node->parent;
            if (parent->left == node)
            {
                result = parent;
                break;
            }
            else
            {
                node = parent;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #993. Cousins in Binary Tree
/// </summary>
bool LeetCodeTree::isCousins(TreeNode* root, TreeNode*& parent, int& depth, int val)
{
    if (root == nullptr) return false;
    if (root->val == val) return true;
    int new_depth = depth + 1;
    TreeNode* new_parent = root;
    if (isCousins(root->left, new_parent, new_depth, val))
    {
        parent = new_parent;
        depth = new_depth;
        return true;
    }
    new_parent = root;
    new_depth = depth + 1;
    if (isCousins(root->right, new_parent, new_depth, val))
    {
        parent = new_parent;
        depth = new_depth;
        return true;
    }
    return false;
}

/// <summary>
/// Leet code #993. Cousins in Binary Tree
/// 
/// In a binary tree, the root node is at depth 0, and children of each depth 
/// k node are at depth k+1.
///
/// Two nodes of a binary tree are cousins if they have the same depth, but 
/// have different parents.
///
/// We are given the root of a binary tree with unique values, and the values 
/// x and y of two different nodes in the tree.
///
/// Return true if and only if the nodes corresponding to the values x and y 
/// are cousins.
///
/// 
/// Example 1:
///
///
/// Input: root = [1,2,3,4], x = 4, y = 3
/// Output: false
///
/// Example 2:
///
/// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
/// Output: true
///
/// Example 3:
///
/// Input: root = [1,2,3,null,4], x = 2, y = 3
/// Output: false
/// 
/// Note:
/// 
/// 1. The number of nodes in the tree will be between 2 and 100.
/// 2. Each node has a unique integer value from 1 to 100.
/// </summary>
bool LeetCodeTree::isCousins(TreeNode* root, int x, int y)
{
    TreeNode * x_parent = root;
    int x_depth = 0;
    TreeNode * y_parent = root;
    int y_depth = 0;

    isCousins(root, x_parent, x_depth, x);
    isCousins(root, y_parent, y_depth, y);

    if ((x_parent != y_parent) && (x_depth == y_depth))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #998. Maximum Binary Tree II
/// 
/// We are given the root node of a maximum tree: a tree where every node 
/// has a value greater than any other value in its subtree.
///
/// Just as in the previous problem, the given tree was constructed from 
/// an list A (root = Construct(A)) recursively with the following 
/// Construct(A) routine:
///
/// If A is empty, return null.
/// Otherwise, let A[i] be the largest element of A.  Create a root node 
/// with value A[i].
/// The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
/// The right child of root will be Construct([A[i+1], A[i+2], ..., 
/// A[A.length - 1]])
/// Return root.
/// Note that we were not given A directly, only a root node 
/// root = Construct(A).
///
/// Suppose B is a copy of A with the value val appended to it.  It is 
/// guaranteed that B has unique values.
///
/// Return Construct(B).
/// 
/// Example 1:
/// Input: root = [4,1,3,null,null,2], val = 5
/// Output: [5,4,null,1,3,null,null,2]
/// Explanation: A = [1,4,2,3], B = [1,4,2,3,5]
///
/// Example 2:
/// Input: root = [5,2,4,null,1], val = 3
/// Output: [5,2,4,null,1,null,3]
/// Explanation: A = [2,1,5,4], B = [2,1,5,4,3]
///
/// Example 3:
/// Input: root = [5,2,3,null,1], val = 4
/// Output: [5,2,4,null,1,3]
/// Explanation: A = [2,1,5,3], B = [2,1,5,3,4]
/// 
/// Note:
/// 1. 1 <= B.length <= 100
/// </summary>
TreeNode* LeetCodeTree::insertIntoMaxTree(TreeNode* root, int val)
{
    if (root == nullptr || val > root->val)
    {
        TreeNode * node = new TreeNode(val);
        node->left = root;
        root = node;
    }
    else if (root->right == nullptr || val > root->right->val)
    {
        TreeNode * node = new TreeNode(val);
        node->left = root->right;
        root->right = node;
    }
    else
    {
        insertIntoMaxTree(root->right, val);
    }

    return root;
}

/// <summary>
/// Leet code #1008. Construct Binary Search Tree from Preorder Traversal
/// </summary>
TreeNode* LeetCodeTree::bstFromPreorder(TreeNode *root, stack<TreeNode*> &left_path, 
    vector<int>& preorder, size_t& index)
{
    if (index >= preorder.size()) return root;
    if (root == nullptr)
    {
        root = new TreeNode(preorder[index]);
        index++;
        bstFromPreorder(root, left_path, preorder, index);
    }
    else
    {
        if (root->val > preorder[index])
        {
            root->left = new TreeNode(preorder[index]);
            index++;
            left_path.push(root);
            bstFromPreorder(root->left, left_path, preorder, index);
        }
        else
        {
            TreeNode * parent = nullptr;
            while (!left_path.empty())
            {
                parent = left_path.top();
                if (parent->val > preorder[index]) break;
                root = parent;
                left_path.pop();
            }
            root->right = new TreeNode(preorder[index]);
            index++;
            bstFromPreorder(root->right, left_path, preorder, index);
        }
    }
    return root;
}

/// <summary>
/// Leet code #1008. Construct Binary Search Tree from Preorder Traversal
/// 
/// Return the root node of a binary search tree that matches the given 
/// preorder traversal.
///
/// (Recall that a binary search tree is a binary tree where for every 
/// node, any descendant of node.left has a value < node.val, and any 
/// descendant of node.right has a value > node.val.  Also recall that a 
/// preorder traversal displays the value of the node first, then 
/// traverses node.left, then traverses node.right.)
///
/// Example 1:
///
/// Input: [8,5,1,7,10,12]
/// Output: [8,5,10,1,7,null,12]
///
/// Note: 
///
/// 1. 1 <= preorder.length <= 100
/// 2. The values of preorder are distinct.
/// </summary>
TreeNode* LeetCodeTree::bstFromPreorder(vector<int>& preorder)
{
    stack<TreeNode *> left_path;
    TreeNode * root = nullptr;
    size_t index = 0;
    root = bstFromPreorder(root, left_path, preorder, index);
    return root;
}

/// <summary>
/// Leet code #1022. Sum of Root To Leaf Binary Numbers
/// </summary>
int LeetCodeTree::sumRootToLeaf(TreeNode* root, int value, int &result)
{
    if (root == nullptr) return result;
    if (root->left == nullptr && root->right == nullptr)
    {
        result += value * 2 + root->val;
        return result;
    }
    else
    {
        if (root->left != nullptr)
        {
            sumRootToLeaf(root->left, value * 2 + root->val, result);
        }
        if (root->right != nullptr)
        {
            sumRootToLeaf(root->right, value * 2 + root->val, result);
        }
        return result;
    }
}

/// <summary>
/// Leet code #1022. Sum of Root To Leaf Binary Numbers
/// 
/// Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path 
/// represents a binary number starting with the most significant bit.  For 
/// example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 
/// 01101 in binary, which is 13.
///
/// For all leaves in the tree, consider the numbers represented by the path 
/// from the root to that leaf.
///
/// Return the sum of these numbers.
///
/// 
/// Example 1:
///
/// Input: [1,0,1,0,1,0,1]
/// Output: 22
/// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
/// 
///
/// Note:
///
/// 1. The number of nodes in the tree is between 1 and 1000.
/// 2. node.val is 0 or 1.
/// 3. The answer will not exceed 2^31 - 1.
/// </summary>
int LeetCodeTree::sumRootToLeaf(TreeNode* root)
{
    int value = 0;
    int result = 0;
    sumRootToLeaf(root, value, result);
    return result;
}

/// <summary>
/// Leet code #1026. Maximum Difference Between Node and Ancestor
/// </summary>
int LeetCodeTree::maxAncestorDiff(TreeNode* root, int min_val, int max_val, int& result)
{
    if (root == nullptr) return result;
    result = max(result, abs(root->val - min_val));
    result = max(result, abs(root->val - max_val));
    maxAncestorDiff(root->left, min(root->val, min_val), max(root->val, max_val), result);
    maxAncestorDiff(root->right, min(root->val, min_val), max(root->val, max_val), result);
    
    return result;
}

/// <summary>
/// Leet code #1026. Maximum Difference Between Node and Ancestor
/// 
/// Given the root of a binary tree, find the maximum value V for which there 
/// exists different nodes A and B where V = |A.val - B.val| and A is an 
/// ancestor of B.
///
/// (A node A is an ancestor of B if either: any child of A is equal to B, or 
/// any child of A is an ancestor of B.)
///
/// Example 1:
/// 
/// Input: [8,3,10,1,6,null,14,null,null,4,7,13]
/// Output: 7
/// Explanation: 
/// We have various ancestor-node differences, some of which are given below :
/// |8 - 3| = 5
/// |3 - 7| = 4
/// |8 - 1| = 7
/// |10 - 13| = 3
/// Among all possible differences, the maximum value of 7 is obtained by 
/// |8 - 1| = 7.
/// 
/// Note:
///
/// 1. The number of nodes in the tree is between 2 and 5000.
/// 2. Each node will have value between 0 and 100000.
/// </summary>
int LeetCodeTree::maxAncestorDiff(TreeNode* root)
{
    int result = 0;
    maxAncestorDiff(root, root->val, root->val, result);
    
    return result;
}

/// <summary>
/// Leet code #1028. Recover a Tree From Preorder Traversal
/// </summary>
TreeNode* LeetCodeTree::recoverFromPreorder(TreeNode * root, int curr_depth, int& child_depth,
    int& child_val, string S, size_t &index)
{
    while (true)
    {
        if (index >= S.size() && child_depth == -1) break;
        if (child_depth == -1)
        {
            child_depth = 0;
            while (S[index] == '-')
            {
                child_depth++;
                index++;
            }
            string str_num;
            while (isdigit(S[index]))
            {
                str_num.push_back(S[index]);
                index++;
            }
            child_val = atoi(str_num.c_str());
        }
        if (root == nullptr)
        {
            root = new TreeNode(child_val);
            child_depth = -1;
            recoverFromPreorder(root, 0, child_depth, child_val, S, index);
            break;
        }
        if (child_depth <= curr_depth)
        {
            break;
        }
        if (root->left == nullptr)
        {
            root->left = new TreeNode(child_val);
            child_depth = -1;
            recoverFromPreorder(root->left, curr_depth + 1, child_depth, child_val, S, index);
        }
        else if (root->right == nullptr)
        {
            root->right = new TreeNode(child_val);
            child_depth = -1;
            recoverFromPreorder(root->right, curr_depth + 1, child_depth, child_val, S, index);
        }
        else
        {
            break;
        }
    }
    return root;
}

/// <summary>
/// Leet code #1028. Recover a Tree From Preorder Traversal
/// 
/// We run a preorder depth first search on the root of a binary tree.
///
/// At each node in this traversal, we output D dashes (where D is the depth 
/// of this node), then we output the value of this node.  (If the depth of 
/// a node is D, the depth of its immediate child is D+1.  The depth of the 
/// root node is 0.)
///
/// If a node has only one child, that child is guaranteed to be the left 
/// child.
///
/// Given the output S of this traversal, recover the tree and return its root.
///
/// Example 1:
/// 
/// Input: "1-2--3--4-5--6--7"
/// Output: [1,2,5,3,4,6,7]
///
/// Example 2:
/// 
/// Input: "1-2--3---4-5--6---7"
/// Output: [1,2,5,3,null,6,null,4,null,7]
/// 
/// Example 3:
/// 
/// Input: "1-401--349---90--88"
/// Output: [1,401,null,349,88,90]
/// 
/// Note:
/// 
/// 1. The number of nodes in the original tree is between 1 and 1000. 
/// 2. Each node will have a value between 1 and 10^9.
/// </summary>
TreeNode* LeetCodeTree::recoverFromPreorder(string S)
{
    TreeNode * root = nullptr;
    int child_depth = -1;
    int cur_depth = -1;
    int child_val = 0;
    size_t index = 0;
    return recoverFromPreorder(root, cur_depth, child_depth, child_val, S, index);
}

/// <summary>
/// Leet code #1038. Binary Search Tree to Greater Sum Tree
/// </summary>
void LeetCodeTree::bstToGst(TreeNode* root, int &sum)
{
    if (root == nullptr) return;
    bstToGst(root->right, sum);
    root->val += sum;
    sum = root->val;
    bstToGst(root->left, sum);
}

/// <summary>
/// Leet code #1038. Binary Search Tree to Greater Sum Tree
/// 
/// Given the root of a binary search tree with distinct values, modify it so 
/// that every node has a new value equal to the sum of the values of the 
/// original tree that are greater than or equal to node.val.
///
/// As a reminder, a binary search tree is a tree that satisfies these 
/// constraints:
///
/// The left subtree of a node contains only nodes with keys less than the 
/// node's key.
/// The right subtree of a node contains only nodes with keys greater than 
/// the node's key.
/// Both the left and right subtrees must also be binary search trees.
/// 
/// Example 1:
/// 
///
/// Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
/// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
/// 
/// Note:
///
/// 1. The number of nodes in the tree is between 1 and 100.
/// 2. Each node will have value between 0 and 100.
/// 3. The given tree is a binary search tree.
/// </summary>
TreeNode* LeetCodeTree::bstToGst(TreeNode* root)
{
    int sum = 0;
    bstToGst(root, sum);
    return root;
}

/// <summary>
/// Leet code #1080. Insufficient Nodes in Root to Leaf Paths
/// </summary>
TreeNode* LeetCodeTree::sufficientSubset(TreeNode* root, int limit, int sum)
{
    if (root == nullptr) return root;
    sum += root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (sum < limit)
        {
            freeTreeNodes(root);
            return nullptr;
        }
        else return root;
    }
    root->left = sufficientSubset(root->left, limit, sum);
    root->right = sufficientSubset(root->right, limit, sum);
    if (root->left == nullptr && root->right == nullptr)
    {
        freeTreeNodes(root);
        return nullptr;
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #1080. Insufficient Nodes in Root to Leaf Paths
/// 
/// Given the root of a binary tree, consider all root to leaf paths: paths 
/// from the root to any leaf.  (A leaf is a node with no children.)
///
/// A node is insufficient if every such root to leaf path intersecting this 
/// node has sum strictly less than limit.
///
/// Delete all insufficient nodes simultaneously, and return the root of the 
/// resulting binary tree.
///
/// 
/// Example 1:
///
/// Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
///
/// Output: [1,2,3,4,null,null,7,8,9,null,14]
///
/// Example 2:
///
/// Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
///
/// Output: [5,4,8,11,null,17,4,7,null,null,null,5]
///
/// Note:
///
/// 1. The given tree will have between 1 and 5000 nodes.
/// 2. -10^5 <= node.val <= 10^5
/// 3. -10^9 <= limit <= 10^9
/// </summary>
TreeNode* LeetCodeTree::sufficientSubset(TreeNode* root, int limit)
{
    int sum = 0;
    root = sufficientSubset(root, limit, sum);
    return root;
}

/// <summary>
/// Leet code #1104. Path In Zigzag Labelled Binary Tree
/// 
/// In an infinite binary tree where every node has two children, the nodes 
/// are labelled in row order.
///
/// In the odd numbered rows (ie., the first, third, fifth,...), the labelling 
/// is left to right, while in the even numbered rows (second, fourth, 
/// sixth,...), the labelling is right to left.
/// 
/// Given the label of a node in this tree, return the labels in the path from 
/// the root of the tree to the node with that label.
///
/// Example 1:
/// Input: label = 14
/// Output: [1,3,4,14]
///
/// Example 2:
/// Input: label = 26
/// Output: [1,2,6,10,26]
///
/// Constraints:
///
/// 1. 1 <= label <= 10^6
/// </summary>
vector<int> LeetCodeTree::pathInZigZagTree(int label)
{
    int sum = 1;
    int level = 1;
    int start = 1;
    while (label > sum)
    {
        level++;
        sum = 2 * sum + 1;
        start *= 2;
    }

    vector<int> result;

    int index = 0;
    if (level % 2 == 1) index = label;
    else index = start * 2 - 1 - (label - start);
    while (level > 0)
    {
        if (level % 2 == 1) label = index;
        else label = start * 2 - 1 - (index - start);
        result.push_back(label);

        level--;
        start /= 2;
        index /= 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #1110. Delete Nodes And Return Forest
/// </summary>
TreeNode* LeetCodeTree::delNodes(TreeNode* root, vector<int>& del_bit, vector<TreeNode*> &result)
{
    if (root == nullptr) return root;
    root->left = delNodes(root->left, del_bit, result);
    root->right = delNodes(root->right, del_bit, result);
    if (del_bit[root->val] == 1)
    {
        if (root->left != nullptr) result.push_back(root->left);
        if (root->right != nullptr) result.push_back(root->right);
        delete root;
        return nullptr;
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #1110. Delete Nodes And Return Forest
/// 
/// Given the root of a binary tree, each node in the tree has a distinct 
/// value.
///
/// After deleting all nodes with a value in to_delete, we are left with a 
/// forest (a disjoint union of trees).
///
/// Return the roots of the trees in the remaining forest.  You may return 
/// the result in any order.
/// 
/// Example 1:
///
/// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
/// Output: [[1,2,null,4],[6],[7]]
/// 
/// Constraints:
/// 1. The number of nodes in the given tree is at most 1000.
/// 2. Each node has a distinct value between 1 and 1000.
/// 3. to_delete.length <= 1000
/// 4. to_delete contains distinct values between 1 and 1000.
/// </summary>
vector<TreeNode*> LeetCodeTree::delNodes(TreeNode* root, vector<int>& to_delete)
{
    vector<int> del_bit(1001);
    for (size_t i = 0; i < to_delete.size(); i++)
    {
        del_bit[to_delete[i]] = 1;
    }
    vector<TreeNode*> result;
    root = delNodes(root, del_bit, result);
    if (root != nullptr) result.push_back(root);

    return result;
}

/// <summary>
/// Leet code #1120. Maximum Average Subtree
/// </summary>
double LeetCodeTree::maximumAverageSubtree(TreeNode* root, double& sum, int& count)
{
    if (root == nullptr)
    {
        return (double)0.0;
    }
    else
    {
        double result = 0.0;
        double left_sum = 0, right_sum = 0;
        int left_count = 0, right_count = 0;
        result = max(result, maximumAverageSubtree(root->left, left_sum, left_count));
        result = max(result, maximumAverageSubtree(root->right, right_sum, right_count));
        sum = left_sum + right_sum + root->val;
        count = left_count + right_count + 1;
        result = max(result, sum / count);
        
        return result;
    }
}

/// <summary>
/// Leet code #1120. Maximum Average Subtree
/// 
/// Given the root of a binary tree, find the maximum average value of any 
/// subtree of that tree.
/// (A subtree of a tree is any node of that tree plus all its descendants. 
/// The average value of a tree is the sum of its values, divided by the 
/// number of nodes.)
/// 
/// Example 1:
/// Input: [5,6,1]
/// Output: 6.00000
/// Explanation: 
/// For the node with value = 5 we have and average of (5 + 6 + 1) / 3 = 4.
/// For the node with value = 6 we have and average of 6 / 1 = 6.
/// For the node with value = 1 we have and average of 1 / 1 = 1.
/// So the answer is 6 which is the maximum.
/// 
/// Note:
/// 1. The number of nodes in the tree is between 1 and 5000.
/// 2. Each node will have a value between 0 and 100000.
/// 3. Answers will be accepted as correct if they are within 10^-5 of the 
///    correct answer.
/// </summary>
double LeetCodeTree::maximumAverageSubtree(TreeNode* root)
{
    double sum = 0.0;
    int count = 0;
    double result = maximumAverageSubtree(root, sum, count);
    return result;
}

/// <summary>
/// Leet code #1123. Lowest Common Ancestor of Deepest Leaves
/// </summary>
TreeNode* LeetCodeTree::lcaDeepestLeaves(TreeNode* root, int& depth)
{
    if (root == nullptr) return root;
    depth++;
    int left_depth = depth;
    TreeNode* left_ancestor = lcaDeepestLeaves(root->left, left_depth);
    int right_depth = depth;
    TreeNode* right_ancestor = lcaDeepestLeaves(root->right, right_depth);

    if (left_depth == right_depth)
    {
        depth = left_depth;
        return root;
    }
    else if (left_depth > right_depth)
    {
        depth = left_depth;
        return left_ancestor;
    }
    else
    {
        depth = right_depth;
        return right_ancestor;
    }
}

/// <summary>
/// Leet code #1123. Lowest Common Ancestor of Deepest Leaves
/// 
/// Given a rooted binary tree, return the lowest common ancestor of its 
/// deepest leaves.
/// Recall that:
/// The node of a binary tree is a leaf if and only if it has no children
/// The depth of the root of the tree is 0, and if the depth of a node is 
/// d, the depth of each of its children is d+1.
/// The lowest common ancestor of a set S of nodes is the node A with the 
/// largest depth such that every node in S is in the subtree with root A.
/// 
/// Example 1:
/// Input: root = [1,2,3]
/// Output: [1,2,3]
/// Explanation: 
/// The deepest leaves are the nodes with values 2 and 3.
/// The lowest common ancestor of these leaves is the node with value 1.
/// The answer returned is a TreeNode object (not an array) with 
/// serialization "[1,2,3]".
///
/// Example 2:
/// Input: root = [1,2,3,4]
/// Output: [4]
///
/// Example 3:
/// Input: root = [1,2,3,4,5]
/// Output: [2,4,5]
/// 
/// Constraints:
/// 1. The given tree will have between 1 and 1000 nodes.
/// 2. Each node of the tree will have a distinct value between 1 and 1000.
/// </summary>
TreeNode* LeetCodeTree::lcaDeepestLeaves(TreeNode* root)
{
    int depth = 0;
    return lcaDeepestLeaves(root, depth);
}

/// <summary>
/// Leet code #1145. Binary Tree Coloring Game
/// </summary>
int LeetCodeTree::btreeGameWinningMove(TreeNode* root, int &curr, int &left, int &right, int x)
{
    if (root == nullptr) return 0;

    int left_sum = btreeGameWinningMove(root->left, curr, left, right, x);
    int right_sum = btreeGameWinningMove(root->right, curr, left, right, x);
    int sum = 1;
    sum += left_sum + right_sum;
    if (root->val == x)
    {
        left = left_sum;
        right = right_sum;
        curr = sum;
    }
    return sum;
}

/// <summary>
/// Leet code #1145. Binary Tree Coloring Game
/// 
/// Two players play a turn based game on a binary tree.  We are given the 
/// root of this binary tree, and the number of nodes n in the tree.  n is 
/// odd, and each node has a distinct value from 1 to n.
///
/// Initially, the first player names a value x with 1 <= x <= n, and the 
/// second player names a value y with 1 <= y <= n and y != x.  The first 
/// player colors the node with value x red, and the second player colors 
/// the node with value y blue.
///
/// Then, the players take turns starting with the first player.  In each 
/// turn, that player chooses a node of their color (red if player 1, blue 
/// if player 2) and colors an uncolored neighbor of the chosen node 
/// (either the left child, right child, or parent of the chosen node.)
///
/// If (and only if) a player cannot choose such a node in this way, they 
/// must pass their turn.  If both players pass their turn, the game ends, 
/// and the winner is the player that colored more nodes.
///
/// You are the second player.  If it is possible to choose such a y to 
/// ensure you win the game, return true.  If it is not possible, return 
/// false.
///
/// Example 1:
/// 
/// Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
/// Output: true
/// Explanation: The second player can choose the node with value 2.
/// 
///
/// Constraints:
/// 
/// 1. root is the root of a binary tree with n nodes and distinct node 
///    values from 1 to n.
/// 2. n is odd.
/// 3. 1 <= x <= n <= 100
/// </summary>
bool LeetCodeTree::btreeGameWinningMove(TreeNode* root, int n, int x)
{
    int curr = 0;
    int left = 0;
    int right = 0;
    btreeGameWinningMove(root, curr, left, right, x);
    if (left > n - left || right > n - right || n - curr > curr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #1161. Maximum Level Sum of a Binary Tree
/// 
/// Given the root of a binary tree, the level of its root is 1, the level 
/// of its children is 2, and so on.
/// Return the smallest level X such that the sum of all the values of nodes 
/// at level X is maximal.
/// 
/// Example 1:
///
/// Input: [1,7,0,7,-8,null,null]
/// Output: 2
/// Explanation: 
/// Level 1 sum = 1.
/// Level 2 sum = 7 + 0 = 7.
/// Level 3 sum = 7 + -8 = -1.
/// So we return the level with the maximum sum which is level 2.
/// 
/// Note:
/// 1. The number of nodes in the given tree is between 1 and 10^4.
/// 2. -10^5 <= node.val <= 10^5
/// </summary>
int LeetCodeTree::maxLevelSum(TreeNode* root)
{
    int max_sum = INT_MIN;
    queue<TreeNode*> search;
    search.push(root);
    int level = 0;
    int result = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        level++;
        int sum = 0;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = search.front();
            search.pop();
            if (node == nullptr) continue;
            sum += node->val;
            search.push(node->left);
            search.push(node->right);
        }
        if (sum > max_sum)
        {
            max_sum = sum;
            result = level;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1214. Two Sum BSTs      
///
/// Given two binary search trees, return True if and only if there is a 
/// node in the first tree and a node in the second tree whose values 
/// sum up to a given integer target.
/// 
/// Example 1:
///
/// Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
/// Output: true
/// Explanation: 2 and 3 sum up to 5.
///
/// Example 2:
///
/// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
/// Output: false
/// 
/// Constraints:
/// 1. Each tree has at most 5000 nodes.
/// 2. -10^9 <= target, node.val <= 10^9
/// </summary>
bool LeetCodeTree::twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
{
    int result = false;
    queue<TreeNode*> search;
    search.push(root1);

    while (!search.empty())
    {
        TreeNode* node = search.front();
        search.pop();
        if (node == nullptr) continue;
        search.push(node->left);
        search.push(node->right);

        int num = target - node->val;

        node = root2;
        while (node != nullptr)
        {
            if (node->val == num) return true;
            else if (node->val < num)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
    return false;
}

/// <summary>
/// Decodes your encoded data to tree.
/// </summary>
/// <param name="data">the string data</param>
/// <returns>The root</returns>
TreeNode* LeetCodeTree::deserialize(string data)
{
    queue<TreeNode*> input_queue;
    queue<TreeNode*> output_queue;
    string number;
    for (size_t i = 0; i < data.size(); i++)
    {
        if ((data[i] == '[') || (data[i] == ',') || data[i] == ']' ||
            isspace(data[i]))
        {
            if (number.size() != 0)
            {
                if (number == "null")
                {
                    input_queue.push(nullptr);
                }
                else
                {
                    input_queue.push(new TreeNode(std::stoi(number)));
                }
                number.clear();
            }
        }
        else
        {
            number.push_back(data[i]);
        }
    }
    TreeNode* root = nullptr;
    TreeNode* node = nullptr;
    while (!input_queue.empty())
    {
        if (output_queue.empty())
        {
            root = input_queue.front();
            input_queue.pop();
            node = root;
            output_queue.push(node);
        }
        else
        {
            node = output_queue.front();
            output_queue.pop();
            if (node != nullptr)
            {
                if (!input_queue.empty())
                {
                    node->left = input_queue.front();
                    if (node->left != nullptr) node->left->parent = node;
                    input_queue.pop();
                }
                if (!input_queue.empty())
                {
                    node->right = input_queue.front();
                    if (node->right != nullptr) node->right->parent = node;
                    input_queue.pop();
                }
                output_queue.push(node->left);
                output_queue.push(node->right);
            }
        }
    }
    return root;
}

/// <summary>
/// Leetcode #1305. All Elements in Two Binary Search Trees
///
/// Medium
///
/// Given two binary search trees root1 and root2.
/// Return a list containing all the integers from both trees sorted in 
/// ascending order.
/// 
/// Example 1:
/// Input: root1 = [2,1,4], root2 = [1,0,3]
/// Output: [0,1,1,2,3,4]
///
/// Example 2:
/// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
/// Output: [-10,0,0,1,2,5,7,10]
///
/// Example 3:
/// Input: root1 = [], root2 = [5,1,7,0,2]
/// Output: [0,1,2,5,7]
///
/// Example 4:
/// Input: root1 = [0,-10,10], root2 = []
/// Output: [-10,0,10]
///
/// Example 5:
/// Input: root1 = [1,null,8], root2 = [8,1]
/// Output: [1,1,8,8]
///
/// Constraints:
/// 1. Each tree has at most 5000 nodes.
/// 2. Each node's value is between [-10^5, 10^5].
/// </summary>
vector<int> LeetCodeTree::getAllElements(TreeNode* root1, TreeNode* root2)
{
    vector<int> result;
    queue<TreeNode*> search;
    search.push(root1);
    while (!search.empty())
    {
        TreeNode* node = search.front();
        search.pop();
        if (node == nullptr) continue;
        result.push_back(node->val);
        search.push(node->left);
        search.push(node->right);
    }
    search.push(root2);
    while (!search.empty())
    {
        TreeNode* node = search.front();
        search.pop();
        if (node == nullptr) continue;
        result.push_back(node->val);
        search.push(node->left);
        search.push(node->right);
    }
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leetcode #1302. Deepest Leaves Sum
///
/// Medium
///
/// Given a binary tree, return the sum of values of its deepest leaves.
/// 
/// Example 1:
///
/// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
/// Output: 15
/// 
/// Constraints:
/// 1. The number of nodes in the tree is between 1 and 10^4.
/// 2. The value of nodes is between 1 and 100.
/// </summary>
int LeetCodeTree::deepestLeavesSum(TreeNode* root)
{
    queue<TreeNode*> search;
    search.push(root);
    int result = 0;

    while (!search.empty())
    {
        size_t size = search.size();
        result = 0;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = search.front();
            search.pop();
            result += node->val;
            if (node->left != nullptr) search.push(node->left);
            if (node->right != nullptr) search.push(node->right);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1315. Sum of Nodes with Even-Valued Grandparent
///
/// Medium
///
/// Given a binary tree, return the sum of values of nodes with 
/// even-valued grandparent.  (A grandparent of a node is the parent 
/// of its parent, if it exists.)
/// If there are no nodes with an even-valued grandparent, return 0.
/// 
/// Example 1:
///
/// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
/// Output: 18
/// Explanation: The red nodes are the nodes with even-value grandparent 
/// while the blue nodes are the even-value grandparents.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is between 1 and 10^4.
/// 2. The value of nodes is between 1 and 100.
/// </summary>
int LeetCodeTree::sumEvenGrandparent(TreeNode* root)
{
    queue<vector<TreeNode*>> search;
    vector<TreeNode*> node = { nullptr, nullptr, root };
    search.push(node);
    
    int result = 0;
    while (!search.empty())
    {
        node = search.front();
        search.pop();

        if ((node[0] != nullptr) && (node[0]->val % 2 == 0))
        {
            result += node[2]->val;
        }

        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[1]->left;
        if (node[2] != nullptr)
        {
            search.push(node);
        }
        node[2] = node[1]->right;
        if (node[2] != nullptr)
        {
            search.push(node);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1325. Delete Leaves With a Given Value
///
/// Medium
///
/// Given a binary tree root and an integer target, delete all the leaf 
/// nodes with value target.
///
/// Note that once you delete a leaf node with value target, if it's 
/// parent node becomes a leaf node and has the value target, it should 
/// also be deleted (you need to continue doing that until you can't).
/// 
/// Example 1:
/// Input: root = [1,2,3,2,null,2,4], target = 2
/// Output: [1,null,3,null,4]
/// Explanation: Leaf nodes in green with value (target = 2) are removed 
/// (Picture in left). 
/// After removing, new nodes become leaf nodes with value (target = 2) 
/// (Picture in center).
///
/// Example 2:
/// Input: root = [1,3,3,3,2], target = 3
/// Output: [1,3,null,null,2]
///
/// Example 3:
/// Input: root = [1,2,null,2,null,2], target = 2
/// Output: [1]
/// Explanation: Leaf nodes in green with value (target = 2) are removed 
/// at each step.
/// 
/// Example 4:
/// Input: root = [1,1,1], target = 1
/// Output: []
///
/// Example 5:
/// Input: root = [1,2,3], target = 1
/// Output: [1,2,3]
/// 
/// Constraints:
/// 1. 1 <= target <= 1000
/// 2. Each tree has at most 3000 nodes.
/// 3. Each node's value is between [1, 1000].
/// </summary>
TreeNode* LeetCodeTree::removeLeafNodes(TreeNode* root, int target)
{
    if (root == nullptr) return root;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->val == target)
        {
            return nullptr;
        }
    }
    return root;
}

/// <summary>
/// Leet code #1343. Maximum Product of Splitted Binary Tree 
/// </summary>
long long LeetCodeTree::maxProduct(TreeNode* root, long long sum, long long &result)
{
    if (root == nullptr) return 0;
    long long left = maxProduct(root->left, sum, result);
    result = max(left * (sum - left), result);
    long long right = maxProduct(root->right, sum, result);
    result = max(right * (sum - right), result);
    return left + right + root->val;
}

/// <summary>
/// Leet code #1339. Maximum Product of Splitted Binary Tree 
/// 
/// Medium
///
/// Given a binary tree root. Split the binary tree into two subtrees by 
/// removing 1 edge such that the product of the sums of the subtrees are 
/// maximized.
///
/// Since the answer may be too large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: root = [1,2,3,4,5,6]
/// Output: 110
/// Explanation: Remove the red edge and get 2 binary trees with sum 11 
/// and 10. Their product is 110 (11*10)
///
/// Example 2:
/// Input: root = [1,null,2,3,4,null,null,5,6]
/// Output: 90
/// Explanation:  Remove the red edge and get 2 binary trees with sum 15 
/// and 6.Their product is 90 (15*6)
/// 
/// Example 3:
/// Input: root = [2,3,9,10,7,8,6,5,4,11,1]
/// Output: 1025
///
/// Example 4:
/// Input: root = [1,1]
/// Output: 1
/// 
/// Constraints:
/// 1. Each tree has at most 50000 nodes and at least 2 nodes.
/// 2. Each node's value is between [1, 10000].
/// </summary>
int LeetCodeTree::maxProduct(TreeNode* root)
{
    long long sum = 0;
    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty())
    {
        TreeNode * node = q.front();
        q.pop();
        sum += node->val;
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }

    long long M = 1000000007;
    long long result = 0;
    maxProduct(root, sum, result);
    
    return (int)(result % M);
}

/// <summary>
/// Leet code #1367. Linked List in Binary Tree
/// </summary>
bool LeetCodeTree::isSubPath(ListNode* head, TreeNode* root, vector<ListNode *> &lead)
{
    if (root == nullptr) return false;
    if (lead.empty()) return false;
    vector<ListNode *> next;
    for (size_t i = 0; i < lead.size(); i++)
    {
        if (lead[i]->val == root->val)
        {
            if (lead[i]->next == nullptr)
            {
                return true;
            }
            else
            {
                next.push_back(lead[i]->next);
            }
        }
    }
    next.push_back(head);
    return isSubPath(head, root->left, next) || isSubPath(head, root->right, next);
}

/// <summary>
/// Leet code #1367. Linked List in Binary Tree
///
/// Medium
///
/// Given a binary tree root and a linked list with head as the first node.
///	
/// Return True if all the elements in the linked list starting from the 
/// head correspond to some downward path connected in the binary tree 
/// otherwise return False.
///
/// In this context downward path means a path that starts at some node 
/// and goes downwards.
///
/// Example 1:
/// Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,
/// null,null,null,1,3]
/// Output: true
/// Explanation: Nodes in blue form a subpath in the binary Tree.  
///
/// Example 2:
/// Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,
/// null,null,null,null,1,3]
/// Output: true
///
/// Example 3:
/// Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,
/// null,null,null,null,1,3]
/// Output: false
/// Explanation: There is no path in the binary tree that contains all 
/// the elements of the linked list from head.
///
/// Constraints:
/// 1. 1 <= node.val <= 100 for each node in the linked list and binary 
///    tree.
/// 2. The given linked list will contain between 1 and 100 nodes.
/// 3. The given binary tree will contain between 1 and 2500 nodes.
/// </summary>
bool LeetCodeTree::isSubPath(ListNode* head, TreeNode* root)
{
    vector<ListNode*> next;
    next.push_back(head);
    return isSubPath(head, root, next);
}

/// <summary>
/// Leet code #1372. Longest ZigZag Path in a Binary Tree
///  
/// Medium
///
/// Given a binary tree root, a ZigZag path for a binary tree is defined 
/// as follow:
///
/// Choose any node in the binary tree and a direction (right or left).
/// If the current direction is right then move to the right child of the 
/// current node otherwise move to the left child.
/// Change the direction from right to left or right to left.
/// Repeat the second and third step until you can't move in the tree.
/// Zigzag length is defined as the number of nodes visited - 1. 
/// (A single node has a length of 0).
///
/// Return the longest ZigZag path contained in that tree.
///
/// Example 1:
/// Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,
/// 1,null,1]
/// Output: 3
/// Explanation: Longest ZigZag path in blue nodes 
/// (right -> left -> right).
/// 
/// Example 2:
/// Input: root = [1,1,1,null,1,null,null,1,1,null,1]
/// Output: 4
/// Explanation: Longest ZigZag path in blue nodes (left -> right -> 
/// left -> right).
///
/// Example 3:
/// Input: root = [1]
/// Output: 0
/// 
/// Constraints:
/// 1. Each tree has at most 50000 nodes..
/// 2. Each node's value is between [1, 100].
/// </summary>
int LeetCodeTree::longestZigZag(TreeNode* root)
{
    queue<pair<TreeNode *, pair<int, int>>> queue;
    queue.push(make_pair(root, make_pair( -1, 0 )));

    int result = 0;
    while (!queue.empty())
    {
        pair<TreeNode *, pair<int, int>> node = queue.front();
        queue.pop();
        result = max(result, node.second.second);
        TreeNode * left = node.first->left;
        if (left != nullptr)
        {
            if (node.second.first == 0)
            {
                queue.push(make_pair(left, make_pair(0, 1)));
            }
            else
            {
                queue.push(make_pair(left, make_pair(0, node.second.second + 1)));
            }
        }
        TreeNode * right = node.first->right;
        if (right != nullptr)
        {
            if (node.second.first == 1)
            {
                queue.push(make_pair(right, make_pair(1, 1)));
            }
            else
            {
                queue.push(make_pair(right, make_pair(1, node.second.second + 1)));
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1373. Maximum Sum BST in Binary Tree
/// </summary>
int LeetCodeTree::maxSumBST(TreeNode* root, int &min_val, int&max_val, bool &is_bst, int &max_sum)
{
    int sum = 0;

    if (root == nullptr)
    {
        max_sum = 0;
        return sum;
    }
    if (root->left != nullptr)
    {
        int left_min = INT_MAX;
        int left_max = INT_MIN;
        bool left_is_bst = true;
        int left_max_sum = 0;
        int left_sum = maxSumBST(root->left, left_min, left_max, left_is_bst, left_max_sum);
        is_bst = is_bst && left_is_bst && (left_max < root->val);
        max_sum = max(max_sum, left_max_sum);
        min_val = min(min_val, left_min);
        max_val = max(max_val, left_max);
        sum += left_sum;
    }
    if (root->right != nullptr)
    {
        int right_min = INT_MAX;
        int right_max = INT_MIN;
        bool right_is_bst = true;
        int right_max_sum = 0;
        int right_sum = maxSumBST(root->right, right_min, right_max, right_is_bst, right_max_sum);
        is_bst = is_bst && right_is_bst && (right_min > root->val);
        max_sum = max(max_sum, right_max_sum);
        min_val = min(min_val, right_min);
        max_val = max(max_val, right_max);
        sum += right_sum;
    }
    sum += root->val;
    min_val = min(min_val, root->val);
    max_val = max(max_val, root->val);
    if (is_bst)
    {
        max_sum = max(max_sum, sum);
    }
    return sum;
}

/// <summary>
/// Leet code #1373. Maximum Sum BST in Binary Tree
///  
/// Hard
///
/// Given a binary tree root, the task is to return the maximum sum 
/// of all keys of any sub-tree which is also a Binary Search Tree (BST).
///
/// Assume a BST is defined as follows:
/// 
/// The left subtree of a node contains only nodes with keys less than 
/// the node's key.
/// The right subtree of a node contains only nodes with keys greater 
/// than the node's key.
/// Both the left and right subtrees must also be binary search trees.
///
/// Example 1:
/// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
/// Output: 20
/// Explanation: Maximum sum in a valid Binary search tree is obtained 
/// in root node with key equal to 3.
///
/// Example 2:
/// Input: root = [4,3,null,1,2]
/// Output: 2
/// Explanation: Maximum sum in a valid Binary search tree is obtained 
/// in a single root node with key equal to 2.
///
/// Example 3:
/// Input: root = [-4,-2,-5]
/// Output: 0
/// Explanation: All values are negatives. Return an empty BST.
///
/// Example 4:
/// Input: root = [2,1,3]
/// Output: 6
///
/// Example 5:
///
/// Input: root = [5,4,8,3,null,6,3]
/// Output: 7
/// Constraints:
/// 1. Each tree has at most 40000 nodes..
/// 2. Each node's value is between [-4 * 10^4 , 4 * 10^4].
/// </summary>
int LeetCodeTree::maxSumBST(TreeNode* root)
{
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    bool is_bst = true;
    int max_sum = 0;
    maxSumBST(root, min_val, max_val, is_bst, max_sum);
    return max_sum;
}

/// <summary>
/// Leet code #1379. Find a Corresponding Node of a Binary Tree in a 
///                  Clone of That Tree
///
/// Medium
///
/// Given two binary trees original and cloned and given a reference to a 
/// node target in the original tree.
///
/// The cloned tree is a copy of the original tree.
///
/// Return a reference to the same node in the cloned tree.
/// 
/// Note that you are not allowed to change any of the two trees or the 
/// target node and the answer must be a reference to a node in the cloned 
/// tree.
///
/// Follow up: Solve the problem if repeated values on the tree are 
/// allowed.
/// 
/// Example 1:
/// Input: tree = [7,4,3,null,null,6,19], target = 3
/// Output: 3
/// Explanation: In all examples the original and cloned trees are shown. 
/// The target node is a green node from the original tree. The answer is 
/// the yellow node from the cloned tree.
///
/// Example 2:
/// Input: tree = [7], target =  7
/// Output: 7
///
/// Example 3:
/// Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
/// Output: 4
///
/// Example 4:
/// Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
/// Output: 5
///
/// Example 5:
/// Input: tree = [1,2,null,3], target = 2
/// Output: 2
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^4].
/// 2. The values of the nodes of the tree are unique.
/// 3. target node is a node from the original tree and is not null.
/// </summary>
TreeNode* LeetCodeTree::getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
{
    queue<TreeNode*> queue;
    queue.push(original);
    queue.push(cloned);
    while (!queue.empty())
    {
        TreeNode * node = queue.front();
        queue.pop();
        TreeNode * result = queue.front();
        queue.pop();
        if (node == target) return result;
        if (node->left != nullptr)
        {
            queue.push(node->left);
            queue.push(result->left);
        }
        if (node->right != nullptr)
        {
            queue.push(node->right);
            queue.push(result->right);
        }
    }
    return nullptr;
}

/// <summary>
/// Leet code #1382. Balance a Binary Search Tree
/// </summary>
void LeetCodeTree::balanceBST(TreeNode* root, vector<TreeNode *> &node_list)
{
    if (root == nullptr) return;
    balanceBST(root->left, node_list);
    node_list.push_back(root);
    balanceBST(root->right, node_list);
}

/// <summary>
/// Leet code #1382. Balance a Binary Search Tree
/// </summary>
TreeNode * LeetCodeTree::balanceBST(vector<TreeNode *> &node_list, int start, int end)
{
    if (start > end) return nullptr;
    int middle = start + (end - start) / 2;
    TreeNode * root = node_list[middle];
    root->left = balanceBST(node_list, start, middle - 1);
    root->right = balanceBST(node_list, middle + 1, end);
    return root;
}

/// <summary>
/// Leet code #1382. Balance a Binary Search Tree
///
/// Medium
///
/// Given a binary search tree, return a balanced binary search tree with 
/// the same node values.
///
/// A binary search tree is balanced if and only if the depth of the two 
/// subtrees of every node never differ by more than 1.
///
/// If there is more than one answer, return any of them.
/// 
/// Example 1:
/// Input: root = [1,null,2,null,3,null,4,null,null]
/// Output: [2,1,3,null,null,null,4]
/// Explanation: This is not the only correct answer, 
/// [3,1,4,null,2,null,null] is also correct.
///
/// 
/// Constraints:
/// 1. The number of nodes in the tree is between 1 and 10^4.
/// 2. The tree nodes will have distinct values between 1 and 10^5.
/// </summary>
TreeNode* LeetCodeTree::balanceBST(TreeNode* root)
{
    vector<TreeNode *> node_list;
    balanceBST(root, node_list);
    return balanceBST(node_list, 0, node_list.size() - 1);
}

/// <summary>
/// Leet code #1430. Check If a String Is a Valid Sequence from Root to 
////                 Leaves Path in a Binary Tree
/// </summary>
bool LeetCodeTree::isValidSequence(TreeNode* root, vector<int>& arr, int pos)
{
    if (root == nullptr) return false;
    if (pos == arr.size()) return false;

    if (root->val != arr[pos]) return false;
    if (pos == arr.size() - 1)
    {
        return (root->left == nullptr && root->right == nullptr);
    }
    return (isValidSequence(root->left, arr, pos + 1) || isValidSequence(root->right, arr, pos + 1));
}

/// <summary>
/// Leet code #1430. Check If a String Is a Valid Sequence from Root to 
///                  Leaves Path in a Binary Tree
/// 
/// Medium
///
/// Given a binary tree where each path going from the root to any leaf 
/// form a valid sequence, check if a given string is a valid sequence 
/// in such binary tree. 
///
/// We get the given string from the concatenation of an array of integers 
/// arr and the concatenation of all values of the nodes along a path 
/// results in a sequence in the given binary tree.
///
/// Example 1:
/// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
/// Output: true
/// Explanation: 
/// The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the 
/// figure). 
/// Other valid sequences are: 
/// 0 -> 1 -> 1 -> 0 
/// 0 -> 0 -> 0
///
/// Example 2:
/// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
/// Output: false 
/// Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not 
/// even a sequence.
///
/// Example 3:
/// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
/// Output: false
/// Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a 
/// valid sequence.
///
/// Constraints:
/// 1. 1 <= arr.length <= 5000
/// 2. 0 <= arr[i] <= 9
/// 3. Each node's value is between [0 - 9].
/// </summary>
bool LeetCodeTree::isValidSequence(TreeNode* root, vector<int>& arr)
{
    return isValidSequence(root, arr, 0);
}

/// <summary>
/// Leet code #1448. Count Good Nodes in Binary Tree
///
/// Medium
///
/// Given a binary tree root, a node X in the tree is named good if in 
/// the path from root to X there are no nodes with a value greater 
/// than X.
///
/// Return the number of good nodes in the binary tree.
///
/// Example 1:
/// Input: root = [3,1,4,3,null,1,5]
/// Output: 4
/// Explanation: Nodes in blue are good.
/// Root Node (3) is always a good node.
/// Node 4 -> (3,4) is the maximum value in the path starting from 
///                 the root.
/// Node 5 -> (3,4,5) is the maximum value in the path
/// Node 3 -> (3,1,3) is the maximum value in the path.
///
/// Example 2:
/// Input: root = [3,3,null,4,2]
/// Output: 3
/// Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher 
/// than it.
///
/// Example 3:
/// Input: root = [1]
/// Output: 1
/// Explanation: Root is considered as good.
/// Constraints:
/// 1. The number of nodes in the binary tree is in the range [1, 10^5].
/// 2. Each node's value is between [-10^4, 10^4].
/// </summary>
int LeetCodeTree::goodNodes(TreeNode* root)
{
    int result = 0;
    queue<pair<int, TreeNode*>> search;
    search.push(make_pair(root->val, root));
    while (!search.empty())
    {
        pair<int, TreeNode*> pos = search.front();
        search.pop();
        int max_val = pos.first;
        TreeNode* node = pos.second;
        if (max_val <= node->val) result++;
        if (node->left != nullptr)
        {
            search.push(make_pair(max(node->left->val, max_val), node->left));
        }
        if (node->right != nullptr)
        {
            search.push(make_pair(max(node->right->val, max_val), node->right));
        }
    }
    return result;
}

/// <summary>
/// Leet code #1457. Pseudo-Palindromic Paths in a Binary Tree
/// </summary>
int LeetCodeTree::pseudoPalindromicPaths(TreeNode* root, unordered_map<int, int>& num_map)
{
    int result = 0;
    if (root == nullptr) return result;
    num_map[root->val]++;
    if (root->left == nullptr && root->right == nullptr)
    {
        int odd = 0;
        int even = 0;
        for (auto itr : num_map)
        {
            if (itr.second % 2 == 0) even++;
            else odd++;
        }
        if (odd <= 1) result++;
    }
    
    if (root->left != nullptr)
    {
        result += pseudoPalindromicPaths(root->left, num_map);
    }
    if (root->right != nullptr)
    {
        result += pseudoPalindromicPaths(root->right, num_map);
    }
    num_map[root->val]--;
    
    if (num_map[root->val] == 0) num_map.erase(root->val);

    return result;
}

/// <summary>
/// Leet code #1457. Pseudo-Palindromic Paths in a Binary Tree
///                
/// Medium
/// 
/// Given a binary tree where node values are digits from 1 to 9. A 
/// path in the binary tree is said to be pseudo-palindromic if at 
/// least one permutation of the node values in the path is a palindrome.
/// Return the number of pseudo-palindromic paths going from the root 
/// node to leaf nodes.
///
/// Example 1:
/// Input: root = [2,3,1,3,1,null,1]
/// Output: 2 
/// Explanation: The figure above represents the given binary tree. 
/// There are three paths going from the root node to leaf nodes: 
/// the red path [2,3,3], the green path [2,1,1], and the 
/// path [2,3,1]. Among these paths only red path and green path 
/// are pseudo-palindromic paths since the red path [2,3,3] can be 
/// rearranged in [3,2,3] (palindrome) and the green path [2,1,1] 
/// can be rearranged in [1,2,1] (palindrome).
///
/// Example 2:
/// Input: root = [2,1,1,1,3,null,null,null,null,null,1]
/// Output: 1 
/// Explanation: The figure above represents the given binary tree. 
/// There are three paths going from the root node to leaf nodes: 
/// the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. 
/// Among these paths only the green path is pseudo-palindromic 
/// since [2,1,1] can be rearranged in [1,2,1] (palindrome).
///
/// Example 3:
/// Input: root = [9]
/// Output: 1
///
/// Constraints:
/// 1. The given binary tree will have between 1 and 10^5 nodes.
/// 2. Node values are digits from 1 to 9.
/// </summary>
int LeetCodeTree::pseudoPalindromicPaths(TreeNode* root)
{
    unordered_map<int, int> num_map;
    return pseudoPalindromicPaths(root, num_map);
}

/// <summary>
/// Leet code #1469. Find All the Lonely Nodes
///                
/// Easy
/// 
/// In a binary tree, a lonely node is a node that is the only child 
/// of its parent node. The root of the tree is not lonely because 
/// it does not have a parent node.
///
/// Given the root of a binary tree, return an array containing the 
/// values of all lonely nodes in the tree. Return the list in any order.
///
/// Example 1:
/// Input: root = [1,2,3,null,4]
/// Output: [4]
/// Explanation: Light blue node is the only lonely node.
/// Node 1 is the root and is not lonely.
/// Nodes 2 and 3 have the same parent and are not lonely.
///
/// Example 2:
/// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
/// Output: [6,2]
/// Explanation: Light blue nodes are lonely nodes.
/// Please remember that order doesn't matter, [2,6] is also an 
/// acceptable answer.
///
/// Example 3:
/// Input: root = [11,99,88,77,null,null,66,55,null,null,44,33,null,
///                null,22]
/// Output: [77,55,33,66,44,22]
/// Explanation: Nodes 99 and 88 share the same parent. Node 11 is the 
/// root.
/// All other nodes are lonely.
///
/// Example 4:
/// Input: root = [197]
/// Output: []
///
/// Example 5:
/// Input: root = [31,null,78,null,28]
/// Output: [78,28]
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 1000].
/// 2. Each node's value is between [1, 10^6].
/// </summary>
vector<int> LeetCodeTree::getLonelyNodes(TreeNode* root)
{
    vector<int> result;
    queue<pair<TreeNode*, int>> search;
    search.push(make_pair(root, 0));

    while (!search.empty())
    {
        TreeNode* node = search.front().first;
        int state = search.front().second;
        search.pop();
        if (node == nullptr) continue;
        if (state == 1) result.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            continue;
        }
        else if (node->left == nullptr)
        {
            search.push(make_pair(node->right, 1));
        }
        else if (node->right == nullptr)
        {
            search.push(make_pair(node->left, 1));
        }
        else if (node->left != nullptr && node->right != nullptr)
        {
            search.push(make_pair(node->left, 2));
            search.push(make_pair(node->right, 2));
        }
    }
    return result;
}

/// <summary>
/// Leet code #1485. Clone Binary Tree With Random Pointer
/// </summary> 
TreeNode* LeetCodeTree::cloneRandomBinaryTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& map)
{
    if (root == nullptr) return nullptr;
    
    TreeNode* node = new TreeNode(root->val);
    map[root] = node;
    node->left = cloneRandomBinaryTree(root->left, map);
    node->right = cloneRandomBinaryTree(root->right, map);
    return node;
}

/// <summary>
/// Leet code #1485. Clone Binary Tree With Random Pointer
/// </summary> 
TreeNode* LeetCodeTree::setRandomBinaryTree(TreeNode* root, TreeNode* clone, unordered_map<TreeNode*, TreeNode*>& map)
{
    if (clone == nullptr) return clone;
    if (root->random != nullptr) clone->random = map[root->random];
    setRandomBinaryTree(root->left, clone->left, map);
    setRandomBinaryTree(root->right, clone->right, map);
    return clone;
}

/// <summary>
/// Leet code #1485. Clone Binary Tree With Random Pointer
///
/// Medium
///
/// A binary tree is given such that each node contains an additional 
/// random pointer which could point to any node in the tree or null.
///
/// Return a deep copy of the tree.
///
/// The tree is represented in the same input/output way as normal 
/// binary trees where each node is represented as a pair of 
/// [val, random_index] where:
///
/// val: an integer representing Node.val
/// random_index: the index of the node (in the input) where the 
/// random pointer points to, or null if it does not point to any node.
/// You will be given the tree in class Node and you should return the 
/// cloned tree in class NodeCopy. NodeCopy class is just a clone of 
/// Node class with the same attributes and constructors.
/// 
/// Example 1:
/// Input: root = [[1,null],null,[4,3],[7,0]]
/// Output: [[1,null],null,[4,3],[7,0]]
/// Explanation: The original binary tree is [1,null,4,7].
/// The random pointer of node one is null, so it is represented 
/// as [1, null].
/// The random pointer of node 4 is node 7, so it is represented as [4, 3] 
/// where 3 is the index of node 7 in the array representing the tree.
/// The random pointer of node 7 is node 1, so it is represented as [7, 0] 
/// where 0 is the index of node 1 in the array representing the tree.
///
/// Example 2:
/// Input: root = [[1,4],null,[1,0],null,[1,5],[1,5]]
/// Output: [[1,4],null,[1,0],null,[1,5],[1,5]]
/// Explanation: The random pointer of a node can be the node itself.
///
/// Example 3:
/// Input: root = [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
/// Output: [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
///
/// Example 4:
/// Input: root = []
/// Output: []
///
/// Example 5:
/// Input: root = [[1,null],null,[2,null],null,[1,null]]
/// Output: [[1,null],null,[2,null],null,[1,null]]
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [0, 1000].
/// 2. Each node's value is between [1, 10^6].
/// </summary> 
TreeNode* LeetCodeTree::copyRandomBinaryTree(TreeNode* root)
{
    unordered_map<TreeNode*, TreeNode*> map;
    TreeNode * result = cloneRandomBinaryTree(root, map);
    setRandomBinaryTree(root, result, map);
    return result;
}

/// <summary>
/// Leet code #1490. Clone N-ary Tree
/// 
/// Medium
///
/// Given a root of an N-ary tree, return a deep copy (clone) of the tree.
///
/// Each node in the n-ary tree contains a val (int) and a list (List[Node]) 
/// of its children.
///
/// class Node {
///     public int val;
///     public List<Node> children;
/// }
/// Nary-Tree input serialization is represented in their level order 
/// traversal, each group of children is separated by the null value 
/// (See examples).
///
/// Follow up: Can your solution work for the graph problem?
/// 
/// Example 1:
/// Input: root = [1,null,3,2,4,null,5,6]
/// Output: [1,null,3,2,4,null,5,6]
/// Example 2:
/// 
/// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,
///  null,null,11,null,12,null,13,null,null,14]
/// Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,
/// 11,null,12,null,13,null,null,14]
/// 
/// Constraints:
/// 1. The depth of the n-ary tree is less than or equal to 1000.
/// 2. The total number of nodes is between [0, 10^4].
/// </summary>
Node* LeetCodeTree::cloneTree(Node* root)
{
    if (root == nullptr) return nullptr;
    Node* node = new Node();
    node->val = root->val;
    for (size_t i = 0; i < root->children.size(); i++)
    {
        node->children.push_back(cloneTree(root->children[i]));
    }
    return node;
}

/// <summary>
/// Leet code #1506. Find Root of N-Ary Tree
/// 
/// Medium
///
/// Given all the nodes of an N-ary tree as an array  Node[] tree where 
/// each node has a unique value.
///
/// Find and return the root of the N-ary tree.
/// 
/// Follow up:
/// Could you solve this problem in constant space complexity with a 
/// linear time algorithm?
///
/// Nary-Tree input serialization is represented in their level order 
/// traversal, each group of children is separated by the null value 
/// (See examples).
/// 
/// For example, the above tree is serialized as [1,null,2,3,4,5,null,
/// null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].
///
/// Custom testing:
/// 1. You should provide the serialization of the input tree.
/// 2. The Driver code then extracts the nodes from the tree and 
///    shuffles them. You shouldn't care how the extracted nodes are 
///    shuffled.
/// 3. The driver code will provide you with an array of the extracted 
///    nodes in random order and you need to find the root of the tree 
///    out of these nodes.
///
/// Example 1:
/// Input: tree = [1,null,3,2,4,null,5,6]
/// Output: [1,null,3,2,4,null,5,6]
/// Explanation: The input tree is shown above. The driver code first 
/// extracts the nodes so we now have an array of all tree nodes 
/// [Node(1),Node(3),Node(2),Node(4),Node(5),Node(6)], then the array 
/// is randomly shuffled, thus the actual input is [Node(5),Node(4),
/// Node(3),Node(6),Node(2),Node(1)].
/// The root of the tree is Node(1) and the output is the 
/// serialization of the node you return.
///
/// Example 2:
/// Input: tree = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,
///   null,null,11,null,12,null,13,null,null,14]
/// Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,
/// null,12,null,13,null,null,14]
///
/// Constraints:
/// 1. The total number of nodes is between [1, 5 * 10^4].
/// 2. Each node has a unique value.
/// </summary>
Node* LeetCodeTree::findRoot(vector<Node*> tree)
{
    long long sum = 0;
    for (size_t i = 0; i < tree.size(); i++)
    {
        sum += tree[i]->val;
    }
    for (size_t i = 0; i < tree.size(); i++)
    {
        for (size_t j = 0; j < tree[i]->children.size(); j++)
        {
            sum -= tree[i]->children[j]->val;
        }
    }
    Node* root = nullptr;
    for (size_t i = 0; i < tree.size(); i++)
    {
        if (sum == tree[i]->val)
        {
            root = tree[i];
            break;
        }
    }
    return root;
}

/// <summary>
/// Leet code #1519. Number of Nodes in the Sub-Tree With the Same Label
/// </summary>
void LeetCodeTree::countSubTrees(int node, vector<vector<int>>& links, string& labels,
    vector<int>& tag, vector<int>& result)
{
    result[node] = 0;
    for (size_t i = 0; i < links[node].size(); i++)
    {
        int child = links[node][i];
        // this must be parent;
        if (result[child] == 0) continue;
        vector<int> child_tag(26);
        countSubTrees(links[node][i], links, labels, child_tag, result);
        for (size_t j = 0; j < 26; j++)
        {
            tag[j] += child_tag[j];
        }
    }
    tag[labels[node] - 'a']++;
    result[node] = tag[labels[node] - 'a'];
}

/// <summary>
/// Leet code #1519. Number of Nodes in the Sub-Tree With the Same Label
/// 
/// Medium
///
/// Given a tree (i.e. a connected, undirected graph that has no cycles) 
/// consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 
/// edges. The root of the tree is the node 0, and each node of the tree 
/// has a label which is a lower-case character given in the string 
/// labels (i.e. The node with the number i has the label labels[i]).
///
/// The edges array is given on the form edges[i] = [ai, bi], which means 
/// there is an edge between nodes ai and bi in the tree.
///
/// Return an array of size n where ans[i] is the number of nodes in the 
/// subtree of the ith node which have the same label as node i.
///
/// A subtree of a tree T is the tree consisting of a node in T and all 
/// of its descendant nodes.
/// 
/// Example 1:
/// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], 
/// labels = "abaedcd"
/// Output: [2,1,1,1,1,1,1]
/// Explanation: Node 0 has label 'a' and its sub-tree has node 2 with 
/// label 'a' as well, thus the answer is 2. Notice that any node is 
/// part of its sub-tree.
/// Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 
/// and 5, as nodes 4 and 5 have different labels than node 1, the 
/// answer is just 1 (the node itself).
///
/// Example 2:
/// Input: n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
/// Output: [4,2,1,1]
/// Explanation: The sub-tree of node 2 contains only node 2, so the 
/// answer is 1.
/// The sub-tree of node 3 contains only node 3, so the answer is 1.
/// The sub-tree of node 1 contains nodes 1 and 2, both have label 'b', 
/// thus the answer is 2.
/// The sub-tree of node 0 contains nodes 0, 1, 2 and 3, all with label 
/// 'b', thus the answer is 4.
///
/// Example 3:
/// Input: n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
/// Output: [3,2,1,1,1]
///
/// Example 4:
/// Input: n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], 
/// labels = "cbabaa"
/// Output: [1,2,1,1,2,1]
///
/// Example 5:
/// Input: n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]],
/// labels = "aaabaaa"
/// Output: [6,5,4,1,3,2,1]
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 0 <= ai, bi < n
/// 5. ai != bi
/// 6. labels.length == n
/// 7. labels is consisting of only of lower-case English letters.
/// </summary>
vector<int> LeetCodeTree::countSubTrees(int n, vector<vector<int>>& edges, string labels)
{
    vector<vector<int>> links(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        links[edges[i][0]].push_back(edges[i][1]);
        links[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> tag(26);
    vector<int> result(n, -1);
    countSubTrees(0, links, labels, tag, result);
    return result;
}

/// <summary>
/// Leet code #1530. Number of Good Leaf Nodes Pairs
/// </summary>
vector<int> LeetCodeTree::countPairs(TreeNode* root, int depth, int distance, int& result)
{
    vector<int> children;
    if (root == nullptr) return children;
    if (root->left == nullptr && root->right == nullptr)
    {
        children.push_back(depth);
    }
    else if (root->left == nullptr)
    {
        children = countPairs(root->right, depth + 1, distance, result);
    }
    else if (root->right == nullptr)
    {
        children = countPairs(root->left, depth + 1, distance, result);
    }
    else
    {
        vector<int> left_children = countPairs(root->left, depth + 1, distance, result);
        vector<int> right_children = countPairs(root->right, depth + 1, distance, result);
        for (size_t i = 0; i < left_children.size(); i++)
        {
            for (size_t j = 0; j < right_children.size(); j++)
            {
                if (left_children[i] + right_children[j] - 2 * depth <= distance)
                {
                    result++;
                }
            }
        }
        children.insert(children.end(), left_children.begin(), left_children.end());
        children.insert(children.end(), right_children.begin(), right_children.end());
    }
    return children;
}

/// <summary>
/// Leet code #1530. Number of Good Leaf Nodes Pairs
/// 
/// Medium
///
/// Given the root of a binary tree and an integer distance. A pair of two 
/// different leaf nodes of a binary tree is said to be good if the length 
/// of the shortest path between them is less than or equal to distance.
///
/// Return the number of good leaf node pairs in the tree.
///
/// Example 1: 
/// Input: root = [1,2,3,null,4], distance = 3
/// Output: 1
/// Explanation: The leaf nodes of the tree are 3 and 4 and the length 
/// of the shortest path between them is 3. This is the only good pair.
///
/// Example 2:
/// Input: root = [1,2,3,4,5,6,7], distance = 3
/// Output: 2
/// Explanation: The good pairs are [4,5] and [6,7] with shortest 
/// path = 2. The pair [4,6] is not good because the length of ther 
/// shortest path between them is 4.
///
/// Example 3:
/// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], 
/// distance = 3
/// Output: 1
/// Explanation: The only good pair is [2,5].
///
/// Example 4:
/// Input: root = [100], distance = 1
/// Output: 0
///
/// Example 5:
/// Input: root = [1,1,1], distance = 2
/// Output: 1
///  
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 2^10].
/// 2. Each node's value is between [1, 100].
/// 3. 1 <= distance <= 10
/// </summary>
int LeetCodeTree::countPairs(TreeNode* root, int distance)
{
    int result = 0;
    countPairs(root, 0, distance, result);
    return result;
}

#pragma endregion
