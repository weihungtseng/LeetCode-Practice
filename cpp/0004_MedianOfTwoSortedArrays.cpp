//// Topic: 4. Median of Two Sorted Arrays
//// Tag: [Top 100] [Hard] [Merge Sort] [Tokenize]
//// Author: Wei-Hung, Tseng
//// CreateDate: 2022/08/16
//// Discribe:
/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively, 
    return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)).

    Input:          nums1 = [1,3], nums2 = [2]
    Output:         2.00000
    Explanation:    merged array = [1,2,3] and median is 2.

    Input:          nums1 = [1,2], nums2 = [3,4]
    Output:         2.50000
    Explanation:    merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

    Constraints:
        nums1.length == m
        nums2.length == n
        0 <= m <= 1000
        0 <= n <= 1000
        1 <= m + n <= 2000
        -106 <= nums1[i], nums2[i] <= 106
*/

#include <iostream>
//// split
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int i = 0, j = 0, nums1_len = nums1.size(), nums2_len = nums2.size();
            vector<int> v_merge;
            while (i < nums1.size() || j < nums2.size()) {
                //// If two vec length is difference
                if (i == nums1_len && j != nums2_len) {v_merge.push_back(nums2[j]); j++; continue;}
                if (j == nums2_len && i != nums1_len) {v_merge.push_back(nums1[i]); i++; continue;}
                
                //// Merge
                if (nums1[i] < nums2[j]) {v_merge.push_back(nums1[i]); i++;}
                else {v_merge.push_back(nums2[j]); j++;}
            }
            
            if ((i+j)%2 == 0) {return ((double)((v_merge[((i+j)/2)-1]) + (v_merge[(((i+j)/2)+1)-1])))/2.0;}
            else {return (double)(v_merge[((i+j)/2)]);}
        }
};

void tokenize (const string& str, const char delim, vector<int>& vec_inputs) {
    //// Construct a stream from the string
    stringstream ss(str);
    string s;
    while (getline( ss, s, delim)) {vec_inputs.push_back(stoi(s));}
}

int main(){
    Solution solution;
    string inputs;
    const char delim = ' ';
    vector<int> v1, v2;

    getline(cin, inputs);
    tokenize(inputs, delim, v1);

    getline(cin, inputs);
    tokenize(inputs, delim, v2);

    cout << solution.findMedianSortedArrays(v1, v2) << endl;
}