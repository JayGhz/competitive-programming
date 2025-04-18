#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;
    queue<int> auxQueue;

    myQueue.push(1);
    myQueue.push(25);
    myQueue.push(3);
    myQueue.push(10);

    int size = myQueue.size();

    for(int i = size; i > 0; i--) {
        for(int j = 0; j < i-1; j++) {
            auxQueue.push(myQueue.front());
            myQueue.pop();
        }
        
        cout << myQueue.front() << " ";
        myQueue.pop();
        
        while(!auxQueue.empty()) {
            myQueue.push(auxQueue.front());
            auxQueue.pop();
        }
    }
}