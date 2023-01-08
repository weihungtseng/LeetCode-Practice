//// Topic: 11. Container With Most Water
//// Tag: [Top 100] [Medium]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/20
//// Discribe:
/*
    You are given an integer array height of length n. 
    There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) 
    and (i, height[i]).

    Find two lines that together with the x-axis form a container, 
    such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.

    Input:          height = [1,8,6,2,5,4,8,3,7]
    Output:         49
    Explanation:    The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
                    In this case, the max area of water (blue section) the container can 
                    contain is 49.
    
    Input:          height = [1,1]
    Output:         1

    Constraints:
        n == height.length
        2 <= n <= 105
        0 <= height[i] <= 104
*/

#include <iostream>
//// split
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0, j = height.size()-1, maxNum = 0;
            while (i < j) {
                maxNum = max(maxNum, (j-i)*min(height[i], height[j]));
                if (height[i] < height[j]) {i++;}
                else {j--;}
            }
            return maxNum;
        }
};

void tokenize (const string& str, const char delim, vector<int>& vec_inputs) {
    //// Construct a stream from the string
    stringstream ss(str);
    string s;
    while (getline(ss, s, delim)) {vec_inputs.push_back(stoi(s));}
}

int main(){
    Solution solution;
    string inputs;
    const char delim = ' ';
    vector<int> height;

    getline(cin, inputs);
    tokenize(inputs, delim, height);
    cout << solution.maxArea(height) << endl;
}