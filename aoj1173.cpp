#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
const int INF = 1<<28;

string input;

int find(int a, int p) {
	int btn[2] = {};
	FOR(i, p, input.size()) {
		if(a) {
			if(input[i] == '[')
				btn[0]++;
			if(input[i] == ']')
				btn[0]--;
				if(btn[0] < 0) return 1;
			if(input[i] == '(')
				btn[1]++;
			if(input[i] == ')') {
				btn[1]--;
				if(!btn[0] && !btn[1])
					return 0;
			}
		}
		else {
			if(input[i] == '(')
				btn[0]++;
			if(input[i] == ')')
				btn[0]--;
				if(btn[0] < 0) return 1;
			if(input[i] == '[')
				btn[1]++;
			if(input[i] == ']') {
				btn[1]--;
				if(!btn[0] && !btn[1])
					return 0;
			}
		}
	}
	return 1;
}


int main() {
	while(getline(cin, input)) {
		if(input == ".") break;
		int cnt = 0;
		int chk[2] = {};
		REP(i, input.size()) {
			if(input[i] == '(') {
				cnt += find(1, i);
				chk[1]++;
			}
			if(input[i] == '[') {
				cnt += find(0, i);
				chk[0]++;
			}
			if(input[i] == ')') {
				chk[1]--;
				if(chk[1] < 0) cnt++;
			}
			if(input[i] == ']') {
				chk[0]--;
				if(chk[0] < 0) cnt++;
			}
		}
		if(chk[0] || chk[1]) cnt++;
		cout << (cnt ? "no" : "yes") << endl;
	}
	return 0;
}
