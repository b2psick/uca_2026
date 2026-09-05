#include <bits/stdc++.h>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class snakeGame {

    int width;
    int height;
    queue<pair<int, int>> qFood;
    deque<pair<int, int>> snakeCoord;
    unordered_set<pair<int, int>, PairHash> set;
    int length;

public:
    
    snakeGame(int width, int height, vector<vector<int>> food) {
        this->width = width;
        this->height = height;
        for(auto it :  food) {
            qFood.push({it[0], it[1]});
        }
        length = 0;
        snakeCoord.push_front({0, 0});
        set.insert({0, 0});
    }

    int move(char dir) {

        pair<int, int> lastCoor = snakeCoord.front();
        pair<int, int> currCoord = snakeCoord.back();
        snakeCoord.pop_front();
        set.erase(lastCoor);


        if(dir == 'U') {
            currCoord.first = currCoord.first - 1; 
        }else if(dir == 'D') {
            currCoord.first = currCoord.first + 1;
        }else if(dir == 'R') {
            currCoord.second = currCoord.second + 1;
        }else {
            currCoord.second = currCoord.second - 1;
        }

        if(currCoord.first < 0 || currCoord.first >= height || currCoord.second < 0 || currCoord.second >= width || set.find(currCoord) != set.end()) return -1;

        if(!qFood.empty() && qFood.front() == currCoord) {
            this->length++;
            qFood.pop();
            snakeCoord.push_front(lastCoor);
            set.insert({lastCoor});
        }

        snakeCoord.push_back(currCoord);
        set.insert(currCoord);

        return length;
    }

};

int main() {

    vector<vector<int>> food({{1, 2}, {0, 1}});

    snakeGame* sg = new snakeGame(3, 2, food);

    vector<char> moves({'R', 'D', 'R', 'U', 'L', 'U'});

    vector<int> ans;

    for(int i = 0; i < moves.size(); i++) {

        int currLength = sg->move(moves[i]);

        if(currLength == -1) {
            ans.push_back(-1);
            break;
        }else {
            ans.push_back(currLength);
        }

    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}