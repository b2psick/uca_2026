#include <bits/stdc++.h>

using namespace std;

vector<int> smallestRange(vector<vector<int>> arr) {
    vector<int> index(arr.size());
    vector<int> ans(2, INT_MAX);
    priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int currMax = INT_MIN;

    for(int i = 0; i < arr.size(); i++) {
        pq.push({arr[i][0], 0, i});
        currMax = max(currMax, arr[i][0]);
    }

    while(true) {

        auto [value, index, listIndex] = pq.top();

        if(ans[1] - ans[0] > currMax - value || (ans[0] == INT_MAX && ans[1] == INT_MAX)) {
            ans[0] = value;
            ans[1] = currMax;
        }

        pq.pop();
        if(index == arr[listIndex].size() - 1) break;
        pq.push({arr[listIndex][index + 1], index + 1, listIndex});
        currMax = max(currMax, arr[listIndex][index + 1]);
    }
    
    return ans;
}

int main() {
    vector<vector<int>> arr({{4,10,15,24,26},{0,9,12,20},{5,18,22,30}});

    vector<int> ans = smallestRange(arr);

    cout << ans[0] << " " << ans[1] <<endl;

    return 0;
}