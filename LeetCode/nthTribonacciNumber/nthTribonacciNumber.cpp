class Solution {
public:
	int arr[38] = {};
	int tribonacci(int n)
	{
		arr[0] = 0;
		arr[1] = arr[2] = 1;

		for (int i = 0; i < n && i < 35; i++)
			arr[i + 3] = arr[i] + arr[i + 1] + arr[i + 2];

		return arr[n];
	}
};
