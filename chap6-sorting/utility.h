#ifndef __SORT_UTILITY
#define __SORT_UTILITY

#include <cstdlib>
#include <array>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>


template <size_t N>
void generateRandomDataSet(std::array<int, N>& arr)
{
    srand(time(0));
    for (int i=0; i < N; i++)
        arr[i] = N * (1.0 * rand()/(double)RAND_MAX);

#ifdef DEBUG
    std::cout<<"random data set: "<<std::endl;
    for (auto v : arr)
        std::cout<<v<<", ";

    std::cout<<"\n";
#endif
}

template <class T, size_t N>
void dumpData(const std::array<T, N>& arr){
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<T>(std::cout, ", "));
}

template<class T, size_t N>
void selection_sort(std::array<T, N>& arr)
{
    for(int i=0; i < N; i++){
        int min = i;
        for(int j=i+1; j < N; j++){
            if ( arr[j] < arr[i] ){
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}


// ex_6.19
// non-adaptive selection sort, with minimum key swapped each loop
template<class T, size_t N>
void selection_sort_1(std::array<T, N>& arr)
{
    for(int i=0; i < N; i++){
        int min = i;
        for(int j=i+1; j < N; j++){
            if ( arr[j] < arr[i] ){
                std::swap(arr[j], arr[i]);
            }
        }
        
    }
}

template <class T, size_t N>
void 
insertion_sort(std::array<T, N>& arr)
{
    //compare and swap to find the smallest key
    // to be the sentinel key and also as the first element
    for(int i=N-1; i>0; i--){
        if ( arr[i] < arr[i-1] )
            std::swap(arr[i-1], arr[i]);
    }

    // since arr[0], arr[1] are already sorted.
    for(int i=2; i<N; i++){
        int j = i;
        typename std::array<T, N>::value_type v = arr[i];
        while( v < arr[j-1] ){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}

// ex6.16
template <class T, size_t N>
void 
insertion_sort_1(std::array<T, N>& arr)
{
    for(int i=0; i<N; i++){
        int j = i;
        typename std::array<T, N>::value_type v = arr[j];
        while( j>1 && (v < arr[j-1]) ){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}


// example_6.1 
// non-adaptive insertion sort 
template <class T, size_t N>
void 
insertion_sort_2(std::array<T, N>& arr)
{
    int i, j;
    for(i=1; i<N; i++){
        for(j=i; j>0; j--){
            if (arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
            }
        }
    }
}

// example_6.4
template <class T, size_t N>
void 
bubble_sort(std::array<T, N>& arr)
{
    for(int i=0; i<N; i++){
        for(int j=N-1; j>i; j--){
            if (arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
            }
        }       
    }
}

//ex6.25, adaptive bubble sort
template <class T, size_t N>
void 
bubble_sort_1(std::array<T, N>& arr)
{
    int i,j;
    i=0;
    while( i<N ){
        int lastSwapped = -1;
        for(int j=N-1; j>i; j--){
            if (arr[j] < arr[j-1]){
                std::swap(arr[j], arr[j-1]);
                lastSwapped = j;
            }
        }
        if ( lastSwapped == -1 )
            break;
        else
            i = lastSwapped;        
    }
}

//ex6.30, shaker sort
template <class T, size_t N>
void
shaker_sort(std::array<T, N>& arr)
{
    int left = 0;
    int right = N;
    int shift;

    while(left < right){
        for(int i=left+1; i<right; i++){
            if ( arr[i-1] > arr[i] ){
                std::swap(arr[i-1], arr[i]);
                shift = i;
            }
        }
        right = shift;

        for(int i=right-1; i>left; i--){
            if (arr[i-1] > arr[i]){
                std::swap(arr[i-1], arr[i]);
                shift = i;
            }
        }
        left = shift;
    }
}

//ex6.75
template <class T, size_t N, size_t M>
void
small_key_range_sort(std::array<T, N>& arr)
{
    std::array<int, M+1> counts; 
    std::array<T, N> b;
    for(int i=0; i<M; i++) {
        counts[i] = 0;     
    }

    for(int j=0; j<N; j++) 
        counts[arr[j]+1]++; // valid key: from 1~M (0~M-1)

    for(int i=1; i<M; i++)
        counts[i] += counts[i-1];
#ifdef DEBUG
    std::cout<<"counts: "<<std::endl;
    std::copy(counts.begin(), counts.end(), std::ostream_iterator<int>(std::cout, ", "));
#endif    

    for(int j=0; j<N; j++)
        b[counts[arr[j]]++] = arr[j]; //

#ifdef DEBUG
    std::cout<<"\nb: "<<std::endl;
    std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, ", "));
#endif

    for(int i=0; i<N; i++)
        arr[i] = b[i];
}

template <class T, size_t N>
int
partition(std::array<T, N>&arr, int first, int last)
{
    typename std::array<T, N>::value_type v = arr[last];
    int i = first-1;
    int j = last;
    while( i<j ){
        while(arr[++i] < v) 
            ;

        while(j>first && v < arr[--j])
            ;

        if( i<j )
            // advance of i, j will be done
            // in the next loop of comparision
            std::swap(arr[i], arr[j]);
    }

    std::swap(arr[i], arr[last]);
    return i;
}

template <class T, size_t N>
void
quick_sort_1(std::array<T, N>& arr, int first, int last)
{
    int i ;
    if ( last <=first )
        return;

    i = partition(arr, first, last);
    quick_sort_1(arr, first, i-1);
    quick_sort_1(arr, i+1, last);
}

template <class T, size_t N>
void
quick_sort(std::array<T, N>& arr)
{
    quick_sort_1(arr, 0, N-1);
}

//example7.3
template <class T, size_t N>
void 
non_recursive_quick_sort_by_stack(std::array<T, N>&arr)
{
    std::stack<std::pair<int, int>> stk;
    stk.push(std::make_pair(0, N-1));

    while(!stk.empty()){
        auto range = stk.top();
        int first = range.first;
        int last = range.second;
        stk.pop();

        if ( last<=first )  
            continue;

        int i = partition(arr, first, last);

        if ( i-1 > last-i ){
            // prior to process sub array with less elements
            // 
            stk.push(std::make_pair(first, i-1));
            stk.push(std::make_pair(i+1, last));      
        } else {
            stk.push(std::make_pair(i+1, last)); 
            stk.push(std::make_pair(first, i-1));
        }
        
    }   
}

//example7.3
//refer: https://codereview.stackexchange.com/questions/178735/quick-sort-c-implementation?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
// try use make_pair function
template <class T, size_t N>
void 
non_recursive_quick_sort_by_queue(std::array<T, N>&arr)
{
    std::queue<std::pair<int, int> > Q;
    Q.push(std::make_pair(0, N-1));

    while(!Q.empty()){
        auto range = Q.front();
        Q.pop();

        int first = range.first;
        int last  = range.second;

        if ( last<=first )  
            continue;

        int i = partition(arr, first, last);
        Q.push(std::make_pair(first, i-1));
        Q.push(std::make_pair(i+1, last));
    }   
}
//ex7.10 
// generate N unique data set 
// which is best for quick sort
// when partition. 

template <size_t N>
void generateBestDataSetForQSort(std::array<int, N>& arr, int first ,int last)
{
    if ( last<=first+1 ){
        return;
    } 

    int mid = (first+last)/2;
    typename std::array<int, N>::value_type v = arr[mid];
    int j = mid+1;
    while( j <= last ) {
        arr[j-1] = arr[j]; 
        j++;        
    }
    arr[last] = v;

    generateBestDataSetForQSort(arr, first, mid-1);
    generateBestDataSetForQSort(arr, mid, last-1);
}

template <size_t N>
void generateBestDataSetForQSort(std::array<int, N>& arr)
{
    int n = 1;
    std::generate(arr.begin(), arr.end(), [&n]{return n++;});

    generateBestDataSetForQSort(arr, 0, N-1);
}

template <class T, size_t N, size_t M>
void
improved_quick_sort_1(std::array<T, N>& arr, int first, int last)
{
    int i ;
    // for sub array with less than M elements,
    // just stop the recursion and 
    // the array will be the near-sorted one
    // Insertion sort is a good candidate for such 
    // kind of data sorting.
    if ( last - first <= M ) 
        return;

    i = partition(arr, first, last);
    quick_sort_1(arr, first, i-1);
    quick_sort_1(arr, i+1, last);
}


template <class T, size_t N>
void
improved_quick_sort(std::array<T, N>&arr)
{
    improved_quick_sort_1<T, N,10>(arr, 0, N-1);
    insertion_sort(arr);
}

template<class T, size_t N>
T
select(std::array<T, N> &arr, int k)
{
    assert(k>=0 && k<N);

    int first = 0;
    int last = N-1;
    while( last > first ){
        int i = partition(arr, first, last);
        if ( i == k )
            break;
        if ( i>k )
            last = i-1;
        if ( i<k )
            first = i+1;
    }
    return arr[k];
}


/***********************/
/* chap8 - merge sort  */
/************************/
template <class T, size_t N, size_t M>
void
merge(std::array<T, N+M>& result, const std::array<T, N>& a, const std::array<T, M>&b)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while( i< N && j<M ){
        if (a[i] < b[j]){
            result[k++] = a[i++];
        }
        else {
            result[k++] = b[j++] ;
        }
    }

    if ( i==N ){
        while(j<M) 
            result[k++] = b[j++];
    }
    else if (j==M) {
        while(i<N) 
            result[k++] = a[i++];
    }
    else {
        // we should not reach here
        assert(0);
    } 
}

// by coying the b array as the reverse order


// sort bitonic sequence is like merge sort
// the benifit is the largest num in the aux array
// will be the pivot, which eliminates the array boundary check
/// 
template <class T, size_t N, size_t M>
void
merge_1(const std::array<T, N>& a, const std::array<T, M>&b, std::array<T, N+M>& result)
{
    std::array<T, N+M> aux;
    int i,j,k;

    for(i=0; i<N; i++)
        aux[i] = a[i];

    for(j=M; j>0; j--)
        aux[N+M-j] = b[j-1]; 

    i = 0;
    j = N+M-1;
    k = 0;
    for(k=0; k< N+M; k++) {
        if (aux[i] < aux[j]) {
            result[k] = aux[i++];
        } else {
            result[k] = aux[j--];
        }
    }
}


const int maxN = 100;
std::array<int, maxN> auxArr;
template <class T, size_t N>
void
merge(std::array<T, N>& a, int first, int middle, int last)
{
    // could also used the temp result array as following
    int i,j,k;
    for(i = first; i <= last; i++)
        auxArr[i] = a[i];

    i = first;
    j = last;
    k = first;

    for(i=first, j = middle+1, k = first; k <= last; k++) {

        if ( i==(middle+1) ) { a[k] = auxArr[j++]; continue; }
        if ( j==last+1 ) { a[k] = auxArr[i++]; continue; }

        a[k]= (auxArr[i] < auxArr[j] ? auxArr[i++] : auxArr[j++]);
    }
}  

template<class T, size_t N>
void mergesort(std::array<T, N>&a, int first, int last)
{
    int m = (first+last)/2;
    if (last <= first ) return;

    mergesort(a, first, m);
    mergesort(a, m+1, last);
    merge(a, first, m, last);
}

//prog 8.5. bottom-up merge sort
template<class T, size_t N>
void mergesortBU(std::array<T, N>&a, int first, int last)
{
    int i, m;
    // m-m merge 
    // different scale
    // bottom up
    for(m = 1; m <= last-first; m = m+m){ 
        for(i=first; i <= last-m; i += m+m){
            merge(a, i, i+m-1, std::min(i+m+m-1, last));
        }
    }
}


template <class T, size_t N>
void
merge(std::array<T, N>& a, std::array<T, N>&aux, int first, int middle, int last)
{
    int i = first;
    int j = last;
    int k = first;

    for(i=first, j = middle+1, k = first; k <= last; k++) {

        if ( i==(middle+1) ) { a[k] = auxArr[j++]; continue; }
        if ( j==last+1 ) { a[k] = auxArr[i++]; continue; }

        a[k]= (auxArr[i] < auxArr[j] ? auxArr[i++] : auxArr[j++]);
    }
}  

//ex8.31 bottom-up merge sort without copying array
template<class T, size_t N>
void improved_mergesortBU(std::array<T, N>&a, int first, int last)
{
    std::array<T, N> auxArr;
    std::copy(a.begin(), a.end(), auxArr.begin());

    int i, m;
    bool flip=false;
    // m-m merge 
    // different scale: 1 - 2 - 4 - 8 - 16
    // bottom up
    int length = last - first;
    while( length ){  
        length = length >> 1;      
        flip = !flip ;   
    }

    std::cout<<"\nlast, first, flip: "<<last<<","<<first<<","<<flip<<std::endl;


    for(m = 1; m <= last-first; m = m+m, flip = !flip){ 
        for(i=first; i <= last-m; i += m+m){
            if (flip)
                merge(a, auxArr, i, i+m-1, std::min(i+m+m-1, last));
            else
                merge(auxArr, a, i, i+m-1, std::min(i+m+m-1, last));
        }
    }
}

#endif
