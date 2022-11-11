#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Quick Sort";

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (l >= r){
        return;
    }
    int pivot = (l + r) / 2;
    /*std::vector<T> array1;
    std::vector<T> array2;
    for (int i = l; i <= pivot; i++){
        array1.push_back(array[i]);
    }
    for (int i = pivot + 1; pivot <= r; i++){
        array2.push_back(array[i]);
    }*/
    sort(array, l, pivot);
    sort(array, pivot+1, r);
}

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
