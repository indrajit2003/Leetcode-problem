class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_set<char>st;
     int l=0,r=0,ans=0;
     while(r<s.size()){
        if(st.find(s[r]) != st.end()){
            st.erase(s[l]);
            l++;
        }else{
            st.insert(s[r]);
            ans = max(ans,r-l+1);
            r++;
        }
     }
     return ans;
    }
};