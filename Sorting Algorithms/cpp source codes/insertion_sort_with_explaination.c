#include <stdio.h>

void insertion_sort(int array[], int n)
{
    int key, i, j;
    for (i = 1; i < n; i ++)
    {
        /* storing terget value(array[i]) cause if its previous
         value is greater then it then we have to push back the 
         value to make a space for this value. at this time its
          previous value will be at this element position and it
           will be vanish. so we are storing it for ferther use.*/
        key = array[i];

        /*we will check previous elements of array[i], so we are
         storing index of its previous element's index.*/
        j = i - 1;

        /*j >= 0 is a fullstop which will check if the range dont
         overfollow.cause index cant be less then 0 in c/c++.
        if key's previous element is less then key we will copy 
        that position's element and store in next position for 
        make a space. we will do this tast again and again until 
        key is not less then its previous value. when key not 
        less, we will paste key at the space after the value.
         this is why we always push greater element , so that
          in time we can get the sit to paste key.*/
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j --;
        }
        array[j + 1] = key;
    }
}

int main(void)
{
    int i, n = 6;
    int array[] = {5, 4, 6, 3, 2, 1};
    printf("Before Insertion sort: ");
    for (i = 0; i < 6; i ++)
    {
        printf("%d, ", array[i]);
    }

    insertion_sort(array, n);
    printf("\n\nAfter Insertion Sort: ");
    for (i = 0; i < 6; i ++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    return 0;
}