// // TLE
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int res = 0;
//         for (int i=0; i<heights.size(); i++) {
//             if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) {
//                 continue;
//             }
//             int minH = heights[i];
//             for (int j=i; j>=0; j--) {
//                 minH = std::min(minH, heights[j]);
//                 int area = minH * (i - j + 1);
//                 res = std::max(res, area);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int ans = 0;
        stack<int> ms;
        for(int i=0 ; i<heights.size() ; i++){
            if(ms.empty() || heights[ms.top()] < heights[i]){
                ms.push(i);
            }
            else{
                int cur = ms.top();
                ms.pop();
                // cout << "idx : " << i << "\n";
                // cout << (ms.empty() ? i : (i - ms.top() - 1)) << "\n";
                // cout << heights[cur] * (ms.empty() ? i : (i - ms.top() - 1)) << "\n";
                ans = std::max(
                        ans,
                        heights[cur] * (ms.empty() ? i : (i - ms.top() - 1)) );
                i--;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         heights.push_back(0);
//         int ans = 0;
//         stack<int> ms;
//         for(int i=0 ; i<heights.size() ; i++){
//             while (!ms.empty() && heights[ms.top()] >= heights[i]) {
//                 int cur = ms.top(); ms.pop();
//                 res = max(res, heights[cur] * (ms.empty() ? i : (i - ms.top() - 1)));
//             }
//             st.push(i);
//         }
//         return ans;
//     }
// };
