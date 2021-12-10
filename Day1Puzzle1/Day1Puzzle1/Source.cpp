#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	string line;
	int numIncrease = 0;
	int prevNum = 0;

	ifstream myFile("123.txt");
	while (getline(myFile, line)) 
	{
		int temp = stoi(line);
		if (prevNum == 0) 
		{
			cout << line << " (N/A - no previous measurement)" << endl;
		}
		else if (temp > prevNum)
		{
			cout << line << " (increased)" << endl;
			numIncrease++;
		}
		else if (temp < prevNum) 
		{
			cout << line << " (decreased)" << endl;
		}
		prevNum = temp;
	}
	cout << "there were " << numIncrease << " measurements bigger than the previous one" << endl;
}