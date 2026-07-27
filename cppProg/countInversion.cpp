#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long merge(vector<int>& arr, int left, int mid, int right, vector<int>& aux) {
        int i = left;
        int j = mid + 1;
        int k = left;
        long long count = 0;
        while(i <= mid || j <= right) {
            if(i >= mid + 1) aux[k++] = arr[j++];
            else if(j >= right+1) aux[k++] = arr[i++];
            else if(arr[i] <= arr[j]) aux[k++] = arr[i++];
            else {
                aux[k++] = arr[j++];
                count += mid - i + 1;
            }
        }
        for(int i = left; i <= right; i++) {
            arr[i] = aux[i];
        }
        return count;
    }
    long long mergeSort(vector<int>& arr, int left, int right, vector<int>& aux) {
        if(left >= right) return 0;
        int mid = left + (right - left) / 2;
        long long count = 0;
        
        count += mergeSort(arr, left, mid, aux)%1000000007;
        count += mergeSort(arr, mid + 1, right, aux)%1000000007;
        count += merge(arr, left, mid, right, aux)%1000000007;
        
        return count%1000000007;
    }
    int countInversion(vector<int>& nums) {
        vector<int> aux(nums.size());
        return mergeSort(nums, 0, nums.size() - 1, aux);
    }
};

int main() {
    Solution* s = new Solution; 

    vector<int> arr({2,4,3,5,1});

    cout<<s->countInversion(arr)<<endl;

    return 0;
}