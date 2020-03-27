/*
문제
A 채널과 B 채널이 있는 2채널 무전기가 있다. 지원되는 주파수 범위는 144.000 MHz 이상, 146.000 MHz 이하이다. 0.001 MHz보다 작은 단위로는 주파수를 조절할 수 없다. 각 채널의 주파수를 설정할 수 있는데, 전파 수신은 현재 설정된 채널 하나에서만 가능하다.

예를 들어 A 채널이 145.000 MHz, B 채널이 145.500 MHz로 설정되어 있고 현재 채널이 A 채널이라면, 145.000 MHz가 수신된다. 이 상태에서 채널을 B로 전환하면, 145.500 MHz가 수신된다. 주파수 변경은 현재 설정된 채널에서만 가능하다. 현재 설정되지 않은 채널의 주파수를 변경하고 싶다면, 채널을 먼저 전환하고 나서, 주파수를 변경해야 한다.

사용 가능한 버튼에는 세 가지 부류가 있다.

A/B 버튼을 누르면, 현재 채널이 A에서 B로, 또는 B에서 A로 전환된다.

0에서 9까지의 숫자 키패드를 이용하여 현재 채널의 주파수를 직접 입력할 수 있다. 원하는 주파수의 숫자 전체 6자리를 순서대로 입력하면 된다. 반드시 6자리 전부 한 번에 입력해야 한다. 예를 들어 144.678 MHz를 입력하려면 1 4 4 6 7 8을 순서대로 누른다.

UP 버튼과 DOWN 버튼을 이용하여 현재 채널의 주파수를 0.02 MHz 간격으로 조절할 수 있다. 조절 간격은 0.02 MHz로 고정되어 있다. 예를 들어, 145.005 MHz에서 UP을 한 번 누르면 145.025 MHz가 된다.

만약 UP 버튼이나 DOWN 버튼을 눌렀을 때 지원 주파수 범위를 벗어나게 되면, 반대쪽 끝 경계로 강제 설정된다.

146.000 MHz에서 UP 버튼을 한 번 누르면 144.000 MHz로 설정된다.
145.999 MHz에서 UP 버튼을 한 번 누르면 144.000 MHz로 설정된다.
144.000 MHz에서 DOWN 버튼을 한 번 누르면 146.000 MHz로 설정된다.
144.010 MHz에서 DOWN 버튼을 한 번 누르면 146.000 MHz로 설정된다.
주파수 조절은 세 가지 전략 중에서 하나를 선택하여 이루어진다.

A/B 버튼과 숫자 키패드만 사용하는 전략
A/B 버튼과 UP 버튼만 사용하는 전략
A/B 버튼과 DOWN 버튼만 사용하는 전략
주파수 변경 과정에서, 버튼 조작 방법은 유일하지 않다. 예를 들어서 현재 채널의 주파수를 145.000 MHz에서 145.040 MHz로 전환하고 싶다면,

전략 1에 따라서, 숫자 버튼을 이용하기. 1 4 5 0 4 0을 순서대로 누른다.
전략 2에 따라서, UP 버튼을 이용하기. UP 버튼을 두 번 누른다.
이외에도 무수히 많은 방법이 있다. 주파수를 원하는 만큼 계속 바꾸다가, 마지막에 145.040 MHz에서 멈추면 된다.
버튼을 누른 횟수를 비교해 보면, 전략 1에서 6회, 전략 2에서 2회이다. 여기에서는 전략 2가 더 효율적이다.

입력으로 채널 A에 설정된 주파수, 채널 B에 설정된 주파수, 현재 설정된 채널, 목표 주파수가 주어진다. 목표 주파수가 수신되도록 하는 최소한의 버튼 누름 횟수를 계산하는 프로그램을 작성한다. 목표 주파수 수신에 사용되는 채널은 A 채널과 B 채널 중 어떤 채널이라도 상관없다.

입력
첫 번째 줄에 테스트 케이스의 개수가 입력된다. 테스트 케이스의 개수는 최대 5,000개이다. 두 번째 줄부터는 테스트 케이스가 한 줄에 하나씩 입력된다. 각 테스트 케이스의 세부 형식은 아래와 같다.

채널 A에 설정된 주파수, 채널 B에 설정된 주파수, 현재 채널, 목표 주파수가 공백으로 구분되어 입력된다. 현재 채널은 알파벳 대문자, A 또는 B로 입력된다. 입력되는 모든 주파수 값은 144 MHz 이상, 146 MHz 이하이고 항상 소수점 셋째 자리까지로 표현된다. 주파수의 단위는 생략된다.

출력
테스트 케이스마다, 목표 주파수가 수신되도록 하는 최소한의 버튼 누름 횟수를 한 줄에 하나씩 출력한다. 입력받은 상황에서 처음부터 이미 현재 채널에 목표 주파수가 설정되어 있는 경우에는 최소한의 버튼 누름 횟수가 0이다.

풀이:
...
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

int T;
int tg;
int ans;

int main(void) {
	FIO;

	cin >> T;

	while (T--) {
		double CA, CB, target;
		char nowC;
		int up_cnt, down_cnt, now;

		cin >> CA >> CB >> nowC >> target;

		int ca = (int)(CA * 1000);
		int cb = (int)(CB * 1000);
		tg = (int)(target * 1000);
		
		if (nowC == 'A') {
			if (ca == tg)
				cout << "0" << "\n";
			else if(cb == tg)
				cout << "1" << "\n";
			else {
				
				now = ca;
				for (up_cnt = 1; up_cnt <= 5; up_cnt++)
				{
					now += 20;
					if (now > 146000)
						now = 144000;
					if (now == tg) {
						break;
					}
				}
				
					now = ca;
					for (down_cnt = 1; down_cnt <= 5; down_cnt++)
					{
						now -= 20;
						if (now < 144000)
							now = 146000;
						if (now == tg) {
							break;
						}
					}
					ans = min(up_cnt, down_cnt);

					now = cb;
					for (up_cnt = 1; up_cnt <= 5; up_cnt++)
					{
						now += 20;
						if (now > 146000)
							now = 144000;
						if (now == tg) {
							break;
						}
					}

					now = cb;
					for (down_cnt = 1; down_cnt <= 5; down_cnt++)
					{
						now -= 20;
						if (now < 144000)
							now = 146000;
						if (now == tg) {
							break;
						}
					}

					ans = min(ans, min(up_cnt + 1, down_cnt + 1));

					cout << ans << "\n";
			}
		}
		else {
			if (cb == tg)
				cout << "0" << "\n";
			else if (ca == tg)
				cout << "1" << "\n";
			else {
				now = cb;
				for (up_cnt = 1; up_cnt <= 5; up_cnt++)
				{
					now += 20;
					if (now > 146000)
						now = 144000;
					if (now == tg) {
						break;
					}
				}
					now = cb;
					for (down_cnt = 1; down_cnt <= 5; down_cnt++)
					{
						now -= 20;
						if (now < 144000)
							now = 146000;
						if (now == tg) {
							break;
						}
					}
					ans = min(up_cnt, down_cnt);

					now = ca;
					for (up_cnt = 1; up_cnt <= 5; up_cnt++)
					{
						now += 20;
						if (now > 146000)
							now = 144000;
						if (now == tg) {
							break;
						}
					}

					now = ca;
					for (down_cnt = 1; down_cnt <= 5; down_cnt++)
					{
						now -= 20;
						if (now < 144000)
							now = 146000;
						if (now == tg) {
							break;
						}
					}

					ans = min(ans, min(up_cnt + 1, down_cnt + 1));

					cout << ans << "\n";
			}
		}
	}
}