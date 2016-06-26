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

int main() {
	string chk = "yuiophjklnm";
	string n;
	while(cin >> n, n != "#") {
		string ed = "";
		for(int i=0; i<n.size(); i++) {
			bool flg = false;
			for(int j=0; j<chk.size(); j++) {
				if(n[i] == chk[j]) {
					flg = true;
					ed.push_back('1');
					break;
				}
			}
			if(!flg) ed.push_back('0');
		}
		int cnt = 0;
		for(int i=1; i<n.size(); i++)
			if(ed[i-1] != ed[i]) cnt++;

		cout << cnt << endl;
	}
	return 0;
}
