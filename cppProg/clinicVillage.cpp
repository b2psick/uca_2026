#include <bits/stdc++.h>

using namespace std;

vector<int> clinics(vector<int> population, int n, int k) {
    priority_queue<tuple<double, int, int>> pq;

    vector<int> ans(population.size(), 1);

    for(int i = 0; i < population.size(); i++) {
        pq.push({(double)population[i], i, 1});
    }

    k -= population.size();

    while(k > 0) {

        auto [curr, i, c] = pq.top();

        pq.pop();

        pq.push({(double)population[i] / (c + 1), i, c + 1});
        
        k--;
    }

    while(!pq.empty()) {
        auto [curr, i, c] = pq.top();

        pq.pop();

        ans[i] = c;
    }
    
    return ans;
}

int main() {

    vector<int> population({200, 100, 50});

    vector<int> ans = clinics(population, 3, 5);

    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}