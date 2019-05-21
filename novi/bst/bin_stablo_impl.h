#ifndef BIN_STABLO_IMPL_H_INCLUDED
#define BIN_STABLO_IMPL_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iterator>
#include <vector>
#include "bin_stablo.h"




using namespace std;
///// Implementacija metoda iz Node klase //////////////////////
template <typename T>
Node<T>::Node()
{
    left=nullptr;
    right=nullptr;
    data;
}


template <typename T>
Node<T>::Node(T const &t)
{
    left=nullptr;
    right=nullptr;
    data=t;
}


//// Implementacija metoda iz BinaryTree klase //////////////////



template<typename T>
 BinarySTree<T>::BinarySTree():root(nullptr) {}

 template<typename T>
 bool BinarySTree<T>::empty() const
 {
     if(root == nullptr) return true;
     return false;

 }

template <typename T>
template <typename Funct>
void BinarySTree<T>::preOrder(Node<T> * root, Funct visit)
{
     if(root != nullptr)
     {
         visit(root->data);
         preOrder(root->left,visit);
          preOrder(root->right,visit);

     }
}


template <typename T>
template <typename Funct>
void BinarySTree<T>::inOrder(Node<T> * root, Funct visit)
{
     if(root != nullptr)
     {
         inOrder(root->left,visit);
         visit(root->data);
         inOrder(root->right,visit);

     }
}




template <typename T>
template <typename Funct>
void BinarySTree<T>::postOrder(Node<T> * root, Funct visit)
{
     if(root != nullptr)
     {

         postOrder(root->left,visit);
          postOrder(root->right,visit);
          visit(root->data);

     }
}

template<typename T>
 ErrorCode BinarySTree<T>::insert(Node<T> * & root, T const & t)
 {
     if(root == nullptr)
     {
         root=new Node<T>(t);
         return success;
     }

     else if(root->data < t)
         return insert(root->right,t);


     else if(root->data > t)
         return insert(root->left,t);

     else return duplicate;


 }

template<typename T>
int BinarySTree<T>::size()
{
    broj=0;
    preOrder(broji);
    return broj;
}

template<typename T>
Node<T> * BinarySTree<T>::find(Node<T> *root, const T &t)
{
    if(root == nullptr || root->data==t)
        return root;

    if(t > root->data)
        return find(root->right,t);

    else
        return find(root->left,t);
}

template<typename T>
bool BinarySTree<T>::isInTree(T const & t)
{
    if(find(root,t) != nullptr) return true;
    return false;
}

template<typename T>
void BinarySTree<T>::clear(Node<T> *root)
{
    if(root!=nullptr)
    {
        clear(root->left);
        clear(root->right);
        delete root;
        root=nullptr;
    }
}


template<typename T>
void BinarySTree<T>::clear()
{ clear(root); }


template<typename T>
Node<T> * BinarySTree<T>::findParent(Node<T> *tmp, Node<T> *root)
{
    if (root == nullptr) return nullptr;
    if(tmp == root) return nullptr;
    if(root->left==tmp) return root;
    if(root->right==tmp) return root;

    Node<T> *l, *r;
    l=findParent(tmp, root->left);
    r=findParent(tmp, root->right);
     if(left == nullptr) return r;
     else return l;

}





template<typename T>
 ErrorCode BinarySTree<T>::remove(T const & t)
 {


    if(empty()) return notfound;
    if(!isInTree(t)) return notfound;

    if(size()==1) root=nullptr;


    Node<T> *parent, *dijete;


    dijete=find(root,t);

    parent = findParent(dijete,root);


    if(dijete->left==nullptr && dijete->right==nullptr) //list
    {
        if( parent->left != nullptr  && parent->left->data == t )
        {
            parent->left=dijete->left;
            delete dijete;

        }


            if(  parent->right != nullptr && parent->right->data == t)
            {

                parent->right=dijete->right;
                delete dijete;

            }

    }

    else if(dijete->left!=nullptr && dijete->right==nullptr) // samo lijevo dijete

    {
        if( parent->left != nullptr && parent->left->data == t)
        {
            parent->left=dijete->left;
            delete dijete;
        }

        if(  parent->right != nullptr && parent->right->data == t)
        {

            parent->right=dijete->left;
            delete dijete;
        }
    }

    else if(dijete->left==nullptr && dijete->right!=nullptr) //samo desno dijete

    {
        if( parent->left != nullptr && parent->left->data == t)
        {
            parent->left=dijete->right;
            delete dijete;
        }

        if( parent->right != nullptr && parent->right->data == t)
        {
            parent->right=dijete->right;
            delete dijete;
        }
    }


    else
    {
        Node<T> *tmp;
        tmp=dijete->right;

        if(tmp->left != nullptr )

        {
            while(tmp->left!=nullptr)
                tmp=tmp->left;
        }


            parent = findParent(dijete, root);

        dijete->data=tmp->data;
        parent->left=tmp->right;
        delete tmp;





    }




    return success;

}

#endif // BIN_STABLO_IMPL_H_INCLUDED
