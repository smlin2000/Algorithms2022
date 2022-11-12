#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Quick Sort";

/*template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (l >= r){
        return;
    }
    int pivot = (l + r) / 2;
    std::vector<T> array1;
    std::vector<T> array2;
    for (int i = l; i <= pivot; i++){
        array1.push_back(array[i]);
    }
    for (int i = pivot + 1; pivot <= r; i++){
        array2.push_back(array[i]);
    }
    sort(array1, l, pivot);
    sort(array2, pivot+1, r);

}*/

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    if (r - l <= 6){
        insertion_sort(array, l, r);
    }
    else{
        int pivot = find_pivot(array, l, r);
        int low = find_next(pivot, array, l + 1);
        int high = find_previous(pivot, array, r - 2);
        while (low < high){
            std::swap(array[low], array[high]);
            low = find_next(pivot, array, low + 1);
            high = find_previous(pivot, array, high - 1);
        }
        array[r - 1] = array[low];
        array[low] = pivot;
        sort(array, l, low);
        sort(array, high, r);
    }
}

template<class T>
int find_pivot(std::vector<T> &array, int l, int r){
    return array[((r + l)/ 2)];
}
template<class T>
int find_next(int pivot, std::vector<T> &array, int l){
    for (int i = l; i < array.size(); i++){
        if (array[i] > pivot){
            return i;
        }
    }
}
template<class T>
int find_previous(int pivot, std::vector<T> &array, int r){
    for (int i = r; i >= 0; i--){
        if (array[i] < pivot){
            return i;
        }
    }
}
template<class T>
void insertion_sort(std::vector<T> &array, int l, int r)
{
    for(int i=l+1;i<r+1;i++){
        int val = array[i] ;
        int k = i ;
        while (k > l && array[k-1] > val){
            array[k]= array[k-1] ;
            k-= 1;
        }
        array[k]= val ;
    }
 
}

template void find_pivot(std::vector<int> &array, int l, int r);
template void find_next(int pivot, std::vector<int> &array, int l);
template void find_previous(int pivot, std::vector<int> &array, int r);
template void insertion_sort(std::vector<T> &array, int l, int r);
template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
