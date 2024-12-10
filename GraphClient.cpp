#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <cassert>

using namespace std;
int main{

    //create the graph 
    Graph ruthgraph; 

    //add edges to make the graph 
    ruthograph.add_edge(0,4);
    ruthograph.add_edge(0,2);
    ruthograph.add_edge(4,1);
    ruthograph.add_edge(2,3);

    //print graph
    cout << ruthograph; //overlaod output operator has only been declared, but not defined so not nothing is printed.
  
}