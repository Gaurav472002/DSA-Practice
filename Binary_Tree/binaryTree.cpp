#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *left;
    Node  *right;

    Node(int data){
        this->left=nullptr;
        this->right=nullptr;
        this->data=data;
    }
};


class BinaryTree {
    Node *root = nullptr;

public:
    void inorder(Node *root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);    
        preorder(root->right);   
    }

    void postorder(Node *root) {
        if (!root) return;
        postorder(root->left);   
        postorder(root->right);  
        cout << root->data << " ";
    }

    void printInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    Node *builtTreeRecursive() {
        int data;
        cout << "Enter the data: ";
        cin >> data;
        if (data == -1) return nullptr;

        Node *newNode = new Node(data);
        cout << "Enter data for the left of " << data << endl;
        newNode->left = builtTreeRecursive();

        cout << "Enter data for the right of " << data << endl;
        newNode->right = builtTreeRecursive();

        return newNode;
    }

    void buildTree() {
        root = builtTreeRecursive();
    }
};



int main(){

    BinaryTree B1;

    B1.buildTree();

    B1.printInorder();

    return 0;
}