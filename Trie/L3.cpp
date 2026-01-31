#include<iostream>
#include<vector> 

using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        for(int i = 0; i < 26; i++){
            this->children[i] = nullptr;
        }

        this->isTerminal = false;
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

        TrieNode* child = root;
        int index = word[0] - 'a';

        if(child->children[index] == nullptr){
            child->children[index] = new TrieNode(word[0]);
        }

        child = child->children[index];

        insert_utils(child, word.substr(1));
        return ;
    }

    void insert_element(string word){
        insert_utils(root, word);
        return ;
    }

    void store_all_string(TrieNode* curr, vector<string> &store, string &prefixString){
        if(curr == nullptr ){
            return ;
        }

        if(curr->isTerminal){  
            store.push_back(prefixString);
        }
        
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(curr->children[ch - 'a'] != nullptr){
                prefixString.push_back(ch);
                store_all_string(curr->children[ch-'a'], store, prefixString);
                prefixString.pop_back();
            }
        }

        return ;

    }

    vector<vector<string > > print_all_string(string word){

        vector< vector < string > > store;

        string prefixString1 = "";

        TrieNode* prev = root;

        for(int i = 0; i < word.length(); i++){
            char lastCharactor = word[i];

            int index = lastCharactor - 'a';
            
            TrieNode* curr = prev->children[index];
            
            if(curr == nullptr){
                break;
            }

            prefixString1.push_back(lastCharactor);
            
            vector<string> store1;
            store_all_string(curr, store1, prefixString1);
            store.push_back(store1);

            store1.clear();

            prev = curr;

            // cout <<"prefix string "<< prefixString1 << endl;
        }

        return store;
    }



    
};

int main(){
    Trie* t1 = new Trie();

    t1->insert_element("coding");
    t1->insert_element("codding");
    t1->insert_element("cod");
    t1->insert_element("coly");
    t1->insert_element("code");

    string word = "coding";

    vector<vector<string > >  ans = t1->print_all_string(word);

    for(auto vec : ans){
        for(auto it : vec){
            cout << it << " ";
        }
        cout << endl << endl;
    }


}