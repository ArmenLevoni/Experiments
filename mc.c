#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


int main()
{
    printf("INFO: Let's start...\n");

    long seed = 12345;
    float pi = 3.1415922653;

    unsigned int t;

    /* Intializes random number generator */
    srand(time(0));

    int npoints = 10000;
    int n, npointsinside;
    double x, y, r, sq, f, fsum, fmean, I;

    r = 1.0;
    fsum = 0.0;
    npointsinside = 0;
    for (n=0;n<npoints;n++){
        x = (rand() % 1000)/1000.*r;
        y = (rand() % 1000)/1000.*r;
        sq = x*x+y*y;
        if (sq<r*r) {
            f =sqrt(r*r-sq);
            fsum += f;
            npointsinside++;
        }
    }
    fmean = fsum/npointsinside;

    I = 2*pi*r*r*fmean;
    printf ("Sphers valume is: %.6f, %.6f %d\n", I, 4*pi/3, npointsinside);

    return 0;
}