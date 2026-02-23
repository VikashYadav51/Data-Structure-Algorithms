#include<iostream>
#include<algorithm>
#include<stack>


using namespace std;

string reverseWords(string s1){
    reverse(s1.begin(), s1.end());
    int size = s1.length();

    string s2 = "";
    string s3 = "";
    bool flag = false;

    for(int i = 0; i < size; i++){
        if(s1[i] != ' '){
            s2.push_back(s1[i]);
            flag = true;
        }

        else{
            if(flag){
                reverse(s2.begin(), s2.end());
                s3.append(s2);
                s3.push_back(' ');
                s2.clear();
                flag = false;
            }
        }
    }

    if(s2.length()){
        reverse(s2.begin(), s2.end());
        s3.append(s2);
    }

    return s3;
}


int main(){
    string s1 = "Hello World India   ";
    string s2 = reverseWords(s1);
    cout << s2 <<",  "<< s2.length()<< endl;
}