class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans =0;
        for(int i=0; i<n;i++){
            if(st.find(nums[i]-1) != st.end()){
                continue;
            }else{
                int count = 0;
                int current = nums[i];
              while(st.find(current) != st.end()){
                  count++;
                  current++;
              }
              ans = max(ans , count);
            }
            
        }
        return ans;

        
    }
};