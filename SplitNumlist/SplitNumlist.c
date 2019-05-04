// SplitNumlist.c

#include <stdio.h>
#include <assert.h>

#define SPLIT_MAX 100

int compareArray(int[], int, int, int[], int, int);
void splitArray(int[], int[], int[]);
void showSplitArray(int[], int[], int[]);

int main(void)
{
	int inputNumList[] = { 5, 6, 7, -1 };
	int compNumList[] = { 1, 2, 3, 0, 2, 3, 4, 0, 5, 0, 5, 6, 7, -1 };

	int beginIndex[SPLIT_MAX];
	int numCountBySplit[SPLIT_MAX];

	for (int i = 0; i < SPLIT_MAX; i += 1) {
		beginIndex[i] = -1;
		numCountBySplit[i] = -1;
	}

	// count input array
	int inputNumLength = 0;
	for (int i = 0; i < 4; i += 1) {
		if (inputNumList[i] == -1) {
			inputNumLength = i;
			break;
		}
	}
	splitArray(compNumList, beginIndex, numCountBySplit);
	showSplitArray(compNumList, beginIndex, numCountBySplit);

	int matchIndex = -1;
	for (int i = 0; beginIndex[i] != -1; i += 1) {
		if (compareArray(inputNumList, 0, inputNumLength, compNumList, beginIndex[i], numCountBySplit[i])) {
			matchIndex = i;
			break;
		}
	}
	printf("match at %d\n", matchIndex);

#ifdef _DEBUG
	int testA[] = { 1, 2 };
	int testB[] = { 1, 2 };
	assert(compareArray(testA, 0, 2, testB, 0, 1) == 0);
	assert(compareArray(testA, 0, 2, testB, 0, 2) == 1);
	testB[1] = 3;
	assert(compareArray(testA, 0, 2, testB, 0, 2) == 0);
#endif // _DEBUG

}

int compareArray(int aArray[], int aIndex, int aLength, int bArray[], int bIndex, int bLength)
{
	if (aLength != bLength) {
		return 0;
	}

	// '1' mean true. compare correct
	int result = 1;
	for (int i = aIndex, j = bIndex; i < aLength; i += 1, j += 1) {
		if (aArray[i] != bArray[j]) {
			result = 0;
			goto breakPoint;
		}
	}
	// label line nop.
breakPoint:;

	return result;
}

void splitArray(int compNumList[], int beginIndex[], int numCountBySplit[])
{
	int current = 0;
	int index = 0;
	int count = 0;

	for (int i = 0; compNumList[i] != -1; i += 1) {
		if (count != 0 && compNumList[i] == 0) {
			beginIndex[current] = index;
			numCountBySplit[current] = count;

			count = 0;
			current += 1;
			index = i + 1;
		}
		else {
			count += 1;
		}
	}

	if (count > 1) {
		beginIndex[current] = index;
		numCountBySplit[current] = count;
	}
}

void showSplitArray(int compNumList[], int beginIndex[], int numCountBySplit[])
{
	for (int i = 0; beginIndex[i] != -1; i += 1) {
		printf("line no %d : ", i);
		for (int j = 0; j < numCountBySplit[i]; j += 1) {
			printf("%d ", compNumList[beginIndex[i] + j]);
		}
		printf("\n");
	}
}
