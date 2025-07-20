#include <iostream>
#include <string>
using namespace std;
 
 class Node{
     public:
     string name;
     Node* next_ptr;
     
     Node(string name){
         this->name=name;
         this->next_ptr=nullptr;
     }
 };
 
 class Stack{
     Node* top;
     
     public:
     Stack(){
         top=nullptr;
     }
     void pushNode(string name){
         Node* newNode= new Node(name);
         
         if (top==nullptr){
             top=newNode;
             return;
         }
         Node* temp=top;
         while(temp->next_ptr!=nullptr){
             temp=temp->next_ptr;
         }
         temp->next_ptr=newNode;
     }
     void popNode(){
         Node* temp=top;
         Node* prev=nullptr;
         
         if (temp->next_ptr==nullptr){
             top=nullptr;
         }else{
             while(temp->next_ptr!=nullptr){
                 prev=temp;
                 temp=temp->next_ptr;
             }prev->next_ptr=nullptr;
         }
         delete temp;
     }
     
     void displayNode(){
         Node* temp=top;
         
         if(top==nullptr){
             cout<<"List is empty";
             return;
         }
         
         while(temp!=nullptr){
             cout<<temp->name<<" -> ";
             temp=temp->next_ptr;
         }cout<<"NULL";
     }
 };
 
 int main(){
     Stack stack;
     
     stack.pushNode("Ali");
     stack.pushNode("Alice");
     stack.pushNode("Ah Chong");
     stack.displayNode();
     
     cout<<"\nAfter popping the top element:"<<endl;
     stack.popNode();
     stack.displayNode();
 }
 
