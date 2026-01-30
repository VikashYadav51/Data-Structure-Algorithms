#include<iostream>
#include<vector>

using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch){
        this->data = ch;
        for(int i = 0; i < 26; i++){
            this->children[i] = nullptr;
        }
        this->isTerminal = false;
        this->childCount = 0;
    }
};



class Trie{
    public:

    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insert_utils(TrieNode* root, string word){
        TrieNode* child = root;
        if(word.length() == 0){
            child->isTerminal = true;
            return  ;
        }
        
        int index = word[0] -'a';

        if(child->children[index] == nullptr){
            child->childCount++;
            child->children[index] = new TrieNode(word[0]);
        }

        child = child->children[index];

        insert_utils(child, word.substr(1));
        return ;
    }

    void insert_word(string word){
        insert_utils(root, word);
    }

    void Longest_prefix(string word , int &ans){
        TrieNode* child = root;

        int i = 0;
        while(child-> childCount == 1){
            int index = word[i]-'a';
            // cout <<child->children[index]-> data << endl;
            ans++;
            i++;
            child = child->children[index];
        }

        return ;
    }
};




int main(){
    Trie * t1 = new Trie();

    vector<string> arr;

    arr.push_back("coadeing");
    arr.push_back("coader");
    arr.push_back("coadeingninza");
    arr.push_back("coadezer");

    int n = arr.size();
    // cout << n << endl;


    for(int i = 0; i < n; i++){
        string s1 = arr[i];
        t1->insert_word(s1);
    }

    string first = arr[0];
    int ans = 0;

    // cout << arr.size();

    t1->Longest_prefix(first, ans);

    cout << ans << endl;
}

