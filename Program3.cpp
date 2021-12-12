#include <omp.h>
#include <iostream>
#include <time.h>
using namespace std;

#define NUM_THREADS = 4;
int num_step = 1000;
double step;

int main()
{
    int i, nthreads;
    double pi = 0.0, sum[NUM_THREADS];
    step = 1.0 / (double)num_step;

    omp_set_num_threads(4);

#pragma omp parallel for
    {
        int i, id, nt;
        double x;

        id = omp_get_thread_num();
        nt = omp_get_num_threads();

        if (id == 0)
            nthreads = nt;
        sum[id] == 0.0;

        for (i = id; i < num_step; i += nt)
        {
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x * x);
        }

        for (i = 0; i < nthreads; i++)
        {
            pi += sum[i] * step;
        }
    }

    cout << "The Value of PI is " << pi << "\n";
}