//// Topic: 20. Valid Parentheses
//// Tag: [Top 100] [Easy]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/12
//// Discribe:
/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
    determine if the input string is valid.

    An input string is valid if:
        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.

    Input:          s = "()"
    Output:         true

    Input:          s = "()[]{}"
    Output:         true

    Input:          s = "(]"
    Output:         false

    Constraints:
        1 <= s.length <= 104
        s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            if ((s.length()%2) == 1) {return false;}
            stack<char> stk;
            for (int i=0; i<s.length(); i++) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {stk.push(s[i]);}
                if (s[i] == ')') {
                    if (stk.empty()) {return false;}
                    if (stk.top() == '(') {stk.pop();}
                    else {return false;}
                }
                else if (s[i] == ']') {
                    if (stk.empty()) {return false;}
                    if (stk.top() == '[') {stk.pop();}
                    else {return false;}
                }
                else if (s[i] == '}') {
                    if (stk.empty()) {return false;}
                    if (stk.top() == '{') {stk.pop();}
                    else {return false;}
                }
            }
            if (stk.empty()) {return true;}
            else {return false;}
        }
};

int main(){
    Solution solution;
    string inputs;

    getline(cin, inputs);
    if (solution.isValid(inputs)) {cout << "true" << endl;}
    else {cout << "false" << endl;}
}