#include <iostream>
#include <vector>
#include <linked_list.hpp> 
#include <graph.hpp> 
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sort.hpp>
#include <cmath>

#ifdef OPENCV
#include <opencv2/opencv.hpp>
#endif

bool testSort() {
    std::cout << "You are using " << sortAlgName << " algorithm" << std::endl;
    std::vector<int> array;
    int n = 100000;
    for (int i = 0; i < n; ++i)
        array.push_back(rand() % n); 
    sort(array, 0, n-1);

    for (int i = 1; i < n; ++i)
        if (array[i] < array[i-1])
            return false;
    return true;
}

bool testGraph() {
    Graph G(6);
    G.insertEdge(0, 1, 1);
    G.insertEdge(1, 2, 2);
    G.insertEdge(1, 3, 3);
    G.insertEdge(2, 4, 4);
    G.insertEdge(4, 3, 5);
    G.insertEdge(4, 5, 6);
    
    std::vector<Edge> tree = mst(G);
    std::cout << "Minimum Spanning Tree: " << std::endl;
    int totalCost = 0;
    for (int i = 0; i < tree.size(); ++i) {
        std::cout << "Edge: " << tree[i].u << " " << tree[i].v << ". Cost: " << tree[i].w << std::endl;
        totalCost += tree[i].w;
    }
    std::cout << "Total Cost: " << totalCost << std::endl;

    return true;
}

void mstOnCampus() {
    std::ifstream reader("assets/map_info.txt");
    int n, m;
    reader >> n >> m;
    std::map<std::string, int> name2index;
    std::map<int, std::string> index2name;
    std::vector<int> xs;
    std::vector<int> ys;
    for (int i = 0; i < n; ++i) {
        int index, x, y;
        std::string name;
        reader >> index >> name >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        name2index[name] = index;
        index2name[index] = name;
    }

    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        reader >> u >> v;
        int dx = xs[u] - xs[v];
        int dy = ys[u] - ys[v];
        int w = (int)sqrt(dx * dx + dy * dy);
        G.insertEdge(u, v, w);
    }
    
    std::vector<Edge> tree = mst(G);

    std::cout << "Minimum Spanning Tree: " << std::endl;
    int totalCost = 0;
    for (int i = 0; i < tree.size(); ++i) {
        std::cout << "Edge: " << tree[i].u << " " << tree[i].v << ". Cost: " << tree[i].w << std::endl;
        totalCost += tree[i].w;
    }
    std::cout << "Total Cost: " << totalCost << std::endl;


#ifdef OPENCV
    cv::Mat image = cv::imread("assets/map.png");
    for (int i = 0; i < n; ++i) {
        cv::circle(image, cv::Point(xs[i], ys[i]), 8, cv::Scalar(255, 0, 0), -1);
        cv::putText(image, index2name[i],  cv::Point(xs[i], ys[i]-10),  cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(255, 0, 0), 1);
    }
    for (int i = 0; i < tree.size(); ++i) {
        int u = tree[i].u;
        int v = tree[i].v;
        cv::line(image, cv::Point(xs[u], ys[u]), cv::Point(xs[v], ys[v]), cv::Scalar(255, 0, 0), 4);
    }
    //cv::resize(image, image, cv::Size(), 0.75, 0.75);
    cv::imshow("Minimum Spanning Tree", image);
    cv::waitKey(0);

#else
    std::cout << "You have to use OpenCV to visualize your map\n";
#endif


}
int main(int argc, char **args) {
    
    std::cout << "Perform unit test on the sorting algorithm" << std::endl;
    if (testSort())
        std::cout << "Your sorting implementation is correct\n" << std::endl;
    else {
        std::cout << "Your sorting implementation is incorrect\n" << std::endl;
        return -1;
    }
    
    std::cout << std::endl << "Perform unit test on your implementation with graph" << std::endl;
    testGraph();
    
    std::cout << "\n\n";
    
    mstOnCampus();

    std::cout << "\n";

    
    
}
