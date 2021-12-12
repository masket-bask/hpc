#include <omp.h>
#include <iostream>
#include <time.h>
using namespace std;

#define n = 50;

int main()
{
    int n = 50, i;
    double a[1000] // unsigned long long int a[n];

        int n1,
        n2;

    double start, end;

    a[0] = 0;
    a[1] = 1;

    start = omp_get_wtime();

#pragma omp parallel shared(a) num_threads(2)
    {
#pragma omp single {
        cout << "Calculation \n";
        for (i = 2; i < n; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
            n1 = omp_get_thread_num();
        }
        cout << "Thread Number " << n1 << "\n";
    }

#pragma omp barrier
    {
#pragma omp single
        {
            for (i = 0; i < n; i++)
            {
                n2 = omp_get_thread_num();
                cout << a[i] << "\n"
            }
            cout << "Thread Number " << n2 << "\n";
        }
    }
}
end = omp_get_wtime();
cout << "Time Taken :" << end - start << endl;
}
