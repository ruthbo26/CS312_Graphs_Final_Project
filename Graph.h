
Graph()      // Constructor. Creates a graph object. 
void add_vertex ( ) //Adds a vertex to the graph (index automatically assigned)
void add_edge (int source, int target) //Adds an edge connecting source to target
int V( ) const //Returns the number of vertices
int E( )const //Returns the number of edges
set<int> neighbors(int v) const //Returns a set containing the vertices adjacent 
// to v (the neighbors of v)
bool contains(int v) const; //Checks whether vertex v is in the graph

//OVERLOADED OUTPUT OPERATOR
friend std::ostream& operator<< (std::ostream &out, const Graph &g);