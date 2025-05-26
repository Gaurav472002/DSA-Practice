#include<iostream>
using namespace std;

// Structure for the node of the BST
class Node{

    public:
    int data;
    Node *left;
    Node *right;

    
    Node(int data){
        this->data =data;
        this->left=nullptr;
        this->right=nullptr;
    }
};


class BST{
    
    Node *root;


    // Function to insert a Node into BST
    Node * insertNode(Node *root,int data){
        if(!root)return new Node(data);
        if(data<root->data){
            root->left= insertNode(root->left,data);
        }
        else if(data>root->data){
            root->right= insertNode(root->right,data);
        }
        return root;
    }


    // Function to delete a node from the BST

    Node * deleteNode(Node *root,int key){

        if(!root)return nullptr;
        if(key<root->data){
            root->left= deleteNode(root->left,key);
        }
        else if(key>root->data){
            root->right= deleteNode(root->right,key);
        }
        else{ // Key is found, this is the node to be deleted

            // Case 1: Leaf node deletion
            if(root->left==nullptr && root->right==nullptr){
                delete root;
                return nullptr;
            }
            // Case 2: Node with only right child
            else if(root->left==nullptr && root->right!=nullptr){
                Node *temp = root->right; // Store the right child
                delete root;              // Delete the current node
                return temp;              // Return the right child to be the new child of the parent
            }
            // Case 2: Node with only left child
            else if(root->left!=nullptr && root->right==nullptr){
                Node *temp = root->left;  // Store the left child
                delete root;              // Delete the current node
                return temp;              // Return the left child
            }
            // Case 3: Node with two children
            else{
                // Find the inorder predecessor (largest node in the left subtree)
                Node * temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                
                // Copy the inorder predecessor's data to this node
                root->data=temp->data;

                // Delete the inorder predecessor from the left subtree
                root->left = deleteNode(root->left,temp->data);
                // No need to 'return root' here explicitly if it's the last statement,
                // but it's fine. The final 'return root' outside this else will handle it.
            }
        }
        return root; // Return the (possibly modified) root of the current subtree
    }

    // Function to get the inorder of the tree
    void inorder(Node *root){
        if(!root)return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    // Function to get the preorder of the tree
    void preorder(Node *root){
        if(!root)return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    // Function to get the postorder of the tree
    void postorder(Node *root){
        if(!root)return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    public:

    BST(){
        root=nullptr;
    }

    // Function to insert a node
    void insert(int data){
        root= insertNode(root,data);
    }   

    // Function to delete a node

    void remove(int data){
        root= deleteNode(root,data);
    }

    // Function to create the bst
    void createBST(){
        cout<<" Enter the elements of the BST press -1 to stop:"<<endl;
        
        int data;

        while(cin>>data && data!=-1){
            insert(data);   
        }
    }

    // function to print the inorder
    void printInorder(){
        cout<<"Inorder:";
        inorder(root);
        cout<<endl;
    }

     // function to print the preorder
    void printPreorder(){
        cout<<"Preorder:";
        preorder(root);
        cout<<endl;
    }

     // function to print the postorder
    void printPostorder(){
        cout<<"Postorder:";
        postorder(root);
        cout<<endl;
    }

    
};

int main() {
    BST tree;

    // Step 1: Create the BST
    tree.createBST();

    // Step 2: Traversals
    tree.printInorder();
    tree.printPreorder();
    tree.printPostorder();

    // Step 3: Remove a node and show updated traversals
    int nodeToDelete;
    cout << "Enter a node to delete: ";
    cin >> nodeToDelete;

    tree.remove(nodeToDelete);

    // Step 4: Show updated tree
    cout << "\nAfter deletion:\n";
    tree.printInorder();
    tree.printPreorder();
    tree.printPostorder();

    return 0;
}
