#include "MyGraph.h"
#include <iostream>
#include <vector>

using  namespace std;

MyGraph::MyGraph(vector<vector<int>>& matriz) {
    loadGraph(matriz);
}


void MyGraph::loadGraph(vector<vector<int>>& matriz) {
    this->matriz = matriz;
}


void MyGraph::DFS() {
    int n = matriz.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void MyGraph::BFS() {
    int n = matriz.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFSUtil(i, visited);
        }
    }
}