// compile & run:     g++ -std=c++11 main.cpp -o main && ./main < input.txt > out.txt
// Problem Url: https://omegaup.com/arena/problem/OMI2018-Soumaya
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
  int x1, y1;
  int x2, y2;
};
const int movsX[4] = { -1, 0, 1, 0 };
const int movsY[4] = { 0, 1, 0, -1 };

int N,M;
vector<vector<bool>> matrix;
vector<vector<bool>> visited;
vector<Rectangle> figures;

void readMatrix() {
    // Read carefull as the integers are closed to each other, and reading INT will not work.
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char isPainted;
            cin>>isPainted;
            matrix[i][j] = isPainted == '1' ? true : false;
        }
    }
}

void printMatrix() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void expandRectangleWithCoord(int i, int j, Rectangle &figure) {
    figure.x1 = min(i, figure.x1);
    figure.y1 = min(j, figure.y1);
    figure.x2 = max(i, figure.x2);
    figure.y2 = max(j, figure.y2);
}

// Figure passed by reference to be modified, while in the dfs we expand it.
void dfs(int i, int j, Rectangle &figure) {
    // initialize the stack to start the dfs
    stack<pair<int,int>> canvaStack;
    canvaStack.push({i, j});

    while(!canvaStack.empty()) {
        pair<int,int> coord = canvaStack.top();
        canvaStack.pop();
        int x = coord.first;
        int y = coord.second;

        // Validate OUT OF BOUNDARY coordinates
        if (x<0 || x>=N || y<0 || y>=M) {
            continue;
        }
        // Validate if is already visited 
        if (visited[x][y]) {
            continue;
        }
        // Validate we are on a paint coord.
        if (matrix[x][y] == false) {
            continue;
        }

        // We process this coordinate and expand the current rectangle
        expandRectangleWithCoord(x,y,figure);

        // We add the neighbours to the DFS and continue
        for (int k = 0; k < 4; k++) {
            int newX = x + movsX[k];
            int newY = y + movsY[k];
            canvaStack.push({newX, newY});
        }

        // Mark as visited
        visited[x][y] = true;
    }
}

void findFiguresAndCalculateRectangles() {
    //ITERATE MATRIX AND FIND ONES (1), PER EACH ONE, DO A BFS TO CALCULATE RECTANGLE
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            bool isNotVisited = visited[i][j] == false;
            bool isPaintSquare = matrix[i][j] == true;

            if (isPaintSquare && isNotVisited) {
                Rectangle figure;
                figure.x1 = i;
                figure.y1 = j;
                figure.x2 = i;
                figure.y2 = j;
                dfs(i,j,figure);
                figures.push_back(figure);
            }
        }
    }
}

bool doOverlap(const Rectangle& a, const Rectangle& b) {
    return !(a.y1 > b.y2 + 1 || a.y2 < b.y1 - 1 || a.x1 > b.x2 + 1 || a.x2 < b.x1 - 1 ||
             (a.x2 == b.x1 - 1 && a.y1 == b.y2 + 1) ||
             (a.x1 == b.x2 + 1 && a.y1 == b.y2 + 1) ||
             (a.x2 == b.x1 - 1 && a.y2 == b.y1 - 1) ||
             (a.x1 == b.x2 + 1 && a.y2 == b.y1 - 1));
}

Rectangle mergeRectangles(const Rectangle& a, const Rectangle& b) {
    Rectangle merged;
    merged.x1 = min(a.x1, b.x1);
    merged.y1 = min(a.y1, b.y1);
    merged.x2 = max(a.x2, b.x2);
    merged.y2 = max(a.y2, b.y2);
    return merged;
}

void mergeOverlappingFigures() {
    bool pendingMerges = true;

    while (pendingMerges) {
        pendingMerges = false;

        vector<Rectangle> newRectangles;
        vector<bool> taken(figures.size(), false);

        for (int i=0; i<figures.size(); i++) {
            if (taken[i]) {
                continue;
            }

            for (int j = i+1; j<figures.size(); j++) {
                if (taken[j]) {
                    continue;
                }

                if (doOverlap(figures[i], figures[j])) {
                    newRectangles.push_back(mergeRectangles(figures[i], figures[j]));
                    taken[i] = taken[j] = true;
                    pendingMerges = true;
                    break; // Break to handle one merge at a time
                }
            }

            if (!taken[i]) {
                newRectangles.push_back(figures[i]);
            }
        }

        figures.swap(newRectangles); // Use the newly merged rectangles for the next iteration
    }
}

void drawFiguresInMatrix() {
    for (auto figure : figures) {
        for (int i=figure.x1; i <= figure.x2; i++) {
            for (int j=figure.y1; j <= figure.y2; j++) {
                matrix[i][j] = 1;
            }
        }
    }
}

int main() {
    // READ SIZE OF MATRIX
    cin>>N>>M;
    
    // ASSING SIZE TO OUR MATRIX AND ADD SPACE FOR BORDERS.
    matrix.resize(N, vector<bool>(M));
    visited.resize(N, vector<bool>(M));

    // READ THE MATRIX
    readMatrix();

    // PROCESS
    findFiguresAndCalculateRectangles();
    mergeOverlappingFigures();
    drawFiguresInMatrix();

    // PRINT
    printMatrix();
    return (0);
}
