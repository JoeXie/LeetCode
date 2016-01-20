class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        if (k >= 0 ) {
			// move right
			k = k % nums.size();
			rightStep(nums, k);
		} else {
			// move left
			if (-k >= nums.size()) {  // steps are longer than vector size. set vector to 0.
				for(auto& v : nums)
					v = 0;
			}
			else { 
				k = -k;
				leftStep(nums, k);
			}
		}
    }

private: 
	// move right in 1 step.
	void rightStep(vector<int>& nums, int k)
	{
		vector<int> vec;
		auto it_brk = nums.end() - k;
		for(auto it = it_brk; it != nums.end(); ++it) {
			vec.push_back(*it);
		}
		
		for(auto it = nums.begin(); it != it_brk; ++it) {
			vec.push_back(*it);
		}
		
		nums = vec;
	}
	
	// move left in 1 step.
	void leftStep(vector<int>& nums, int k)
	{
		vector<int> vec;
		for(auto it = nums.begin() + k; it != nums.end(); ++it) {
			vec.push_back(*it);
		}
		
		while(k--) {
			vec.push_back(0);
		}
		
		nums = vec;
	}
	
	
};