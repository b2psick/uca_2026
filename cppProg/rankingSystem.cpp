#include <bits/stdc++.h>

using namespace std;

string rankingSystem(vector<string> votes) {
    unordered_map<char, vector<int>> mp;

    for(auto it : votes) {
        for(int i = 0; i < it.length(); i++) {
            if(mp.find(it[i]) == mp.end()) {
                mp[it[i]] = vector<int>(votes[0].size());
            }
            mp[it[i]][i]++;
        }
    }

    auto cmp = [&mp, &votes](char& a, char& b) {
        for(int i = 0; i < votes[0].size(); i++) {
            if(mp[a][i] != mp[b][i]) {
                return mp[a][i] < mp[b][i];
            }
        }
        return a > b;
    };

    priority_queue<char, vector<char>, decltype(cmp)> pq(cmp);
    
    for(auto it : votes[0]) pq.push(it);
    string ans = "";

    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    
    return ans;
}

int main() {
    vector<string> arr({"ABC", "ACB", "ABC", "ACB", "ACB"});

    cout << rankingSystem(arr) << endl;

    return 0;
}