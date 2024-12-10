#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "LabeledGraph.h"
#include "LabeledGraph.cpp"
#include <cassert>

using namespace std;
int main{

    //create the graph 
    LabeledGraph ruthLabeledGraph; 

    //add edges to make the graph 
    ruthLabeledGraph.add_edge('Chris Pratt', 'Guardians of the Galaxy');
    ruthLabeledGraph.add_edge('Guardians of the Galaxy', 'Zoe saldana');
    ruthLabeledGraph.add_edge('Guardians of the Galaxy', 'Vin Diesel');
    ruthLabeledGraph.add_edge('Zoe Saldana', 'Avatar');
    ruthLabeledGraph.add_edge('Sam Worthington', 'Avatar');
    ruthLabeledGraph.add_edge('Michelle Rodriguez', 'Avatar');
    ruthLabeledGraph.add_edge('Fate of the Furious', 'Michcelle Rodriguez');
    ruthLabeledGraph.add_edge('Fate of the Furious', 'Vin Diesel');
   

    //print graph
    cout << ruthograph; 
  
}