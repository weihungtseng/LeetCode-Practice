//// Topic: 3. Longest Substring Without Repeating Characters
//// Tag: [Top 100] [Medium]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/16
//// Discribe:
/*
    Given a string s, find the length of the longest substring without repeating characters.    

    Input:          s = "abcabcbb"
    Output:         3
    Explanation:    The answer is "abc", with the length of 3.

    Input:          s = "bbbbb"
    Output:         1
    Explanation:    The answer is "b", with the length of 1.

    Input:          s = "pwwkew"
    Output:         3
    Explanation:    The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

    Constraints:
        0 <= s.length <= 5 * 104
        s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            string substring, tmp, ans = "";

            if (s.length() == 1) {return 1;}

            //// Traversal
            for (int i=0; i<s.length(); i++) {
                substring = s[i];
                for (int j=i+1; j<s.length(); j++) {
                    //// found
                    if (substring.find(s[j]) != string::npos) {
                        tmp = substring;
                        break;
                    }
                    else {tmp = (substring += s[j]);}
                }
                if (ans.length() < tmp.length()) {ans = tmp;}
            }
            return ans.length();
        }
};

int main(){
    Solution solution;
    string inputs;
    cin >> inputs;
    cout << solution.lengthOfLongestSubstring(inputs) << endl;
}