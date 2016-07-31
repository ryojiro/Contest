#include <iostream>

int main() {
	int n, time;
	std::cin >> n;
	std::cin >> time;
	
	int sum = 0;
	int previous;
	for(int i=0; i<n; i++) {
		int arrive;
		std::cin >> arrive;
		if(i==0) previous = arrive;
		if(arrive - previous >= time) {
			sum += time;
		} else {
			sum += arrive - previous;
		}
		previous = arrive;
	}
	if(previous != 0) sum += time;
	std::cout << sum << "\n";
}
