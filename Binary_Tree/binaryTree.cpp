#include<iostream>
#include<queue>
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

    void buildTreeLevelOrder(){

        int data;
        cout<<"Enter the data for the root node: "<<endl;
        cin>>data;
        if(data==-1)return;

        root= new Node(data);

        queue<Node*>q;

        q.push(root);

        while(!q.empty()){
            Node * frontNode = q.front();
            q.pop();

            cout<<"Enter the data for the left of: "<<frontNode->data<<endl;
            int ldata;
            cin>>ldata;
            if(ldata==-1){
                frontNode->left=nullptr;
                
            }
            else{
                frontNode->left= new Node(ldata);
                q.push(frontNode->left);
            }

            cout<<"Enter the data for the right of: "<<frontNode->data<<endl;
            int rdata;
            cin>>rdata;
            if(rdata==-1){
                frontNode->right=nullptr;
            }
            else{
                frontNode->right= new Node(rdata);
                q.push(frontNode->right);
            }
        }
    }

    void printLevelOrder() {
        cout << "Level Order: ";
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }

};

int main(){

    BinaryTree B1;

    B1.buildTreeLevelOrder();

    B1.printInorder();
    B1.printPreorder();
    B1.printPostorder();

    return 0;
}