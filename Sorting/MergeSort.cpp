static void Merge(int *arr, int start, int mid, int end);

void MergeSort(int *arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}

static void Merge(int *arr, int start, int mid, int end)
{
	int *sorted = new int[end + 1];
	int left = start;
	int right = mid + 1;
	int i = start;

	while (left <= mid && right <= end)
	{
		if (arr[left] < arr[right])
			sorted[i++] = arr[left++];
		else
			sorted[i++] = arr[right++];
	}

	while (left <= mid)
		sorted[i++] = arr[left++];
	while (right <= end)
		sorted[i++] = arr[right++];

	for(i = start; i <= end; i++)
		arr[i] = sorted[i];
	delete[] sorted;
}
