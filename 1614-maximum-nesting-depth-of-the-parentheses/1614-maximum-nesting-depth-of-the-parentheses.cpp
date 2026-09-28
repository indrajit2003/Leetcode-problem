class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char>st;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }
            int p = st.size();
            maxi=max(maxi,p);
            if(s[i]==')'){
                st.pop();
            }
        }
        return maxi;
    }
};