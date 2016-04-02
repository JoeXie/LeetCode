/*
1. Two Sum My Submissions Question
Total Accepted: 204125 Total Submissions: 924280 Difficulty: Easy
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

Subscribe to see which companies asked this question

Hide Tags Array Hash Table
Hide Similar Problems (M) 3Sum (M) 4Sum (M) Two Sum II - Input array is sorted (E) Two Sum III - Data structure design

*/
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i = 0, j = 0;
        vector<int> rst;
        for(; i < nums.size(); ++i) 
        {
            for(j = i+1; j < nums.size(); ++j)
            {
                if((nums[i]+nums[j]) == target)
                {
                    rst.push_back(i);
                    rst.push_back(j);
                    return rst;
                }
            }
        }
    }
};