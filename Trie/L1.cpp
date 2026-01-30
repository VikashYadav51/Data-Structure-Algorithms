#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        this->isTerminal = false;
        for(int i = 0; i < 26; i++){
            this->children[i] = nullptr;
        }
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insert_utils(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        
        int index = word[0] - 'A';

        if(root->children[index] == nullptr){
            root->children[index] = new TrieNode(word[0]);
        }

        root = root->children[index];
        
        insert_utils(root, word.substr(1));
        return ;
    }

    void insert_word(string s){
        insert_utils(root, s);
    }


    bool search_word(string s1){
        TrieNode* child = root;
        int i = 0;
        while(i < s1.length()){
            int index = s1[i] - 'A';

            if(child->children[index] == nullptr){
                return false;
            }

            child = child->children[index];
            i++;

        }

        return child->isTerminal;
    }

    void remove_element(string s1){
        TrieNode* child = root;
        int i = 0;

        while(i < s1.length()){
            int index = s1[i]  - 'A';
            if(child->children[index] != nullptr){
                child = child->children[index];
            }
            i++;
        }

        if(child->isTerminal){
            child->isTerminal = false;
        }

        return ;
    }
};



int main(){
    Trie* t1 = new Trie();
    t1->insert_word("ABCD");

    bool ans = t1->search_word("ABCDE");
    cout << " ans "<< ans  << endl;

    t1->remove_element("ABCD");

    bool ans1 = t1->search_word("ABCD");
    cout << " ans "<< ans1  << endl;

}