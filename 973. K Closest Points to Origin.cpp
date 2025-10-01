class Solution {
    struct compare{
        bool operator()(const vector<int>& a, const vector<int>& b){
            int sumA = a[0]*a[0] + a[1]*a[1];
            int sumB = b[0]*b[0] + b[1]*b[1];
            return sumA > sumB;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for(auto point : points){
            pq.push(point);
        }
        vector<vector<int>> ans;
        while((k--) > 0){
            auto point = pq.top();
            pq.pop();
            ans.push_back(point);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        	return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
