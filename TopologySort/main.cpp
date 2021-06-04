#include <iostream>
#include <fstream>
#include <cassert>
#include "Stack.h"
#include "Queue.h"
#include "DALGraph.h"

int main() {
    const char* fileName = "graph.txt";
    std::ifstream ifs(fileName);
    assert(ifs);
    int n;
    ifs >> n;
    DALGraph G(n);
    std::cout << "Created graph: n = " << G.vertexSize() << "\n";

    int u, v;
    while (ifs >> u) {
        ifs >> v;
        G.addEdge(u, v); // u -> v
    }
    std::cout << "Edges in graph: m = " << G.edgeSize() << "\n";

    int *vertices = new int[n]; // vertices[a] number of `in edge` in vertex-a
    assert(vertices);
    // vertices 초기화
    for(int i = 0; i < n; i++) {
        vertices[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        NeighborIter neighbor(G, i); // i번 node
        int temp; // i번 node 가 temp 로 간다.
        while((temp = ++neighbor) != n) { // 맨 끝까지 반복
            vertices[temp] += 1; // temp 번 node 에 i번 노드가 들어오기 때문에 temp 번 node 의 `in-edge` 개수를 1 증가
        }
    }

    Stack<int> stack;
    for(int i = 0; i < n; i++) {
        if(vertices[i] == 0) {
            stack.push(i);
        }
        if(stack.isEmpty()) {
            return 0;
        }
    }

    int count = 0;
    Queue<int> sortedEdges;
    while (!stack.isEmpty()) {
        count += 1;
        int u_ = stack.pop();
        sortedEdges.enqueue(u_);
        NeighborIter neighbor(G, u_);
        int v_;
        while ((v_ = ++neighbor) != n) {
            vertices[v_] -= 1;
            if(vertices[v_] == 0) {
                stack.push(v_);
            }
        }
    }

    if(count < n) {
        std::cout << "Couldn't complete top sort -- cycle present. \n";
    }
    std::cout << "Ordering for top sort: \n";
    while (!sortedEdges.isEmpty()) {
        std::cout << sortedEdges.dequeue() << " ";
    }

    std::cout << std::endl;
}
