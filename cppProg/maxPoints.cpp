#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int maxPoints(vector<vector<int>>& points) {

    int ans = 0;
    double slope;

    for(int i = 0; i < points.size(); i++) {

        int currMax = 0;
        unordered_map<double, int> mp;
        int duplicates = 0;

        for(int j = i + 1; j < points.size(); j++) {

            if(points[i] == points[j]) {
                duplicates++;
                continue;
            }

            if(points[j][0] - points[i][0] == 0) {
                slope = INT_MAX;
            } else {
                slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
            }

            if(mp.find(slope) == mp.end()) {
                mp[slope] = 1;
            }

            mp[slope]++;
            currMax = max(currMax, mp[slope]);

        }

        ans = max(ans, currMax + duplicates);
    }

    return ans;
}

int main() {

    vector<vector<int>> points;
    points.push_back({1,1});
    points.push_back({3,2});
    points.push_back({5,3});
    points.push_back({4,1});
    points.push_back({2,3});
    points.push_back({1,4});


    vector<vector<int>> points1({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 5}, {2, 5}, {3, 5}});

    vector<vector<int>> points2({{{1, 1}, {1, 1}, {1, 1}, {1, 1}, {2, 2}}});

    cout << maxPoints(points1) << endl;

    return 0;
}