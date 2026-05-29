#pragma once
#include <iostream>
#include <cstdio>
#include "MinHeap.h"
#include "VertexSets.h"

#define MAX_VTXS 100
#define INF 9999 // 가중치 무한대 (연결 없음)

// 기반 인접 행렬 그래프 클래스
class AdjMatGraph {
protected:
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];
public:
    AdjMatGraph();
    void insertVertex(char name);
    void setEdge(int i, int j, int val);
    int getEdge(int i, int j);
    char getVertex(int i);
};

// 가중치 그래프 클래스 (PPT 5~6페이지 기반)
class WGraph : public AdjMatGraph {
public:
    void insertEdge(int u, int v, int weight);
    bool hasEdge(int i, int j);
    void load(const char* filename);
};

// 최소 비용 신장 트리 가중치 그래프 클래스 (19페이지)
class WGraphMST : public WGraph {
public:
    void Kruskal();
};