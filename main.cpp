#include <iostream>
#include <fstream>
#include "LabeledGraph.cpp"
using namespace std;

int main() {

    LabeledGraph g("movies_short.txt");
    // cout << g << endl;
    // ofstream out("output.txt");
    // out << g;
    // out.close();

    cout << "Enter actor (Lastname, Firstname) or movie name with year (Movie Name (YYYY)):  ";
    string name;
    getline(cin, name);

    if (g.contains(name)) {
        cout << "Neighbors of " << name << ": ";
        for (int n : g.neighbors(g.index(name))) {
            cout << g.label(n) << " ";
        }
        cout << endl;
    } else {
        cout << name << " not found." << endl;
    }


    return 0;
} 