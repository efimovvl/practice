#!/bin/python3

import sys

'''
Class to count number of items less then provided value.
Keeps track of previous count for performance, traverses full list once.
'''
class CachedCounter():
	'''
	Init with integer list
	'''
	def __init__(self, lst):
		self.cachedCount = 0;
		self.index = 0;
		self.lst = sorted(lst);
		self.lastSearch = 0;

	'''
	Returns count of values in lst that are less or equal to
	the provided integer.

	For linear runtime, the first value provided should be the smallest
	and each proeceding value should be larger than the former.
	'''
	def getCachedCount(self, q):

		# Bad case, resets cached counter.
		if (q < self.lastSearch):
			self.cachedCount = 0;
			self.index = 0;
		# If same value as last call, return same value
		elif (q == self.lastSearch):
			return self.cachedCount;

		# Retain count for smaller items, count up from last used index
		lastVal = 0;
		for i in range(self.index, len(self.lst)):
			val = self.lst[i];
			if (val > q):
				break; # Done
			self.cachedCount += 1;
			self.index = i + 1; # offset, start at next index next time

		self.lastSearch = q;
		return self.cachedCount;

	'''
	Returns print out of object for debuging
	'''
	def __str__(self):
		return "Count:" + str(self.cachedCount) +\
		", index:" + str(self.index) +\
		" ,lastSearch:" + str(self.lastSearch);

	def __repr__(self):
		return self.__str__();

'''
Returns count of unique "sum" triplets given 3 integer lists.
'''
def triplets(a, b, c):

	b = sorted(set(b));

	countFromA = CachedCounter(a);
	countFromC = CachedCounter(c);

	count = 0;
	for val in b:
		# count values in a less or equal to val
		countA = countFromA.getCachedCount(val);
		countC = countFromC.getCachedCount(val);
		count += countA * countC;
		lastVal = val;

	return count;

'''
Main call provided as starter code for challenge:
'''
if __name__ == '__main__':
	fptr = sys.stdout;

	lenaLenbLenc = input().split()

	lena = int(lenaLenbLenc[0])

	lenb = int(lenaLenbLenc[1])

	lenc = int(lenaLenbLenc[2])

	arra = list(map(int, input().rstrip().split()))

	arrb = list(map(int, input().rstrip().split()))

	arrc = list(map(int, input().rstrip().split()))

	ans = triplets(arra, arrb, arrc)

	fptr.write(str(ans) + '\n')

	fptr.close()

