//// Topic: 23. Merge k Sorted Lists
//// Tag: [Top 100] [Hard] [Singly-Linked List] [Tokenize]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2023/01/02
//// Discribe:
/*
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending 
    order.

    Merge all the linked-lists into one sorted linked-list and return it.

    Input:          lists = [[1,4,5],[1,3,4],[2,6]]
    Output:         [1,1,2,3,4,4,5,6]
    Explanation:    The linked-lists are:
                    [
                        1->4->5,
                        1->3->4,
                        2->6
                    ]
                    merging them into one sorted list:
                    1->1->2->3->4->4->5->6

    Input:          lists = []
    Output:         []

    Input:          lists = [[]]
    Output:         []

    Constraints:
        k == lists.length
        0 <= k <= 104
        0 <= lists[i].length <= 500
        -104 <= lists[i][j] <= 104
        lists[i] is sorted in ascending order.
        The sum of lists[i].length will not exceed 104.
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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.size() == 0) {return NULL;}
            ListNode *head, *currentNode = NULL;
            int lstSize = lists.size(), cnt, minVal, minInd;
            while (true) {
                //// Find min
                cnt = 0;
                minVal = 105;
                for (int i=0; i<lstSize; i++) {
                    if (lists[i] == NULL) {cnt++; continue;}
                    if (lists[i]->val <= minVal) {minVal = lists[i]->val; minInd = i;}
                }
                //// If finish
                if (cnt == lstSize) {break;}
                //// Construct sorted linked list
                if (currentNode != NULL) {
                    currentNode->next = new ListNode(minVal);;
                    currentNode = currentNode->next;
                }
                else {
                    currentNode = new ListNode(minVal);;
                    head = currentNode;
                }
                //// Move lists[i] linked list to next
                if (lists[minInd] != NULL) {lists[minInd] = lists[minInd]->next;}
            }
            return head;
        }
};

void tokenizeByStr (string str, const string delim, vector<string>& vec_inputs) {
    size_t pos = 0;
    while ((pos = str.find (delim)) != string::npos) {
        vec_inputs.push_back(str.substr(0, pos));
        str.erase(0, pos + delim.length());
    }
    vec_inputs.push_back(str);
}

void tokenizeByChar (const string& str, const char delim, vector<int>& vec_inputs) {
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
    const string delim_str = "],[";
    const char delim_char = ',';
    vector<string> vec_inputs_str;
    vector<int> vec_inputs_int;
    vector<ListNode*> lst;

    //// Input [[1,4,5],[1,3,4],[2,6]] | [[1,3],[2,4]]
    getline(cin, inputs);
    if (inputs == "[]" || inputs == "[[]]") {cout << "[]" << endl; return 0;}
    inputs = string(inputs.begin()+2, inputs.end()-2);
    //// inpusts = 1,4,5],[1,3,4],[2,6
    tokenizeByStr(inputs, delim_str, vec_inputs_str);
    for (int i=0; i<vec_inputs_str.size(); i++) {
        tokenizeByChar(vec_inputs_str[i], delim_char, vec_inputs_int);
        lst.push_back(createLinkedList(vec_inputs_int));
    }
    printLinkedList(solution.mergeKLists(lst));
}