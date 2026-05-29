#include "AdjMatGraph.h"

/// <summary>

void main()
{
	SrchAMGraph g;
	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i);
	g.insertEdge(0, 1);
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);
	g.insertEdge(4, 5);
	g.insertEdge(3, 4);
	g.insertEdge(5, 6);
	printf("인접행렬로 표현한 그래프\n");
	g.display();

	FILE* fp;
	fopen_s(&fp, "C:/Users/USER/Desktop/data-structure-2026/new.txt","w");
	g.display(fp);
	fclose(fp);

	printf("DFS ==>");
	g.resetVisited();
	g.DFS(0);
	printf("\n");

}
/// </summary>

void main() {

	WGraphMST g;

	g.load("graph.txt");

	printf("MST By Kruskal Algorithm\n\n");

	g.Kruskal();

	return 0;
}

