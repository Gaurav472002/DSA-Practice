#include<iostream>
using namespace std;


class TrieNode{

    public:

    char data;
    TrieNode *children[26];
    
    // To check if the node is the end node or node
    bool isTerminal;


    TrieNode(char data){
        this->data=data;

        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isTerminal=false;
    }
};

class Trie{

    TrieNode *root;

    public:

    Trie(){
        root= new TrieNode('\0');
        cout<<" Trie Initialized"<<endl;
    }

     // Function to insert a word into the trie
    void insertWord(string word){

        TrieNode * curr=root;

        for(char ch: word){
            int index = ch -'a';
            if(curr->children[index]==nullptr){
                curr->children[index] = new TrieNode(ch);
            }
            curr= curr->children[index];
        }
        curr->isTerminal=true;
    }

    // Function to see if a word exists in the trie or not
    bool searchWord(string word){

        TrieNode *curr=root;

        for(char ch:word){
            int index =ch-'a';
            if(curr->children[index]==nullptr)return false;
            curr=curr->children[index];
        }
        return curr->isTerminal;
    }

    // Function to remove a word from the trie
    void removeWord(string word){

        TrieNode * curr=root;

        for(char ch:word){
            int index = ch -'a';
            if(curr->children[index]==nullptr)return;

            curr=curr->children[index];
        }
        curr->isTerminal=false;
    }
};


int main(){

Trie * t = new Trie();
    t->insertWord("daddy");
    t->insertWord("dad");
    t->insertWord("dada");
    t->insertWord("daddys");
    // t->remove("daddy");
    t->removeWord("dad");

    cout<<t->searchWord("daddy");
    cout<<t->searchWord("dad");
    cout<<t->searchWord("dada");
    cout<<t->searchWord("daddys");
    return 0;
}