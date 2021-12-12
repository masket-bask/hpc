#include <omp.h>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    int i, j, n = 1000

              vector<vector<int>>
                  vect(n, vector<int>(n));
    int x = 500 double start, end, clk;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            vect[i][j] = rand() % 1000;
        }
    }

    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }

    start = clock();
#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = a[i][j] * a[i];
        }
    }

    end = clock();

    clk = (double)(end - start) / CLOCKS_PER_SEC;

    cout << " Time \t" << clk * 1000 << "\n";
}