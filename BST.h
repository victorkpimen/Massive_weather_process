#ifndef BST_H
#define BST_H

#include<iostream>

using namespace std;

    /**
     * @class BST
     * @brief Create a binary search tree and do several operations
     *
     * Consists of a struct nodeType which holds the information, left link and right link of the node
     *
     *
     * @author Victor Kavassaki Pimentel
     * @version 01
     * @date 15/05/2020 Victor Kavassaki Pimentel, Started
     *
     *
     *
     */

template <class T>
struct nodeType
{
    T info;
    nodeType<T> *lLink;
    nodeType<T> *rLink;
};

template <class T>
class BST{

typedef void (*fcnPtr)(const T&);

public:

    /**
     * @brief Default constructor which sets the root to a nullptr
     *
     */
    BST();

    /**
     * @brief Deconstructor which destrois the the tree when program finishes
     *
     */
    ~BST();

    /**
     * @brief Copy Constructor which copies the tree
     * @param otherTree - the tree to be copied
     */
    BST(const BST<T>& otherTree);

    /**
     * @brief assignment operator overloading
     * @param otherTree - the tree that copies the other
     */
    const BST<T>& operator=(const BST<T>& otherTree);


    /**
     * @brief Insert an object of type T into the tree
     * @param insertItem - an object of type T
     * @return void
     */
    void insertNode(const T& insertItem);

    /**
     * @brief Search a specific object in the tree and returns the address of the node if it is found
     * @param item - an object of type T
     * @return T*
     */
    T* searchItem(const T& item) const;

    /**
     * @brief calls the private method: inorderTraversal
     * It can not modify anything since it is const
     * @return void
     */
    void inorderTraversal(fcnPtr fcn1) const;

    /**
     * @brief calls the private method: preorderTraversal
     * It can not modify anything since it is const
     * @return void
     */
    void preorderTraversal(fcnPtr fcn1) const;

    /**
     * @brief calls the private method: postorderTraversal
     * It can not modify anything since it is const
     * @return void
     */
    void postorderTraversal(fcnPtr fcn1) const;

    /**
     * @brief Destrois the tree from root pointed as parameter
     * @return void
     */
    void destroy(nodeType<T>* &p);

    /**
     * @brief Make a copy of the tree
     * @param copiedTreeRoot - root of the tree that is copied, otherTreeRoot - root of the copy tree
     * @return void
     */
    void copyTree(nodeType<T>* &copiedTreeRoot, nodeType<T>* otherTreeRoot);


private:
    nodeType<T>* root; //pointer which points to the root of the tree

    /**
     * @brief Insert an object of type T into the tree
     * @param insertItem - an object of type T
     * @return void
     */
    void insertNode(const T& insertItem, nodeType<T>* &current);

    /**
     * @brief order the tree with inorder traversal
     * @param p - pointer of type T
     * @return void
     */
    void inorderTraversal(nodeType<T>* p, fcnPtr fcn1) const;

    /**
     * @brief order the tree with preorder traversal
     * @param p - pointer of type T
     * @return void
     */
    void preorderTraversal(nodeType<T>* p, fcnPtr fcn1) const;

    /**
     * @brief order the tree with postorder traversal
     * @param p - pointer of type T
     * @return void
     */
    void postorderTraversal(nodeType<T>* p, fcnPtr fcn1) const;
};

template <class T>
BST<T>::BST()
{
    root = nullptr; //sets the root to nullptr
}

template <class T>
BST<T>::~BST()
{
    destroy(root); //call destroy() to delete the tree
}

template <class T>
BST<T>::BST(const BST<T>& otherTree)
{
    if(otherTree.root==nullptr){
        root = nullptr;
    }
    else{
        copyTree(root, otherTree.root);
    }
}

template <class T>
const BST<T>& BST<T>::operator=(const BST<T>& otherTree)
{
    if(this != &otherTree) //avoiding self copy
    {
        if(root != nullptr) //if the current tree is non empty
        {
            destroy(root);
        }

        if(otherTree.root == nullptr) //if tree to be assigned is empty
        {
            root = nullptr;
        }
        else //copy the tree using copyTree function
        {
            copyTree(root, otherTree.root);
        }
    }

    return *this;
}


template <class T>
void BST<T>::destroy(nodeType<T>* &p)
{
    if(p!=nullptr){ //when pointer is not nullptr
        destroy(p->lLink); //call destroy() on the left link
        destroy(p->rLink); //call destroy() on the right link
        delete p; //delete node once it is a leaf
        p = nullptr; //set the deleted pointer to a nullptr
    }
}

