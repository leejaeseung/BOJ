/*문제
송도에 사는 상근이와 친구들은 송도에서 열리는 펜타포트 락 페스티벌에 가려고 한다. 올해는 맥주를 마시면서 걸어가기로 했다. 출발은 상근이네 집에서 하고, 맥주 한 박스를 들고 출발한다. 맥주 한 박스에는 맥주가 20개 들어있다. 목이 마르면 안되기 때문에 50미터에 한 병씩 마시려고 한다.

상근이의 집에서 페스티벌이 열리는 곳은 매우 먼 거리이다. 따라서, 맥주를 더 구매해야 할 수도 있다. 미리 인터넷으로 조사를 해보니 다행히도 맥주를 파는 편의점이 있다. 편의점에 들렸을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다. 하지만, 박스에 들어있는 맥주는 20병을 넘을 수 없다.

편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표가 주어진다. 상근이와 친구들이 행복하게 페스티벌에 도착할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (t ≤ 50)

각 테스트 케이스의 첫째 줄에는 맥주를 파는 편의점의 개수 n이 주어진다. (0 ≤ n ≤ 100).

다음 n+2개 줄에는 상근이네 집, 편의점, 펜타포트 락 페스티벌 좌표가 주어진다. 각 좌표는 두 정수 x와 y로 이루어져 있다. (두 값 모두 미터, -32768 ≤ x, y ≤ 32767)

송도는 직사각형 모양으로 생긴 도시이다. 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다. (맨해튼 거리)

출력
각 테스트 케이스에 대해서 상근이와 친구들이 행복하게 페스티벌에 갈 수 있으면 "happy", 중간에 맥주가 바닥나면 "sad"를 출력한다. 

풀이 : 거리가 1000이하인 점들만 큐에 넣어 BFS
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;

typedef struct point {
	int x;
	int y;
	bool visit;
}PT;

int N;


bool CanGo(int x1,int y1,int x2,int y2) {
	if (abs(x1 - x2) + abs(y1 - y2) <= 1000)
		return true;
	else
		return false;
}

bool BFS(PT start,PT Dst, vector<PT> vt) {
	queue<PT> q;
	q.push(start);

	while (!q.empty()) {
		PT temp = q.front();
		q.pop();
		if (CanGo(Dst.x, Dst.y, temp.x, temp.y))
			return true;

		for (int i = 0; i < N; i++)
		{
			
			if (!vt.at(i).visit && CanGo( temp.x , temp.y , vt.at(i).x , vt.at(i).y )) {
				vt.at(i).visit = true;
				q.push(vt.at(i));
			}
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> N;

		vector<PT> vt;
		cin >> x >> y;
		PT start = { x , y , true};
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			PT CV = { x , y , false};
			vt.push_back(CV);
		}
		cin >> x >> y;
		PT Dst = { x , y , false};

		if (BFS(start, Dst, vt))
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
}