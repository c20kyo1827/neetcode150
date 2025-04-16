// class Solution {
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         std::map<int, double, std::greater<int>> posToTime;
//         for(int i=0 ; i<position.size() ; i++){
//             posToTime[position[i]] = (double)(target - position[i]) / speed[i];
//         }

//         double cur = 0;
//         int res = 0;
//         for(auto[pos, time] : posToTime){
//             if (time <= cur) continue;
//             cur = time;
//             res++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, int>> q;
        for(int i=0 ; i<position.size() ; i++){
            q.push({position[i], speed[i]});
        }

        double cur = 0;
        int res = 0;
        while (!q.empty()) {
	    	auto p2t = q.top();
            q.pop();
            double time = (double)(target - p2t.first) / p2t.second;
	    	if (time <= cur) continue;
	    	cur = time;
	    	++res;
	    }
	    return res;
    }
};
