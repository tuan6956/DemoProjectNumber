#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#pragma warning(disable:4996)
#include <bitset>
using namespace std;
class QInt
{
private:
	__int64 A[2];
public:

	QInt(string number);
	QInt();
	~QInt();

#pragma region Function Helper
	//Convert Char To Binary
	string ConverCharToBinary(char character)
	{
		char output[9];
		_itoa(character, output, 2);
		std::stringstream ss;
		ss << std::setw(4) << std::setfill('0') << output;
		std::string s = ss.str();
		return s;
	}
	//Big num to binary
	void DichbitPhai(string &temp, string &binarySave)
	{
		int templeng = temp.length();
		binarySave.insert(0, 1, temp[templeng - 1]);
		temp.erase(templeng - 1, 1);
	}
	//Binary to Big Num
	void DichbitTrai(string &temp, string &binarySave)
	{
		binarySave.insert(binarySave.length(), 1, temp[0]);
		temp.erase(0, 1);
	}
	//Add 3 or Sub 3everywhere that block 4byte >= 5
	//Add 3 When Convert Binary to bignum
	//Subtract 3 When Convert BigNum to Binary
	string Update(string content, bool add)
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
			int iValue = i - 3;
			if (add)
				iValue = i + 3;
			if (i >= 5)
				contentnew.insert(0, ConverCharToBinary(iValue));
			else
				contentnew.insert(0, sub);
			length = temp.length();

		}
		return contentnew;
	}

	//Convert BigNumber To Binary
	string BigNumberToBinary(string Number);

	// Convert Binary To Big Number
	string BinaryToBigNum(string Binary);
#pragma endregion


};

