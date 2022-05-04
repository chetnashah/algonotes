package Graph.implementations;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;
import java.io.File; 
import java.io.*;

class EdgePair<A extends Comparable<A>,B extends Comparable<B>> implements Comparable<EdgePair<A,B>> {
    public A vertexid;
    public B weight;

    EdgePair(A vertexId, B weight) {
        this.vertexid = vertexId;
        this.weight = weight;
    }

    @Override
    public String toString() {
        return "Vertex-id: "+ vertexid + " weight: " + weight;
    }

    @Override
    public int compareTo(EdgePair<A,B> o) {
        return this.weight.compareTo(o.weight) ;
    }
}

class NodeDistPair<A extends Comparable<A>,B extends Comparable<B>> implements Comparable<NodeDistPair<A,B>> {
    public A vertexid;
    public B dist;

    NodeDistPair(A vertexId, B dist) {
        this.vertexid = vertexId;
        this.dist = dist;
    }

    @Override
    public String toString() {
        return "Vertex-id: "+ vertexid + " dist: " + dist;
    }

    @Override
    public int compareTo(NodeDistPair<A,B> o) {
        return this.dist.compareTo(o.dist) ;
    }
}

public class DjikstraSSSP {
    public static void main(String[] args) {
        System.out.println("Hello world " + new File(".").getAbsolutePath());
        Map<Integer,ArrayList<EdgePair<Integer,Integer>>> graph = new HashMap<>();
        
        try {
            BufferedReader reader = new BufferedReader(new FileReader("Graph\\implementations\\tests\\djikstra-in.txt"));
            Scanner sc = new Scanner(reader);
            int N = sc.nextInt();
            int E = sc.nextInt();
            for(int i = 0; i< E; i++) {
                Integer src = sc.nextInt();
                Integer dest = sc.nextInt();
                Integer wt = sc.nextInt();
                EdgePair<Integer,Integer> ep = new EdgePair<Integer, Integer>(dest, wt);
                if(graph.get(src) == null) {
                    graph.put(src, new ArrayList<>());
                }
                graph.get(src).add(ep);
            } // graph reading done

            computeDjikstrasShortestPaths(N, graph);


        } catch(IOException ex) {
            System.out.println(ex);
        }

    }

    private static void computeDjikstrasShortestPaths(Integer N, Map<Integer, ArrayList<EdgePair<Integer, Integer>>> graph) {
        // dist vector
        ArrayList<Integer> dist = new ArrayList<>();// index is vertex-id, value is dist to that vertex-id
        ArrayList<Boolean> selected = new ArrayList<>();

        for(int i = 0; i < N; i++) {
            dist.add(i, Integer.MAX_VALUE); // initialize all dist at INF/Max value
            selected.add(i, Boolean.FALSE);
        }

        PriorityQueue<NodeDistPair<Integer,Integer>> pq = new PriorityQueue<>();
        pq.add(new NodeDistPair<>(0, 0));
        dist.set(0,0);
        selected.set(0, Boolean.TRUE);

        while(!pq.isEmpty()){
            NodeDistPair<Integer,Integer> nodeDistPair = pq.poll();
            Integer selectedVertexId = nodeDistPair.vertexid;

            for(EdgePair<Integer,Integer> neighbourEdge: graph.getOrDefault(selectedVertexId, new ArrayList<>())) {
                Integer neighborVertexId = neighbourEdge.vertexid;
                Integer neighborEdgeWeight = neighbourEdge.weight;

                if(selected.get(neighborVertexId)) continue;

                // relax and update both dist and pq.
                Integer transitiveDist = dist.get(selectedVertexId) + neighborEdgeWeight;
                if(transitiveDist < dist.get(neighborVertexId)) {
                    dist.set(neighborVertexId, transitiveDist);
                    pq.offer(new NodeDistPair<>(neighborVertexId, transitiveDist));
                }
            }
        }

        for(int i = 0; i< dist.size(); i++ ){
            System.out.println("dist to " + i + " is " + dist.get(i));
        }
    }
}