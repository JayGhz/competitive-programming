#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int getSum(vector<int>& fw, int i) {
    int sum = 0;
    ++i;
    
    while (i > 0) {
        // sum += fw[i];
        ++sum;
        i -= i & -i;
    }

    return sum;
}

void updateFW(vector<int>& fw, int n, int i, int newVal) {
    ++i;
    while (i <= n) {
        fw[i] += newVal;
        i += i & -i;
    }
}

void constructFenwick(vector<int>& a, vector<int>& fw) {
    fw.resize(a.size() + 1);
    a[0] = 0;
    fw[0] = 0;
    for (auto i = 0; i < fw.size(); ++i) {
        fw[i] = 0;
    }
    for (auto i = 0; i < a.size(); ++i) {
        updateFW(fw, a.size(), i, a[i]);
    }
}

void printStuff(vector<int> &a, vector<int> &fw) {
    cout << setw(8) << "index"
        << setw(4) << "f"
        << setw(4) << "cf"
        << setw(4) << "fw" << '\n';
    int sum = 0;
    for (auto i = 0; i < a.size(); ++i) {
        sum += a[i];
        cout << setw(8) << i
            << setw(4) << a[i]
            << setw(4) << sum
            << setw(4) << fw[i] << '\n';
    }
    cout << setw(20) << fw[fw.size() - 1] << '\n';
}

int main(int argc, char const *argv[]) {
    
    int n = 1000000;
    vector<int> a(n);
    vector<int> fw;

    srand(42);
    for (auto i = 1; i < n; ++i) {
        a[i] = rand() % 10;
    }
    constructFenwick(a, fw);

    // printStuff(a, fw);

    cout << getSum(fw, 1000000) << '\n';

    return 0;
}