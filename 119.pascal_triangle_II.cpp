/*
119. Pascal's Triangle II 
Total Accepted: 63522 Total Submissions: 204643 Difficulty: Easy

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/


// solution 1. use the function in Question 118. but it is O(k*k) extra space.

// solution 2.
class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> line = {1}; // first member.
        
        if(rowIndex == 0)
            return line;
            
        // add other members if rowIndex > 0.
        for(int i = 1; i < rowIndex; ++i) {
            line.push_back(combination(rowIndex, i));
        }
        line.push_back(1); // last member.
        
        return line;
    }
    
private:
    // calculate combination coefficient.
    int combination(int n, int k)
    {
        double a = 1; // product of k.
        double b = 1; // product of n.
        
        if(k > n-k)
            k = n - k;
         
        for(int i = 2; i <= k; ++i) {
            a *= i;
        }
        for(int i = n - k + 1; i <= n; ++i) {
            b *= i;
        }
        
        return (b/a + 0.5); // in order to prevent x.99999999999
    }
};