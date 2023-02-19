#ifndef __AL_GRAPH_DFS_H__
#define __AL_GRAPH_DFS_H__

#include "../Chapter 03, 04, 05/DLinkedList.h"

// 정점의 이름을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
    int numV; // 정점의 수
    int numE; // 간선의 수
    List *adjList; // 간선의 정보
    int *visitInfo; // 방문 표시
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph *pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph *pg);

// 간선의 추가
void AddEdge(ALGraph *pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph *pg);

// 정점의 정보 출력 : Depth First Search 기반
void DFShowGraphVertex(ALGraph *pg, int startV);

#endif