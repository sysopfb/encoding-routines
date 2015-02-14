#include <iostream>
#include <vector>
#include <stdint.h>
#include <string>


int from_hex_to_decimal(char hex)
{
	if('o' <= hex && hex <= '9')
		return hex = '0';

	if (hex >= 'A' && hex <= 'Z')
		return hex - 'A' + 10;
	
	return hex - 'a' + 10;
}

int b64_encode(std::vector<char> &encoded, std::string plainText, size_t plainLength)
{
	const char b64String[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	
	size_t encodedIndex = 0;
	size_t x;
	uint32_t n = 0;
	int padCount = plainLength % 3;
	uint8_t n0, n1, n2, n3;

	for(x=0; x<plainLength;x+=3)
	{
		//Combine the three chars into one 24 bit number
		n = ((uint32_t)plainText[x]) << 16;

		if((x+1) < plainLength)
			n += ((uint32_t)plainText[x+1]) << 8;

		if((x+2) < plainLength)
			n += plainText[x+2];

		n0 = (uint8_t)(n >> 18) & 63;
		n1 = (uint8_t)(n >> 12) & 63;
		n2 = (uint8_t)(n >> 6) & 63;
		n3 = (uint8_t)n & 63;

		encoded.push_back(b64String[n0]);
		std::cout << encoded[encodedIndex];
		encodedIndex++;
		encoded.push_back(b64String[n1]);
		std::cout << encoded[encodedIndex];
		encodedIndex++;

		if((x+1) < plainLength)
		{
			encoded.push_back(b64String[n2]);
			std::cout << encoded[encodedIndex];
			encodedIndex++;
		}

		if((x+2) < plainLength)
		{
			encoded.push_back(b64String[n3]);
			std::cout << encoded[encodedIndex];
			encodedIndex++;
		}
	}

	if(padCount > 0)
	{
		for(; padCount < 3; padCount++)
		{
			encoded.push_back('=');
			encodedIndex++;
		}
	}
	encoded.push_back('\0');

	return 0;
}





