#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <unistd.h>
#include <sched.h>

#include "geopm.h"

int main(int argc, char **argv)
{
    int lrank, nranks;
    int *list_of_rankids = NULL;
    char host[64];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &lrank);
    MPI_Comm_size(MPI_COMM_WORLD, &nranks);
    gethostname(host, 64);

    printf("My rank ID is %d. There are %d ranks.\n", lrank, nranks);

    if (lrank == 0) {
        list_of_rankids = new int[nranks];
    }

    int err = MPI_Gather(&lrank, 1, MPI_INT, list_of_rankids, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (lrank == 0 && err != MPI_SUCCESS) {
        printf("MPI err %d\n", err);
    }

    printf("Receiving rank %d on %s CPU %d\n", lrank, host, sched_getcpu());
    if (lrank == 0) {
        for (int i = 0; i < nranks; i++) {
            printf("%d ", list_of_rankids[i]);
        }
        printf("\n");
        delete [] list_of_rankids;
    } 
    
    MPI_Finalize();
    return 0;
}
