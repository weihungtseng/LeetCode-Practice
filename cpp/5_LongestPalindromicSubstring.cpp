//// Topic: 5. Longest Palindromic Substring
//// Tag: [Top 100] [Medium] [Palindromic]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/17
//// Discribe:
/*
    Given a string s, return the longest palindromic substring in s.

    Input:          s = "babad"
    Output:         "bab"
    Explanation:    "aba" is also a valid answer.
    
    Input:          s = "cbbd"
    Output:         "bb"

    Constraints:
        1 <= s.length <= 1000
        s consist of only digits and English letters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            string substring;
            int s_len = s.length(), head, tail, tmp_head, tmp_tail, ans_len = 0, ans_head = 0, ans_tail = 0;

            if (s_len <= 1) {return s;}

            //// Traversal
            for (double center=0; center<=(s_len-1); center+=0.5) {
                //// Set the string index pointer
                if ((int)(center*10)%10 == 0) {head = center; tail = center;}
                else                          {head = center; tail = center+1;}
                //// Check palindrome in range
                while (head >= 0 && tail <=(s_len-1)) {
                    if (s[head] == s[tail]) {
                        tmp_head = head;
                        tmp_tail = tail;
                    }
                    else {break;}
                    head--; tail++;
                }
                //// Store current loop variable for each center if ans_len is longer
                if ((tmp_tail-tmp_head) > ans_len) {
                    ans_head = tmp_head;
                    ans_tail = tmp_tail;
                    ans_len = tmp_tail-tmp_head;
                }
            }

            return substring.assign(s, ans_head, (ans_tail-ans_head)+1);
        }
};

int main(){
    Solution solution;
    string inputs;
    cin >> inputs;
    cout << solution.longestPalindrome(inputs) << endl;
}