#include<vector>

// undirected graph
std::vector<int> dfs_num; // either UNVISITED or num of discovery
std::vector<int> dfs_low; // lowest reachable vertex through non tree edge
std::vector<int> p; // record parents in tree discovery
std::vector<int> articulation_vertex; // boolean vector where 1 is set for vertieces that are articulation vertices

int dfsNumberCounter, dfsRoot, rootChildren;

