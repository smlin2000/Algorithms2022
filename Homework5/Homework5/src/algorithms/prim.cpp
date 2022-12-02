#include <graph.hpp> 
#include <sort.hpp> 
#include <disjoint_set.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};



std::vector<Edge> constructMSTPrim(Graph G) {
    std::vector<Edge> edges = G.exportEdges(); // Graph's edges

    std::vector<Edge> MST; // Initialize an empty list of edges in the MST

    std::vector<bool> T(G.n, false);  // Initialize the current minimum spanning tree T = { 0 }
    T[0] = true; // T[0] = true which mean we append 0 into minimum spanning tree

    std::vector<int> distance(G.n, INT_MAX); // Initialize the distances of all vertex into maximum value
    std::vector<int> parent(G.n, -1); // Initialize the parent of each vertex by -1

    for (auto e: G.e[0]) { // Go to neighbor of 0 and update their distances and parents
        int v = e.v;
        int w = e.w;
        distance[v] = w ; // You have to fill in here based on the pseudo code 
        parent[v] = 0 ; // You have to fill in here based on the pseudo code
    }

    for (int i = 1; i <= G.n - 1; ++i) { // We are going to add n - 1 vertices into the MST
        int u, minDistance = INT_MAX;
        for (int i = 0; i < G.n; ++i)
            if (distance[i] < minDistance && T[i] == false) // We are searching for a vertex not in the current minimum spanning tree and closest to the MST
                minDistance = distance[i], u = i;
        T[u] = u; // We add u into the minimum spanning tree T = T U { u }. You have to fill in here.

        MST.push_back( Edge( u, parent[u], distance[u]) ); // We add (u, parent[u], distance[u]) which is an edge of (u, parent[u], w(u, parent[u])) into MST

        // Now we have to update distance of other vertices to the MST
        // As only neighbor vertex of u is affected, we only a neighbor of u which is not in the MST
        for (auto e: G.e[u]) {
            int v = e.v;
            int w = e.w;
            if (T[v] == false && w < distance[v]) {
                distance[v] = w; // You have to fill in here based on the pseudo code 
                parent[v] = u; // You have to fill in there based on the pseudo code
            }
        }
    }
    return MST;
}