/*template <class T>
void BST<T>::insertNode(const T& insertItem)
{
    insertNode(insertItem, root);
}
template <class T>
void BST<T>::insertNode(const T& insertItem, nodeType<T>* &current)
{
    if(current==0){
        nodeType<T> *newNode;
        newNode = new nodeType<T>;
        newNode->info = insertItem;
        current = newNode;
        return;
    }
    else if(insertItem>current->info){
        insertNode(insertItem, current->rLink);
    }
    else{
        insertNode(insertItem, current->lLink);
    }
}*/
template <class T>
void BST<T>::insertNode(const T& insertItem)
{
    nodeType<T> *curr; //current pointer to hold the pointer that is being dealt with
    nodeType<T> *trackcurr; //pointer to track current pointer
    nodeType<T> *newNode; //new node pointer whhich will be the inserted object

    newNode = new nodeType<T>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if(root==nullptr){ //if the root is a nullptr, the new object will be the root of the tree
        root = newNode;
    }
    else{
        curr = root;

        while(curr!=nullptr){ //while loop till it hits a nullptr
            trackcurr = curr;

            if(curr->info==insertItem){ //display a message when the item already exists in the tree
               // cout<<"The data already exists...."<<'\n';

                return;
            }
            else if(curr->info > insertItem){
                curr = curr->lLink; //traverse through the left link when inserting item is smaller than the current node's item
            }
            else{
                curr = curr->rLink; //traverse through the right link when inserting item is smaller than the current node's item
            }
        }

        if(trackcurr->info > insertItem){
            trackcurr->lLink = newNode; //assign the new node to the left link of the leaf node if the item is smaller than leaf node's item
        }
        else{
            trackcurr->rLink = newNode; //assign the new node to the right link of the leaf node if the item is greater than leaf node's item
        }
    }
}

template <class T>
T* BST<T>::searchItem(const T& item) const
{
    nodeType<T>* curr; //pointer which will hold the current node

    if(root==nullptr){ //display a message when tree is empty
        //cout<<"Tree is empty..."<<'\n';
        curr=nullptr;
    }
    else{
        curr = root;

        while(curr!=nullptr){
            if(curr->info==item){ //return true when searching item is found
                return &curr->info;
            }
            else if(curr->info > item){
                curr = curr->lLink; //traverse through the left link of the current node if the searching item is smaller than the current node's item
            }
            else{
                curr = curr->rLink; //traverse through the right link of the current node if the searching item is greater than the current node's item
            }
        }
    }

    return nullptr;
}

template <class T>
void BST<T>::inorderTraversal(fcnPtr fcn1) const
{

    inorderTraversal(root, fcn1); //Call the private inorderTraversal()

}

template <class T>
void BST<T>::inorderTraversal(nodeType<T>* p, fcnPtr fcn1) const
{
    if(p!=nullptr){
        inorderTraversal(p->lLink, fcn1); //traverse through left subtree
        //cout<<p->info<<" "; //visit the node
        (fcn1)(p->info);
        inorderTraversal(p->rLink, fcn1); //traverse the right subtree
    }
}

template <class T>
void BST<T>::preorderTraversal(fcnPtr fcn1) const
{
    preorderTraversal(root, fcn1); //Call the private preorderTraversal()
}

template <class T>
void BST<T>::preorderTraversal(nodeType<T>* p, fcnPtr fcn1) const
{
    if(p!=nullptr){
        (fcn1)(p->info);
        //cout<<p->info<<" "; //visit the node
        preorderTraversal(p->lLink, fcn1); //traverse the left subtree
        preorderTraversal(p->rLink, fcn1); //traverse the right subtree
    }
}

template <class T>
void BST<T>::postorderTraversal(fcnPtr fcn1) const
{
    postorderTraversal(root, fcn1); //Call the private postorderTraversal()
}

template <class T>
void BST<T>::postorderTraversal(nodeType<T>* p, fcnPtr fcn1) const
{
    if(p!=nullptr){
        postorderTraversal(p->lLink, fcn1); //traverse the left subtree
        postorderTraversal(p->rLink, fcn1); //traverse the right subtree
        (fcn1)(p->info);
        //cout<<p->info<<" "; //visit the node
    }
}

template <class T>
void BST<T>::copyTree(nodeType<T>* &copiedTreeRoot, nodeType<T>* otherTreeRoot)
{
    if(otherTreeRoot==nullptr){
        copiedTreeRoot=nullptr; //If the tree root is nullptr, the copying tree's root is also a nullptr
    }
    else{//If the root is not a nullptr, copy the value in the node and copy the left and right node recursively
        copiedTreeRoot=new nodeType<T>;
        copiedTreeRoot->info=otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink,otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink,otherTreeRoot->rLink);
    }
}

#endif // BST_H
