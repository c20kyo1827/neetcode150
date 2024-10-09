class Solution {
public:
    int getSum(int a, int b) {
        int andRes = a&b;
        int xorRes = a^b;
        while(andRes != 0){
            andRes = (andRes << 1);
            int temp = xorRes^andRes;
            andRes = xorRes&andRes;
            xorRes = temp;
        }
        return xorRes;
    }
};
