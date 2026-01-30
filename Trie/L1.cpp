#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;

    TrieNode(char ch){
        this->data = ch;
        this->isterminal = false;
        for(int i = 0; i < 26; i++){
            this->children[i] = nullptr;
        }
    }
};



int main(){

}