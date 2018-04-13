#ifndef __SEARCHING_H
#define __SEARCHING_H

#include <iostream>
#include <iterator> // iterator support by stl 

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

#endif

