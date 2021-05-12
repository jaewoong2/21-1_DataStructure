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
    bool isEmpty() const { return nullTree; };
    elementType getData() const { assert(!isEmpty()); return treeData; };
    void insert(const elementType &data);
    Tree* left();
    Tree* right();
    void makeLeft(Tree* anotherTree);
    void makeRight(Tree* anotherTree);
private:
    bool nullTree;
    elementType treeData;
    Tree* leftTree;
    Tree* rightTree;
};

template <class elementType>
Tree<elementType>::Tree(const Tree<elementType> *anotherTree) {
    nullTree = anotherTree->isEmpty();
    treeData = anotherTree->getData();
    leftTree = anotherTree->left();
    rightTree = anotherTree->right();
}

template <class elementType>
void Tree<elementType>::insert(const elementType &data) {
    treeData = data;
    if(nullTree) {
        nullTree = false;
        leftTree = new Tree;
        rightTree = new Tree;
    }
}

template <class elementType>
Tree<elementType>* Tree<elementType>::left() {
    assert(!isEmpty());
    return leftTree;
}

template <class elementType>
Tree<elementType>* Tree<elementType>::right() {
    assert(!isEmpty());
    return rightTree;
}

template <class elementType>
void Tree<elementType>::makeLeft(Tree* anotherTree) {
    Tree* leftT = left();
    assert(!isEmpty());
    assert(leftT->isEmpty());
    delete leftT;
    leftTree = anotherTree;
}

template <class elementType>
void Tree<elementType>::makeRight(Tree* anotherTree) {
    Tree* rightT = right();
    assert(!isEmpty());
    assert(rightT->isEmpty());
    delete right();
    rightTree = anotherTree;
}





#endif //TREE_V1_TREE_H
