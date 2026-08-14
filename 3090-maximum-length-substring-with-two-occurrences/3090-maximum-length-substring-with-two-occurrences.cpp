class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>m;
        int i=0,j=0,res=0,n=s.size();
        while(j<n){
            m[s[j]]++;
            while(m[s[j]]>2){
                m[s[i]]--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};