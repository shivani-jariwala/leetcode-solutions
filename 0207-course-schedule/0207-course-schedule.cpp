class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
        //build adjacency list 
        vector<vector<int>> adjList(numCourses);
        for(int i =0 ;i<prerequisites.size(); i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        //building indegree array
  vector<int> indegree(numCourses, 0); 
        for(int i=0; i<numCourses; i++) {
            for(auto it: adjList[i]){
                indegree[it]++;
            }
        }

        vector<int> topo;
        queue<int>q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adjList[node]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(topo.size()==numCourses) return true;
        return false;
    }
};