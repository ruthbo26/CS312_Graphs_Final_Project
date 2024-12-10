#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <cassert>

using namespace std;

//Adds a vertex to the graph
//The index of the new vertex is automatically assigned
// Big-O time: O(1) constant time to add new set
void Graph::add_vertex(){
  set<int> s;   //makes a set of integers that will represent edges of the new vertex
  edges.push_back(s);  //add s to edges

}


//Adds an edge connecting source to target
// Big-O time: O(log N),its take O(log n) to insert into a set, we do this 2 times, but we can drop the constant
void Graph::add_edge(int source, int target){
    assert (contains(source) && contains(target)); //check if source and target exist in graph
    edges[source].insert(target); //add target to source adjaceny list
    edges[target].insert(source); //add source to target adjaceny list 
    nedges++; //increase edge count 
}

//Returns number of vertices
// Runs in O(1) beause it takes contsant time to access size 
int Graph::V( ) const { 
	return edges.size();  //gives the number of vertices, which is equivalent to size of edges vector
} 

//Returns number of edges
// Returning integer variable takes constant time, so O(1)
int Graph::E( ) const { 
	return nedges; 
} 

//Returns the vertices adjacent to vertex v
// Ruuning time: checking if vertices xsit and accessing adjaceny list are both O(1), so overall time is O(1)
set<int> Graph::neighbors(int v) const{
    assert (contains(v)); // checks if v exist in graph, if it does assert is true and prgoram will proceed
    return edges[v]; //returns adjaceny list of v
}

//Checks if vertex v is in the graph
// Running time is O(1)
bool Graph::contains(int v) const{
  return v < V(); //if v smaller than total # of vertices, it's in the graph
}

ostream& operator<< (ostream &out, const Graph &g) {
  out << "======================================\n";
  out << "Graph Summary: " << g.V() << " vertices, " << g.E() << " edges\n";
  out << "======================================\n";

  for (int i = 0; i < g.V(); ++i) {
        out << "Vertex " << i << " --> "; //print index of vertex
        for (int neighbor : g.neighbors(i)) { //iterate through adjaceny list 
            out << neighbor << " "; //print each neighbor
        }
        out << "\n";
    }
  return out;
}


// Questions Set 1:
// 1. The code from the graph.h file represents an Adjaceny List.
// 2. On each line


// Question Set 2:
// 1. Because the number of vertices is directly related to the edges. Since the graph uses vector, every index in the edges vector
//    connects to a vertex.
// 2.  Running time for overloaded output operator: outer loop iterates through aall vertices so O(V) and the inner loop 
//     iterates through the neighbors or edges so O(E). Overall running time is O(V+E)
// 3. An adjacency matrix is a 2D array. To display the graph using a matrix, we would need to iterate through the entire matrix. 
//      An outer loop that would iterate through each vertex V. Then an inner for loop that each vertex would need to check for every 
//      posible neighbor. Overall running time would be V^2.


//Question Set 3:
// 1. Vector of strings called labels was added to store the label for each vertex in the graph. 
// 2. Add vertex changes: include adding label of vertex to the labels vector and code to map the label to the vertex. This will 
//    simplfy the lookup process as everything is labeled and not just integers.
//    Add edges changes: first check if source and target vertex exist, if they dont, add source or target vertex if they are missing