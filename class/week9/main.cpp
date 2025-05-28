#include <iostream>
#include <vector>
#include <cstdlib>
#define N 8

using namespace std;

vector<int> a(N);
vector<int> T(2*N);

void init(int node=1, int l=0, int r=N-1) {
    if(l == r) {
        T[node] = a[l];
    } else {
        int mid = (l+r)/2;
        init(node*2, l, mid);
        init(node*2+1, mid+1, r);
        T[node] = T[node*2] + T[node*2+1];
    }
}

void update(int x, int val, int node=1, int l=0, int r=N-1) {
    if(x < l || x > r) return;
    if(l == r) {
        T[node] = val;
        a[x] = val;
    } else {
        int mid = (l+r)/2;
        update(x, val, node*2, l, mid);
        update(x, val, node*2+1, mid+1, r);
        T[node] = T[node*2] + T[node*2+1];
    }
}

int query(int x, int y, int node=1, int l=0, int r=N-1) {
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) {
        return T[node];
    }
    int mid = (l+r)/2;
    return query(x, y, node*2, l, mid) + query(x, y, node*2+1, mid+1, r);
}

ostream& operator<<(ostream& os, vector<int>& v) {
    os << "[";
    for(int i = 0; i < v.size(); i++) {
        os << v[i];
        if(i < v.size()-1) os << ",";
    }
    os << "]";
    return os;
}

int main() {
    srand(42);
    for(int i = 0; i < a.size(); ++i) {
        a[i] = rand()%100;
    }
    cout << a << "\n";
    init();
    cout << T << "\n";
    update(5, 1);
    cout << T << "\n";
    
    cout << "Sum of range [2,5]: " << query(2, 5) << "\n";
    
    return 0;
}