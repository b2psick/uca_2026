#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int count;

    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;
        maxHeap.push(num);
        if(maxHeap.size() > count / 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() > count / 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (double) (maxHeap.top() + minHeap.top()) / 2;
    }
};

int main() {
    MedianFinder* mf = new MedianFinder();

    return 0;
}