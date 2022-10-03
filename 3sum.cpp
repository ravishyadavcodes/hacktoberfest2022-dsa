class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {          sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n= nums.size();
       unordered_map<int,int> m;
        set<vector<int>> s;
       unordered_map<int,int> :: iterator it;
        set<vector<int>> :: iterator itr;
        vector<int> v;
        int k=0, l=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0){
                break;
            }
            for(int j=i+1;j<n;j++)
            {
                int p=1;
                k=0-(nums[i]+nums[j]);
                if(k==nums[i])p++;
                if(k==nums[j])p++;
                it=m.find(k);
                if(it!=m.end()){
                if((*it).second>=p)
                {
                    v.push_back((*it).first);
v.push_back(nums[i]);
v.push_back(nums[j]) ; 
sort(v.begin(), v.end());
                    
                s.insert(v);
                    if(p==3){
                      l=1;
                        break;
                    }
                }
                
                v.clear();
            }
           }
            if(l==1){
                
                break;
            }
        }
        for(itr=s.begin();itr!=s.end();itr++)
        {
            ans.push_back(*itr);
        }
        return ans;
    }
};