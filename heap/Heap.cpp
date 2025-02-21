#include <iostream>

using namespace std; 

class Heap {
    private:
    //creates the initial heap array
        int heap[101];
        int size;
   
        public:
     
    Heap() {
        size = 0;
    }
    //all of the functions that are used to control the program
    void insert(int value);
    void deleteMax();
    void print();
    void heapify(int i);
    void removeAll();
    
        };

//inserts a value into the heap
void Heap::insert(int value) {
    size++;
    heap[size] = value; 
    int i = size;
    while (i > 1 && heap[i] > heap[i/2]) {
        swap(heap[i], heap[i/2]);
        i = i/2;
    }
}

//deletes the maximum value from the heap
void Heap::deleteMax() {
    heap[1] = heap[size];
    size--;
    heapify(1);
}
    
//prints the heap
void Heap::print(int index, int tab = 0) {
    if (index > size) {
        return;
    }
    print(2*index + 1, tab + 1);
    for (int i = 0; i < tab; i++) {
        cout << " ";
    }
    cout << heap[index] << endl;
    print(2*index, tab + 1);
}

//removes all values from the heap
void Heap::removeAll() {
    size = 0;
}

//heapifies the heap
void Heap::heapify(int i) {
//gonna work on this later tbh
}


