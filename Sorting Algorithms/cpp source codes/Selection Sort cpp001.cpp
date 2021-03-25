#include<iostream>
#include<cstdlib>
#include<algorithm>
void swap(int &x, int &y);

//process 1
void process_1(){
    int arr[]{64, 25, 12, 22, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i ++){
        int min_number = arr[i];
        int min_number_index = i;
        for(int j = i + 1; j < n; j ++){
            if(arr[j] < min_number){
                min_number = arr[j];
                min_number_index = j;
            }
        }
        swap(arr[i], arr[min_number_index]);
    }
    for(int i = 0; i < n; i ++){
        std::cout << arr[i] << " ";
    }
}
//

int main(){
    process_1();
return 0;
}
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y =  temp;
}
