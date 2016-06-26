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

bool ms[300000];

void sprime() {
	memset(ms, false, sizeof(ms));
	ms[6] = true;
	for(int i=7; i<300000-6; i+=7)
		ms[i+1] = ms[i+6] = true;
	REP(i, 300000) {
		if(ms[i]) {
			for(int j; j<300000; j+=i)
				ms[j] = false;
		}
	}
}

int main() {
	sprime();
	int n;
	while(cin >> n, n!=1) {
		
	return 0;
}
//16m
