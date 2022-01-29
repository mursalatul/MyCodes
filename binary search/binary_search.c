#include <stdio.h>


int binary_search(int arr[], int size_of_arr, int val)
{
    /*Perform binary search on sorted arr and return position of val*/

    // initializing start, end and middle point.
    int start = 0, end = size_of_arr - 1, mid = (start + end) / 2;

    // find value until start or end or the middle position has the value
    while ((arr[start] != val) && (arr[end] != val) && (arr[mid] != val))
    {
        // when start + end / 2 = start, it means start and end neibours now.
        // and loop still open means start and end not equal to val. 
        // so return -1(means not found)
        if((start + end) / 2 == start) return -1;
        // if mid value < val, then val must be after this mid point.
        // so make start point = mid point and calculate new mid point. but
        // when mid value > val, then val must be before this mid point.
        // so make end point = mid point and calculate new mid point for further check
        if(arr[mid] < val)
        {
            start = mid;
            mid = (start + end) / 2;
        }
        else{
            end = mid;
            mid = (start + end) / 2;
        }
    }
    // if loop break without return -1 thats means val found
    // return the position where val if founded.
    if (arr[start] == val) return start;
    else if (arr[end] == val) return end;
    else if (arr[mid] == val) return mid;
}

int main(void)
{
    // test case
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);

    printf("%d\n%d", binary_search(array, size ,7), binary_search(array, size,  11));
    
    return 0;
}