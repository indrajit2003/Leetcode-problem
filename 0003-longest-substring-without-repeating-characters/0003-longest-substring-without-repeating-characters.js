/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let st = new Set();
    let right=0;
    let left=0;
    let ans=0;
    while(right<s.length){
        if(st.has(s[right])){
            st.delete(s[left]);
            left++;
        }else{
            st.add(s[right]);
            ans = Math.max(ans,right-left+1);
            right++;
        }
    }
    return ans;
};