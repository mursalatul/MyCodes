#include<iostream>
#include<cstdlib>

int main(){

int arr[]{9, 5, 3, 6, 4, 2, 1, 8, 7};
int n = sizeof(arr) / sizeof(arr[0]);

for(int i = 0; i < n; i ++){
    for(int j = 0; j < n - 1 - i; j++){
        if(arr[j] > arr[j + 1]){

            std::swap(arr[j], arr[j + 1]);
        }std::cout<<"\n" << n - 1 - i<<"\n";
    }
}
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++){
    std::cout << arr[i] << " ";
}
return 0;
}
