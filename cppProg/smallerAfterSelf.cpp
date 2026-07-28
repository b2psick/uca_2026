#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<pair<int, int>>& count, vector<int>& ans, int left, int mid, int right, vector<pair<int, int>>& aux) {
        int i = left;
        int j = mid + 1;
        int k = left;
        int smaller = 0;

        while(i <= mid || j <= right) {
            if(i >= mid + 1) aux[k++] = count[j++];
            else if(j >= right+1) {
                ans[count[i].second] += smaller;
                aux[k++] = count[i++];
            }
            else if(count[i].first <= count[j].first) {
                ans[count[i].second] += smaller;
                aux[k++] = count[i++];
            }
            else {
                smaller++;
                aux[k++] = count[j++];
            }
        }
        for(int i = left; i <= right; i++) {
            count[i] = aux[i];
        }
    }
    void mergeSort(vector<pair<int, int>>& count, vector<int>& ans, int left, int right, vector<pair<int, int>>& aux) {
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        
        mergeSort(count, ans, left, mid, aux);
        mergeSort(count, ans, mid + 1, right, aux);
        merge(count, ans, left, mid, right, aux);

    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> count(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            count[i].first = nums[i];
            count[i].second = i;
        }
        vector<pair<int, int>> aux(nums.size());
        vector<int> ans(nums.size());
        mergeSort(count, ans, 0, nums.size() - 1, aux);
        
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {1,2,5,6,7,2,1};

    vector<int> result = solution.countSmaller(nums);

    for(auto it : result) {
        cout << it << " ";
    }

    return 0;
}