#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

template <class T>
void merge(std::vector<T> &array, int l, int m, int r){
    std::cout << "Merging";
    std::vector<T> temp;
    for (int i = l; i <= m; i++){
        temp[i] = array[i];
    }
    int k = m+1;
    for (int i = m+1; i <= r; i++){
        temp[k] = array[i];
        k++;
    }
    for (int i = 0; i < k; i++){
        array[i]  = temp[k];
    }
}

template<class T>
void insertion_sort(std::vector<T> &array, int l, int r)
{
    std::cout << "Insertion Sort";
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
    // YOUR CODE HERE 
    if (r - l <= 6){
        insertion_sort(array, l, r);
    }
    else {
        std::cout << "Else";
        int m = (l + r)/2;
        sort (array, l, m);
        sort (array, m + 1, r);
        merge(array, l, m, r);
    }
}

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
