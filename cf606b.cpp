#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

int main() {
	int x, y, x0, y0;
	string commands;
	cin >> x >> y >> x0 >> y0 >> commands;

	int field[500][500] = {};
	int currentX = x0;
	int currentY = y0;
	int count = 1;
	int move;

	field[currentX][currentY] = 1;
	cout << 1 << ' ';
	for(int i=0; i<commands.length()-1; i++) {
		move=0;
		if(commands.at(i) == 'U' && 1 < currentX) {
			currentX -= 1;
			move = 1;
		} else if(commands.at(i) == 'D' && currentX < x) { 
			currentX += 1;
			move = 1;
		} else if(commands.at(i) == 'L' && 1 < currentY) {
			currentY -= 1;
			move = 1;
		} else if(commands.at(i) == 'R' && currentY < y) {
			currentY += 1;
			move = 1;
		}

		if(field[currentX][currentY] == 0) {
			count += 1;
			cout << 1 << ' ';
			field[currentX][currentY] = 1;
		} else if(field[currentX][currentY] == 1 && move ==1 || commands.length() == count) { 
			break;
		} else {
			cout << 0 << ' ';
		}

		// cout << currentX << currentY << "hoge" << endl;
		if(currentX == x0 && currentY == y0) {
			break;
		}
	}

  cout << count << endl;
	return 0;
}
