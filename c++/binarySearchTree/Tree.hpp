#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <stdlib.h>
#include "Treenode.hpp"
using namespace std;

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
// insert node in Tree
void insertNode(const NODETYPE& value) {
insertNodeHelper(&rootPtr, value);
}

// begin preorder traversal of Tree
void preOrderTraversal() const {
preOrderHelper(rootPtr);
}

// begin inorder traversal of Tree
void inOrderTraversal() const {
inOrderHelper(rootPtr);
}

// begin postorder traversal of Tree
void postOrderTraversal() const {
postOrderHelper(rootPtr);
}

// get the depth of the tree
int getDepth() const {
int totalDepth{-1};
int currentDepth{-1};

determineDepth(rootPtr, &totalDepth, &currentDepth);
return totalDepth;
}

// begin binary search
TreeNode<NODETYPE>* binaryTreeSearch(NODETYPE val) const {
return binarySearchHelper(rootPtr, val);
}

private:
TreeNode<NODETYPE>* rootPtr{nullptr};

// utility function called by insertNode; receives a pointer
// to a pointer so that the function can modify pointer's value
void insertNodeHelper(
TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
// subtree is empty; create new TreeNode containing value
if (*ptr == nullptr) {
*ptr = new TreeNode<NODETYPE>(value);
}
else { // subtree is not empty
// data to insert is less than data in current node
if (value <= (*ptr)->data) {
insertNodeHelper(&((*ptr)->leftPtr), value);
}
else {
insertNodeHelper(&((*ptr)->rightPtr), value);
}
}
}

// utility function to perform preorder traversal of Tree
void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
if (ptr != nullptr) {
std::cout << ptr->data << ' '; // process node
preOrderHelper(ptr->leftPtr); // traverse left subtree
preOrderHelper(ptr->rightPtr); // traverse right subtree
}
}

// utility function to perform inorder traversal of Tree
void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
if (ptr != nullptr) {
inOrderHelper(ptr->leftPtr); // traverse left subtree
std::cout << ptr->data << ' '; // process node
inOrderHelper(ptr->rightPtr); // traverse right subtree
}
}

// utility function to perform postorder traversal of Tree
void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
if (ptr != nullptr) {
postOrderHelper(ptr->leftPtr); // traverse left subtree
postOrderHelper(ptr->rightPtr); // traverse right subtree
std::cout << ptr->data << ' '; // process node
}
}

// calculate the depth of the tree
//rootPtr: the pointer to the root of the tree or sub tree when called recursively
// passed from calling statement
//totalDepthPtr: a pointer to point to an int variable, calculate and store the max depth of nodes traversed
//currentDepthPtr: a pointer to point to an int variable, it is a middle step variable
// to calculate and hold the depth of the node that rootPtr pointing to
//postcondition: the value of the variable that totalDepthPtr pointing to is the height of the tree
void determineDepth(TreeNode<NODETYPE> * rootPtr, int *totalDepthPtr, int *currentDepthPtr) const {
    if(rootPtr == NULL) {
        *currentDepthPtr = 0;
        return;
    }
    else{
        int lDepth , rDepth ;
        determineDepth(rootPtr->getLeftPtr() , totalDepthPtr , &lDepth);
        determineDepth(rootPtr->getRightPtr() , totalDepthPtr , &rDepth);
        /* use the larger one */
        if (lDepth > rDepth)
            *currentDepthPtr = (lDepth + 1);
        else
            *currentDepthPtr = (rDepth + 1);
        
        *totalDepthPtr = *currentDepthPtr;
    }
}

// do a binary search on the Tree, searching the value val within a tree of rootPtr
TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE> *rootPtr, NODETYPE val) const{
    if (rootPtr == NULL)
        return NULL;
    system("echo \"\e[;33m\"");   
    cout<<"Comparing "<<val<<" to "<<rootPtr->getData()<<"; ";

    if (rootPtr->getData() == val)
    {
        cout<<"search complete"<<endl;
        return rootPtr;
    }
    else if(rootPtr->getData() > val){
    /* then recur on left subtree */
        cout<<" smaller, walk left "<<endl;
        TreeNode<NODETYPE>* res1 = binarySearchHelper(rootPtr->getLeftPtr(), val);
        // node found, no need to look further
        if(res1 != NULL) return res1;
    }
    else{
        cout<<" larger, walk right "<<endl;
        /* node is not found in left,
        so recur on right subtree */
        TreeNode<NODETYPE>* res2 = binarySearchHelper(rootPtr->getRightPtr(), val);
    
        if(res2 != NULL) return res2;
    }
}


};

#endif // TREE_HPP