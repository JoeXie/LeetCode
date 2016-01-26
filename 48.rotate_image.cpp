/*
48. Rotate Image My Submissions Question
Total Accepted: 58385 Total Submissions: 173435 Difficulty: Medium

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/


class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> rotateImg = matrix;
        // copy every row.
        for(int row = 0; row < matrix.size(); ++row) {
            copyOneRow(matrix, rotateImg, row);
        }
        
        matrix = rotateImg;
    }
    
private:
    // copy data row by row.
    void copyOneRow(vector<vector<int>>& src, vector<vector<int>>& dst, int row)
    {
            for (int x = 0; x < src.size(); ++x) {
                dst[x][src.size()-1-row] = src[row][x];
            }
    }
};