#define _CRT_SECURE_NO_WARNINGS
#include "WGraphMST.h"

// AdjMatGraph 구현부
AdjMatGraph::AdjMatGraph() : size(0) {
    for (int i = 0; i < MAX_VTXS; i++) {
        for (int j = 0; j < MAX_VTXS; j++) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }
}
void AdjMatGraph::insertVertex(char name) {
    if (size < MAX_VTXS) vertices[size++] = name;
}
void AdjMatGraph::setEdge(int i, int j, int val) {
    adj[i][j] = adj[j][i] = val;
}
int AdjMatGraph::getEdge(int i, int j) { return adj[i][j]; }
char AdjMatGraph::getVertex(int i) { return vertices[i]; }

// WGraph 구현부
void WGraph::insertEdge(int u, int v, int weight) {
    if (weight > INF) weight = INF;
    setEdge(u, v, weight);
}
bool WGraph::hasEdge(int i, int j) { return (getEdge(i, j) < INF); }

// PPT 6페이지 원본 대조 반영 load 함수
void WGraph::load(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp != NULL) {
        int n, val;
        if (fscanf(fp, "%d", &n) == 1) {
            for (int i = 0; i < n; i++) {
                char str[80];
                if (fscanf(fp, "%s", str) == 1) {
                    insertVertex(str[0]);
                    for (int j = 0; j < n; j++) {
                        if (fscanf(fp, "%d", &val) == 1) {
                            if (i <= j) {
                                insertEdge(i, j, val);
                            }
                        }
                    }
                }
            }
        }
        fclose(fp);
    }
}

// WGraphMST 구현부 (19페이지)
void WGraphMST::Kruskal() {
    MinHeap heap;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (hasEdge(i, j)) heap.insert(getEdge(i, j), i, j);
        }
    }

    VertexSets set(size);
    int edgeAccepted = 0;

    while (edgeAccepted < size - 1) {
        if (heap.isEmpty()) break;
        HeapNode e = heap.remove();
        int uset = set.findSet(e.getV1());
        int vset = set.findSet(e.getV2());

        if (uset != vset) {
            printf("간선 추가 : %c - %c (비용:%d)\n",
                getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
            set.unionSets(uset, vset);
            edgeAccepted++;
        }
    }
}