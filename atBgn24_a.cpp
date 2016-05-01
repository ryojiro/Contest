#include<iostream>

int main () {
	int input[6];
	
	for(int i=0; i<6; i++) {
		std::cin >> input[i];
	}

	if(input[4] + input[5] >= input[3]) {
		std::cout << input[0] * input[4] + input[1] * input[5] - (input[4] + input[5]) * input[2] << "\n";
	} else {
		std::cout << input[0] * input[4] + input[1] * input[5] << "\n";
	}
}
