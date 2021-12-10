#include<iostream>
#include<fstream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	ifstream myfile("123.txt");
	int numIncrease = 0;
	string input = "";
	vector<int> inputs;
	vector<vector<int>> intinputs;
	//Try 1
	/*int total1 = 0;
	int total2 = 0;
	int total3 = 0;
	int total4 = 0;
	int total5 = 0;
	int total6 = 0;
	int total7 = 0;
	int total8 = 0;
	int currLine = 0;
	string line;

	while (getline(myfile, line)) 
	{
		if (currLine % 10 == 0) {
			total1 = 0;
		}
		else if (currLine % 10 == 1) {
			total2 = 0;
		}
		else if (currLine % 10 == 2) {
			total3 = 0;
		}
		else if (currLine % 10 == 3) {
			total4 = 0;
		}
		else if (currLine % 10 == 4) {
			total5 = 0;
		}
		else if (currLine % 10 == 5) {
			total6 = 0;
		}
		else if (currLine % 10 == 6) {
			total7 = 0;
		}
		else if (currLine % 10 == 7) {
			total8 = 0;
		}
		int temp = stoi(line);
		if (currLine % 10 == 0 || currLine % 10 == 1 || currLine % 10 == 2) {
			total1 += temp;
			cout << "1 " << total1 << ",";
		}
		if (currLine % 10 == 1 || currLine % 10 == 2 || currLine % 10 == 3) {
			total2 += temp;
			cout << "2 " << total2 << ",";
		}
		if (currLine % 10 == 2 || currLine % 10 == 3 || currLine % 10 == 4) {
			total3 += temp;
			cout << "3 " << total3 << ",";
		}
		if (currLine % 10 == 3 || currLine % 10 == 4 || currLine % 10 == 5) {
			total4 += temp;
			cout << "4 " << total4 << ",";
		}
		if (currLine % 10 == 4 || currLine % 10 == 5 || currLine % 10 == 6) {
			total5 += temp;
			cout << "5 " << total5 << ",";
		} 
		if (currLine % 10 == 5 || currLine % 10 == 6 || currLine % 10 == 7) {
			total6 += temp;
			cout << "6 " << total6 << ",";
		}
		if (currLine % 10 == 6 || currLine % 10 == 7 || currLine % 10 == 8) {
			total7 += temp;
			cout << "7 " << total7 << ",";
		} 
		if (currLine % 10 == 7 || currLine % 10 == 8 || currLine % 10 == 9) {
			total8 += temp;
			cout << "8 " << total8 << ",";
		}
		cout << endl;
		if (currLine % 10 == 2) {
			if (total8 == 0) {

			}
			else if (total1 > total8) {
				//cout << total1 << " increase" << endl;
				numIncrease++;
			}
		}
		if (currLine % 10 == 3) {
			if (total2 > total1) {
				//cout << total2 << " increase" << endl;
				numIncrease++;
			}
		}
		if (currLine % 10 == 4) {
			if (total3 > total2) {
				//cout << total3 << " increase" << endl;
				numIncrease++;
			}
		}
		if (currLine % 10 == 5) {
			if (total4 > total3) {
				//cout << total4 << " increase" << endl;
				numIncrease++;
			}
		}
		if (currLine % 10 == 6) {
			if (total5 > total4) {
				//cout << total5 << " increase" << endl;
				numIncrease++;
			}
		}
		if (currLine % 10 == 7) {
			if (total6 > total5) {
				//cout << total6 << " increase" << endl;
				numIncrease++;
			}
		}
		if (currLine % 10 == 8) {
			if (total7 > total6) {
				//cout << total7 << " increase" << endl;
				numIncrease++;
			}
		}
		if (currLine % 10 == 9) {
			if (total8 > total7) {
				//cout << total8 << " increase" << endl;
				numIncrease++;
			}
		}
		cout << currLine % 10 << endl;
		currLine++;
		
	}*/
	//Try 2
while (getline(myfile, input)) {
	inputs.push_back(stoi(input));
	}
for (int i = 0; i < inputs.size()-2; i++) {
	vector<int> temp;
	temp.push_back(inputs.at(i));
	temp.push_back(inputs.at(i + 1));
	temp.push_back(inputs.at(i + 2));
	intinputs.push_back(temp);
}
for (int i = 0; i < intinputs.size()-1; i++) {
	//cout << intinputs.at(i).at(0) << " " << intinputs.at(i).at(1) << " " << intinputs.at(i).at(2) << endl;
	int sumArr1;
	int sumArr2;
	sumArr1 = intinputs.at(i).at(0) + intinputs.at(i).at(1) + intinputs.at(i).at(2);
	sumArr2 = intinputs.at(i + 1).at(0) + intinputs.at(i+1).at(1) + intinputs.at(i + 1).at(2);
	if (sumArr2 > sumArr1) {
		numIncrease++;
	}
}
	cout << numIncrease << endl;
}