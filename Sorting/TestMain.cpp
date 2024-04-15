#include <iostream>
#include <ctime>

#include "SortFuncs.hpp"

using namespace std;

static int* generateRandomArr(int& count);
static bool PrintArr(const char *title, int *arr, int count);

int main()
{
	int count;
	int *arr = generateRandomArr(count); // 랜덤 배열 생성

	PrintArr("Before: ", arr, count);
	
	// BubbleSort(arr, count);
	// InsertionSort(arr, count);
	// QuickSort(arr, count);

	// MergeSort(arr, 0, count - 1);
	// QuickSort(arr, 0, count - 1);

	// CountingSort(arr, count);
	// RadixSortLSD(arr, count);
	RadixSortMSD(arr, count);

	bool sorted = PrintArr("After: ", arr, count);
	cout << "[sorted] " << boolalpha << sorted << endl;

	delete[] arr;
	return 0;
}

static int* generateRandomArr(int& count)
{
	std::srand(std::time(nullptr)); // 현재 시간을 기반으로 랜덤 시드 초기화

	count = std::rand() % 100 + 1; // 랜덤 개수 (1 ~ 100 사이)

	int *arr = new int[count];
	for(int i = 0; i < count; i++)
		arr[i] = std::rand() % 1000; // 랜덤 숫자 (0 ~ 999 사이)
	
	return arr;
}

static bool PrintArr(const char *title, int *arr, int count)
{
	bool sorted = true;

	cout << title << ": " << endl;
	for(int i = 0; i < count; i++)
	{
		if (i+1 < count && arr[i] > arr[i+1])
			sorted = false;
		cout << arr[i] << ' ';
	}
	cout << endl;

	return sorted;
}
