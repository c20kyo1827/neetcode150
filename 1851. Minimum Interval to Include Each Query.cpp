class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int numOfIntervals = intervals.size();
        int numOfQueries = queries.size();

        // Sort intervals based on the start value
        sort(intervals.begin(), intervals.end());

        // Sort the queries based on the value
        vector<pair<int, int>> sortedQueryValAndIndex(numOfQueries);
        for(int i=0 ; i<numOfQueries ; i++){
            sortedQueryValAndIndex[i] = make_pair(queries[i], i);
        }
        sort(sortedQueryValAndIndex.begin(), sortedQueryValAndIndex.end());

        // Priority queue
        vector<int> ans(numOfQueries, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int intervalIndex = 0;
        for (auto& [queryValue, originalIndex] : sortedQueryValAndIndex) {
            // Add all intervals that 
            //      start before or at the current query point
            //      end after or at the current query point
            while (intervalIndex < numOfIntervals &&
                 intervals[intervalIndex][0] <= queryValue) {
                int startPoint = intervals[intervalIndex][0];
                int endPoint = intervals[intervalIndex][1];
                int intervalLength = endPoint - startPoint + 1;
              
                // Store interval length and end point in the heap
                minHeap.emplace(intervalLength, endPoint);
                ++intervalIndex;
            }
          
            // Remove intervals that end before the current query point
            while (!minHeap.empty() && minHeap.top().second < queryValue) {
                minHeap.pop();
            }
          
            // If there's a valid interval, record its length
            if (!minHeap.empty()) {
                ans[originalIndex] = minHeap.top().first;
            }
        }
      
        return ans;
    }
};
