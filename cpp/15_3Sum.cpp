//// Topic: 15. 3Sum
//// Tag: [Top 100] [Medium]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/20
//// Discribe:
/*
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
    such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Input:          nums = [-1,0,1,2,-1,-4]
    Output:         [[-1,-1,2],[-1,0,1]]
    Explanation:    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
                    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
                    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
                    The distinct triplets are [-1,0,1] and [-1,-1,2].
                    Notice that the order of the output and the order of the triplets does not 
                    matter.
    
    Input:          nums = [0,1,1]
    Output:         []
    Explanation:    The only possible triplet does not sum up to 0.

    Input:          nums = [0,0,0]
    Output:         [[0,0,0]]
    Explanation:    The only possible triplet sums up to 0.

    Constraints:
        3 <= nums.length <= 3000
        -105 <= nums[i] <= 105
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
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            int j, k, sum;
            sort(nums.begin(), nums.end());
            for (int i=0; i<nums.size()-2; i++) {
                //// Skip all duplicates from left
                if (i > 0 && nums[i] == nums[i-1]) {continue;}
                j = i+1;
                k = nums.size()-1;
                while (j < k) {
                    sum = nums[i]+nums[j]+nums[k];
                    if (sum == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        k--;
                        //// Skip all duplicates from right
                        while (j < k && nums[k] == nums[k+1]) {k--;}
                    }
                    else if (sum > 0) {k--;}
                    else {j++;}
                }
            }
            return result;
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
    const char delim = ',';
    vector<int> nums;
    vector<vector<int>> result;

    getline(cin, inputs);
    tokenize(inputs, delim, nums);
    result = solution.threeSum(nums);
    for (int i=0; i<result.size(); i++) {
        for (int j=0; j<result[i].size(); j++) {cout << result[i][j] << " ";}
        cout << endl;
    }
}