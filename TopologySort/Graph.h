//
// Created by 82109 on 2021-06-01.
//

#ifndef TOPOLOGYSORT_GRAPH_H
#define TOPOLOGYSORT_GRAPH_H


class Graph {
public:
    Graph(int size): n(size), m(0) {}
    virtual int vertexSize() { return n; }
    virtual int edgeSize() { return m; }
    virtual void addEdge(int fromV, int toV) = 0;
protected:
    int n; // size of vertex
    int m; // size of edge
};


#endif //TOPOLOGYSORT_GRAPH_H
