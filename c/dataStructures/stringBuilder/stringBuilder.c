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

/*
 * Builds string into char* pointer provided,
 * frees stringBuilder struct.
 * Expecting correct size was allocated for string to be intesterted
 * into memory starting at toString pointer.
 */
void toStringToPtr(struct stringBuilder* strB, char* toString) {
	unsigned int toPtr = 0;
	// Get first string to copy over.
	char* strTocopy;
	strTocopy = (char*)pop(strB->lst);

	// While there is a string to copy.
	while(strTocopy) {
		unsigned int fromPtr = 0;
		char letter = *(strTocopy + fromPtr);
		// While not a terminating character.
		while(letter) {
			*(toString + toPtr) = letter; // Copy the one letter
			toPtr += 1; // Move to pointer
			fromPtr += 1; // Move from pointer
			letter = *(strTocopy + fromPtr); // get next letter
		}
		strTocopy = (char*)pop(strB->lst);
	}
	// Set final letter to be null terminating character.
	*(toString + toPtr) = '\0';
	// Free stringBuilder struct
	delete(strB->lst);
	free(strB);
}

/* Builds and returns the string, frees stringBuilder struct,
 * allocates memory for string returned.
 */
char* toString(struct stringBuilder* strB) {
	// Allocate size for string + 1 for terminating char
	char* finalString = malloc(strB->totalLength + 1);
	toStringToPtr(strB, finalString);
	return finalString;
}
