//// Topic: 19. Remove Nth Node From End of List
//// Tag: [Top 100] [Medium]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/22
//// Discribe:
/*
    Given the head of a linked list, remove the nth node from the end of the list and return 
    its head.

    Input:          head = [1,2,3,4,5], n = 2
    Output:         [1,2,3,5]
    
    Input:          head = [1], n = 1
    Output:         []

    Input:          head = [1,2], n = 1
    Output:         [1]

    Constraints:
        The number of nodes in the list is sz.
        1 <= sz <= 30
        0 <= Node.val <= 100
        1 <= n <= sz
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
//// split
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode():                        val(0), next(nullptr) {}
    ListNode(int x):                   val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):   val(x), next(next) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *initHead = head;
            int lenHead = 0, frontOfTarget;
            for (; head; head = head->next) {lenHead++;} head = initHead;
            if (lenHead == 1) {return NULL;}
            frontOfTarget = lenHead-n-1;
            if (frontOfTarget < 0) {return head = head->next;}
            //// Move to front of remove target
            for (int i=0; i<frontOfTarget; i++) {head = head->next;}
            head->next = head->next->next;
            return initHead;
        }
};

void tokenize (const string& str, const char delim, vector<int>& vec_inputs) {
    //// Construct a stream from the string
    stringstream ss(str);
    string s;
    while (getline(ss, s, delim)) {vec_inputs.push_back(stoi(s));}
}

ListNode* createLinkedList(vector<int>& vec_inputs) {
    if (vec_inputs.size() == 0) {return NULL;}
    ListNode *head, *linkedList = NULL;
    for (int i=0; i<vec_inputs.size(); i++) {
        if (linkedList != NULL) {
            linkedList->next = new ListNode(vec_inputs[i]);
            linkedList = linkedList->next;
        }
        else {
            linkedList = new ListNode(vec_inputs[i]);
            head = linkedList;
        }
    }
    vec_inputs.clear();
    return head;
}

void printLinkedList (ListNode* start) {
    for (; start; start = start->next) {cout << (start->val) << " ";} cout << endl;
}

int main(){
    Solution solution;
    string inputs;
    int n;
    const char delim = ',';
    vector<int> vec_inputs;

    getline(cin, inputs);
    cin >> n;
    tokenize(inputs, delim, vec_inputs);
    printLinkedList(solution.removeNthFromEnd(createLinkedList(vec_inputs), n));
}