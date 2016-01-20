/*
118. Pascal's Triangle
Total Accepted: 70429 Total Submissions: 219899 Difficulty: Easy

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result;
        vector<int> line;
        
        // 0 line
        if(numRows == 0) {
            return result;
        }
        
        // 1 line.
        if(numRows == 1) {
            line.push_back(1);
            result.push_back(line);
            return result;
        }
        
        // 2 lines.
        if(numRows == 2) {
            line.push_back(1);
            result.push_back(line); // first line
            line.push_back(1);
            result.push_back(line); // second line
            return result;
        }
        
        // more than 2 lines.
        line.push_back(1);
        result.push_back(line); // first line
        line.push_back(1);
        result.push_back(line); // second line
        
        for (int i = 3; i <= numRows; ++i) {
            line = nextLine(line); // generate next line based in current line.
            result.push_back(line);
        }
        
        return result;
    }
    
private:
    // generate next line based in current line.
    vector<int> nextLine(vector<int>& line)
    {
        vector<int> newLine = {1};
        for(int i = 1; i < line.size(); ++i) {
            newLine.push_back(line[i-1] + line[i]);
        }
        
        newLine.push_back(1); //add last member. return result.
        return newLine;
    }
        
        
};