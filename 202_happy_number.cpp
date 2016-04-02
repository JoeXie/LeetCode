/*
202. Happy Number My Submissions Question
Total Accepted: 60313 Total Submissions: 167366 Difficulty: Easy
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Credits:
Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Hash Table Math
Show Similar Problems
*/
#include<unordered_set>

class Solution 
{
public:
    bool isHappy(int n) 
    {
        int sum = 0;
        
        if(0 == n)
            return false;
        if(1 == n)
            return true;
        
        std::unordered_set<int> iset;
        iset.insert(n);
        while(1)
        {
            while(n)
            {
            sum += (n % 10) * (n % 10);
            n = n / 10;
            }
            
            if(sum == 1)
            {
                return true;
            }
            if(iset.find(sum) != iset.end())
                return false;
            else
            {
                n = sum;
                iset.insert(n);
                sum = 0;
            }          
        }
        
        
    }
};