//
// Created by 82109 on 2021-06-01.
//

#ifndef TOPOLOGYSORT_ALGRAPH_H
#define TOPOLOGYSORT_ALGRAPH_H

#include "Graph.h"
#include "List.h"


class ALGraph: public Graph {
public:
    ALGraph(int size): Graph(size) { vertexList = new List<int>[n]; assert(vertexList); };
    friend class NeighborIter;

protected:
    List<int> *vertexList;
};

class NeighborIter: public ListIter<int> {
public:
    NeighborIter(const ALGraph &G, int startVertex): ListIter<int>(G.vertexList[startVertex], G.n)
            { assert(startVertex < G.n); }
};



#endif //TOPOLOGYSORT_ALGRAPH_H
