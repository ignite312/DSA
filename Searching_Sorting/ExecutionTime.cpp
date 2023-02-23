#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    auto start_time = high_resolution_clock::now();

    int x = 0;
    for(int i = 0; i < 1000000; i++) {
        x+=i;
    }
    cout << x << "\n";

    auto end_time = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end_time - start_time);
    auto duration2 = duration_cast<microseconds>(end_time - start_time);
    cout << "Total runtime: " << duration1.count() << " ms" << endl;
    cout << "Total runtime: " << duration2.count() << " microseconds\n";
}
