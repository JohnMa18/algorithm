// by john
// extra array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while(k>n)
        {
            k-=n;
        }
        vector<int>temp;
        for(int i = n-k;i<n;++i)
        {
            temp.emplace_back(nums[i]);
        }
        for(int i =k-1;i>=0;--i)
        {
            nums.insert(nums.begin(),temp[i]);
            nums.pop_back();
        }
    }
};
// by leetcode solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i) {
            newArr[(i + k) % n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }
};

// circular permutation
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};

// reverse 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }

    void reverse(vector<int>& nums,int start,int end)
    {
        while(start<end)
        {
            swap(nums[start],nums[end]);
            start+=1;
            end-=1;
        }
    }
};
