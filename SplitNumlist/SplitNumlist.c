// SplitNumlist.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>
#include <assert.h>

#define SPLIT_MAX 100

int compareArray(int[], int, int, int[], int, int);
void splitArray(int[], int[], int[]);
void showSplitArray(int[] , int[] , int[]);

int main(void)
{
	int inputNumList[] = {5, 6, 7, -1};
	int compNumList[] = {1, 2, 3, 0, 2, 3, 4, 0, 5, 0, 5, 6, 7, -1};

	int beginIndex[SPLIT_MAX];
	int numCountBySplit[SPLIT_MAX];

	for (int i = 0; i < SPLIT_MAX; i += 1) {
		beginIndex[i] = -1;
		numCountBySplit[i] = -1;
	}

    printf("Hello World!\n"); 
	splitArray(compNumList, beginIndex, numCountBySplit);
	showSplitArray(compNumList, beginIndex, numCountBySplit);

#ifdef _DEBUG
	int testA[] = {1};
	int testB[] = {1};
	assert(compareArray(testA, 0, 2, testB, 0, 1) == 0);
	assert(compareArray(testA, 0, 1, testB, 0, 1) == 1);
	testB[0] = 2;
	assert(compareArray(testA, 0, 1, testB, 0, 1) == 0);
#endif // _DEBUG

}

int compareArray(int aArray[], int aIndex, int aLength, int bArray[], int bIndex, int bLength)
{
	if (aLength != bLength) {
		return 0;
	}

	// '1' mean true. compare correct
	int result = 1;
	for (int i = aIndex; i < aLength; i +=1) {
		for (int j = bIndex; j < bLength; j += 1) {
			if (aArray[i] != bArray[j]) {
				result = 0;
				goto breakPoint;
			}
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
		for (int j = 0; j < numCountBySplit[i]; j += 1) {
			printf("%d ", compNumList[beginIndex[i] + j]);
		}
		printf("\n");
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
