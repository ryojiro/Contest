#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

void calc(long a, long b, long c, long x, long y, long z, bool &flg) {
	if(a >= x && b >= y && c >= z) flg = true;

	if(a > x+1) {
		if(b < y) {
			if((a-x)/2 > y-b) calc(x+(a-x)%2, y, c+(a-x)/2-(y-b), x, y, z, flg);
			else calc(x+(a-x)%2, b+(a-x)/2, c, x, y, z, flg);
		}
		if(c < z) {
			if((a-x)/2 > z-c) calc(x+(a-x)%2, b+(a-x)/2-(z-c), z, x, y, z, flg);
			else calc(x+(a-x)%2, b, c+(a-x)/2, x, y, z, flg);
		}
	}
	if(b > y+1) {
		if(a < x) {
			if((b-y)/2 > x-a) calc(x, y+(b-y)%2, c+(b-y)/2-(x-a), x, y, z, flg);
			else calc(a+(b-y)/2, y+(b-y)%2, c, x, y, z, flg);
		}
		if(c < z) { 
			if((b-y)/2 > z-c) calc(a+(b-y)/2-(z-c), y+(b-y)%2, z, x, y, z, flg);
			else calc(a, y+(b-y)%2, c+(b-y)/2, x, y, z, flg);
		}
	}
	if(c > z+1) {
		if(a < x) {
			if((c-z)/2 > x-a) calc(x, b+(c-z)/2-(x-a), z+(c-z)%2, x, y, z, flg);
			else calc(a+(c-z)/2, b, z+(c-z)%2, x, y, z, flg);
		}
		if(b < y) {
			if((c-z)/2 > y-b) calc(a+(c-z)/2-(y-b), y, z+(c-z)%2, x, y, z, flg);
			else calc(a, b+(c-z)/2, z+(c-z)%2, x, y, z, flg);
		}
	} 
}
int main() {
	long a, b, c, x, y, z;
	cin >> a >> b >> c >> x >> y >> z;

	bool flg = false;
	calc(a, b, c, x, y, z, flg);

	if(flg) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
