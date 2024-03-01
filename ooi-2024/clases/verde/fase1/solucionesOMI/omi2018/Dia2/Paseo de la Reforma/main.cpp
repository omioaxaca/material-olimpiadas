// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/OMI2018-Reforma#problems
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    vector<int> numbers;

    // READ
    cin>>n;
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        numbers.push_back(x);
    }


    // PROCESS
    int currentMax = 0;
    int pastBuilding = numbers[0];
    int size = 0;

    for (int i=1; i<n; i++) {
        if (numbers[i] < pastBuilding) {
            size++;
        } else {
            currentMax = max(currentMax, size);
            size = 0;
        }
        pastBuilding = numbers[i];
    }

    currentMax = max(currentMax, size);

    // PRINT 
    cout<<currentMax+1<<endl;

    return 0;
}
