/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    // let sl = s.toLowerCase().replace(/[^A-Za-z0-9]/g, "");
    // let leftIdx = 0;
    // let rightIdx = sl.length-1;
    // while(leftIdx < rightIdx){
    //     if(sl[leftIdx] != sl[rightIdx]) return false;
    //     leftIdx++;
    //     rightIdx--;
    // }
    // return true;
    let leftIdx = 0;
    let rightIdx = s.length-1;
    while(leftIdx < rightIdx){
        while(1){
            if(isAlphaNumeric(s[leftIdx])) break;
            leftIdx++
        }
        while(1){
            if(isAlphaNumeric(s[rightIdx])) break;
            rightIdx--;
        }
        if(leftIdx > rightIdx) break;
        if(s[leftIdx].toLowerCase() != s[rightIdx].toLowerCase()) return false;
        leftIdx++;
        rightIdx--;
    }
    return true;
};

function isAlphaNumeric(char) {
  return /^[a-zA-Z0-9]+$/.test(char);
}
