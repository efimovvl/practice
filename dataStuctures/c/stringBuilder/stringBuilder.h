#ifndef STRING_BUILDER_H_
#define STRING_BUILDER_H_

/* A linkedList of char, but tracks length of final string */
struct stringBuilder {
	struct linkedList* lst;
	// Using size_t type used for malloc.
	size_t totalLength;

};

struct stringBuilder* initStringBuilder();
void appendStr(struct stringBuilder* strB,
char* str, unsigned int strLength);
char* toString(struct stringBuilder* strB);

#endif
