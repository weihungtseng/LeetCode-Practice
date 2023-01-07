//// Topic: 25. Reverse Nodes in k-Group
//// Tag: [Top 100] [Hard] [Singly-Linked List] [Tokenize]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2023/01/04
//// Discribe:
/*
    Given the head of a linked list, reverse the nodes of the list k at a time, and return 
    the modified list.

    k is a positive integer and is less than or equal to the length of the linked list. If 
    the number of nodes is not a multiple of k then left-out nodes, in the end, should remain 
    as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Input:          head = [1,2,3,4,5], k = 2
    Output:         [2,1,4,3,5]

    Input:          head = [1,2,3,4,5], k = 3
    Output:         [3,2,1,4,5]

    Constraints:
        The number of nodes in the list is n.
        1 <= k <= n <= 5000
        0 <= Node.val <= 1000
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head == NULL || head->next == NULL || k == 1) {return head;}
            ListNode *currentNode = head;
            ListNode *nextNode;
            ListNode *groupTailNode;
            vector<ListNode*> v;
            int cnt = 0, loop;
            for (; currentNode; currentNode = currentNode->next) {v.push_back(currentNode->next); cnt++;}
            loop = cnt/k;
            currentNode = head;
            for (int i=0; i<=loop; i++) {
                for (int j=(k-1); j>=0; j--) {
                    if (currentNode == NULL) {break;}
                    nextNode = currentNode->next;
                    currentNode->next = v[(i*k)+j];
                    if (j == (k-1)) {groupTailNode = currentNode;}
                    currentNode = nextNode;
                }
                if (i == 0) {head = groupTailNode;}
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
    int k;
    // const string delim_str = "],[";
    const char delim_char = ',';
    // vector<string> vec_inputs_str;
    vector<int> vec_inputs_int;

    //// Input [1,2,3,4,5], k = 2
    getline(cin, inputs);
    cin >> k;
    if (inputs == "[]") {cout << "[]" << endl; return 0;}
    if (inputs.length() == 3) {cout << inputs << endl; return 0;}
    inputs = string(inputs.begin()+1, inputs.end()-1);
    tokenizeByChar(inputs, delim_char, vec_inputs_int);
    printLinkedList(solution.reverseKGroup(createLinkedList(vec_inputs_int), k));
}