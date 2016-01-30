/*
31. Next Permutation
Total Accepted: 56949 Total Submissions: 220388 Difficulty: Medium

Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest 
possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its 
corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/


class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size(); // nums size.
        
        // n = 1 or 2
        if(n < 3) {
            swap(nums[0], nums[n-1]);
            return;
        }
        
        // i >= 2, n > 2
        for (int i = 2; i <= n; ++i) {
            // sort last i-1 numbers.
            sort(nums.end()-i+1, nums.end());
            
            for(int j = i-1; j >= 1; --j) {
                if(nums[n-j] > nums[n-i]) {
                    // swap nums[n-i] with others
                    swap(nums[n-j], nums[n-i]);
                    sort(nums.end()-i+1, nums.end());
                    return; // end the function.
                }
                
            }
        }
        
        // loop has finished, the permutation is largest. 
        // return the most small.
        sort(nums.begin(), nums.end());
        
        
    }
};