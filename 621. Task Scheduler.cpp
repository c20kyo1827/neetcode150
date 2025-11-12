// Sort
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // AAAABBBEEFFGG 3
        std::vector<int> taskToNum(26,0);
        for(auto& task : tasks) {
            taskToNum[task - 'A']++;
        }
        sort(taskToNum.begin(), taskToNum.end());
        int i = 25, max = taskToNum[25];
        while(i >= 0 && taskToNum[i] == max){
            i--;
        }
        int size = tasks.size();
        // Number of block (A---A---A---) + (A)
        // Number of task in block (4)

        return std::max(size, ((max-1) * (n+1) + 25 - i));
    }
};

/*
    1. Count the size of block (partCnt --> max count - 1)
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max = 0, maxCnt = 0;
        vector<int> taskToNum(26, 0);        
        for (char task : tasks) {
            ++taskToNum[task - 'A'];
            if (max == taskToNum[task - 'A']) {
                ++maxCnt;
            } else if (max < taskToNum[task - 'A']) {
                max = taskToNum[task - 'A'];
                maxCnt = 1;
            }
        }
        int partCnt = max - 1; // Number of block
        int partLen = n - (maxCnt - 1); // 
        int emptySlots = partCnt * partLen;
        int taskLeft = tasks.size() - mx * mxCnt;
        int idles = max(0, emptySlots - taskLeft);
        return tasks.size() + idles;
    }
};

// Priority queue
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0, cycle = n + 1;
        unordered_map<char, int> m;
        priority_queue<int> q;
        for (char c : tasks) ++m[c];
        for (auto a : m) q.push(a.second);
        while (!q.empty()) {
            int cnt = 0;
            vector<int> t;
            for (int i = 0; i < cycle; ++i) {
                if (!q.empty()) {
                    t.push_back(q.top()); q.pop();
                    ++cnt;
                }
            }
            for (int d : t) {
                if (--d > 0) q.push(d);
            }
            res += q.empty() ? cnt : cycle;
        }
        return res;
    }
};
