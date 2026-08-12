class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>shortelement;
        int count=0;
        for(int i=0;i<n;i++){
           if(nums[i]==pivot)
           count++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                shortelement.push_back(nums[i]);
            }
        }
        while(count--){
            shortelement.push_back(pivot);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                shortelement.push_back(nums[i]);
            }
        }
        return shortelement;


    }
};