#include <iostream>
#include <vector>
using namespace std;

//base condition for sortVector function
/**
 * @brief  Function to insert variable temp at its correct position
 * @param  &v: passing vector v by reference
 * @param  temp: variable that is to be inserted
 * @retval None
 */
void insert(vector<int> &v, int temp)
{
    // Base Condition
    if (v.empty() || v.back() >= temp)
    {
        v.push_back(temp);
        return;
    }
    int val = v.back();
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
}

/**
 * @brief  Function to sort vector
 * @param  &v: getting vector v by reference
 * @retval None
 */
void sortVector(vector<int> &v)
{
    // Base Condition
    if (v.size() == 1)
    {
        return;
    }
    int temp = v.back();
    v.pop_back();
    sortVector(v);
    // we also have to insert the temp variable back to vector v, to achieve that we make a call to insert function
    insert(v, temp);
}
/**
 * @brief  Function to print a vector
 * @param  v: vector that is to be printed
 * @retval None
 */
void print(vector<int> v){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    vector<int> v = {1,4,2,7,3,9};
    sortVector(v);
    print(v);
    return 0;
}