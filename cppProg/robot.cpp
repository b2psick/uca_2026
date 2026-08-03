#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct PairHash {
    size_t operator()(const pair<string,int>& p) const {
        return hash<string>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class RobotMessageTracker {
public:
    unordered_map<string,int> mp;
    deque<pair<string,int>> dq;
    unordered_set<pair<string,int>,PairHash> st;
    void shouldPrintMessage(int timestamp, string message){
        if(mp.find(message)!=mp.end()&&mp[message]==timestamp){
            st.insert({message,timestamp});
        }
        while(!dq.empty() && timestamp - dq.front().second >= 10){
            if(st.find({dq.front().first,dq.front().second})!=st.end()){
                st.erase({dq.front().first,dq.front().second});
                dq.pop_front();
                continue;
            }else if(mp[dq.front().first] == dq.front().second){
                cout<<dq.front().first<<endl;
                cout<<dq.front().second<<endl;
            }
            dq.pop_front();
        }
       
        if(mp.find(message)==mp.end() || timestamp - mp[message] >= 10){
            dq.push_back({message,timestamp});
        }
       
        mp[message]=timestamp;
    }
};


int main()
{
    RobotMessageTracker logger;
    logger.shouldPrintMessage(1, "foo");
    logger.shouldPrintMessage(11, "foo");
    logger.shouldPrintMessage(21, "foo");
    logger.shouldPrintMessage(21, "foo");
    logger.shouldPrintMessage(45, "foo");
    logger.shouldPrintMessage(61, "foo");
    // logger.shouldPrintMessage(28, "foo");
    // logger.shouldPrintMessage(29, "foo");
    // logger.shouldPrintMessage(30, "foo");
    // logger.shouldPrintMessage(31, "bar");
    // logger.shouldPrintMessage(100, "bar");
    // logger.shouldPrintMessage(8, "bar");
    // logger.shouldPrintMessage(10, "foo");
    // logger.shouldPrintMessage(11, "foo");
    // logger.shouldPrintMessage(12, "bar");
    // logger.shouldPrintMessage(30, "foo");
    // logger.shouldPrintMessage(-100, "foo");
    // logger.shouldPrintMessage(0, "foo");
    // logger.shouldPrintMessage(42, "bar");
    // logger.shouldPrintMessage(53, "bar");
    // logger.shouldPrintMessage(95, "bar");
    return 0;
}