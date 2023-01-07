//// Topic: 2. Add Two Numbers
//// Tag: [Top 100] [Medium] [Singly-Linked List] [Tokenize]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/12
//// Discribe:
/*
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, 
    except the number 0 itself.

    Input:          l1 = [2,4,3], l2 = [5,6,4]
    Output:         [7,0,8]
    Explanation:    342 + 465 = 807.

    Input:          l1 = [0], l2 = [0]
    Output:         [0]

    Input:          l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output:         [8,9,9,9,0,0,0,1]

    Constraints:
        The number of nodes in each linked list is in the range [1, 100].
        0 <= Node.val <= 9
        It is guaranteed that the list represents a number that does not have leading zeros.
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *head = l1;
            int l1_val, l2_val, sum, carry = 0;
            string l1_signal = "notEnd", l2_signal = "notEnd";

            while(true){
                if (l1_signal != "isEnd") {l1_val = l1->val;} else {l1_val = 0;}
                if (l2_signal != "isEnd") {l2_val = l2->val;} else {l2_val = 0;}

                //// Plus
                sum = (l1_val + l2_val + carry)%10;

                //// Carry
                if (l1_val + l2_val + carry > 9) {carry = 1;} else {carry = 0;}
                
                //// sum store in l1
                l1->val = sum;

                //// Move current node to next
                if (l1->next != NULL) {l1 = l1->next;} else {l1_signal = "isEnd";}
                if (l2->next != NULL) {l2 = l2->next;} else {l2_signal = "isEnd";}

                //// Create a new node for l1 when needed
                if (l1_signal == "isEnd" && l2_signal == "notEnd") {
                    ListNode *new_node = new ListNode();
                    l1->next = new_node;
                    l1 = l1->next;
                }
                
                //// Finish
                if (l1_signal == "isEnd" && l2_signal == "isEnd") {
                    if (carry == 1) {
                        ListNode *new_node = new ListNode(carry);
                        l1->next = new_node;
                    }
                    break;
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
    for (; start; start = start->next) {cout << start->val << endl;}
}

int main(){
    Solution solution;
    string inputs;
    const char delim = ',';
    vector<int> vec_inputs;
    /* ListNode l1 = [2,4,3], l2 = [5,6,4]; */
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

    printLinkedList(solution.addTwoNumbers(l1, l2));
}