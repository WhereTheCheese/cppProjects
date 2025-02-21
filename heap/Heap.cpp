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
    void display();
    void heapify(int i);
    
        };

    
