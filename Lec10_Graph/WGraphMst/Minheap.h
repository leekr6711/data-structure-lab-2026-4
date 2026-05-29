#pragma once
#ifndef MAX_VTXS
#define MAX_VTXS 100
#endif
#include "HeapNode.h"

class MinHeap {
    HeapNode node[MAX_VTXS * MAX_VTXS]; // 간선 수가 많으므로 크기를 충분히 확보
    int size;

public:
    MinHeap() : size(0) {}
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= (MAX_VTXS * MAX_VTXS - 1); }
    HeapNode getParent(int i) { return node[i / 2]; }

    // 삽입 함수 (18페이지)
    void insert(int key, int u, int v) {
        if (isFull()) return;
        int i = ++size;
        while (i != 1 && key < getParent(i).getKey()) {
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key, u, v);
    }

    // 삭제 함수 (Kruskal 연산 동작을 위해 필수 구현)
    HeapNode remove() {
        HeapNode root = node[1];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;

        while (child <= size) {
            if (child < size && node[child].getKey() > node[child + 1].getKey()) {
                child++;
            }
            if (last.getKey() <= node[child].getKey()) break;
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return root;
    }
};