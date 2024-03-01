// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/OMI2018-Convertidor
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

long long int titleToNumber(string s) {
    long long int result = 0;
    for(char c : s) {
        long long int d = c - 'A' + 1;
        result = result * 26 + d;
    }
    return result;
}

string convertToTitle(long long int columnNumber) {
    string ans;
    
    while (columnNumber) {
        columnNumber--;
        ans = ans + (char)((columnNumber) % 26 + 'A');
        columnNumber = (columnNumber) / 26;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int op;
    cin>>op;

    if (op) {
        string title;
        cin>>title;
        cout<<titleToNumber(title)<<endl;
    } else {
        long long int number;
        cin>>number;
        cout<<convertToTitle(number)<<endl;
    }

    return 0;
}
