#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <string>
#include "base64.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	string input, hex_decode, temp, ouput;
	vector<char> output;
	string data;
	//string lookup = "0123456789ABCDEF";
	int val;

	getline(cin, input);
	for(int i=0; i< input.length(); i+=2)
	{
		//val = ((int)from_hex_to_decimal(input[i])) << 2;
		//val = val & ((int)from_hex_to_decimal(input[i+1]));
		temp = input[i];
		temp += input[i+1];
		val = strtol(temp.c_str(), 0, 16);
		//cout << val;
		//printf("%c", (input[i]);
		data += val;
	}
	cout << "encode now " << data << endl;
	b64_encode(output, data, data.length());

	for(int i=0; i<output.size();i++)
		cout << output[i];
	cout << endl;
	//cout << output << endl;

	return 0;
}

