import sys

## 입력 받는 코드입니다. 수정할 필요 없습니다.
sys.stdin = open('case.txt')
N, M = list(map(int,input().split()))
print(N, M)
concerts = []
for v in range(N):
    values = list(map(int, input().split()))
    concerts.append(values)
# print(concerts)
# [[1, 0, 0, 1, 1, 0], [1, 0, 1, 1, 0, 0], [1, 1, 1, 1, 0, 1], [0, 1, 1, 0, 1, 1], [0, 1, 0, 0, 1, 0]]
###################################

def count_stages(concerts):
    """
    행렬 형태로 주어진 콘서트장 내부(concerts)에서 상하좌우로 연결된 
    독립된 무대 공간(0의 묶음 구역)의 총 개수를 계산하여 반환하는 함수입니다.
    너비 우선 탐색(BFS) 알고리즘과 방문 여부 행렬(visited)을 활용합니다.
    """
    from collections import deque

    if not concerts:
        return 0

    rows = len(concerts)
    cols = len(concerts[0])
    visited = [[False] * cols for _ in range(rows)]
    answer = 0

    # 상, 하, 좌, 우 이동을 위한 방향 배열
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    for r in range(rows):
        for c in range(cols):
            # 아직 방문하지 않은 공간이며, 빈 무대 공간(0)인 경우 새로운 구역 발견
            if concerts[r][c] == 0 and not visited[r][c]:
                answer += 1  # 무대 공간 개수 증가
                
                # 큐(Queue)를 이용하여 해당 구역 전체를 BFS 탐색 및 방문 처리
                queue = deque([(r, c)])
                visited[r][c] = True

                while queue:
                    curr_r, curr_c = queue.popleft()

                    # 인접한 상하좌우 네 방향 탐색
                    for i in range(4):
                        nr = curr_r + dr[i]
                        nc = curr_c + dc[i]

                        # 콘서트장 격자 범위 내에 있고, 아직 방문하지 않았으며, 동일하게 0인 공간인 경우
                        if 0 <= nr < rows and 0 <= nc < cols:
                            if concerts[nr][nc] == 0 and not visited[nr][nc]:
                                visited[nr][nc] = True
                                queue.append((nr, nc))
                                
    return answer

print(count_stages(concerts))
