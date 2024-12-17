#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream> 
#include <sstream> 
#include "LabeledGraph.h"
#include <queue> 


using namespace std;
// constructor for the LabeledGraph class that takes a filename as an argument 
//(basically does everything in the main function)
LabeledGraph::LabeledGraph(string filename) {

  nedges = 0;
  ifstream in(filename); // creates a stream object to read from the file

  //checks if the file was opened successfully
  if (!in) { 
    cout << "Cannot open the input file." << endl;
    exit(1); // exit if ile could not sucessfully open
  }

  string line;
  while (getline(in, line)) {
    istringstream iss(line);
    vector<string> tokens;
    string token;
    while(getline(iss, token, '/')) {
      tokens.push_back(token);
      }
    for (int i = 1; i < tokens.size(); i++) {
      add_edge(tokens[0], tokens[i]); //adds an edge between the movie and all its actors
      }
    }
    in.close();
}

void LabeledGraph::add_vertex(string vlabel){
  labels.push_back(vlabel);
  indexedLabels.insert(pair<string, int>(vlabel, V()));
  unordered_set<int> s;
  vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target){
  if (!contains(source)) {
    add_vertex(source);
  }
  if (!contains(target)){ 
    add_vertex(target); 
  }
 
 // add edges after making sure both vertex exist 
  vertices[indexedLabels[source]].insert(indexedLabels[target]);
  vertices[indexedLabels[target]].insert(indexedLabels[source]);
  nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
  return indexedLabels.find(vlabel) != indexedLabels.end();
}

unordered_set<int> LabeledGraph::neighbors(int v) const{
    return vertices[v];
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    return indexedLabels[vlabel];
}

unordered_map<int, int> LabeledGraph::BFS(int v)
{
  queue<int> Q; // new queue
  unordered_set<int> visited; // new set to keep track of visited vertices
  unordered_map<int, int> parent_map; // new map to keep track of the parent of each vertex
  parent_map[v] = -1; // set the parent of the starting vertex to -1
  Q.push(v); // push the starting vertex to the queue
  visited.insert(v); //  add the starting vertex to the visited set
  while (!Q.empty()) { // loop until the queue is empty
    int parent = Q.front(); // get the front integer of the queue and assign it to parent
    Q.pop(); //  remove the front integer from the queue
    for (int child : neighbors(parent)) { // loop through the neighbors of the parent
      if (visited.find(child) == visited.end()) { // if the child is not in the visited set, add it to the queue, visited set, and parent map
        parent_map[child] = parent; // set the parent of the child to the parent in the map
        Q.push(child); // add the child to the queue 
        visited.insert(child); // add the child to the visited set
      }
    }
  }
  return parent_map; // return the parent map
}

vector<int> LabeledGraph::pathTo(unordered_map<int, int>& parent_map, int target) // this function returns the shortest path from the starting vertex to the target vertex
{
  vector<int> path; // initialize a vector to store the path
  int current = target; // set the current vertex to the target
  while (current != -1) { // loop until the current vertex is the starting vertex
    path.push_back(current); // add the current vertex to the path
    current = parent_map[current]; // set the current vertex to its parent
  }
  reverse(path.begin(), path.end()); // reverse the path to get the correct order
  return path; // that returns the shortest path
}

ostream& operator<< (ostream &out, const LabeledGraph &g) {
  out << "====================================" << endl;
  out << "Graph Summary: " << g.V() << " vertices, " << g.E() << " edges" << endl;
  out << "====================================" << endl;
  for (int i = 0; i < g.V(); i++) {
      // Output the label of the vertex
      out << g.label(i) << endl;

      // Output the labels of its neighbors
      for (int neighbor : g.neighbors(i)) {
          out << "    " << g.label(neighbor) << endl;
      }
  }
  return out;
}
