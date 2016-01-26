/*
73. Set Matrix Zeroes My Submissions Question
Total Accepted: 56772 Total Submissions: 173915 Difficulty: Medium

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

https://leetcode.com/problems/set-matrix-zeroes/
*/


class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> colNums, rowNums; // save the numbers of row or column which should to be set to 0. 
        
        // inspect all elements.
        for(int y = 0; y < row; ++y) {
            for(int x = 0; x < col; ++x) {
                // if element is 0, save the row and colums.
                if(matrix[y][x] == 0) { 
                    colNums.push_back(x);
                    rowNums.push_back(y);
                }
            }
        }
        
        // sort and unique numbers.
        sort(rowNums.begin(), rowNums.end());
        sort(colNums.begin(), colNums.end());
        unique(rowNums.begin(), rowNums.end());
        unique(colNums.begin(), colNums.end());
        
        // set rows to 0.
        for(auto y : rowNums) {
            fill(matrix[y].begin(), matrix[y].end(), 0);
        }
        
        // set columns to 0.
        for(int y = 0; y < row; ++y) {
            for(auto x : colNums) {
                matrix[y][x] = 0;
            }
        }
        
    }
};