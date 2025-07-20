#include <iostream>
using namespace std;

class Node{
    public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string name){
        this-> name = name;
        this-> next_ptr = nullptr;
        this-> prev_ptr = nullptr;
    }

};

class DoublyLinkedlist{
    Node* head;

    public:
    DoublyLinkedlist(){
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
        temp->next_ptr = newNode;
        newNode->prev_ptr = temp;
    }

    void deleteNode(string name){
        Node* temp = head;

        if (head == nullptr){
            cout<<"List is empty";
            return;
        }

        while (temp != nullptr && temp->name != name){
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
                temp->prev_ptr->next_ptr = nullptr;
            }
            else{
                temp->prev_ptr->next_ptr = temp->next_ptr;
                temp->next_ptr->prev_ptr = temp->prev_ptr;
            }
            delete temp;
        }
    }

    void displayNodes(){
        Node* temp = head;
        
        if (head == nullptr){
            cout<<"The List is Empty"<<endl;
            return;
        }

        while (temp != nullptr){
            cout<<temp-> name<<" ";
            temp=temp-> next_ptr;
        }
    }
    
};

int main(){
    DoublyLinkedlist list;

    list.addNode("Ali");
    list.addNode("Alicia");
    list.addNode("Ah Cheng");
    list.deleteNode("Ammar");
    list.deleteNode("Alicia");

    cout<<"The list of nodes:"<<endl;
    list.displayNodes();
    cout<<endl;

    return 0;
}
