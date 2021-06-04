//
// Created by 82109 on 2021-06-01.
//

#ifndef TOPOLOGYSORT_UALGRAPH_H
#define TOPOLOGYSORT_UALGRAPH_H
#include "ALGraph.h"
#include <cassert>


class UALGraph: public ALGraph {
public:
    UALGraph(int size): ALGraph(size) {}
    virtual void addEdge(int fromV, int toV);
};

void UALGraph::addEdge(int fromV, int toV) {
    assert(fromV < n && fromV >= 0 && toV < n && toV >= 0);
    vertexList[fromV].insert(toV);
    vertexList[toV].insert(fromV);
    m = m + 1;
}


#endif //TOPOLOGYSORT_UALGRAPH_H
