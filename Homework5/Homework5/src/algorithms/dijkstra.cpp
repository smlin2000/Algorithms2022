#include <graph.hpp>
#include <queue>

struct EdgeKeyComparison {
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination) {

    std::vector<bool> visited(G.n, false);  // Initialize all vertices as a unvisited vertex

    std::vector<int> distance(G.n, INT_MAX); // Initialize the distances of all vertex into maximum value
    std::vector<int> parent(G.n, -1); // Initialize the parent of each vertex by -1

    distance[start] = 0; // Inititlize distance of start. You have to fill in here based on the pseudo code
    parent[start] = -1; // Initialize parent of start. You have to fill in here based on the pseudo code


    for (int i = 1; i <= G.n - 1; ++i) { // We loop over n-1 times as there will be not path has the number of edges > n-1
        int u, minDistance = INT_MAX;
        for (int i = 0; i < G.n; ++i)
            if (distance[i] < minDistance && visited[i] == false) // We are searching for a vertex not visited yet has the minimum distance
                minDistance = distance[i], u = i;
        visited[u] = true; // Set u as a visited vertex. You have to fill in here.

        // Now we have to update distance start from u
        // As only neighbor vertex of u is affected, we only a neighbor of u which is not vitisted yet 
        for (auto e: G.e[u]) {
            int v = e.v;
            int w = e.w;
            if (visited[v] == false && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w; // You have to fill in here based on the pseudo code 
                parent[v] = u; // You have to fill in there based on the pseudo code
            }
        }
    }

    std::vector<int> path;
    int u = destination; // We trace back from the destination. You have to fill in there based on the pseudo code 
    while (u != -1) {
        path.push_back(u);
        u = parent[u]; // Based on parent[u], we move back one step. You have to fill in here based on the pseudo code
    }
    // After the while loop, we will have a path from destination -- to --> start, we need to reverse an array to get the correct result
    std::reverse(path.begin(), path.end());
    return path;
}
