#ifndef _MAX_HEAP_H_
#define _MAX_HEAP_H_

class Heap{
        int* S;
        int heap_size;
    public : 
        Heap(const int size);
        ~Heap();
        void set_heap_size(const int size);
        void set_heap_full(const int size, const int* const S_in);
        void set_heap_root(const int value);
        void set_heap_tail(const int value);
        void set_heap_index(const int index, const int value);

        int  get_heap_size();
        int* get_heap_full();
        int  get_heap_root();
        int  get_heap_tail();
        int  get_heap_index(const int index);
};


namespace HeapSort_V01{
    void SiftDown(Heap &H, const int index);
    void MakeHeap(const int size, Heap &H);
    void HeapSort(const int size, Heap &H);
    void RemoveKey(const int size, Heap &H);
    int  Root(Heap &H);
}

#endif
