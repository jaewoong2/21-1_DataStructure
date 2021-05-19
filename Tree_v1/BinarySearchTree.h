//
// Created by 82109 on 2021-05-20.
//

#ifndef TREE_V1_BINARYSEARCHTREE_H
#define TREE_V1_BINARYSEARCHTREE_H
#include "Tree.h"

template <class elementType>
class BinarySearchTree: public Tree<elementType> {
public:
    BinarySearchTree(): Tree<elementType>() { };
    virtual void insert(const elementType &data);
    virtual Tree<elementType> * retrieve(const elementType& data);
};

template <class elementType>
void BinarySearchTree<elementType>::insert(const elementType &data) {
    if(this->nullTree) {
        this->nullTree = false;
        this->leftTree = new BinarySearchTree;
        this->rightTree = new BinarySearchTree;
        this->treeData = data;
    } else if(data == this->treeData) {
        this->treeData = data;
    } else if(data < this->treeData) {
        ((BinarySearchTree<elementType>*)(this->leftTree))->insert(data);
    } else {
        ((BinarySearchTree<elementType>*)(this->rightTree))->insert(data);
    }
}

template <class elementType>
Tree<elementType> * BinarySearchTree<elementType>::retrieve(const elementType &data) {
    if(this->nullTree || data == this->treeData) {
        return this;
    }
    if(this->treeData > data) {
        return ((BinarySearchTree<elementType>*)(this->leftTree))->retrieve(data);
    }
    return ((BinarySearchTree<elementType>*)(this->rightTree))->retrieve(data);
}



#endif //TREE_V1_BINARYSEARCHTREE_H
