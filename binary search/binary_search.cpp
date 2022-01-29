#include <vector>
#include <iostream>

int binary_search(std::vector <int> vec, int val)
{
    /*Perform binary search on sorted vector and return position of val*/

    // initializing start, end and middle point.
    int start = 0, end = vec.size() - 1, mid = (start + end) / 2;
    
    // find value until start or end or the middle position has the value
    while ((vec[start] != val) && (vec[end] != val) && (vec[mid] != val))
    {
        // when start + end / 2 = start return -1, means not found.
        if((start + end) / 2 == start) return -1;
        // if mid value < val, then val must be after this mid point.
        // so make start point = mid point and calculate new mid point. but
        // when mid value > val, then val must be before this mid point.
        // so make end point = mid point and calculate new mid point for further check
        if(vec[mid] < val)
        {
            start = mid;
            mid = (start + end) / 2;
        }
        else{
            end = mid;
            mid = (start + end) / 2;
        }
    }
    // return the position where val if founded.
    if (vec[start] == val) return start;
    else if (vec[end] == val) return end;
    else return mid;
}

int main(void)
{
    // test case
    std::vector <int> v { 1, 2, 3, 5, 6, 66, 77, 88, 456, 678, 890};
    std::cout << binary_search(v, 88) << "\n";
    std::cout << binary_search(v, 89) << "\n";
    return 0;
}