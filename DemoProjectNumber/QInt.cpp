#include "QInt.h"



QInt::QInt(string number)
{
	//StringToBinary(number);
	//string binary =strrev(BigNumberToBinary(number).c_str);
}

QInt::QInt()
{
}


QInt::~QInt()
{
}

string QInt::BigNumberToBinary(string number)
{
	string temp = "";
	string savevalue = "";
	for (int i = 0; i < number.length(); i++)
	{
		string bi = ConverCharToBinary(number[i] - '0');
		temp += bi;
	}
	string binary = "";
	while (temp.length() != 0)
	{
		DichbitPhai(temp, savevalue);
		temp = Update(temp,false);
	}
	return savevalue;
}

string QInt::BinaryToBigNum(string Binary)
{
	string Number = "";
	string temp = Binary;
	string binarySave = "";
	while (temp.length() != 0)
	{

		DichbitTrai(temp,binarySave);
		if (temp.length() == 0)
		{
			break;
		}
		Number = Update(Number,true);

	}
	string output = "";
	while (Number.length() != 0)
	{
		string sub = "";
		if (Number.length() < 4)
		{
			sub = Number.substr(0, Number.length());
			binarySave = binarySave.erase(0, binarySave.length());
		}
		else
		{
			sub = Number.substr(Number.length() - 4, 4);
			binarySave = binarySave.erase(binarySave.length() - 4, 4);
		}

		int i = std::stoi(sub, nullptr, 2);
		output.insert(0, 1, (char)(i + '0'));
	}
	return output;
}
