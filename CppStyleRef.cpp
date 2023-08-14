#include <iostream>
#include <vector>
using namespace std;

void separateOddsAndEvensRef(const int arr[], size_t size, int*& odds, size_t& numOdds, int*& evens, size_t& numEvens)
{
	numOdds = numEvens = 0;
	for (size_t i{ 0 }; i < size; i++) {
		if (arr[i] % 2 == 0) {
			++numOdds;
		}
		else {
			++numEvens;
		}
	}

	odds = new int[numOdds];
	evens = new int[numEvens];
	
	size_t oddsPos{ 0 }, evensPos{ 0 };
	for (size_t i{ 0 }; i < size; i++) {
		if (arr[i] % 2 == 0) {
			odds[oddsPos++] = arr[i];
		}
		else {
			evens[evensPos++] = arr[i];
		}
	}
}

// ±ÇÀåÇÏ´Â ¹æ½Ä ±ò²û, ¼¼·Ã
void separateOddsAndEvensVector(const vector<int>& arr, vector<int>& odds, vector<int>& evens)
{
	for (int i : arr) {
		if (i % 2 == 0) {
			odds.push_back(i);
		}
		else {
			evens.push_back(i);
		}
	}
}

struct OddsAndEvens{ vector<int> odds, evens; };

OddsAndEvens separateOddsAndEvensStruct(const vector<int>& arr)
{
	vector<int> odds, evens;
	for (int i : arr) {
		if (i % 2 == 0) {
			odds.push_back(i);
		}
		else {
			evens.push_back(i);
		}
	}
	return OddsAndEvens{ .odds = odds, .evens = evens };
}
int mainCppStyleRef()
{
	vector<int> vecUnSplit{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> odds, evens;
	separateOddsAndEvensVector(vecUnSplit, odds, evens);
	for (const auto i : odds) {
		cout << i << endl;
	}

	for (const auto i : evens) {
		cout << i << endl;
	}

	vector<int> vecUnSplit2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto oddsAndEvens{ separateOddsAndEvensStruct(vecUnSplit2) };
	for (int i : oddsAndEvens.evens) {
		cout << i << " ";
	}
	cout << endl;
	for (int i : oddsAndEvens.odds) {
		cout << i << endl;
	}

	return 0;
}