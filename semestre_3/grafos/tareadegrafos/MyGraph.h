#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <vector>

using namespace std;

class MyGraph {
private:
    vector<vector<int>> matriz;
    void DFSUtil(int nodo, vector<bool>& visited);
    void BFSUtil(int nodo, vector<bool>& visited);

public:
 
    MyGraph(vector<vector<int>>& matriz);
    void loadGraph(vector<vector<int>>& matriz);
    void DFS(int nodoInicial);
    void BFS(int nodoInicial);
};

#endif