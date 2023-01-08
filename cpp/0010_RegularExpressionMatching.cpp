//// Topic: 10. Regular Expression Matching
//// Tag: [Top 100] [Hard] [Regular Expression]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/18
//// Discribe:
/*
    Given an input string s and a pattern p, 
    implement regular expression matching with support for '.' and '*' where:
        '.' Matches any single character.​​​​
        '*' Matches zero or more of the preceding element.

    The matching should cover the entire input string (not partial).

    Input:          s = "aa", p = "a"
    Output:         false
    Explanation:    "a" does not match the entire string "aa".
    
    Input:          s = "aa", p = "a*"
    Output:         true
    Explanation:    '*' means zero or more of the preceding element, 
                    'a'. Therefore, by repeating 'a' once, it becomes "aa".
    
    Input:          s = "ab", p = ".*"
    Output:         true
    Explanation:    ".*" means "zero or more (*) of any character (.)".

    Constraints:
        1 <= s.length <= 20
        1 <= p.length <= 30
        s contains only lowercase English letters.
        p contains only lowercase English letters, '.', and '*'.
        It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            string pp;
            // printf("s = %s\tp = %s\n", s.c_str(), p.c_str());
            if (p == "") {return (s == "");}

            bool firstMatch = (s != "" && (p[0] == s[0] || p[0] == '.'));

            //// For safe, copy first then modify value
            pp = p;
            if (p.length() >= 2 && p[1] == '*') {
                return (isMatch(s, pp.erase(0, 2)) || (firstMatch && isMatch(s.erase(0, 1), p)));
            } 
            else {
                return (firstMatch && isMatch(s.erase(0, 1), pp.erase(0, 1)));
            }
        }
};

int main(){
    Solution solution;
    string str, pattern;
    cin >> str;
    cin >> pattern;
    if (solution.isMatch(str, pattern)) {cout << "true" << endl;}
    else {cout << "false" << endl;}
}