//
// Created by 82109 on 2021-05-11.
//

#ifndef TREE_V1_TREE_H
#define TREE_V1_TREE_H
#include <cassert>
// binary Tree 이진트리
template <class elementType>
class Tree {
public:
    Tree(): nullTree(true), leftTree(nullptr), rightTree(nullptr) {};
    Tree(const Tree *anotherTree);
    bool isEmpty() const { return this->nullTree; };
    elementType getData() const { assert(!isEmpty()); return this->treeData; };
    virtual void insert(const elementType &data);
    Tree* left();
    Tree* right();
    void makeLeft(Tree* anotherTree);
    void makeRight(Tree* anotherTree);

protected:
    bool nullTree;
    elementType treeData;
    Tree* leftTree;
    Tree* rightTree;
};

template <class elementType>
Tree<elementType>::Tree(const Tree<elementType> *anotherTree) {
    this->nullTree = anotherTree->isEmpty();
    this->treeData = anotherTree->getData();
    this->leftTree = anotherTree->left();
    this->rightTree = anotherTree->right();
}

template <class elementType>
void Tree<elementType>::insert(const elementType &data) {
    this->treeData = data;
    if(this->nullTree) {
        this->nullTree = false;
        this->leftTree = new Tree;
        this->rightTree = new Tree;
    }
}

template <class elementType>
Tree<elementType>* Tree<elementType>::left() {
    assert(!this->isEmpty());
    return this->leftTree;
}

template <class elementType>
Tree<elementType>* Tree<elementType>::right() {
    assert(!this->isEmpty());
    return this->rightTree;
}

template <class elementType>
void Tree<elementType>::makeLeft(Tree* anotherTree) {
    Tree* leftT = this->left();
    assert(!this->isEmpty());
    assert(leftT->isEmpty());
    delete leftT;
    this->leftTree = anotherTree;
}

template <class elementType>
void Tree<elementType>::makeRight(Tree* anotherTree) {
    Tree* rightT = this->right();
    assert(!this->isEmpty());
    assert(rightT->isEmpty());
    delete right();
    this->rightTree = anotherTree;
}





#endif //TREE_V1_TREE_H
