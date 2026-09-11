class Solution {
public:
    int totalNumbers(vector<int>& digits) {
         vector<int>freq(10,0);
         int count=0;
         for(int i=0;i<digits.size();i++){
            freq[digits[i]]++;
         }
         for(int i=100;i<1000;i++){
            if(i%2 !=0) continue;

            int n=i;
            int a = n%10;
            n/=10;
            int b = n%10;
            n/=10;
            int c = n%10;

            vector<int>need(10,0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool flag = true;
            for(int j=0;j<10;j++){
                if(need[j]>freq[j]){
                    flag=false;
                    break;
                }
            }
            if(flag) count++;

         }
         return count;
    }
};