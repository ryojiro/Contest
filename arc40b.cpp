#include<iostream>

using namespace std;

int move(int current,int N, int R, string S) {
	int cnt = 0;
	if(R+current < N) {
		for(int i=current; i<(R+current); i++) {
			cout << "1a" << ' ' << cnt  << ' ' << current << endl;
			if(S.at(current) == 'o') cnt++;
			else if(S.at(current) == '.') break;
			if(i==N-1) break;
		}
	} else {
		cout << "1b" << ' ' << cnt << ' ' << current << endl;
		cnt = N;
	}
	return cnt;
}

int main() {
	int N, R;
	string S;
	cin >> N >> R;
	cin >> S;

	int current=0;
	int cnt=0;
	while(current < N) {
		cout << "2" << ' ' << cnt << ' ' << current << endl;
		int temp = move(current, N, R, S);
		if(temp == 0) {
			if(current + R < N) {
				int temp = move(current, N, R, S);
				current += R + temp;
				cnt += R+1 + temp;
			} else {
				current += N-current;
			}
		} else {
			if(current + R >= N) {
			current = N;
			cnt += 1;
		}
	}
	cout << cnt << endl;

	return 0;
	}
}
