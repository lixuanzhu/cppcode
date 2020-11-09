#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findContentChildren(vector<int>& children, vector<int>& cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child = 0 ,cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
        if (children[child] <= cookies[cookie]) child++;
        cookie++;
    }
    return child;
}

int candy(vector<int>& rating) {
    int size = rating.size();
    if(size < 2) return size;
    vector<int> num(size, 1);
    for (int i = 1; i < size; i++) {
        if(rating[i] > rating[i-1]) num[i] = num[i-1] +1;
    }
    for (int i = size - 1; i > 0; i--) {
        if(rating[i-1] > rating[i]) num[i-1] = max(num[i-1], num[i] + 1);
    }
    return accumulate(num.begin(), num.end(), 0);
}


int main()
{
    vector<int> ch {1,2};
    vector<int> co {1,2,3};
    vector<int> can{ 1,0,2 };

    std::cout << findContentChildren(ch, co) << "\n";
    std::cout << candy(can) << "\n";
}