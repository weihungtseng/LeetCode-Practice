//// Topic: 17. Letter Combinations of a Phone Number
//// Tag: [Top 100] [Medium]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/21
//// Discribe:
/*
    Given a string containing digits from 2-9 inclusive, 
    return all possible letter combinations that the number could represent. 
    Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. 
    Note that 1 does not map to any letters.

    Input:          digits = "23"
    Output:         ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    Input:          digits = ""
    Output:         []

    Input:          digits = "2"
    Output:         ["a","b","c"]

    Constraints:
        3 <= nums.length <= 3000
        -105 <= nums[i] <= 105
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> result, tmp1, tmp2;
            string current_str, s;
            for (int i=0; i<digits.length(); i++) {
                if      (digits[i] == '2') {current_str = "abc";}
                else if (digits[i] == '3') {current_str = "def";}
                else if (digits[i] == '4') {current_str = "ghi";}
                else if (digits[i] == '5') {current_str = "jkl";}
                else if (digits[i] == '6') {current_str = "mno";}
                else if (digits[i] == '7') {current_str = "pqrs";}
                else if (digits[i] == '8') {current_str = "tuv";}
                else if (digits[i] == '9') {current_str = "wxyz";}
                if (digits.length() == 1) {
                    for (int j=0; j<current_str.length(); j++) {s = current_str[j]; result.push_back(s);}
                    break;
                }
                if (digits.length() > 1) {
                    if (i == 0) {result = {""};}
                    //// Store in tmp2
                    for (int j=0; j<current_str.length(); j++) {s = current_str[j]; tmp2.push_back(s);}
                    tmp1 = result;
                    result.clear();
                    //// Store in result
                    for (int j=0; j<tmp1.size(); j++) {
                        for (int k=0; k<tmp2.size(); k++) {
                            result.push_back((tmp1[j] + tmp2[k]));
                        }
                    }
                    tmp2.clear();
                }
            }
            return result;
        }
};

int main(){
    Solution solution;
    string inputs;
    vector<string> result;

    getline(cin, inputs);
    result = solution.letterCombinations(inputs);
    for (int i=0; i<result.size(); i++) {cout << result[i] << ' ';} cout << endl;
}