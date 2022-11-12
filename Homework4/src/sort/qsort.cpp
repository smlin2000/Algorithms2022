#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Quick Sort";


template<class T>
T find_pivot(std::vector<T> &array, int l, int r){
    return array[((r + l)/ 2)];
}

template<class T>
int find_next(T pivot, std::vector<T> &array, int l, int r) { // add one more argument r 
    //for (int i = l; i < array.size(); i++){
    for (int i = l; i <= r; ++i) { // It should only search in range [l..r] 
        if (array[i] >= pivot){ // find the first value >= pivot
            return i;
        }
    }
    return l; // if it could not find, return l instead of zero
}
template<class T>
int find_previous(T pivot, std::vector<T> &array, int l, int r) { // add one more argument r
    //for (int i = r; i >= 0; i--){
    for (int i = r; i >= l; --i) { // It should only search in range[l..r]
        if (array[i] <= pivot){ // find the the first value >= pivot
            return i;
        }
    }
    return r; //if it could not find, return r instead of zero
}
template<class T>
void insertion_sort(std::vector<T> &array, int l, int r)
{
    for(int i=l+1;i<r+1;i++){
        T val = array[i] ;
        int k = i ;
        while (k > l && array[k-1] > val){
            array[k]= array[k-1] ;
            k-= 1;
        }
        array[k]= val ;
    }
}

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (r - l <= 6){
        insertion_sort(array, l, r);
    }
    else {
        T pivot = find_pivot(array, l, r);
        int low = find_next(pivot, array, l, r); // search the index of value > pivot  from l to r
        int high = find_previous(pivot, array, l, r); // search the index of value < pivot from l to r 
        while (low <= high) { // if low <= high, it means these two value are in the wrong positions, the swap them
            std::swap(array[low], array[high]);
            low = find_next(pivot, array, low + 1, r);
            high = find_previous(pivot, array, l, high - 1);
        }

        //array[r - 1] = array[low]; It is not necessary
        //array[low] = pivot; It is not necessary
        // after partitioning, we have 2 paritions: a[l...high] <= pivot and a[low..r] >= pivot
        sort(array, l, high);
        sort(array, low, r);
    }
}


template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
