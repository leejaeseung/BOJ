/*
문제
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.

둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.

0: 빈 칸
1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
9: 아기 상어의 위치
아기 상어는 공간에 한 마리 있다.

출력
첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.

풀이:
문제의 조건에 맞게 매 아기 상어에 위치에 따라 bfs로 먹을 상어를 정한다.
아기 상어를 먹을 상어의 위치로 옮기고, 이동한 수만큼 초를 카운트한다.
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vii vector<pii>
#define IMAX 2000000001
#define LMAX 1000000000000000000
#define DMAX 0xFFFFFFFFFFFFF
#define MOD 100003
int mv1[4] = { 0, 1, 0, -1 };
int mv2[4] = { 1, 0, -1, 0 };
int mv_all1[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int mv_all2[8] = { 1, 0, -1, 0 , -1, 1, -1, 1 };

int n;
int maps[21][21];

pair<pii, int> bfs(pii now, int sz) {
	bool visit[21][21];
	fill(&visit[0][0], &visit[20][21], false);

	int minDis = IMAX;
	queue<pair<pii, int>> q;
	q.push({ { now.first, now.second }, 0 });
	visit[now.first][now.second] = true;

	priority_queue<pair<pii, int>> eat;

	while (!q.empty()) {
		pii now = q.front().first;
		int nowCnt = q.front().second;
		q.pop();

		if (maps[now.first][now.second] < sz && maps[now.first][now.second] != 0) {
			if (minDis > nowCnt) {
				minDis = nowCnt;
				priority_queue<pair<pii, int>> temp;
				eat.swap(temp);

				eat.push({ { -now.first, -now.second }, nowCnt});
			}
			else if (minDis == nowCnt) {
				eat.push({ { -now.first, -now.second }, nowCnt });
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + mv1[i];
			int ny = now.second + mv2[i];

			if (nx >= n || ny >= n || nx < 0 || ny < 0 || maps[nx][ny] > sz)	continue;

			if (!visit[nx][ny]) {
				visit[nx][ny] = true;

				q.push({ {nx, ny}, nowCnt + 1 });
			}
		}
	}
	
	if (eat.empty())
		return { { -1, -1 }, -1};
	else
		return eat.top();
}

int main(void) {
	FIO;

	cin >> n;

	pii baby;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 9)
				baby = { i, j };
		}
	}

	int ans = 0;
	int nowSize = 2;
	int eatCnt = 0;

	while (true) {
		pair<pii, int> next = bfs(baby, nowSize);

		if (next.second == -1)
			break;
		
		ans += next.second;
		maps[baby.first][baby.second] = 0;
		baby = { -next.first.first, -next.first.second };
		maps[baby.first][baby.second] = 0;

		eatCnt++;
		if (eatCnt == nowSize) {
			eatCnt = 0;
			nowSize++;
		}
	}

	cout << ans;
}