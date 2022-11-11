#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Merge Sort";

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    // YOUR CODE HERE 
    if (l >= r){
        return;
    }
    int m = (l + r)/2;
    sort (array, l, m);
    sort (array, m + 1, r);
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

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
