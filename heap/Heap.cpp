#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Heap {
private:
    int heap[101];

public:
int size;
    Heap() {
        size = 0;
    }
     

    void insert(int value);
    void deleteMax();
    void print(int index, int tab = 0);
    void heapify(int i);
    void removeAll();
};
//inserts a value into the heap
void Heap::insert(int value) {
    if (size >= 100) {
        cout << "Heap is full. Cannot insert more elements." << endl;
        return;
    }
    size++;
    heap[size] = value;
    int i = size;
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}
//deletes the maximum value from the heap
void Heap::deleteMax() {
    if (size == 0) {
        cout << "Heap is empty. Lock in..." << endl;
        return;
    }
    heap[1] = heap[size];
    size--;
    heapify(1);
}
//prints the heap
void Heap::print(int index, int tab) {
    if (index > size) {
        return;
    }
    print(2 * index + 1, tab + 1);
    for (int i = 0; i < tab; i++) {
        cout << "    ";
    }
    cout << heap[index] << endl;
    print(2 * index, tab + 1);
}
//heapify function (it sounds like a superpower or something lol)
void Heap::heapify(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right <= size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}
//removes all the stuff from the thing
void Heap::removeAll() {
    size = 0;
}

int main() {
    Heap heap;
    //inputs stuff lol
    cout << "Would you like to use a file (f) or manual input (m)? ";
    char input;
    cin >> input;

    if (input == 'f') {
        string fileName;
        cout << "Enter the file name: ";
        cin >> fileName;

        ifstream file(fileName);
        if (!file.is_open()) {
            cout << "Error: Unable to open file '" << fileName << "'. Please check the file name and try again." << endl;
            return 1;
        }

        int value;
        while (file >> value) {
            heap.insert(value);
        }
        file.close();
    } else if (input == 'm') {
        cout << "Enter values to insert into the heap (enter -1 to stop): " << endl;
        int value;
        while (true) {
            cin >> value;
            if (value == -1) {
                break;
            }
            heap.insert(value);
        }
    } else {
        cout << "I gave you one instuction, put in f or m" << endl;
        return 1;
    }

    if (heap.size == 0) {
        cout << "Heap is empty. No elements to display." << endl;
    } else {
        cout << "Heap structure:" << endl;
        heap.print(1); 
    }

    return 0;
}
