#include<iostream>

int main() {
	int n, d, k;
	std::cin >> n;
	std::cin >> d;
	std::cin >> k;

	int move[d][2];
	int eth[k][3];

	for(int i=0; i<d; i++){
		std::cin >> move[i][0];
		std::cin >> move[i][1];
	}
	for(int i=0; i<k; i++){
		std::cin >> eth[i][0];
		std::cin >> eth[i][1];
		eth[i][2] = 0;
	}
	for(int i=0; i<d; i++){
		for(int j=0; j<k; j++){
			if(move[i][0] <= eth[j][0] && eth[j][0] <= move[i][1]){
				if(eth[j][1] - eth[j][0] > 0) { //目的地が右側
					eth[j][0] = move[i][1];
					eth[j][2] = i + 1;
					if(eth[j][0] > eth[j][1]) eth[j][0] = eth[j][1];
				} else if(eth[j][1] - eth[j][0] < 0) { //目的地が左側
					eth[j][0] = move[i][0];
					eth[j][2] = i + 1;
					if(eth[j][0] < eth[j][1]) eth[j][0] = eth[j][1];
				}
			}
		}
	}

	for(int i=0; i<k; i++){
		std::cout << eth[i][2] << "\n";
	}
	return 0;
}
