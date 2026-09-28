/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    let total=0;
    let prefixSum=0
    let rem;
    const mp = new Map();
    mp.set(0,1);
    for(let i=0;i<nums.length;i++){
        prefixSum+=nums[i];
        rem = prefixSum%k
        if(rem<0)
        rem+=k;
        if(mp.has(rem)){
            total += mp.get(rem)
            mp.set(rem, mp.get(rem) + 1);
        }else{
           mp.set(rem, 1);
        }
    }
    return total;

};