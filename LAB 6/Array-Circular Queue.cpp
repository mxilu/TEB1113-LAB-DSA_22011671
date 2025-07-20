#include <iostream>
using namespace std;

class CircularQueue {
private:
    int array[5];
    int front, rear;
    int maxSize;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        maxSize = 5;
    }

    void enqueue(int num) {
        if ((rear + 1) % maxSize == front) {
            cout<<"Queue is full! Cannot enqueue "<<num<<endl;
            return;
        }

        if (front == -1) { 
            front=rear=0;
        } else {
            rear=(rear+1)%maxSize;
        }

        array[rear] = num;
        cout<<num<<" has enqueued" << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout<<"Queue is empty! Cannot dequeue"<<endl;
            return;
        }

        cout<<array[front] <<" has dequeued"<< endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
    }

    void display() {
        if (front == -1) {
            cout<< "Queue is empty."<< endl;
            return;
        }

        cout<< "Current Queue: ";
        int i = front;
        while (true) {
            cout << array[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();

    return 0;
}
