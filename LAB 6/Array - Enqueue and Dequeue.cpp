#include <iostream>
#include <vector>
using namespace std;

class Queue {
public:
    vector<int> array;
    int maxSize = 5;

    void enqueue(int num) {
        if (array.size() >= maxSize) {
            cout << "Cannot enqueue, list is full." << endl;
        } else {
            array.push_back(num);
            cout << num << " has enqueued." << endl;
        }
    }

    void dequeue() {
        if (array.empty()) {
            cout << "Cannot dequeue, the list is empty." << endl;
        } else {
            cout << array.front() << " has dequeued." << endl;
            array.erase(array.begin());
        }
    }

    void display() {
        if (array.empty()) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Array: ";
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.dequeue();          
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);        
    q.display();          
    q.dequeue();          
    q.display();         
    return 0;
}
