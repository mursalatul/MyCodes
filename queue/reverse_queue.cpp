#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int>rev(queue<int>&q){
    stack<int>st;
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        st.push(ele);
    }
    while(!st.empty()){
        int ele=st.top();
        st.pop();
        q.push(ele);
    }return q;
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    rev(q);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" ";

    }
}