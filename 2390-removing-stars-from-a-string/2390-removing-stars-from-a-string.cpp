class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        string s2="";
        for(int i=0;i<n;i++){
            if(s[i]!='*')
            s2+=s[i];
            if(s[i]=='*')
            s2.pop_back();
        }
        return s2;
    }
};