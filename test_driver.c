#include <stdio.h>
#include "rc4.h"

int main()
{
	unsigned char bleh[] = "hello there";
	unsigned char key[] = "tfd";

	rc4(bleh, key);

	printf("\n%s\n", bleh);

	rc4(bleh, key);

	printf("\n%s\n", bleh);

	return 0;
}
