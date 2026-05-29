#include "WGraphMST.h"

int main() {
    WGraphMST g;
    g.load("graph.txt"); // 불러올 파일 이름 명시

    printf("MST By Kruskal's Algorithm\n");
    g.Kruskal();

    return 0;
}