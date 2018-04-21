#ifndef __SEARCHING_H
#define __SEARCHING_H

#include <iostream>
#include <iterator> // iterator support by stl 

#include <memory> // shared_ptr

#include <list> // stl dual-list

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


//
// 
//
//
// binary search tree implementation
template <typename T>
class BSTree {
    struct TreeNode{
        T key;
        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;
#ifdef DUPKEY_LIST
        std::list<std::unique_ptr<TreeNode>> keylist; // ex12_51
#endif
        TreeNode(T x): key(x), left(), right() {}
    };

    // the root of the tree
    std::unique_ptr<TreeNode> root; 

public:
    BSTree() : root() {}
    ~BSTree() { clean(); }
    BSTree(BSTree&&) = default; // move semantics
    BSTree& operator= (BSTree& rhs) = default;
    BSTree(const BSTree&);
    BSTree& operator=(const BSTree& rhs);
    void insert(const T& key);
    void inorder();

    int search(const T& key);

private:
    void inorder_1(TreeNode* root);
    void clean();
};

template<typename T>
void BSTree<T>::insert(const T& key)
{
    std::unique_ptr<TreeNode> node(new TreeNode(key)); 
    if ( root == nullptr ){
        root = std::move(node);
        return;
    }

    TreeNode *temp = root.get();
    TreeNode *parent = nullptr;
    while(temp != nullptr){
        parent = temp;
        if (key < parent->key){
            temp = parent->left.get();
        }
#ifdef DUPKEY_LIST
        else if (key == parent->key){
            parent->keylist.push_back(std::move(node));         
            return ;
        }
#endif
        else {
            temp = parent->right.get();
        }
    }

    if (key < parent->key) {
        parent->left = std::move(node);
    }
    else {
        parent->right = std::move(node);
    }
}

template<typename T>
int BSTree<T>::search(const T& key)
{
    if ( root == nullptr ){
        return 0;
    }

    int cnt = 0;

    TreeNode *temp = root.get();
    TreeNode *parent = nullptr;
    while(temp != nullptr){
        parent = temp;
        if (key < parent->key){
            temp = parent->left.get();
        }
        else {
#ifdef DUPKEY_LIST
        if (key == parent->key){
            return parent->keylist.size()+1;
        }
#else 
            if (key == parent->key) cnt++;
#endif
            temp = parent->right.get();
        }
    }

    return cnt;
}

template<typename T>
void BSTree<T>::inorder()
{
    inorder_1(root.get());
}

template<typename T>
void BSTree<T>::inorder_1(TreeNode* root)
{
    if ( root == nullptr ) {
        std::cout<<"nil"<<std::endl;
        return;
    }

    inorder_1(root->left.get());
    std::cout<<root->key<<", ";
    inorder_1(root->right.get());
}


template<typename T>
void BSTree<T>::clean()
{
    return;
}


#endif

