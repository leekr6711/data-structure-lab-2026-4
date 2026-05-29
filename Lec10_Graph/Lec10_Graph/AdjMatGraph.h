#pragma once
#include <cstdio>
#define MAX_VTXS 10
#define INF 9999
class AdjMatGraph {
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }

	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else printf("Error: 그래프 정점 개수 초과\n");
	}
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}
	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);
		for (int i = 0; i < size; i++) {
			fprintf(fp, "%c ", getVertex(i));
			for (int j=0; j < size; j++)
				fprintf(fp, "%3d", getEdge(i, j));
			fprintf(fp, "\n");
		}
	}
};

//탐색 기능이 추가된 인접 행렬 기반 그래프 클래스
class SrchAMGraph : public AdjMatGraph
{
	bool visited[MAX_VTXS];
public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}
	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v) {
		visited[v] = true;
		printf("%c ", getVertex(v));

		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false)
				DFS(w);
		}
	}
};


//가중치 그래프를 표현하는 클래스
class WGraph : public AdjMatGraph {
public:
	void insertEdge(int u, int v, int weight) {
		if (weight > INF) weight = INF;
		setEdge(u, v, weight);
	}
	bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }

	void load(char* filename) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n, val;
			fscanf_s(fp, "%d", &n);
			for (int i = 0; i < n; i++) {
				char str[80];
				int val;
				fscanf(fp, "%s", str);
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					fscanf_s(fp, "%d", &val);
					insertEdge(i, j, val);
				}
			}
			fclose(fp);
		}
	}
};

// MST 기능이 추가된 가중치 그래프 (19페이지 코드)
class WGraphMST : public WGraph {
public:
	void Kruskal() { // kruskal의 최소 비용 신장 트리 프로그램 
		MinHeap heap; [cite:37]
			for (int i = 0; i < size - 1; i++)[cite:38]
				for (int j = i + 1; j < size; j++)[cite:38]
					if (hasEdge(i, j)) heap.insert(getEdge(i, j), i, j); // 모든 간선 삽입 [cite: 38, 39]

		VertexSets set(size); // size개의 집합을 만듦 [cite: 39]
		int edgeAccepted = 0;   // 선택된 간선의 수 [cite: 39, 40]

		while (edgeAccepted < size - 1) { // 간선의 수 < (size-1) [cite: 40]
			HeapNode e = heap.remove(); // 레퍼런스(&) 제거하여 안정적으로 노드 복사 [cite: 40]
			int uset = set.findSet(e.getV1()); [cite:40]
				int vset = set.findSet(e.getV2()); [cite:41]

				if (uset != vset) {
					printf("간선 추가 : %c - %c (비용:%d)\n",
						getVertex(e.getV1()), getVertex(e.getV2()), e.getKey()); [cite:41]
						set.unionSets(uset, vset); // 두개의 집합을 합함. [cite: 41, 42]
					edgeAccepted++;
				}
		}
	}
};