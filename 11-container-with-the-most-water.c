int maxArea(int* height, int heightSize){

    int left_pos = 0;
    int right_pos = heightSize - 1;
    int max_area;

    // When heightSize == 2
    if (heightSize == 2) {
        max_area = height[left_pos] * height[right_pos];
    }

    // Iterate through all bars by moving the left and right positions.
    // Move the bar with the least height towards the other bar.
    // Stop iterating just before the left and right bars meet.


    while (left_pos < right_pos) {
        int current_area;
        int left_height = height[left_pos];
        int right_height = height[right_pos];
        int distance = right_pos - left_pos;

        if (left_height > right_height) {
            current_area = right_height * distance;
            right_pos--;
        } else {
            current_area = left_height * distance;
            left_pos++;
        }

        if (current_area > max_area) {
            max_area = current_area;
        }
    }

    return max_area;