class Solution {
public:
    bool ispal(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])
            return false;

            start++;
            end--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans=0;
        int lastEnd = -1;
        for(int end=0;end<n;end++){
            for(int start=0;start<=end;start++){
                int len = end-start+1;

                if(len<k) continue;
                if(start<=lastEnd) continue;
                if(!ispal(s,start,end)) continue;


                ans++;
                lastEnd = end;
                break;
            }
        }
        return ans;
    }
};