class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> courseGraph(numCourses, vector<int>(0));
        vector<int> courseNumAncestor(numCourses, 0);
        for(auto& course : prerequisites) {
            courseGraph[course[1]].push_back(course[0]);
            courseNumAncestor[course[0]]++;
        }

        queue<int> qCourse;
        for(int i=0 ; i<numCourses ; i++) {
            if(courseNumAncestor[i] == 0)
                qCourse.push(i);
        }

        while(!qCourse.empty()) {
            int course = qCourse.front();
            qCourse.pop();
            ans.push_back(course);

            for(auto& next : courseGraph[course]) {
                courseNumAncestor[next]--;
                if(courseNumAncestor[next] == 0) {
                    qCourse.push(next);
                }
            }
        }

        if(ans.size() != numCourses)
            return vector<int>();
        return ans;
    }
};
