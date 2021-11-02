
/**
 * By Jatin Vashisht.
 * Program to find the Nearest Greater Element to the left of each element of array.
 * It is a variation of NGR only, following changes have been made from code of NGR.
 * ** We will traverse the array from left instead of right.
 * ** We will not reverse the vectore before returning it.
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nGL(int* arr, int size){
    vector<int> result;
    stack<int> s;
    for(int i = 0; i<size; i++){
        if(s.empty()){
            result.push_back(-1);
        }else if(!s.empty() && s.top() > arr[i]){
            result.push_back(s.top());

        }else if(!s.empty() && s.top() <= arr[i]){
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                result.push_back(-1);
            }else{
                result.push_back(s.top());
            }
        }
        s.push(arr[i]);// we are pushing arr[i] in order to push current element onto stack also otherwise stack would not update and will give wrong output
    }
    
    return result;
}

int main(){
    int arr[5] = {9, 8, 5, 8, 5};
    vector<int> result = nGL(arr, 5);
    for(int i = 0; i<5; i++){
        cout<<result[i]<<" ";
    }
return 0;
}
