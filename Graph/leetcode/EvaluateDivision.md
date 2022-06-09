
https://leetcode.com/problems/evaluate-division/

## Treat numerator and denominator as edges in graph

## Quotients are edge weights

## To get any division, you can traverse the graph with dfs and collect quotient values along the graph edges

## code

```java
class EdgeWeightPair {
    String nodeName;
    double weight;
    
    public EdgeWeightPair(String nodeName, double weight) {
        this.nodeName = nodeName;
        this.weight = weight;
    }
    
    @Override
    public String toString() {
        return "to: "+nodeName+" wt: "+weight;
    }
}

class Solution {
            static Set<String> visited;

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        
        Map<String, List<EdgeWeightPair>> graph = new HashMap<>();
        visited = new HashSet<>();
        
        for(int i=0;i<equations.size();i++) {
            String first = equations.get(i).get(0);
            String second = equations.get(i).get(1);
            double value = values[i];
            
            List<EdgeWeightPair> edgeList = graph.get(first);
            if(edgeList == null) {
                edgeList = new ArrayList<>();
            }
            edgeList.add(new EdgeWeightPair(second, value));
            graph.put(first, edgeList);
            
            // add reverse edge with 1/value
            List<EdgeWeightPair> secondEdgeList = graph.get(second);
            if(secondEdgeList == null) {
                secondEdgeList = new ArrayList<>();
            }
            secondEdgeList.add(new EdgeWeightPair(first, 1/value));
            graph.put(second, secondEdgeList);
        }
        double[] ans = new double[queries.size()];
        for(int i=0;i<queries.size();i++) {
            List<String> query = queries.get(i);
            String queryFirst = query.get(0);
            String querySecond = query.get(1);
            
            List<EdgeWeightPair> firstEdges = graph.get(queryFirst);
            List<EdgeWeightPair> secondEdges = graph.get(querySecond);
            
            if(firstEdges == null || secondEdges == null) {
                ans[i] = -1;
                continue;
            }
            
            if(queryFirst.equals(querySecond)) {
                ans[i] = 1;
                continue;
            }
            
            // find path from first to second, multiplying edge weights along the way
            visited.clear();
            double ansEnd = getDfsPathValue(graph, queryFirst, querySecond, queryFirst, 1);
            ans[i] = ansEnd;
        }
        return ans;
    }
    
    public static double getDfsPathValue(Map<String, List<EdgeWeightPair>> graph, String startNode, String endNode, String currNode, double estimate) {
        visited.add(currNode);
        // System.out.println("visiting: " + currNode+ " startNode = " + startNode + " endNode: " +endNode+ " estimate: "+ estimate);
        if(currNode.equals(endNode)) {
            // System.out.println("estimate = " + estimate);
            return estimate;
        }
        List<EdgeWeightPair> neighborEdges = graph.get(currNode);
        
        if(neighborEdges!=null && neighborEdges.size() > 0 ){
            double retAns = -1;
            for(int i=0;i<neighborEdges.size();i++) {
                String neighborNode = neighborEdges.get(i).nodeName;
                // System.out.println("neighbor: "+neighborNode);
                if(!visited.contains(neighborNode)) {
                    double gotEstimate = getDfsPathValue(graph, startNode, endNode, neighborNode, estimate * neighborEdges.get(i).weight);
                    retAns = Math.max(retAns,gotEstimate);
                }
            }
            return retAns;
        }
        return -1;
    }
}
```