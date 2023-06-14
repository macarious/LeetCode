// Helper function to find maximum between two integers (a and b):
int max(int a, int b) {
    return (a > b)? a : b;
}

// Helper function to find minimum between two integers (a and b):
int min(int a, int b) {
    return (b > a)? a : b;
}

// Helper function for recursion:
// nums is the array pointer
// l is left index
// r is right index
int maxProductRecursion(int* nums, int l, int r) {
    // Base case:
    if (l == r) {
        return nums[l];
    }

    // Find mid index m.
    int m = (l + r) / 2;

    // Recursively find max product (left or mid and right of mid):
    int leftMax = maxProductRecursion(nums, l, m);
    int rightMax = maxProductRecursion(nums, m + 1, r);
    
    // Find max and min product that includes middle element:
    int productLeft = 1;
    int productLeftMax = INT_MIN;
    int productLeftMin = INT_MAX;
    for (int i = m; i >= l; i--) {
        productLeft *= nums[i];
        productLeftMax = max(productLeft, productLeftMax);
        productLeftMin = min(productLeft, productLeftMin);
    }
    int productRight = 1;
    int productRightMax = INT_MIN;
    int productRightMin = INT_MAX;
    for (int i = m + 1; i <= r; i++) {
        productRight *= nums[i];
        productRightMax = max(productRight, productRightMax);
        productRightMin = min(productRight, productRightMin);
    }
    int crossProduct1 = productLeftMax * productRightMax;
    int crossProduct2 = productLeftMin * productRightMin;
    int crossMax = max(crossProduct1, crossProduct2);

    // Return the maximum products:
    int result = max(leftMax, rightMax);
    return max(result, crossMax);
}


int maxProduct(int* nums, int numsSize){
    return maxProductRecursion(nums, 0, numsSize - 1);
}