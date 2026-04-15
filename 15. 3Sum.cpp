/**
 * @param {number[]} nums
 * @return {number[][]}
 */
 /*
    recall two sum => if we select the first element, then we can know the remain sum should be (0 - element.value)
    the two sum use two pointer to construct
 */
var threeSum = function(nums) {
    nums.sort(function(a, b) {
        return a - b;
    });
    const ans = new Set();
    for(let i=0 ; i<nums.length ; i++){
        if(i+1 >= nums.length) break;
        let dict = {};
        for (let j=i+1 ; j<nums.length ; j++){
            let target = 0-nums[i]-nums[j];
            if (dict.hasOwnProperty(nums[j]) === true){
                let array = [nums[i], nums[j], target].sort();
                ans.add((array).toString());
            }
            else{
                dict[target] = 1;
            }
        }
    }
    let res = [];
    ans.forEach(function(element){
        res.push(element.split(","));
    });
    return res;
};
