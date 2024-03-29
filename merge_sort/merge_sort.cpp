#include <bits/stdc++.h>
using namespace std;

void merge_two_sorted_arrays(long long int array[], int const left, int const mid, int const right) 
{
    // Sub-array sizes
	int const sub_array_one = mid - left + 1;
	int const sub_array_two = right - mid;

	// Create temp arrays
	long long int *left_array = new long long int[sub_array_one];
	long long int *right_array = new long long int[sub_array_two];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
	for (int index = 0; index < sub_array_one; index++){
		left_array[index] = array[left + index];
	}

	for (int index = 0; index < sub_array_two; index++){
		right_array[index] = array[mid + index + 1];
	}

    /* Indices of the left, right and merged array*/
	int i = 0;
	int j = 0;
	int k = left;

	/* Merge the temp arrays back into array[left..right] */
	while(i < sub_array_one && j < sub_array_two){
		if(left_array[i] <= right_array[j]){
			array[k] = left_array[i];
			i++;
		}else{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of left[], if there are any */
	while(i < sub_array_one){
		array[k] = left_array[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of
	   right[], if there are any */
	while(j < sub_array_two){
		array[k] = right_array[j];
		j++;
		k++;
	}

	// Delete left and right sub-arrays
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(long long int array[], int const begin, int const end){
	if(begin >= end){
		return;
	}

	int q = floor((begin + end) / 2);

	merge_sort(array, begin, q);
	merge_sort(array, q + 1, end);
	merge_two_sorted_arrays(array, begin, q, end);
}
