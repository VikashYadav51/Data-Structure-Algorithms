#include<iostream>
#include<vector>
#include<queue>


using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > mini;
    int size = nums.size();

    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = i; j < size; j++){
            sum = sum + nums[j];

            if(mini.size() < k){
                mini.push(sum);
            }

            else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }

    return mini.top();
}

int main(){

}