#ifndef __SEARCHING_H
#define __SEARCHING_H

#include <iostream>
#include <iterator> // iterator support by stl 

#include <memory> // shared_ptr

//Generic Declartion
template<typename RandomIterator, 
    typename C = typename std::iterator_traits<RandomIterator>::iterator_category>
RandomIterator BinarySearch(RandomIterator first, 
    RandomIterator last, 
    typename std::iterator_traits<RandomIterator>::value_type const &val)

// Special implementation for random_access_iterator
//template <typename RandomIt>
//RandomIt BinarySearch<RandomIt, std::random_access_iterator_tag>(
//    RandomIt first, 
//    RandomIt last, 
//    typename std::iterator_traits<RandomIt>::value_type const &val)
{
    /*
    if ( first >= last )
        return RandomIterator(); // return null 

    RandomIterator mid = first + (last - first)/2 ; // this is better than (first+last)/2 to avoid overflow
    if ( *mid == val )
        return mid;
    if ( *mid < val )
        return BinarySearch(first, mid-1, val);
    if ( *mid > val )
        return BinarySearch(mid+1, last, val);
        */

    RandomIterator saved_last = last;

    while(first != last)
    {
        RandomIterator mid = first + (last - first)/2;
        // keep [first, last)
        if (val < *mid)
            last = mid;
        else if( val > *mid )
            first = mid+1;
        else 
            return mid;
    }

    return saved_last;
}



// binary search tree implementation
template <typename T>
class BSTree {
    struct TreeNode{
        T key;
        std::shared_ptr<TreeNode*> left;
        std::shared_ptr<TreeNode*> right;
        TreeNode(): key(), left(), right(){}
        TreeNode(T x): key(x), left(), right() {}
    };

    // the root of the tree
    std::shared_ptr<TreeNode*> root;

public:
    BSTree() : root() {}
    ~BSTree();

    BSTree(BSTree&&) = default; // move semantics
    BSTree& operator= (BSTree& rhs) = default;
    BSTree(const BSTree&);
    BSTree& operator=(const BSTree& rhs);
    bool push(T);
    bool remove(T);
    void inorder();
    shared_ptr<T> find(T, x) {
        return find (x, root);
    }

    size_t height() {
        return height(root);
    }
};

template<typename T>
bool BSTree<T>::remove(T x, std::shared_ptr<T> &p)
{
    if ( p && x < p->key )
        return remove(x, p->left);
    else if (p && x > p->key)
        return remove(x, p->right);
    else if (p && p->key == x)
    {
        // how to remove the node is key:
        // 1. there is only one child ,
        //  use the child to replace the parent
        // 
        // if ( !p->left  && !p->right) ?? why no need this?
        if (!p->left) 
            p = p->right;
        else if (!p->right)
            p = p->left;
        else {
            // need to find the "后继" node
            // 左子树的右节点
            std::shared_ptr<TreeNode> q = p->left;
            while(q->right) q = q->right;// find the leaf node
            p->key = q->key;
            // how to remove the q?
                      
        }
    }

}





#endif

