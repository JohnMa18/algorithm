class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i =0;
        int n =nums.size();
        vector<string> res;
        while(i<n)
        {
            int low = i;
            ++i;
            while(i<n&&nums[i]==nums[i-1]+1)
            {
                ++i;
            }
            int high = i-1;
            string temp = to_string(nums[low]);
            if(high>low)
            {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            res.emplace_back(temp);
        }
        return res;
    }
};
