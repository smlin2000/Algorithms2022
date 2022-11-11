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
    std::vector<T> array1;
    for (int i = l; i <= pivot; i++){
        array1.push_back(array[i]);
    }
    array1.shrink_to_fit();
    std::cout << "\nVector elements are: ";
    for (auto it = array1.begin(); it != array1.end(); it++)
        std::cout << *it << " ";
}

template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
