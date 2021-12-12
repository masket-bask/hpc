#include <omp.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int sec, items, *allitems, total = 0, i, j, threads, thr;

    double start, end, clk;

    cout << "Enter the number of sections";
    cin >> sec;
    cout << "Enter the number of items";
    cin >> items;

    allitems = (int *)malloc(sec * items * sizeof(int));
    for (i = 0; i < sec; i++)
    {
        for (j = 0; j < items; j++)
        {
            allitems[i * items + j] = rand() % 1000;
        }
    }

    start = clock();

#pragma omp parallel for
    for (i = 0; i < sec * items; i++)
    {

#pragma omp critical {
        total += allitems[i];
    }
}

end = clock();

clk = (double)(end - start) / CLOCKS_PER_SEC;

cout << "Grand Total " << total << "\n";
cout << " Time \t" << clk * 1000 << "\n";
}