#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int minimum;
vector<string> check;

void calc(int num, string cards) {

	string card;

	if(num+1 < cards.length() && num%4 < 3 && cards[num] == cards[num+1]) {
		card = cards;
		card.erase(card.begin()+num+1);
		card.erase(card.begin()+num);
		if(find(check.begin(), check.end(), card) == check.end()) {
			check.push_back(card);
			calc(0, card);
		}
	}
	if(num+4 < cards.length() && cards[num] == cards[num+4]) {
		card = cards;
		card.erase(card.begin()+num+4);
		card.erase(card.begin()+num);
		if(find(check.begin(), check.end(), card) == check.end()) {
			check.push_back(card);
			calc(0, card);
		}
	}
	if(num+3 < cards.length() && num%4 > 0 && cards[num] == cards[num+3]) {
		card = cards;
		card.erase(card.begin()+num+3);
		card.erase(card.begin()+num);
		if(find(check.begin(), check.end(), card) == check.end()) {
			check.push_back(card);
			calc(0, card);
		}
	}
	if(num+5 < cards.length() && num%4 < 3 && cards[num] == cards[num+5]) {
		card = cards;
		card.erase(card.begin()+num+5);
		card.erase(card.begin()+num);
		if(find(check.begin(), check.end(), card) == check.end()) {
			check.push_back(card);
			calc(0, card);
		}
	}

	if(num+1 < cards.length()) calc(num+1, cards);
	else if(cards.length() < minimum) minimum = cards.length();
}

int main() {
	int N;
	cin >> N;
	string cards;
	char input;

	for(int i=0; i<N; i++) {
		check.clear();
		minimum=20;
		cards = "";

		for(int j=0; j<20; j++) {
			cin >> input;
			cards.push_back(input);
		}

		for(int j=0; j<20; j++) {
			calc(j, cards);
		}
		cout << minimum << endl;
	}

	return 0;
}
