class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int p = k;
        while(st.count(p)){
            p+=k;
        }
        return p;
    }
};