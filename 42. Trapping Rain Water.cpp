// Two pointer
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right){
            int minHeight = std::min(height[left], height[right]);
            if(minHeight == height[left]){
                ++left;
                while(left < right && height[left] < minHeight){
                    res += (minHeight - height[left++]);
                }
            }
            else{
                --right;
                while(left < right && height[right] < minHeight){
                    res += (minHeight - height[right--]);
                }
            }
        }
        return res;
    }
};

// DP
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
//         int size = height.size();
//         std::vector<int> dp(size, 0);
//         for(int i=0 ; i<size-1 ; i++){
//             dp[i+1] = std::max(dp[i], height[i]);
//         }

//         int rightMax = 0;
//         for(int i=size-1 ; i>=0 ; i--){
//             int curLevel = std::min(dp[i], rightMax);
//             if (curLevel > height[i]) res += (curLevel-height[i]);
//             rightMax = std::max(rightMax, height[i]);
//         }
//         return res;
//     }
// };

// Monotonic Stack
class Solution {
public:
     int trap(vector<int>& height) {
        std::stack<int> s; //h store the mininum idx i from 0 to i
        int i = 0, res = 0;
        while(i < height.size()) {
            if(s.empty() || height[i] < height[s.top()]) {
                cout << "i : " << i << "\n";
                s.push(i);
                i++;
            }
            else {
                int minIdx1 = s.top(); s.pop();
                cout << minIdx1 << "\n";
                if(!s.empty()) {
                    int minIdx2 = s.top();
                    res += (min(height[minIdx2], height[i]) - height[minIdx1]) * (i - minIdx2 - 1);
                    cout << "++\n";
                }
            }
        }
        return res;
    } 
};
