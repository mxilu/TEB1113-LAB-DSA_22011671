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

    void searchNode(string name){
        Node* node = root;
        string position = "Root";

        while (node != nullptr){
            if (name == node->name){
                cout<<"Found node "<<node->name<<" at position: "<<position;
                return;
            } else if  (name < node->name){
                node = node->left;
                position += "->Left";
            } else{
                node = node->right;
                position += "->Right";
            }
        }
        cout<<"The node "<<name<<" is not found";
    }

    void deleteNode(string name) {
        root = deleteNode(root, name);
    }

    Node* deleteNode(Node* node, string name) {
    if (node == nullptr) return nullptr;

    if (name < node->name)
        node->left = deleteNode(node->left, name);
    else if (name > node->name)
        node->right = deleteNode(node->right, name);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = node->right;
        while (temp->left) temp = temp->left; 
        node->name = temp->name;
        node->right = deleteNode(node->right, temp->name);
    }
    return node;
    }

    void display() {
        displayNode(root);      
        cout << endl;
    }

    void displayNode(Node* node) {
        if (node == nullptr)      
            return;

        displayNode(node->left); 
        cout << node->name <<" "; 
        displayNode(node->right); 
    }
};

int main(){
    Tree tree;

    tree.addRoot("D");
    tree.addLeft(tree.root, "B");
    tree.addRight(tree.root, "F");
    tree.addLeft(tree.root->right, "E");
    tree.addLeft(tree.root->left, "A");
    tree.addRight(tree.root->left, "C");
    tree.addRight(tree.root->right, "G");

    tree.searchNode("C");
    tree.deleteNode("B");
    cout<<endl;
    tree.display();

    return 0;
}