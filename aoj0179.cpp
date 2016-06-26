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
  string musi;
  while(cin >> musi, musi != "0") {
    string tonum;
    for(int i=0; i<musi.size(); i++) {
      if(musi[i] == 'r')
        tonum.push_back('1');
      if(musi[i] == 'g')
        tonum.push_back('2');
      if(musi[i] == 'b')
        tonum.push_back('3');
    }
    queue< pair<string, int> > q;
    pair<string, int> p;
    p.first = tonum;
    p.second = 0;
    q.push(p);
    bool flg = true;
    set<string> memo;
    int test = 0;
    while(q.size()) {
      p = q.front();
      q.pop();
      int cnt = 0;
      for(int i=1; i<p.first.size(); i++) {
        if(p.first[i-1] != p.first[i]) {
          pair<string, int> p2;
          p2 = p;
          int n = (int)p.first[i-1] + (int)p.first[i] - '0' - '0';
          if(n==3) {
            p2.first[i-1] = '3';
            p2.first[i] = '3';
          }
          else if(n==4) {
            p2.first[i-1] = '2';
            p2.first[i] = '2';
          }
          else if(n==5) {
            p2.first[i-1] = '1';
            p2.first[i] = '1';
          }
          if(memo.find(p2.first) == memo.end()) {
            p2.second++;
            q.push(p2);
            memo.insert(p2.first);
          }
        }
        else cnt++;
      }
      if(cnt == p.first.size()-1) {
        flg = false;
        cout << p.second << endl;
        break;
      }
    }
    if(flg) cout << "NA" << endl;
  }
  return 0;
}
