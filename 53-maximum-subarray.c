int maxSubArray(int* nums, int numsSize){
    // Need two variables to keep track of current sum (at current index)
    // and a maximum sum (to be returned)
    int current_sum = nums[0];
    int maximum_sum = nums[0];

    // Base case where there is only 1 element in the array.
    if (numsSize == 1) {
        return maximum_sum;
    }
    
    // Iterate through the array and update the current sum
    for (int i = 1; i < numsSize; i++) {
    // As we iterate through the array, we add the value of the current index
    // to the current sum, and see; if the value is smaller,
    // reset the current sum.
    if (nums[i] > current_sum + nums[i]) {
        current_sum = nums[i];
    } else {
        current_sum += nums[i];
    }

    // Check if we need to update the maximum sum
    if (current_sum > maximum_sum) {
        maximum_sum = current_sum;
    }
    }
    return  maximum_sum;