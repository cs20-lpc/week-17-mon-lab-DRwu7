#include "GraphMatrix.hpp"
#include <iostream>
#include <stdexcept> // <--- Ensure this is included for out_of_range
using namespace std;

// Constructor
GraphMatrix::GraphMatrix(int numV, GType type)
: Graph(numV, 0, type) { 
    adjMatrix = new bool*[v]; 
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new bool[v];
    }
    
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

// Destructor
GraphMatrix::~GraphMatrix() {
    for (int i = 0; i < v; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    adjMatrix = nullptr;
}

// Determine if an edge exists between the two given vertices
bool GraphMatrix::isEdge(int i, int j) const {
    // Check for valid vertex numbers
    if (i < 0 || i >= v || j < 0 || j >= v) {
        // Throwing an exception is acceptable to handle boundary errors
        throw out_of_range("isEdge: Vertex number out of range."); 
    }
    
    // Return the value from the adjacency matrix
    return adjMatrix[i][j]; 
}

// Print a representation of the graph
ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

// Toggle the existence of an edge between the two given vertices
void GraphMatrix::toggleEdge(int i, int j) {
    if (i < 0 || i >= v || j < 0 || j >= v) {
        throw out_of_range("toggleEdge: Vertex number out of range.");
    }
    
    bool exists = adjMatrix[i][j];
    
    // Toggle the edge from i to j
    adjMatrix[i][j] = !exists;
    
    // Adjust the total number of edges (e)
    if (!exists) {
        e++;
    } else {
        e--;
    }
    
    // Handle UNDIRECTED graphs: must also toggle j to i
    if (graphType == UNDIRECTED) {
        if (i != j) {
            // Only assign, do not adjust 'e' again
            adjMatrix[j][i] = adjMatrix[i][j];
        }
    }
}