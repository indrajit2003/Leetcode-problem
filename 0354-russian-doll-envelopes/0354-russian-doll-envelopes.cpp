class Solution {
public:
    static bool comp(vector<int>first,vector<int>second){
        if(first[0]==second[0])
        return first[1]>second[1];

        return first[0]<second[0];
    }
    int maxEnvelopes(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),comp);
        vector<int>temp(1,nums[0][1]);
        for(int i=1;i<n;i++){
            int index = lower_bound(temp.begin(),temp.end(),nums[i][1])-temp.begin();
            if(index==temp.size())
            temp.push_back(nums[i][1]);
            else
            temp[index] = nums[i][1];
        }
        return temp.size();
       
    }
};