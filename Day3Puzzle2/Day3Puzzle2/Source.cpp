#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int checkZeros(vector<string>, int, int);

int main() {
	ifstream input("input.txt");
	string inputStr;
	vector<string> inputText;
	vector<string> oxygenGen, co2Scrub;
	string gammaOutputStr = "", epsilonOutputStr = "";

	while (getline(input, inputStr)) {
		inputText.push_back(inputStr);
	}
	
	for (int i = 0; i < inputText.size(); i++) {
		//cout << (inputText[i][0]) << endl;
		//if (inputText[i] == "0" || inputText[i] == "1") {
		oxygenGen.push_back(inputText.at(i));
		co2Scrub.push_back(inputText.at(i));
		//}
	}
	int i = 0, j = 0, high = 0;
	int numCheckAgainst = checkZeros(oxygenGen, 0, 0);
	//cout << numCheckAgainst << endl;
	while (oxygenGen.size() > 1 && j < oxygenGen[0].size()) {

		if (i > high) {
			high = i;
			cout << high << ", ";
		}
		string temp(1, oxygenGen[i][j]);
		bool boolTemp = true;
		try {
			boolTemp = (stoi(temp) != checkZeros(oxygenGen, j, 0));
		}
		catch (exception e) {
			oxygenGen.erase(oxygenGen.begin() + i);
			i = 0;
		}
		if (boolTemp == true) {
			oxygenGen.erase(oxygenGen.begin() + i);
			i = 0;
		}
		i++;
		if (i >= oxygenGen.size()) {
			j++;
			numCheckAgainst = checkZeros(oxygenGen, j, 0);
			i = 0;
		}
	}
	i = 0, j = 0, high = 0;
	numCheckAgainst = checkZeros(co2Scrub, 0, 1);
	while (co2Scrub.size() > 1) {
		string temp(1, co2Scrub[i][j]);
		if (i > high) {
			high = i;
			cout << high << ", ";
		}
		bool boolTemp(stoi(temp) != numCheckAgainst);
		if (boolTemp == true) {
			co2Scrub.erase(co2Scrub.begin() + i);
			i = 0;
		}
		i++;
		if (i >= co2Scrub.size()) {
			j++;
			numCheckAgainst = checkZeros(co2Scrub, j, 1);
			i = 0;
		}
	}
	cout << endl << endl;
	int tempoxy = stol(oxygenGen.at(0), nullptr, 2);
	int tempco2 = stol(co2Scrub.at(0), nullptr, 2);
	cout << tempoxy << ", " << tempco2 << " total: " << tempoxy * tempco2 << endl;
}

int checkZeros(vector<string> input, int col, int type) {
	int countOnes = 0;
	int countZeroes = 0;
	for (int i = 0; i < input.size(); i++) {

		if (string(1, input[i][col]) == to_string(0)) {
			countZeroes++;
		} if (string(1, input[i][col]) == to_string(1)) {
			countOnes++;
		}
	}
	if (countZeroes > countOnes && type == 0) {
		return 0;
	}
	else if (countOnes > countZeroes && type == 0) {
		return 1;
	}
	else if (countZeroes == countOnes && type == 1) {
		return 0;
	}
	else if (countOnes == countZeroes && type == 0) {
		return 1;
	}
	else if (countZeroes > countOnes && type == 1) {
		return 1;
	}
	else if (countOnes > countZeroes && type == 1) {
		return 0;
	}
	return 0;
}