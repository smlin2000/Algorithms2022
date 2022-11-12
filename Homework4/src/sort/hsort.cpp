#include <sort.hpp>
#include <graph.hpp> 

//extern
std::string sortAlgName = "Heap Sort";

void heapify(std::vector<T> &heap, int N, int i) {

  // N is the size of the current heap

  // i is the index of current node
    T candidate;
    //left = index of left child of i // which is 2*i + 1
    T left = heap[2*i+1];

    //right = index of right child of i // which is 2*i + 2
    T right = heap[2*i+1];
    

    /*if node has no chilren then // which mean left >= N

       return;

    end if*/
    if (left >= N){
        return;
    }
  

    /*if (node i has right child // which mean right < N

            and value right child > value of left child) then

        candidate = right;

    else
    if 

        candidate = left;
    end if*/

    if (right < N && right > left){
        candidate = right
    }
    else{
        candidate = left
    }

    /*if (value of node i < value of node candidate) then

        swap value of node and value of candidate

        recursively call heapify(heap, N, candidate)

    end if*/
    
    if (heap[i] < candidate){
        std::swap(heap[i], candidate)
        heapify(heap, N, candidate)
    }
   

   

    

}

template<class T>
void sort(std::vector<T> &array, int l, int r) {
    int n = (r - l + 1);
    std::vector<T> &heap;
    for (int i = l; i <= r; i++){
        heap [i - l] = array[i]
    }
    for (int i = n/2-1; i >= 0; i--){
        heapify(heap, n, i)
    }
    for (int i = n-1; i >= 0; i--){
        std::swap(heap[0], heap[i])
        heapify(heap, i, 0)
    }
    for (int i = 0; i <= r; i++){
        array[i] = heap[i]
    }
}



template void sort(std::vector<Edge> &array,  int l, int r);
template void sort(std::vector<int> &array,  int l, int r);
