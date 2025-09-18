//
// Created by lixia on 2025/9/18.
//

#ifndef BINSTRTREE_H
#define BINSTRTREE_H
#include "TreeNode.h"

class BinStrTree {
    TreeNode *root = nullptr;

public:
    BinStrTree() = default;
    explicit BinStrTree(const std::string &val, const int count = 0) :
        root(new TreeNode(val, count)) {}
    BinStrTree(const BinStrTree &rhs);
};



#endif //BINSTRTREE_H