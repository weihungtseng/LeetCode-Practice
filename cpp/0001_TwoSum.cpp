//// Topic: 1. Two Sum
//// Tag: [Top 100] [Easy] [Simple Class]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/12
//// Discribe:
/*
    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.

    You can return the answer in any order.

    Input:          nums = [2,7,11,15], target = 9
    Output:         [0,1]
    Explanation:    Because nums[0] + nums[1] == 9, we return [0, 1].

    Constraints:
        2 <= nums.length <= 104
        -109 <= nums[i] <= 109
        -109 <= target <= 109
        Only one valid answer exists.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> tmp;
            for (int i=0; i<nums.size()-1; i++) {
                for (int j=i+1; j<nums.size(); j++) {
                    if (nums[i] + nums[j] == target) {
                        tmp.push_back(i);
                        tmp.push_back(j);
                        return tmp;
                    }
                }
            }
            return {};
        }
};

int main(){
    Solution solution;
    // vector<int> nums{2,7,11,15};
    vector<int> nums{3,2,4};
    vector<int> result;
    // int target = 9;
    int target = 6;
    result = solution.twoSum(nums, target);
    cout << '[' << result[0] << ',' << result[1] << ']' << endl;
}