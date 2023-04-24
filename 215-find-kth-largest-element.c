int findKthLargest(int* nums, int numsSize, int k){


    void swap(int* int1, int* int2) {
        int temp = *int1;
        *int1 = *int2;
        *int2 = temp;
    }

    // l and r are indices of the range where quickSelect is performed.
    // Returns value of pivot.
    int quickSelect(int l, int r) {
        // Set pivot as the right-most element.
        int pivot = nums[r];

        // Set pointer to where pivot is going to end up.
        int p = l;

        // Iterate through the range and determine which elements are smaller/equal to the pivot.
        for (int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(&nums[i], &nums[p]);
                p++;
            }
        }
        swap(&nums[p], &nums[r]);
        
        // Check which partition (left or right) to look at next.
        // Or, if the pivot is already the k-th largest element.
        if (p < numsSize - k) {
            return quickSelect(p + 1, r);
        } else if (p > numsSize - k) {
            return quickSelect(l, p - 1);
        } else {
            return pivot;
        }
    }


    return quickSelect(0, numsSize - 1);

}