class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //build adjList
        vector<vector<int>> adjList(numCourses);
        for(int i=0; i<prerequisites.size();i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        } //0->1

        //now build indegree array
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto it:adjList[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        //now find the one with indegree =0
        for(int i=0; i<numCourses; i++) {
            if(indegree[i]==0) q.push(i);
        }

        //now push this into topo and update indegree from adjList
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it  : adjList[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()!=numCourses) return {};
        return topo;
        }
};