class Solution {
public:
    static bool comp(string word1 , string word2){
        //compare by the size of the string
        return word1.size() < word2.size();
    }
    bool ispredecessor(string word1 , string word2){
         if(word1.size()+1 != word2.size()) return 0;
         int m = word1.size();
         int n = word2.size();
         while(m and n){
            if(word1[m-1]==word2[n-1]){
                m--;
                n--;
            }else{
                n--;
            }
         }
         return m==0;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int>ans(n,1);
        sort(words.begin(),words.end(),comp);
        int result = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(ispredecessor(words[j],words[i])){
                    ans[i] = max(ans[i],1+ans[j]);
                }
            }
            result = max(result,ans[i]);
        }
        return result;
    }
};