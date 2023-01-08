//// Topic: 22. Generate Parentheses
//// Tag: [Top 100] [Medium]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/12/29
//// Discribe:
/*
    Given n pairs of parentheses, write a function to generate all combinations of 
    well-formed parentheses.

    Input:          n = 3
    Output:         ["((()))","(()())","(())()","()(())","()()()"]

    Input:          n = 1
    Output:         ["()"]

    Constraints:
        1 <= n <= 8
*/

#include <iostream>
//// split
#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            set<string> set1{""}, set2;
            string pair = "()";
            string str, strCopy;
            int insertPoint;
            for (; n; n--) {
                for (int i=0; i<set1.size();i++) {
                    // str = set1[i];
                    str = *next(set1.begin(), i);
                    insertPoint = str.length()+1;
                    for (int i=0; i<insertPoint; i++) {
                        strCopy = str;
                        strCopy.insert(i, pair);
                        set2.insert(strCopy);
                    }
                }
                set1 = set2;
                set2.clear();
            }
            vector<string> v(set1.begin(), set1.end());
            return v;
        }
};

int main(){
    Solution solution;
    int inputs;
    vector<string> v;

    cin >> inputs;
    v = solution.generateParenthesis(inputs);
    for (int i=0; i<v.size(); i++) {cout << v[i] << " ";} cout << endl;
}