//// Topic: 21. Merge Two Sorted Lists
//// Tag: [Top 100] [Easy] [Singly-Linked List] [Tokenize]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/24
//// Discribe:
/*
    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists in a one sorted list. The list should be made by splicing together 
    the nodes of the first two lists.

    Return the head of the merged linked list.

    Input:          list1 = [1,2,4], list2 = [1,3,4]
    Output:         [1,1,2,3,4,4]

    Input:          list1 = [], list2 = []
    Output:         []

    Input:          list1 = [], list2 = [0]
    Output:         [0]

    Constraints:
        The number of nodes in both lists is in the range [0, 50].
        -100 <= Node.val <= 100
        Both list1 and list2 are sorted in non-decreasing order.
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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode():                         val(0), next(nullptr) {}
    ListNode(int x):                    val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):    val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == NULL) {return list2;}
            if (list2 == NULL) {return list1;}
            ListNode *head, *currentNode = NULL;
            while (list1 != NULL || list2 != NULL) {
                ListNode *newNode = new ListNode();
                //// Set val
                if      (list1 == NULL)            {newNode->val = list2->val; list2 = list2->next;}
                else if (list2 == NULL)            {newNode->val = list1->val; list1 = list1->next;}
                else if (list1->val > list2->val)  {newNode->val = list2->val; list2 = list2->next;}
                else if (list1->val <= list2->val) {newNode->val = list1->val; list1 = list1->next;}
                //// Construct sorted linked list
                if (currentNode != NULL) {
                    currentNode->next = newNode;
                    currentNode = currentNode->next;
                }
                else{
                    currentNode = newNode;
                    head = currentNode;
                }
            }
            return head;
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
    for (; start; start = start->next) {cout << start->val << ' ';} cout << endl;
}

int main(){
    Solution solution;
    string inputs;
    const char delim = ',';
    vector<int> vec_inputs;
    ListNode *l1;
    ListNode *l2;

    //// Input l1
    getline(cin, inputs);
    tokenize(inputs, delim, vec_inputs);
    l1 = createLinkedList(vec_inputs);
    
    //// Input l2
    getline(cin, inputs);
    tokenize(inputs, delim, vec_inputs);
    l2 = createLinkedList(vec_inputs);

    printLinkedList(solution.mergeTwoLists(l1, l2));
}