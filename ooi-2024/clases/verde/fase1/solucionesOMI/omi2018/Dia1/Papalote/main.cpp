// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/OMI2018-Papalote#problems
//
// © Jose Garfias Lopez
//

#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Matrix;
vector<bool> FlippedRows;
vector<bool> FlippedColumns;
int N,M;

void readInput() {
	// Read Size (N*M) of the matrix
	cin>>N>>M;
	// Resize global vectors to fit N*M
	Matrix.resize(N, vector<int>(M));
	// Resize our additional arrays for saving flipped values;
	FlippedRows.resize(N+2, false);
	FlippedColumns.resize(M+2, false);
	// Read N*M numbers of Matrix
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin>>Matrix[i][j];
		}
	}
}

bool isFlipped(int i, int j) {
    bool isRowFlipped = FlippedRows[i];
    bool isColumnFlipped = FlippedColumns[j];

    if (isRowFlipped && isColumnFlipped) {
        // both are flipped so they cancel each other
        return false;
    }

    // return if one of the two is flipped. if both are not flipped we continue to return false.
    return isRowFlipped || isColumnFlipped;
}

void process() {
	// Iterate until we find the answer.
	bool matrixSumIsPositive = false;
	while(matrixSumIsPositive == false) {
		// We can asume matrixSumIsPositive for now, in later checks we are going to flip this value to negative if that is not the case, this is just for continue checking.
		matrixSumIsPositive = true;
        // Iterate rows and check if any of them needs flipping
		for (int i=0; i<N; i++) {
			// wee need to have the sum for the row stored temporaly to check if it is positive
			int rowSum = 0;
			for (int j=0; j<M; j++) {
				// Check if the current position is flipped, it means that the value for the actual cell is inverted.
				if (isFlipped(i,j)) {
					// We use the inverse of whatever we have on Matrix[i][j];
					rowSum -= Matrix[i][j];
				} else {
					// Cell is not flipped, we use the direct value
					rowSum += Matrix[i][j];
				}
			}
			// At the end of checking the row, we need to check if that row is fine or it needs to be flipped;
			if (rowSum < 0) {
				FlippedRows[i] = FlippedRows[i] == true ? false : true;
				matrixSumIsPositive = false;
			}
		}
		
		
		// Iterate columns and check if any of them needs fliiping
		for (int j=0; j<M; j++) {
            int columnSum = 0;
			for (int i=0; i<N; i++) {
			    // Check if the current position is flipped, it means that the value for the actual cell is inverted.
				if (isFlipped(i,j)) {
					// We use the inverse of whatever we have on Matrix[i][j];
					columnSum -= Matrix[i][j];
				} else {
					// Cell is not flipped, we use the direct value
					columnSum += Matrix[i][j];
				}
			}

            // At the end of checking the column, we need to check if that column is fine or it needs to be flipped;
			if (columnSum < 0) {
                // Flip the column by inverting the current value.
				FlippedColumns[j] = FlippedColumns[j] == true ? false : true;
				matrixSumIsPositive = false;
			}
		}
		
        // If after iterate all the matrix without having any negative integer, we can say that this is fixed.
        // current while loop will exit due to:  matrixSumIsPositive == true;
	}
}

// Check the Flipped arrays to construct the answer.
void printAnswer() {
    // Check flipped rows.
    int numberOfRows = 0;
    for (int i=0; i<N; i++) {
        if (FlippedRows[i]) {
            numberOfRows += 1;
        }
    }
    cout << numberOfRows << " ";
    for (int i = 0; i < N; i++) {
        if (FlippedRows[i]) {
            cout << (i + 1) << " ";
        }
    }
    cout << "\n";
    
    // Check flipped Columns.
    int numberOfColumns = 0;
    for (int j=0; j<M; j++) {
        if (FlippedColumns[j]) {
            numberOfColumns += 1;
        }
    }
    cout << numberOfColumns << " ";
    for (int j=0; j<M; j++) {
        if (FlippedColumns[j]) {
            cout << (j + 1) << " ";
        }
    }
    cout << "\n";
}

int main() {
	readInput();
	process();
	printAnswer();
	return 0;
}