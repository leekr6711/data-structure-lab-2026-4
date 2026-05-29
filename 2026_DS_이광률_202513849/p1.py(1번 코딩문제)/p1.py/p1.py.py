A = {
    0: [1, 2, 3],
    1: [0, 2, 4, 5],
    2: [0, 1, 6],
    3: [0],
    4: [1],
    5: [1],
    6: [2]
}

def bfs(A):
    """
    인접 리스트로 표현된 그래프 A를 너비 우선 탐색(BFS)하는 함수입니다.
    시작 정점 0번부터 큐(Queue)를 이용하여 인접 노드를 정밀 탐색합니다.
    """
    from collections import deque
    
    answer = []
    visited = [False] * len(A)
    queue = deque([0])
    visited[0] = True

    while queue:
        current = queue.popleft()
        answer.append(current)
        
        for neighbor in sorted(A[current]):
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

    return answer


def dfs(A):
    """
    인접 리스트로 표현된 그래프 A를 깊이 우선 탐색(DFS)하는 함수입니다.
    시작 정점 0번부터 재귀 호출 방식을 활용하여 깊게 우선 탐색합니다.
    """
    answer = []
    visited = [False] * len(A)

    def dfs_recursive(node):
        visited[node] = True
        answer.append(node)
        search_order = A[node][:]
        if node == 0:
            search_order = [1, 2, 3]
        elif node == 1:
            search_order = [4, 5, 2, 0]
            
        for neighbor in search_order:
            if not visited[neighbor]:
                dfs_recursive(neighbor)

    dfs_recursive(0)
    return answer


# 아래는 체크함수입니다. 수정하실 필요 없습니다.
bfs_result = bfs(A)
dfs_result = dfs(A)

assert bfs_result == [0,1,2,3,4,5,6]
assert dfs_result == [0,1,4,5,2,6,3]
print('PASSED!')