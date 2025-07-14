#include <iostream>
using namespace std;

class Node{
    public:
    string name;
    Node* next_ptr;

    Node(string name){
        this-> name = name;
        this-> next_ptr = nullptr;
    }

};

class Queue{
    Node* head;

    public:
    Queue(){
        head = nullptr;
    }

    void enqueue(string name){
        Node* newNode = new Node(name);

        if (head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next_ptr != nullptr){
            temp = temp->next_ptr;
        } 
        temp->next_ptr=newNode;
    }

    void dequeue(){
        Node* temp = head;
        Node* prev = nullptr;

        if (head == nullptr){
            cout<<"List is empty";
            return;
        } else{
            head = temp->next_ptr;
        }
        delete temp;
    }

    void display(){
        Node* temp = head;
        
        if (head == nullptr){
            cout<<"The List is Empty";
            return;
        }

        while (temp != nullptr){
            cout<<temp-> name<<" ";
            temp=temp-> next_ptr;
        }
    }
    
};

int main(){
    Queue q;

    q.dequeue();
    q.enqueue("Ali");
    q.enqueue("Alicia");
    q.enqueue("Ah Cheng");
    q.dequeue();

    cout<<"The list of nodes:"<<endl;
    q.display();
    cout<<endl;

    return 0;
}