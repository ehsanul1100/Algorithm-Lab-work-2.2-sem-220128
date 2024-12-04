// tower of hanoi

#include <iostream>
using namespace std;
void towerOfHanoi(int disk, char source, char target, char auxiliary) {
    if (disk == 1) {
        cout << "Move disk 1 from " << source << " to " << target <<endl;
        return;
    }
    towerOfHanoi(disk - 1, source, auxiliary, target);
    cout << "Move disk " << disk << " from " << source << " to " << target << endl;
    towerOfHanoi(disk - 1, auxiliary, target, source);
}

int main() {
    int disk = 4; 
    towerOfHanoi(disk, 'A', 'C', 'B');
    return 0;
}

