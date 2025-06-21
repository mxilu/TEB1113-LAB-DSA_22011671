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

class CircularLinkedlist{
    Node* head;

    public:
    CircularLinkedlist(){
        head = nullptr;
    }

    void addNode(string name){
        Node* newNode = new Node(name);

        if (head == nullptr){
            head = newNode;
            newNode->next_ptr=head;
            return;
        }

        Node* temp = head;
        while (temp->next_ptr != head){
            temp = temp->next_ptr;
        } 
        temp->next_ptr=newNode;
        newNode->next_ptr=head;
    }

    void deleteNode(string name){
        Node* temp = head;
        Node* prev = nullptr;

        if (head == nullptr){
            cout<<"List is empty";
            return;
        }

        do {
            if (temp->name == name)
                break;
            prev = temp;
            temp = temp->next_ptr;
        } while (temp != head);

        if (temp->name != name) {
            cout << name << " doesn't exist" << endl;
        return;
        }

        if (temp->name == name){
            if (temp == head && temp->next_ptr == head){
                head = nullptr;
            }
            else if (temp == head){
                head=temp->next_ptr;
            }
            else{
                if (temp->next_ptr == head){
                    prev->next_ptr = head;
                }
                else prev->next_ptr = temp->next_ptr;
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

        do{
            cout<<temp-> name<<" ";
            temp=temp-> next_ptr;
        }while (temp != head);
    }  
};

int main(){
    CircularLinkedlist list;

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