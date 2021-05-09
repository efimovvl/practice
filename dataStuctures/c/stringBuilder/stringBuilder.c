/**
 * String builder.
 *
 * Given a set of strings, concatenate them and return one string.
 *
 * Naive approach is to concatenate one a time. This is not efficient,
 * as we would have to re-malloc and copy on every concatenation.
 *
 * Better approach is to first collect all the strings and sizes,
 * then when ready malloc once and copy each char. This strategy
 * is known as a String Builder.
 *
 * @author Vladimir Efimov
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // size_t max = SIZE_MAX
#include "../linkedList/linkedList.h"
#include "stringBuilder.h"

// Can be found in stringBuilder.h

//~ struct stringBuilder {
	//~ struct linkedList* lst;
	//~ // Using size_t type used for malloc.
	//~ size_t totalLength;

//~ };

struct stringBuilder* initStringBuilder() {
	struct stringBuilder* strB = malloc(sizeof(struct stringBuilder));
	strB->totalLength = 0;
	strB->lst = init();
	return strB;
}

/* Add string to stringBuilder */
void appendStr(struct stringBuilder* strB,
					char* str, unsigned int strLength) {
	unsigned int newTotalLength =
		(unsigned int)strB->totalLength + strLength;
	// If new length is larger then we can malloc, return.
	if (newTotalLength > SIZE_MAX) {
		return;
	}

	strB->totalLength = (size_t)newTotalLength;
	append(strB->lst, (void*)str);
}

/* Builds and returns the string, frees memory */
char* toString(struct stringBuilder* strB) {
	// Allocate size for string + 1 for terminating char
	char* finalString = malloc(strB->totalLength + 1);

	unsigned int toPtr = 0;
	char* strTocopy;
	strTocopy = (char*)pop(strB->lst);
	// While there is a string to copy.
	while(strTocopy) {
		unsigned int fromPtr = 0;
		char letter = *(strTocopy + fromPtr);
		// While not a terminating character.
		while(letter) {
			*(finalString + toPtr) = letter; // Copy the one letter
			toPtr += 1; // Move to pointer
			fromPtr += 1; // Move from pointer
			letter = *(strTocopy + fromPtr); // get next letter
		}
		strTocopy = (char*)pop(strB->lst);
	}
	// Set final letter to be null terminating character.
	*(finalString + toPtr) = '\0';
	delete(strB->lst);
	free(strB);
	return finalString;
}

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

	return 0;
}

