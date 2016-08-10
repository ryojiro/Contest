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
#include <stack>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
const int INF = 1<<28;
const ll MOD = 1000000007;

int dice[6] = {1,5,4,3,2,6};
void swap(int i, int j, int k, int l) {
	int temp = dice[l];
	dice[l] = dice[k];
	dice[k] = dice[j];
	dice[j] = dice[i];
	dice[i] = temp;
}
int main() {
	int n;
	while(cin >> n, n) {
		dice[0] = 1;
		dice[1] = 5;
		dice[2] = 4;
		dice[3] = 3;
		dice[4] = 2;
		dice[5] = 6;
		REP(i, n) {
			string in; cin >> in;
			if(in == "north")
				swap(0,4,5,1);
			else if(in == "south")
				swap(0,1,5,4);
			else if(in == "west")
				swap(0,3,5,2);
			else if(in == "east")
				swap(0,2,5,3);
		}
		cout << dice[0] << endl;
	}
	return 0;
}
