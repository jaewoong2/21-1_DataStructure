#include <iostream>
#include "Tree.h"
#include "BinarySearchTree.h"

int main() {
    typedef BinarySearchTree<int> BST;

    BST* BinarySearchTree_ = new BST;
    BinarySearchTree_->insert(17);
    BinarySearchTree_->insert(10);
    BinarySearchTree_->insert(26);
    BinarySearchTree_->insert(6);
    BinarySearchTree_->insert(14);
    BinarySearchTree_->insert(20);
    BinarySearchTree_->insert(28);
    BinarySearchTree_->insert(11);
    BinarySearchTree_->insert(31);
    BinarySearchTree_->insert(37);
    BinarySearchTree_->insert(12);


    BST* Tree_11 = (BinarySearchTree<int>*)BinarySearchTree_->retrieve(11);
    if(Tree_11->isEmpty()) {
        std::cout << "11 not found \n";
    } else {
        std::cout << "11 found \n";
    }


    BST* Tree_13 = (BinarySearchTree<int>*)BinarySearchTree_->retrieve(13);
    if(Tree_13->isEmpty()) {
        std::cout << "13 not found \n";
    } else {
        std::cout << "13 found \n";
    }


//    binaryTree* treeOne = new binaryTree;
//    treeOne->insert('D');
//
//    binaryTree* treeTwo = new binaryTree;
//    treeTwo->insert('E');
//
//    binaryTree* treeThree = new binaryTree;
//    treeThree->insert('B');
//
//    treeThree->makeLeft(treeOne);
//    treeThree->makeRight(treeTwo);
//
//    binaryTree* treeFour = new binaryTree;
//    treeFour->insert('F');
//
//    binaryTree* treeFive = new binaryTree;
//    treeFive->insert('C');
//
//    treeFive->makeRight(treeFour);
//
//    binaryTree* treeSix = new binaryTree;
//    treeSix->insert('A');
//
//    treeSix->makeLeft(treeThree);
//    treeSix->makeRight(treeFive);
//
//    binaryTree* root = treeSix;
//
//    while (!root->isEmpty()) {
//        std::cout << root->getData() << " ";
//        root = root->left();
//    }
//
//    std::cout << "\n\n";
//
//    root = treeSix;
//    while (!root->isEmpty()) {
//        std::cout << root->getData() << " ";
//        root = root->right();
//    }


    return 0;
}
