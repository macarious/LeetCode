int maxSubArray(int* nums, int numsSize){

    if (numsSize == 1) {
        return nums[0];
    }

    // Iterate through the array once.
    // Two pointers: head, curr.
    // Store the max sum.
    // Store the curr sum.

    int curr;
    int sum = nums[0];
    int max_sum = nums[0];

    for (int curr = 1; curr < numsSize; curr++) {
        sum += nums[curr];
        if (sum < nums[curr]) {
            sum = nums[curr];
        }

        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;

}