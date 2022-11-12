#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

template <class T>
void merge(std::vector<T> &array, int l, int m, int r){
    std::vector<T> temp(r - l + 1); // We create a temporal array to merge array[l..m] and array[m+1..l]
                                    // The temporal has a size of r - l + 1 elements
    int i = l; // We start from the begining of array[l..m] 
    int j = m + 1; // We start from the begining of array[m+1..r]
    int k = 0; // We are going to assign array[l..r] to temp[0..r-l]
    while (i <= m || j <= r) { // while either array[l..m] or array[m+1..r] still has a value that not assign to temp
        if (i <= m && (array[i] < array[j] || j > r)) { // if either array[i] < array[j] or all values of array[m+1..r] has been asigned, the we push array[i] into temp
            temp[k] = array[i];
            i++;
            k++;
        } else { // Otherwise, we push array[j] into an array
            temp[k] = array[j];
            k++;
            j++;
        }
    }
    for (int i = 0; i < temp.size(); ++i)
        array[l+i] = temp[i];
}

template<class T>
void insertion_sort(std::vector<T> &array, int l, int r)
{
    for(int i = l + 1; i < r + 1; i++){
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
        int m = (l + r)/2;
        sort (array, l, m);
        sort (array, m + 1, r);
        merge(array, l, m, r);
    }
}


template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
