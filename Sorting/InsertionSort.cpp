
void InsertionSort(int *arr, int n) // 숫자 배열, 원소 개수
{
	for(int i = 1; i < n; i++)
	{
		int target = arr[i], j;
		for(j = i - 1; j >= 0; j--)
		{
			if(arr[j] <= target)
				break;
			arr[j+1] = arr[j];
		}
		arr[j+1] = target;
	}
}