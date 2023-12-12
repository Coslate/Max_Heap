#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <math.h>
#include <MaxHeap.h>

void PrintArray(const int size, const int* arr, const std::string arr_name){
    std::cout<<arr_name<<" = [";
    for(int i=0;i<size;++i){
        if(i == 0){
            std::cout<<arr[i];
        }else if(i == size - 1){
            std::cout<<", "<<arr[i]<<"]"<<std::endl; 
        }else{
            std::cout<<", "<<arr[i];
        }
    }
}

void MoveArray(const int* from_arr, int* to_arr, const int to_size, const int to_begin_index, const int from_begin_index){
    int index = to_begin_index;
    for(int i=from_begin_index; i<from_begin_index+to_size; ++i){
        to_arr[index] = from_arr[i];
        ++index;
    }
}

int main(){
    const int n = 10;
    Heap H(n);

    std::cout<<"---H.S initialize---"<<std::endl;
    PrintArray(H.get_heap_size(), H.get_heap_full(), "H.S");

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before HeapSort---"<<std::endl;
    for(int i=0;i<n;++i){
        H.set_heap_index(i, rand()%1000+1);
    }
    PrintArray(H.get_heap_size(), H.get_heap_full(), "H.S");

    HeapSort_V01::HeapSort(n, H);
    std::cout<<"---after HeapSort---"<<std::endl;
    PrintArray(H.get_heap_size(), H.get_heap_full(), "H.S");
    return EXIT_SUCCESS;
}
