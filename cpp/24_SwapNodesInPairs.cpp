//// Topic: 24. Swap Nodes in Pairs
//// Tag: [Top 100] [Medium] [Singly-Linked List] [Tokenize]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2023/01/04
//// Discribe:
/*
    Given a linked list, swap every two adjacent nodes and return its head. You must solve 
    the problem without modifying the values in the list's nodes (i.e., only nodes themselves 
    may be changed.)

    Input:          head = [1,2,3,4]
    Output:         [2,1,4,3]

    Input:          head = []
    Output:         []

    Input:          head = [1]
    Output:         [1]

    Constraints:
        The number of nodes in the list is in the range [0, 100].
        0 <= Node.val <= 100
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
        ListNode* swapPairs(ListNode* head) {
            if (head == NULL || head->next == NULL) {return head;}
            ListNode *currentNode = head;
            ListNode *nextNode = currentNode->next;
            ListNode *previousPair;
            ListNode *nextPair;
            int flag = 0;
            while (true) {
                nextPair = currentNode->next->next;
                nextNode->next = currentNode;
                currentNode->next = nextPair;
                if (flag == 1) {previousPair->next = nextNode;}
                else {head = nextNode; flag++;}
                previousPair = currentNode;
                currentNode = nextPair;
                if (currentNode == NULL) {break;}
                nextNode = currentNode->next;
                if (nextNode == NULL) {break;}
            }
            return head;
        }
};

// void tokenizeByStr (string str, const string delim, vector<string>& vec_inputs) {
//     size_t pos = 0;
//     while ((pos = str.find (delim)) != string::npos) {
//         vec_inputs.push_back(str.substr(0, pos));
//         str.erase(0, pos + delim.length());
//     }
//     vec_inputs.push_back(str);
// }

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
    // const string delim_str = "],[";
    const char delim_char = ',';
    // vector<string> vec_inputs_str;
    vector<int> vec_inputs_int;

    //// Input [1,2,3,4] | [1,2,3]
    getline(cin, inputs);
    if (inputs == "[]") {cout << "[]" << endl; return 0;}
    if (inputs.length() == 3) {cout << inputs << endl; return 0;}
    inputs = string(inputs.begin()+1, inputs.end()-1);
    //// 1,2,3,4 | 1,2,3
    tokenizeByChar(inputs, delim_char, vec_inputs_int);
    printLinkedList(solution.swapPairs(createLinkedList(vec_inputs_int)));
}