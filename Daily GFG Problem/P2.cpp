#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        
        sort(b.begin(), b.end());
        
        sort(c.begin(), c.end());
        
        int size1 = a.size();
        
        int size2 = b.size();
        
        int size3 = c.size();
        
        vector<int> result(3);
        
        int i = 0;
        
        int j = 0;
        
        int k = 0;
        
        int diff = INT32_MAX;
        long long prevSum = 1LL;
        
        while(i < size1 && j < size2 && k < size3){
            int maxi = max(a[i], max(b[j], c[k]));
            
            int mini = min(a[i], min(b[j], c[k]));
            
            long long  sum = 1LL*  a[i] + b[j] + c[k];
            
            int mainDiff = (maxi - mini);
            
            if(mainDiff < diff || (mainDiff == diff  && sum < prevSum)){
                prevSum = sum;
                
                diff = mainDiff;
                
                 result = {a[i], b[j], c[k]};
            }
        
            if(a[i] == mini){
                i++;
            }
            
            else if(b[j] == mini){
                j++;
            }
            
            else{
                k++;
            }
        }
        
        sort(result.begin(), result.end());
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }

int main(){

}