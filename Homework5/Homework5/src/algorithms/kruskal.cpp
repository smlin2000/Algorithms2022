#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>


std::vector<Edge> constructMSTKruskal(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges
    // DisjointSet djs(G.n); 
    // Use Disjoint Set to check wheter two vertices are on the same set
    // Usage: Check djs.isOnSameSet(u, v); Check is u and v is on the same set or not
    //              djs.join(u, v); Join sets of u and v into the same set
    
    // YOUR CODE HERE 

    DisjointSet T(G.n); // Initialize the minimum spanning T
    std::vector<Edge> MST;

    int size_of_edges = edges.size(); // the number of edges 
    sort(edges, 0, size_of_edges - 1); // We sort the list of edges w.r.t edge's weight

    for (auto e: edges) {
        int u = e.u;
        int v = e.v;
        int w = e.w;
        if (T.isOnSameSet(u, v) == false) { // If u and v is not connected or not on the same set. You have to fill in either true or false
            T.join(u, v); // We merge u and v together into T. You have to fill in here
            MST.push_back(Edge(u, v, w)); // We add edge (u, v, w) into MST. You have to fill in here.
        }
    }
    return MST;
}

