class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        function<bool(int)> dfs = [&](int course){
            if(visited[course] == 1) return true;
            if(visited[course] == 2) return false;

            visited[course] = 1;
            for(int next : adj[course]){
                if(dfs(next)) return true;
            }
            visited[course] = 2;
            return false;
        };

        for(int i= 0; i < numCourses; i++){
            if(dfs(i)) return false;
        }
        return true;
    }
};
