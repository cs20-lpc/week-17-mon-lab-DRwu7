[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/MRVkdpK7)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=22010414&assignment_repo_type=AssignmentRepo)
# Week 17 Mon Lab

## Directions

You are going to implement the graph data structure as discussed in lecture using the adjacency matrix strategy. This implementation relies on the `Graph` ADT. For the `GraphMatrix` class, there are 4 methods that you need to implement to complete the data structure. A driver program is already provided. Use this to test your data structure implementation.
### Upload to canvas the adj matrix for the graphs below. ###
![alt text](SampleGraph.jpg)
![alt text](DirectedGraph.jpg)

## Notes

- This implementation uses a 2D `bool` array called `adjMatrix` to represent edges
    + `false` means no edge, `true` means there is an edge
- In the constructor, parameter 1 is the number of vertices and parameter 2 is the type of graph this is supposed to be
    + Pass the parameters up to the `Graph` constructor, using 0 for the number of edges
    + Allocate memory for `adjMatrix`, remembering this is a dynamic array of dynamic values
    + Ensure all entries in the matrix are initialized to `false`
- In the destructor, release the memory for `adjMatrix`
- The parameters for `isEdge` and `toggleEdge` are vertex numbers and need to be checked for validity



