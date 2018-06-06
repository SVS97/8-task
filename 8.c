#include <stdio.h>
#define N 1000
int max(int n, int m);
int max(int n, int m);

int main(void)
{
	int n ;								// Number of elements
	int wall[N];						// array 
	int i;								// counters

	printf("Number of elements n:\n");
	scanf_s("%i", &n);
	printf("Enter elements:\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%i", &wall[i]);
	} 
	for (i = 0; i < n; i++) 
	{
		printf("Elements: %d\n", wall[i]);	// printing elements
	}
		
			// left[N] contains height of tallest bar to the
			// left of N'th bar including itself
	int left[N];

		// Right [N] contains height of tallest bar to
		// the right of ith bar including itself
	int right[N];

		// Initialize result
	int water = 0;

	// Fill left array
		left[0] = wall[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], wall[i]);
	
	// Fill right array
	right[n - 1] = wall[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], wall[i]);


	// Calculate the accumulated water element by element
	// consider the amount of water on i'th bar, the
	// amount of water accumulated on this particular
	// bar will be equal to min(left[i], right[i]) - arr[i] .
	for (int i = 0; i < n; i++)
		water += min(left[i], right[i]) - wall[i];
	printf("Water: %i\n", water);						// O(n^2)
}

int max(m, n)
{
	
	int max = 0;
	
	if (m > n)
	{
		max = m;
	}
	else
		max = n;
	return max;
}

int min(m, n)
{

	int min = 0;

	if (m < n)
	{
		min = m;
	}
	else
		min = n;
	return min;
}

	
	

