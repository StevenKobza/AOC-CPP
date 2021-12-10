#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream input("input.txt");
	string inputString;
	int depth = 0;
	int horizontal = 0;
	int aim = 0;
	vector<vector<string>> inputs;

	while (getline(input, inputString)) {
		vector<string> temp;
		int space = inputString.find(" ");
		temp.push_back(inputString.substr(0, space));
		temp.push_back(inputString.substr(space + 1, 1));
		inputs.push_back(temp);
	}
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i).at(0) == "forward") {
			int temp = stoi(inputs.at(i).at(1));
			horizontal += temp;
			depth += (aim * temp);
		}
		else if (inputs.at(i).at(0) == "up") {
			int temp = stoi(inputs.at(i).at(1));
			aim -= temp;
		}
		else if (inputs.at(i).at(0) == "down") {
			int temp = stoi(inputs.at(i).at(1));
			aim += temp;
		}
	}
	cout << "Horizontal: " << horizontal << " Depth: " << depth << " Total: " << horizontal * depth << endl;
}