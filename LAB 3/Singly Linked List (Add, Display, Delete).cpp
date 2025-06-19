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

class SinglyLinkedlist{
    Node* head;

    public:
    SinglyLinkedlist(){
        head = nullptr;
    }

    void addNode(string name){
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

    void deleteNode(string name){
        Node* temp = head;
        Node* prev = nullptr;

        if (head == nullptr){
            cout<<"List is empty";
            return;
        }

        while (temp != nullptr && temp->name != name){
            prev = temp;
            temp = temp->next_ptr;
        }
        if (temp == nullptr){
            cout<<name<<" doesn't exist"<<endl;
            return;
        }

        if (temp->name == name){
            if (temp == head && temp->next_ptr == nullptr){
                head = nullptr;
            }
            else if (temp == head){
                head=temp->next_ptr;
            }
            else if (temp->next_ptr == nullptr){
                prev->next_ptr = nullptr;
            }
            else{
                prev->next_ptr = temp->next_ptr;
            }
            delete temp;
        }
    }

    void displayNodes(){
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
    SinglyLinkedlist list;

    list.addNode("Ali");
    list.addNode("Alicia");
    list.addNode("Ah Cheng");
    list.deleteNode("Aisyah");
    list.deleteNode("Ah Cheng");

    cout<<"The list of nodes:"<<endl;
    list.displayNodes();
    cout<<endl;

    return 0;
}