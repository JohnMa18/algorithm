// 并查集+优先队列
class Solution {
public:
    int f[100000]={0};

    int findF(int n)
    {
        if(f[n]==n)
        {
            return n;
        }
        else
        {
            f[n]=findF(f[n]);
            return f[n];
        }
    }

    void join(int a,int b)
    {
        int fa = findF(a);
        int fb = findF(b);
        if(fa!=fb)
        {
            f[fb]=fa;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = pairs.size();
        int len = s.size();
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> um;
        for(int i =0;i<len;++i)
        {
            f[i]=i;//初始化并查集
        }
        for(int i =0;i<n;++i)
        {
            join(pairs[i][0],pairs[i][1]);//加入并查集
        }
        
        for(int i =0;i<len;++i)
        {
            int fa = findF(i);
            um[fa].emplace(s[i]);
        }
        //重整字符串
        for(int i =0;i<len;++i)
        {
            int fa = findF(i);
            s[i]=um[fa].top();
            um[fa].pop();
        }
        return s;  
    }
};
