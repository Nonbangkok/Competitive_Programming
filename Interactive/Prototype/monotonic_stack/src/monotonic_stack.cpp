#include "monotonic_stack.h"
#include <stack>
using namespace std;

vector<int> next_smaller_elements(const vector<int>& arr) {
    vector<int> result;
    stack<int> st;
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>=arr[i])st.pop();
        if(st.empty())result.push_back(-1);
        else result.push_back(arr[st.top()]);
        st.push(i);
    }
    reverse(result.begin(),result.end());
    return result;
}
// cd monotonic_stack && make && ./build/main