#include "SortFuncs.hpp"
#include <cmath>

static int getMaxDigits(int *arr, int count);
static void Recursive(int *arr, int count, int exp);

void RadixSortMSD(int *arr, int count)
{
	int max_digits = getMaxDigits(arr, count);
	int highest_exp = pow(10, max_digits - 1);

	Recursive(arr, count, highest_exp);
}

static int getMaxDigits(int *arr, int count)
{
	int max = *std::max_element(arr, arr + count);
	int digits = 0;
	while (max > 0) {
		digits += 1;
		max /= 10;
	}
	return digits;
}

static void Recursive(int *arr, int count, int exp)
{
	if (count <= 1 || exp < 1)
		return;
	
	int counting[10] = {0};
	for(int i = 0; i < count; i++)
	{
		int digit = (arr[i] / exp) % 10;
		counting[digit] += 1;
	}

	int *buckets[10];
	for(int i = 0; i < 10; i++)
		buckets[i] = new int[counting[i]];
	
	int bucket_sizes[10] = {0};
	for(int i = 0; i < count; i++)
	{
		int digit = (arr[i] / exp) % 10;
		int index = bucket_sizes[digit]++;
		buckets[digit][index] = arr[i];
	}

	int index = 0;
	for(int i = 0; i < 10; i++)
	{
		Recursive(buckets[i], bucket_sizes[i], exp / 10);
		for(int j = 0; j < bucket_sizes[i]; j++)
			arr[index++] = buckets[i][j];
		delete[] buckets[i];
	}
}
