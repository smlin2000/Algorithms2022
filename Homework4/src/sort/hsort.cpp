#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Heap Sort";

void heapify(std::vector<T> &heap, int N, int i) {

  // N is the size of the current heap

  // i is the index of current node

 

    left = index of left child of i // which is 2*i + 1

    right = index of right child of i // which is 2*i + 2

   

    if node has no chilren then // which mean left >= N

       return;

    end if

  

    if (node i has right child // which mean right < N

            and value right child > value of left child) then

        candidate = right;

    else

        candidate = left;

   end if

   

    if (value of node i < value of node candidate) then

        swap value of node and value of candidate

        recursively call heapify(heap, N, candidate)

    end if

}

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    int n = (r - l + 1);
    std::vector<T> &heap(0, n-1) = array;

}



template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
