/*
문제
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안 된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.



아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

풀이:
DFS를 활용한 브루트 포스 문제였습니다.

한 점 x,y에서 4칸까지 dfs로 모든 경로를 탐색합니다.
그러면 ㅏ,ㅓ,ㅗ,ㅜ 모양을 제외한 모든 경로를 알 수 있으므로 최대값을 일단 갱신하고,
dfs로 구할 수 없는 ㅏ,ㅗ,ㅓ,ㅜ 모양은 일일히 확인해 주면 됩니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pic pair<int, char>
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 100000000000000
int mv1[4] = { 0, 0, 1, -1 };
int mv2[4] = { 1, -1, 0, 0 };

int n, m;
int maps[503][503];
bool visit[503][503];
int maxV = 0;

void dfs(int x, int y, int cnt, int sum) {
	visit[x][y] = true;
	if (cnt == 4) {
		maxV = max(maxV, sum);
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			int nx = x + mv1[i];
			int ny = y + mv2[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > m)	continue;
			if (!visit[nx][ny]) {
				dfs(nx, ny, cnt + 1, sum + maps[nx][ny]);
			}
		}
	}
	visit[x][y] = false;
}

int getMax(int x, int y) {
	//ㅏ,ㅗ,ㅓ,ㅜ 모양 확인
	int sum1 = maps[x][y] + maps[x + 1][y] + maps[x - 1][y] + maps[x][y + 1];
	int sum2 = maps[x][y] + maps[x + 1][y] + maps[x - 1][y] + maps[x][y - 1];
	int sum3 = maps[x][y] + maps[x + 1][y] + maps[x][y - 1] + maps[x][y + 1];
	int sum4 = maps[x][y] + maps[x - 1][y] + maps[x][y - 1] + maps[x][y + 1];

	return max(max(max(sum1, sum2), sum3), sum4);
}

int main(void) {
	FIO;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dfs(i, j, 1, maps[i][j]);
			maxV = max(maxV, getMax(i, j));
		}
	}
	cout << maxV;
}