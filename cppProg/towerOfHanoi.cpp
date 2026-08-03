#include <bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n, char src, char aux, char dest) {
    if(n == 1) {
        cout<<"moved the disk 1 from "<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n - 1, src, dest, aux);

    cout<<"moved the disk "<<n<<" from "<<src<<" to "<<dest<<endl;

    towerOfHanoi(n-1, aux, src, dest);
}

int main() {
    
    towerOfHanoi(4, 'a', 'b', 'c');

    return 0;
}