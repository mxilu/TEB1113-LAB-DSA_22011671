#include <iostream>

using namespace std;

class Node{
    public:
    string name;
    Node* right;
    Node* left;

    Node(string name){
        this->name=name;
        this->right=nullptr;
        this->left=nullptr;
    }
};

class Tree{
    public:
    Node* root;

    Tree(){
        root=nullptr;
    }

    void addRoot(string name){
        root = new Node(name);
    }

    void addRight(Node* parent, string name){
        parent->right = new Node(name);
    }

    void addLeft(Node* parent, string name){
        parent->left = new Node(name);
    }
};

int main(){
    Tree tree;

    tree.addRoot("A");
    tree.addLeft(tree.root, "B");
    tree.addRight(tree.root, "C");
    tree.addLeft(tree.root->right, "D");
    tree.addLeft(tree.root->left, "F");
    tree.addRight(tree.root->left, "E");
    tree.addRight(tree.root->right, "G");

    cout<<"The root is "<<tree.root->name<<endl;
    cout<<"The left child to the root is "<<tree.root->left->name<<endl;
    cout<<"The right child to the root is "<<tree.root->right->name<<endl;
    cout<<"The left child to C is "<<tree.root->right->left->name<<endl;
    cout<<"The right child to C is "<<tree.root->right->right->name<<endl;
    cout<<"The left child to B is "<<tree.root->left->left->name<<endl;
    cout<<"The right node to B is "<<tree.root->left->right->name<<endl;

    return 0;
}