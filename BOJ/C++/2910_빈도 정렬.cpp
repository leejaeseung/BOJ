/*
문제
위대한 해커 창영이는 모든 암호를 깨는 방법을 발견했다. 그 방법은 빈도를 조사하는 것이다.

창영이는 말할 수 없는 방법을 이용해서 현우가 강산이에게 보내는 메시지를 획득했다. 이 메시지는 숫자 N개로 이루어진 수열이고, 숫자는 모두 C보다 작거나 같다. 창영이는 이 숫자를 자주 등장하는 빈도순대로 정렬하려고 한다.

만약, 수열의 두 수 X와 Y가 있을 때, X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 한다. 만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 한다.

이렇게 정렬하는 방법을 빈도 정렬이라고 한다.

수열이 주어졌을 때, 빈도 정렬을 하는 프로그램을 작성하시오.

입력
첫쨰 줄에 메시지의 길이 N과 C가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ C ≤ 1,000,000,000)

둘째 줄에 메시지 수열이 주어진다.

출력
첫째 줄에 입력으로 주어진 수열을 빈도 정렬한 다음 출력한다.

풀이:
맵에 빈도 수와 그 수의 인덱스를 pair로 넣어 빈도수는 큰 순, 인덱스는 작은 순으로 정렬하여 출력합니다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

string arr[1001];
map<string, pair<int, int> > m;
priority_queue<pair<pair<int, int >, string > > pq;

int main(void) {
	FIO;

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N ; i++)
	{
		string str;
		cin >> str;
		arr[i] = str;

		if (m.find(str) == m.end())
			m.insert(make_pair(str, make_pair(1, i)));
		else
			m[str].first++;
	}
	for (int i = 0; i < N; i++)
	{
		if (m[arr[i]].first != 0) {
			pq.push(make_pair(make_pair(m[arr[i]].first, -m[arr[i]].second), arr[i]));

			m[arr[i]].first = 0;
		}
	}
	while (!pq.empty()) {
		string nowstr = pq.top().second;
		int cnt = pq.top().first.first;
		pq.pop();
		while (cnt--)
			cout << nowstr << " ";
	}
}