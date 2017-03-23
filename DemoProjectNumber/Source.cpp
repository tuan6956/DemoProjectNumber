#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;
vector<string> SaveBit;
string binarySave = "";
string binarySave2 = "";

//limit 39
string printbinchar(char character)
{
	char output[9];
	_itoa(character, output, 2);
	std::stringstream ss;
	ss << std::setw(4) << std::setfill('0') << output;
	std::string s = ss.str();
	return s;
}
//
void DichbitPhai(string &temp)
{
	int templeng = temp.length();
	binarySave2.insert(0, 1, temp[templeng - 1]);
	temp.erase(templeng - 1, 1);
}
void DichbitTrai(string &temp)
{
	binarySave.insert(binarySave.length(), 1, temp[0]);
	temp.erase(0, 1);
}
string Update(string content)
{
	string temp = content;
	string contentnew;
	int length = temp.length();
	while (temp.length() != 0)
	{
		string sub;
		if (length < 4)
		{
			sub = temp.substr(0, length);
			temp = temp.erase(0, length);
		}
		else
		{
			sub = temp.substr(length - 4, 4);
			temp = temp.erase(length - 4, 4);
		}
		int i = std::stoi(sub, nullptr, 2);
		if (i == 0 && length < 4)
			continue;
		if (i >= 5)
			contentnew.insert(0, printbinchar(i - 3));
		else
			contentnew.insert(0, sub);
		length = temp.length();

	}
	return contentnew;
}
string Update2(string content)
{
	string temp = content;
	string contentnew;
	int length = temp.length();
	while (temp.length() != 0)
	{
		string sub;
		if (length < 4)
		{
			sub = temp.substr(0, length);
			temp = temp.erase(0, length);
		}
		else
		{
			sub = temp.substr(length - 4, 4);
			temp = temp.erase(length - 4, 4);
		}
		int i = std::stoi(sub, nullptr, 2);
		if (i == 0 && length < 4)
			continue;
		if (i >= 5)
			contentnew.insert(0, printbinchar(i + 3));
		else
			contentnew.insert(0, sub);
		length = temp.length();

	}
	return contentnew;
}

void Action2(string bignum)
{
	string temp = bignum;
	string binary = "";
	while (temp.length() != 0)
	{

		DichbitTrai(temp);
		if (temp.length() == 0)
		{
			break;
		}
		binarySave = Update2(binarySave);

	}
	string output = "";
	while (binarySave.length() != 0)
	{
		string sub = "";
		if (binarySave.length() < 4)
		{
			sub = binarySave.substr(0, binarySave.length());
			binarySave = binarySave.erase(0, binarySave.length());
		}
		else
		{
			sub = binarySave.substr(binarySave.length() - 4, 4);
			binarySave = binarySave.erase(binarySave.length() - 4, 4);
		}
		
		int i = std::stoi(sub, nullptr, 2);
		output.insert(0,1, (char)(i+'0'));
	}
	cout << output;

	//cout << binarySave;
	/*int maxsize = SaveBit.size();
	while (SaveBit[0] != "")
	{
		SaveBit[maxsize].substr(0,1);
	}*/

}
void Action(string bignum)
{
	string temp = "";
	string savevalue = "";
	for (int i = 0; i < bignum.length(); i++)
	{
		string bi = printbinchar(bignum[i] - '0');
		temp += bi;
	}
	string binary = "";
	while (temp.length() != 0)
	{
		DichbitPhai(temp);
		temp = Update(temp);
	}
	cout<< binarySave2;
}
void main(int argc, const char * argv[])
{
	
	//Action("922337203685477580792233720368547758079223372036854775807922337203685477580792233720368547758079223372036854775807922337203685477580792233720368547758079223372036854775807922337203685477580792233720368547758079223372036854775807");
	//Action("8793278316383117319");
	//cout << endl;
	//Action2("111101000001000000000000000101000111011001010010010000000000111");
	string temp = "111101000001000000000000000101000111011001010010010000000000111001010010010000000000111";
	//reverse(temp.begin(),temp.end());
	__int64 A[2];
	A[0] = 0;
	A[1] = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '1')
		{
			if (i < 64)
			{
				int iTemp = 1 << i;
				A[0] = A[0] | iTemp;
			}
			else
			{
				int iTemp = 1 << (i-64);
				A[1] = A[1] | iTemp;
			}
		}
	}
	cout << A[0] << endl << A[1];

	string output = "";
	for (int i = 0; i < 64; i++)
	{
		output.insert(output.begin(), (A[0] % 2) + '0');
		A[0] /= 2;

	}

	while (A[1] != 0)
	{
		output.insert(output.begin(), (A[1] % 2) + '0');
		A[1] /= 2;
	}

	cout <<output<< endl;
	system("pause");
}