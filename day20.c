#include <stdio.h>
#include <stdlib.h>

// Simple hash map using array (for constraints up to ~10^5 sum range)
// For safety, we shift index using offset

#define MAX 100000
#define OFFSET 100000   // to handle negative sums

int countZeroSumSubarrays(int arr[], int n) {
    int *freq = (int *)calloc(2 * MAX + 1, sizeof(int));
    
    int prefixSum = 0;
    int count = 0;

    freq[OFFSET] = 1;  // prefixSum = 0 already seen

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // if this sum seen before → add its frequency
        count += freq[prefixSum + OFFSET];

        // increase frequency
        freq[prefixSum + OFFSET]++;
    }

    free(freq);
    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);
    printf("%d\n", result);

    return 0;
}