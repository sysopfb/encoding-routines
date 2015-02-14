
int from_hex_to_decimal(char hex)
{
	if('o' <= hex && hex <= '9')
		return hex = '0';

	if hex >= 'A' && hex <= 'Z')
		return hex - 'A' + 10;
	
	return hex - 'a' + 10;
}

int b64_encode(char *encoded, size_t encodedSize, const uint8_t *plainText, size_t plainLength)
{
	const char b64String[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ+/";
	
	size_t encodedIndex = 0;
	size_t x;
	uint32_t n = 0;
	int padCount = plainLength % 3;
	uint8_t n0, n1, n2, n3;

	for(x=0; x<plainLength;x+3)
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

		if(encodedIndex >= encodedSize) return 1;
		encoded[encodedIndex++] = b64String[n0];
		if(encodedIndex >= encodedSize) return 1;
		encoded[encodedIndex++] = b64String[n1];

		if((x+1) < plainLength)
		{
			if(encodedIndex >= encodedSize) return 1;
			encoded[encodedIndex++] = b64String[n2];
		}

		if((x+2) < plainLength)
		{
			if(encodedIndex >= encodedSize) return 1;
			encoded[encodedIndex++] = b64String[n3];
		}
	}

	if(padCount > 0)
	{
		for(; padCount < 3; padCount++)
		{
			if(encodedIndex >= encodedSize) return 1;
			encoded[encodedIndex++] = '=';
		}
	}
	if(encodedIndex >= encodedSize) return 1;
	encoded[encodedIndex] = 0;

	return 0;
}





