class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        long long total = 0;

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        if(total < x)
            return -1;

       
        unordered_map<long long, int> mp;

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if(sum <= x) {
                mp[sum] = i + 1;
            }
        }

        long long suffix = 0;
        int ans = INT_MAX;

        // zero elements from left
        if(mp.find(x) != mp.end()) {
            ans = min(ans, mp[x]);
        }

        for(int i = n - 1; i >= 0; i--) {

            suffix += nums[i];

            if(suffix > x)
                break;

            // only suffix
            if(suffix == x) {
                ans = min(ans, n - i);
            }

            // prefix + suffix
            long long remaining = x - suffix;

            if(mp.find(remaining) != mp.end()) {

                int leftCount = mp[remaining];
                int rightCount = n - i;

                // prefix and suffix overlap nahi karne chahiye
                if(leftCount <= i) {
                    ans = min(ans, leftCount + rightCount);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};