/*
66. Plus One My Submissions Question
Total Accepted: 92180 Total Submissions: 278368 Difficulty: Easy
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Subscribe to see which companies asked this question

Hide Tags Array Math
Hide Similar Problems (M) Multiply Strings (E) Add Binary
*/
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        auto it = digits.rbegin();

        *it += 1;
        while (10 == *it)
        {
            *it = 0;
            ++it;
            if (it == digits.rend())
            {
               digits.insert(digits.begin(), 0);
               return digits;
            }

            *it += 1;
        }

        return digits;
    }
};