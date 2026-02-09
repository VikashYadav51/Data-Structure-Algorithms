#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int minRemoval(vector<int>& nums, int k) {

    int size = nums.size();

    sort(nums.begin(), nums.end());

    int i = 0;

    int maxLen = INT16_MIN;

    for(int j = 0; j < size; j++){
        while( (long)(nums[j]) > (long) nums[i] * k) {
            i++;
        }
        maxLen = max(maxLen, j - i + 1);
    }

    return size - maxLen;
}

int main(){

}