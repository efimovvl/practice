/**
 * String builder c test.
 *
 * @author Vladimir Efimov
 */

#include <stdio.h>
#include <stdlib.h>
#include "stringBuilder.h"

/* Runner to test stringBuilder*/
int main(int argc, char **argv)
{
	struct stringBuilder* sb;
	sb = initStringBuilder();
	char* a = "Hello "; // 7
	char* b = "World. "; // 7
	char* c = "One day "; // 8
	char* d = "you will be mine!"; //17

	printf("%s\n", a);
	printf("%s\n", b);
	printf("%s\n", c);
	printf("%s\n", d);

	appendStr(sb, a, 7);
	appendStr(sb, b, 7);
	appendStr(sb, c, 8);
	appendStr(sb, d, 17);

	char* finalString = toString(sb);
	printf("%s\n", finalString);
	free(finalString);
	return 0;
}
