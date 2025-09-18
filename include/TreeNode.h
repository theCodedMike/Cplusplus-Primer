//
// Created by lixia on 2025/9/18.
//

#ifndef TREENODE_H
#define TREENODE_H

#include <string>

class TreeNode {
    std::string value;
    int count = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

public:
    explicit TreeNode(const std::string &val, const int count = 0) :
        value(std::string(val)), count(count) {}
    TreeNode(const TreeNode & rhs) = default;
    TreeNode & operator=(const TreeNode & rhs) = default;
    ~TreeNode() {
        delete left;
        delete right;
    };
};

#endif //TREENODE_H