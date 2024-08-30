#include <iostream>
/*

*/

#include <iostream>
#include <vector>
using namespace std;

bool twoPointersSum(vector<int> &nums, int N)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == N)
        {
            return true; // Encontramos dos números que suman el valor de N
        }
        else if (sum < N)
        {
            left++; // Incrementamos el puntero izquierdo
        }
        else
        {
            right--; // Decrementamos el puntero derecho
        }
    }

    return false; // No se encontraron dos números que sumen el valor de N
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(14);
    nums.push_back(15);

    int N = 13;

    if (twoPointersSum(nums, N))
    {
        cout << "Verdadero: Existen dos números que suman " << N << endl;
    }
    else
    {
        cout << "Falso: No existen dos números que sumen " << N << endl;
    }

    return 0;
}