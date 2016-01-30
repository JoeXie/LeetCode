/*
238. Product of Array Except Self
Total Accepted: 31734 Total Submissions: 77676 Difficulty: Medium

Given an array of n integers where n > 1, nums, return an array 
output such that output[i] is equal to the product of all the 
elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The 
output array does not count as extra space for the purpose of 
space complexity analysis.)
*/


class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> preProduct = {1}; // product of positive direction.
        int backProduct = 1; // product of negtive direction.
        vector<int> ret(nums.size(), 1); // return.
        
        // calculate preProduct.
        int product = 1;
        for(auto ival : nums) {
            product *= ival;
            preProduct.push_back(product);
        }
        
        // calculate result.
        for (int i = nums.size() - 1; i >= 0; --i) {
            ret[i] = backProduct * preProduct[i];
            backProduct *= nums[i];
        }
        
        
        return ret;
    }
};