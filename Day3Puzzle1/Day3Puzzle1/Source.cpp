#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int convert(long long);

int main() {
	ifstream input("input.txt");
	string inputStr;
	vector<string> inputText;
	vector<vector<string>> onesZeroes;
	vector<int> gammaOutput, epsilonOutput;
	string gammaOutputStr = "", epsilonOutputStr = "";

	while (getline(input, inputStr)) {
		inputText.push_back(inputStr);
	}
	for (int i = 0; i < inputText.at(0).size(); i++) {
		vector<string> temp;
		temp.push_back(" ");
		onesZeroes.push_back(temp);
	}
	for (int i = 0; i < inputText.size(); i++) {
		for (int j = 0; j < inputText.at(i).size(); j++) {
			string temp(1, inputText.at(i).at(j));
			onesZeroes.at(j).push_back(temp);
		}
	}
	for (int i = 0; i < onesZeroes.size(); i++) {

		int numOnes = 0;
		int numZeros = 0;
		for (int j = 0; j < onesZeroes.at(i).size(); j++) {
			if (onesZeroes.at(i).at(j) == "1") {
				numOnes++;
			}
			else if (onesZeroes.at(i).at(j) == "0") {
				numZeros++;
			}
		}

		if (numOnes > numZeros) {
			gammaOutput.push_back(1);
			epsilonOutput.push_back(0);
		}
		else if (numOnes < numZeros) {
			gammaOutput.push_back(0);
			epsilonOutput.push_back(1);
		}
		cout << "1's " << numOnes << " 0's " << numZeros << endl;
	}
	for (int i = 0; i < gammaOutput.size(); i++) {
		//gammaOutputStr.push_back(gammaOutput.at(i));
		//epsilonOutputStr.push_back(epsilonOutput.at(i));
		string temp = to_string(gammaOutput.at(i));
		gammaOutputStr += temp;
		temp = to_string(epsilonOutput.at(i));
		epsilonOutputStr.append(temp);
	}
	cout << "Gamma: " << gammaOutputStr << " Epsilon: " << epsilonOutputStr << endl;
	long long gamma = stol(gammaOutputStr, nullptr, 2);
	long long epsilon = stol(epsilonOutputStr, nullptr, 2);
	cout << "Gamma: " << gamma << " Epsilon: " << epsilon << " Total: " << gamma * epsilon << endl;
}
