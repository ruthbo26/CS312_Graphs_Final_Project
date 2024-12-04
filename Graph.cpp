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
void Graph::add_vertex(){
  set<int> s;
  edges.push_back(s);
}


//Adds an edge connecting source to target
void Graph::add_edge(int source, int target){
    assert (contains(source) && contains(target));
    edges[source].insert(target);
    edges[target].insert(source);
    nedges++;
}

//Returns number of vertices
int Graph::V( ) const { 
	return edges.size(); 
} 

//Returns number of edges
int Graph::E( ) const { 
	return nedges; 
} 

//Returns the vertices adjacent to vertex v
set<int> Graph::neighbors(int v) const{
    assert (contains(v));
    return edges[v];
}

//Checks if vertex v is in the graph
bool Graph::contains(int v) const{
  return v < V();
}

ostream& operator<< (ostream &out, const Graph &g) {
  return out;
}
