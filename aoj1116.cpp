#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>


using namespace std;

int cnt;

char tonum(char word) {
	if(word == 'R') return '1';
	if(word == 'G') return '2';
	if(word == 'B') return '3';
	if(word == 'W') return '4';
	if(word == 'r') return '5';
	if(word == 'g') return '6';
	if(word == 'b') return '7';
	if(word == 'w') return '8';

	return '0';
}

void calc(int num, string rest, string ing) {
	string bkup_r = rest;
	string bkup_i = ing;

	if(num==9) {
		cnt++; return;
	}

	if(num == 0) {
		for(int i=0; i<9; i++) {
			for(int j=0; j<4; j++) {
				ing.push_back(rest[j%4 + i*4]);
				ing.push_back(rest[(j+1)%4 + i*4]);
				ing.push_back(rest[(j+2)%4 + i*4]);
				ing.push_back(rest[(j+3)%4 + i*4]);
				calc(1, rest.erase(i*4, 4), ing);  
				rest = bkup_r;
				ing = "";
			}
		}
	}
	else if(num<3) {
		for(int i=0; i<rest.size(); i++) {
			if(abs((int)ing[2+(num-1)*4] - (int)rest[i]) == 4) {
				ing.push_back(rest[i%4 + i/4*4]);
				ing.push_back(rest[(i+1)%4 + i/4*4]);
				ing.push_back(rest[(i+2)%4 + i/4*4]);
				ing.push_back(rest[(i+3)%4 + i/4*4]);
				calc(num+1, rest.erase(i/4*4, 4), ing);  
				rest = bkup_r;
				ing = bkup_i;
			}
		}
	}
	else if(num%3 == 0) {
		for(int i=0; i<rest.size(); i++) {
			if(abs((int)ing[3+(num-3)*4] - (int)rest[i]) == 4) {
				ing.push_back(rest[(i+3)%4 + i/4*4]);
				ing.push_back(rest[i%4 + i/4*4]);
				ing.push_back(rest[(i+1)%4 + i/4*4]);
				ing.push_back(rest[(i+2)%4 + i/4*4]);
				calc(num+1, rest.erase(i/4*4, 4), ing);  
				rest = bkup_r;
				ing = bkup_i;
			}
		}
	}
	else {
		for(int i=0; i<rest.size(); i++) {
			if(abs((int)ing[2+(num-1)*4] - (int)rest[i]) == 4 &&
				abs((int)ing[3+(num-3)*4] - (int)rest[(i+1)%4 + i/4*4]) == 4) {
				ing.push_back(rest[i%4 + i/4*4]);
				ing.push_back(rest[(i+1)%4 + i/4*4]);
				ing.push_back(rest[(i+2)%4 + i/4*4]);
				ing.push_back(rest[(i+3)%4 + i/4*4]);
				calc(num+1, rest.erase(i/4*4, 4), ing);  
				rest = bkup_r;
				ing = bkup_i;
			}
		}
	}
}

int main() {
	int n;
	char input;
	string pieces;

	cin >> n;
	for(int t=0; t<n; t++) {
		pieces = "";
		for(int i=0; i<36; i++) {
			cin >> input;
			pieces.push_back(tonum(input));
		}
		cnt = 0;
		calc(0, pieces, "");
		cout << cnt << endl;
	}

	return 0;
}
