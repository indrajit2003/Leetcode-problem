class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*')
            st.push(s[i]);
            if(s[i]=='*')
            st.pop();
            
        }
        string s2="";
        if(st.empty()) return s2;
        while(!st.empty()){
            char ch = st.top();
            s2+=ch;
            st.pop();
        }
        reverse(s2.begin(),s2.end());
        return s2;
    }
};