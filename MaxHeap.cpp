#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <MaxHeap.h>


Heap::Heap(const int size){
    heap_size = size;
    S = new int [heap_size]();
}

Heap::~Heap(){
    delete [] S;
}

void Heap::set_heap_size(const int size){
    heap_size = size;
}

void Heap::set_heap_full(const int size, const int* const S_in){
    delete [] S;

    heap_size = size;
    S = new int [heap_size]();
    for(int i = 0;i<heap_size;++i){
        S[i] = S_in[i];
    }
}

void Heap::set_heap_root(const int value){
    S[0] = value;
}

void Heap::set_heap_tail(const int value){
    S[heap_size-1] = value;
}

void Heap::set_heap_index(const int index, const int value){
    S[index] = value;
}

int Heap::get_heap_size(){
    return heap_size;
}

int* Heap::get_heap_full(){
    return S;
}

int Heap::get_heap_root(){
    return S[0];
}

int Heap::get_heap_tail(){
    return S[heap_size-1];
}

int Heap::get_heap_index(const int index){
    return S[index];
}

void HeapSort_V01::SiftDown(Heap &H, const int index){
    int parent             = index;
    int sift_key           = H.get_heap_index(parent);
    int heap_size          = H.get_heap_size();
    int larger_child_index = 0;
    bool spot_found        = false;

    while(((parent*2+1) < heap_size) && (!spot_found)){
        if((parent*2+1) == (heap_size-1)){
            larger_child_index = parent*2 + 1;
        }else if ((parent*2+1) < (heap_size-1)){
            if(H.get_heap_index(parent*2+1) < H.get_heap_index(parent*2+2)){
                larger_child_index = parent*2+2;
            }else{
                larger_child_index = parent*2+1;
            }
        }
        if(sift_key < H.get_heap_index(larger_child_index)){
            H.set_heap_index(parent, H.get_heap_index(larger_child_index));
            parent = larger_child_index;
        }else{
            spot_found = true;
        }
    }
    H.set_heap_index(parent, sift_key);
}

void HeapSort_V01::MakeHeap(const int size, Heap &H){
    for(int i = (floor(size/2)-1); i>=0; --i){
        SiftDown(H, i);
    }
}

int HeapSort_V01::Root(Heap &H){
    int root_key = H.get_heap_root();
    H.set_heap_root(H.get_heap_tail());
    H.set_heap_size(H.get_heap_size() - 1);
    SiftDown(H, 0);
    return root_key;
}

void HeapSort_V01::RemoveKey(const int size, Heap &H){
    for(int i = size-1;i>=0;--i){
        H.set_heap_index(i, Root(H));
    }
    H.set_heap_size(size);
}

void HeapSort_V01::HeapSort(const int size, Heap &H){
    MakeHeap(size, H);
    RemoveKey(size, H);
}
