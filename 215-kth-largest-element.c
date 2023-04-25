void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k){

    // Divide and conquer approach, using quick select.
    // Pick a pivot, put everything smaller than pivot on the left, and reaminder on right.
    // Compare index of pivot, and see whether the target index is left or right of pivot.

    // Target index.
    int t = numsSize - k;

    // Quick select, recursively.
    // Parameters: left index, right index.
    // Return: value of pivot.
    // Use the right most index as the pivot (random/arbitrary).
    int quickSelect(int l, int r) {
        int pivot = nums[r];
        int p = l; // keep track of all the elements which are smaller than pivot.
        for (int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(&nums[i], &nums[p]);
                p++;
            }
        }
        swap(&nums[p], &nums[r]);

        if (t < p) {
            return quickSelect(l, p - 1);
        } else if (t > p) {
            return quickSelect(p + 1, r);
        } else {
            return pivot;
        }
    }

    return quickSelect(0, numsSize - 1);

}