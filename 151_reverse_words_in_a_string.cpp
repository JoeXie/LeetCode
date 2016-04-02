/*
151. Reverse Words in a String My Submissions Question
Total Accepted: 95213 Total Submissions: 608830 Difficulty: Medium
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
Subscribe to see which companies asked this question

Hide Tags String
Hide Similar Problems (M) Reverse Words in a String II
*/
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        if ("" == s)
            return;

                stringstream str(s);
        vector<string> svec;
        string word;
        
        while (str >> word){
            svec.push_back(word);
        }

        if (svec.empty()){
            s = "";
            return;
        }

        word = svec[svec.size()-1];
        for (int i = svec.size() - 2; i >= 0; --i) {
            word = word + " " + svec[i];
        }
        
        s = word;
    }
};