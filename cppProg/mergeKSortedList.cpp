#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(auto it : lists){
            if(it) pq.push(it);
        }

        ListNode* curr = nullptr;
        ListNode* newHead = nullptr;

        while(!pq.empty()) {

            ListNode* top = pq.top();
            pq.pop();

            if(!curr) {
                curr = top;
                newHead = curr;
            }
            else {
                curr -> next = top;
                curr = top;
            }
            
            if(top -> next) pq.push(top->next);

        }
        return newHead;
}

int main() {

    ListNode* first = new ListNode(1);
    first->next = new ListNode(4);
    first->next->next = new ListNode(5);

    ListNode* second = new ListNode(2);
    second->next = new ListNode(3);
    second->next->next = new ListNode(8);

    ListNode* third = new ListNode(1);
    third->next = new ListNode(9);
    third->next->next = new ListNode(9);

    vector<ListNode*> testcase;
    testcase.push_back(first);
    testcase.push_back(second);
    testcase.push_back(third);

    ListNode* ans = mergeKLists(testcase);

    while(ans) {
        cout<<ans -> val;
        if(ans -> next) {
            cout<<"->";
        }
        ans = ans -> next;
    }

    return 0;
}