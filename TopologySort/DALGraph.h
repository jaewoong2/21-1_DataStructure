//
// Created by 82109 on 2021-06-01.
//

#ifndef TOPOLOGYSORT_DALGRAPH_H
#define TOPOLOGYSORT_DALGRAPH_H

#include "ALGraph.h"
#include <cassert>


class DALGraph: public ALGraph {
public:
    DALGraph(int size): ALGraph(size) {}
    virtual void addEdge(int fromV, int toV);
};

void DALGraph::addEdge(int fromV, int toV) {
    assert(fromV < n && fromV >= 0 && toV < n && toV >= 0);
    vertexList[fromV].insert(toV);
    m = m + 1;
}

#endif //TOPOLOGYSORT_DALGRAPH_H
