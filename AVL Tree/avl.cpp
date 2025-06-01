#include<iostream>
#include<queue>
using namespace std;


class AVLTree{

    private:

    class Node{
        public:
        int data;
        Node *left;
        Node *right;
        int height;

        Node(int data){
            this->data=data;
            // By default the height of the node will be 1
            this->height=1;
            this->left=nullptr;
            this->right=nullptr;
        }
    };
    Node *root=nullptr;

    // Function to get the height of the tree
    int getHeight(Node * node){
        if(node==nullptr)return 0;
        return node->height;
    }

    // Function to get the balance factor of the tree

    int getBalance(Node * node){
        if(node==nullptr)return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return leftHeight- rightHeight;
    }


    // Function to right rotate the tree
    Node * rightRotate(Node * y){

        Node * x= y->left;
        Node * T2 = x->right;

        x->right=y;
        y->left=T2;

        y->height = 1+ max(getHeight(y->left), getHeight(y->right));
        x->height = 1+ max(getHeight(x->left), getHeight(x->right));
        return x;

    }

    // Function to left rotate the tree
    Node * leftRotate(Node * x){
        Node * y= x->right;
        Node * T2 = y->left;

        y->left=x;
        x->right =T2;
        x->height= 1+ max(getHeight(x->left), getHeight(x->right));
        y->height = 1+ max(getHeight(y->left),getHeight(y->right));

        return y;
    }

    // Function to balance the tree based on various conditions

    Node * Balance(Node * node){


        // Find the balance factor for the tree

        int balanceFactor = getBalance(node);
        
        //left heavy
        if(balanceFactor>1){

            // LL
            if(getBalance(node->left)>=0){
                return rightRotate(node);
            }
            //LR
            else{
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        // right heavy

        if(balanceFactor<-1){

            // RR
            if(getBalance(node->right)<=0){
                return leftRotate(node);
            }
            else{
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        
        return node;
    }

    // Function to insert node into the tree


    Node * insert(Node *node, int key){

        if(!node)return new Node(key);

        if(key<node->data){
            node->left= insert(node->left,key);
        }
        else if(key > node->data){  
            node->right= insert(node->right,key);
        }
        else{
            return node ; // No duplicates allowed
        }

        // Update the height of the tree after insertion

        node->height = 1+ max(getHeight(node->left), getHeight(node->right));

        // Balance the tree after node insertion and height updation
        return Balance(node);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }


    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void levelOrder(Node* node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }

    public:
    
    void insert(int key){
        root = insert(root,key);
    }

      void buildTree() {
        cout << "Enter values to insert (-1 to stop): ";
        int data;
        while (cin >> data && data != -1) {
            insert(data);
        }
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        postorder(root);
        cout << endl;
    }

    void printLevelOrder() {
        levelOrder(root);
    }

    int getRootBalance() {
        return getBalance(root);
    }

    int getRootHeight() {
        return getHeight(root);
    }
};


int main() {
    AVLTree tree;
    tree.buildTree();

    cout << "Level Order: ";
    tree.printLevelOrder();

    cout << "Inorder: ";
    tree.printInorder();

    cout << "Preorder: ";
    tree.printPreorder();

    cout << "Postorder: ";
    tree.printPostorder();

    cout << "Root Balance: " << tree.getRootBalance() << endl;
    cout << "Root Height: " << tree.getRootHeight() << endl;

    return 0;
}
