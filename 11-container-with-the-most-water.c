int maxArea(int* height, int heightSize){

    // Two pointers (left most and right most indices).
    // Keep track of current maximum.
    // Iterate by moving the lower bar towards the centre until the two bars meet.

    int l = 0;
    int r = heightSize - 1;
    int max_area = 0;

    while (l < r) {
        int dist = r - l;
        int bar_height = 0;
        if (height[l] > height[r]) {
            bar_height = height[r];
            r--;
        } else {
            bar_height = height[l];
            l++;
        }

        int area = dist * bar_height;

        if (area > max_area) {
            max_area = area;
        }
    }
    return max_area;

}