#ifndef LABELED_GRAPH_H
#define LABELED_GRAPH_H

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

class LabeledGraph {
public:

    // CONSTRUCTOR
    LabeledGraph(std::string); //creates an empty graph

    // MODIFICATION MEMBER FUNCTIONS
    //adds a vertex with a specifc label
    void add_vertex(std::string vlabel);

    //adds an edge from vertex with source label to vertex with target label
    void add_edge(std::string source, std::string target);

    // CONSTANT MEMBER FUNCTIONS
    int V( ) const { return vertices.size(); } //number of vertices
    int E( ) const { return nedges; }       //number of edges
    bool contains(std::string vlabel) const;     //does graph contain vertex with label vlabel?
    std::unordered_set<int> neighbors(int v) const;  //returns the vertices adjacent to vertex v
    std::string label(int v) const;     //returns the label of vertex v
    int index(std::string vlabel);           //returns the index of the vertex with label vlabel
    std::unordered_map<int, int> BFS(int); //returns a map of the shortest path from vertex v to all other vertices
    std::vector<int> pathTo(std::unordered_map<int, int>&, int); //returns the shortest path from vertex v to vertex w
    // OVERLOADED OUTPUT OPERATOR
    friend std::ostream& operator<< (std::ostream &out, const LabeledGraph &g);

private:
  int nedges;
  std::vector<std::unordered_set<int> > vertices;
  std::vector<std::string> labels;
  std::unordered_map<std::string, int> indexedLabels;
};

#endif
