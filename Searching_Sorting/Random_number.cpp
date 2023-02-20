#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 100;
    int lower = 1, upper = 100;

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(lower, upper);
    for (int i = 0; i < n; i++)cout << distr(eng) << " ";
}
