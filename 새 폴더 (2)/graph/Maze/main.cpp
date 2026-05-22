#include "location2D.h"
#include <stack>
#include <deque>
using namespace std;

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','0','0','0','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

void main() {
	stack<Location2D> locStack;
	deque<Location2D> locDeque;

	Location2D entry(1, 0);

	int num;
	printf("입력하세요. \n");
	scanf_s("%d", &num);
	if (num == 1) {
		locStack.push(entry);
		while (locStack.empty() == false) {
			Location2D here = locStack.top();
			locStack.pop();

			int r = here.row;
			int c = here.col;
			printf("(%d,%d)", r, c);

			if (map[r][c] == 'x') {
				printf("미로 탐색 성공 \n");
				return;
			}
			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c))locStack.push(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c))locStack.push(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1))locStack.push(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1))locStack.push(Location2D(r, c + 1));

			}
		}
		printf("미로 탐색 실패\n");

	}
	else if (num == 2) {
		locDeque.push_front(entry);

		while (locDeque.empty() == false) {
			Location2D here = locDeque.front();
			locDeque.pop_front();

			int r = here.row;
			int c = here.col;
			printf("(%d,%d)", r, c);

			if (map[r][c] == 'x') {
				printf("미로 탐색 성공 \n");
				return;
			}

			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c))locDeque.push_front(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c)) locDeque.push_front(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1))locDeque.push_front(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1)) locDeque.push_front(Location2D(r, c + 1));
			}
		}
		printf("미로 탐색 실패 \n");
	}
	else if (num == 3) {
		locDeque.push_back(entry);

		while (locDeque.empty() == false) {
			Location2D here = locDeque.front();
			locDeque.pop_front();

			int r = here.row;
			int c = here.col;
			printf("(%d,%d)", r, c);

			if (map[r][c] == 'x') {
				printf("미로 탐색 성공 \n");
				return;
			}

			else {
				map[r][c] = '.';
				if (isValidLoc(r - 1, c))locDeque.push_back(Location2D(r - 1, c));
				if (isValidLoc(r + 1, c)) locDeque.push_back(Location2D(r + 1, c));
				if (isValidLoc(r, c - 1))locDeque.push_back(Location2D(r, c - 1));
				if (isValidLoc(r, c + 1)) locDeque.push_back(Location2D(r, c + 1));
			}
		}
		printf("미로 탐색 실패 \n");
	}

}