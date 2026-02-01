#include<iostream>
#include<vector>
#include<deque>

using namespace std;

 vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;  // store indices
    
        for (int i = 0; i < arr.size(); i++) {
    
            // 1️⃣ Remove elements out of current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
    
            // 2️⃣ Remove smaller elements (not useful)
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
    
            // 3️⃣ Insert current index
            dq.push_back(i);
    
            // 4️⃣ Window complete → take maximum
            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }
    
        return ans;
        
    }

int main(){

}
