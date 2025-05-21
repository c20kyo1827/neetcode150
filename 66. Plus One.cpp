class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        if(digits.back() == 10){
            for(int i=digits.size()-1 ; i>=0 ; i--) {
                int carry = 0;
                if(digits[i] == 10){
                    digits[i] = 0;
                    carry = 1;
                }
                
                if(i > 0){
                    digits[i-1] += carry;
                }
                else{
                    if(carry == 1)
                        digits.insert(digits.begin(), 1);
                }
            }
        }        
        return digits;
    }
};
