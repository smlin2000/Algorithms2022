#include <search.hpp>

void dfs(Graph &G, int start, int destination) {
    Stack<int> stack;
    G.reset();
    // YOUR CODE HERE
    stack.push(start);
    G.setVisited(start);
    while (!stack.empty()) {
        int u = stack.pop();
        // YOUR CODE HERE
        if (u == destination){
            break;
        }
        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<int> *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value;
            // YOUR CODE HERE
            if (G.isVisited(v)){
                continue;
            }
            stack.push(v);
            G.setVisited(v);
            G.setTrace(u, v);
        }
    }
}
