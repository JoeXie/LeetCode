/*
228. Summary Ranges My Submissions Question

Total Accepted: 33719 Total Submissions: 150351 Difficulty: Easy

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/


class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<int> ranges;
        vector<string> result;
        
        if(nums.size() == 0)
            return result;
        
        getRanges(nums, ranges);
        translate(ranges, result);
        
        return result;
    }
    
private:
    // find ranges in pair in nums, even index is start, odd index is end.
    void getRanges(vector<int>& nums, vector<int>& ranges)
    {
        auto it_l = nums.begin();
        auto it_r = it_l;
        
        for(++it_r; it_r != nums.end(); ++it_r) {
            if(*(it_r-1) != *it_r - 1) {
                ranges.push_back(*it_l);
                ranges.push_back(*(it_r - 1));
                it_l = it_r;
            }
        }
        ranges.push_back(*it_l);
        ranges.push_back(*(it_r - 1));
    }
    
    // translate ranges into string.
    void translate(vector<int>& ranges, vector<string> & result)
    {
        stringstream str;
        for (int i = 0; i < ranges.size(); i =+ 2 ) {
            if(ranges[i] == ranges[i+1]) {
                // the range include 1 member.
                str << ranges[i];
                result.push_back(str.str());
            }
            else {
                // the range include 2members.
                str << ranges[i] << "->" << ranges[i+1];
                result.push_back(str.str());
            }
            
            str.str("");
        }
    }
   
};