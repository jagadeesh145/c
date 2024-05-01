#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define A_S 100
int main(){
    const int num_threads=5;
    int array[A_S];
    double sum=0.0;
    for(int i=0;i<A_S;++i){
        array[i]=i+1;
    }
    #pragma omp parallel num_threads(num_threads)shared(sum)
    {

        double local_sum=0.0;
        #pragma omp for
        for(int i=0;i<A_S;++i){
            local_sum+=array[i];
        }
        #pragma omp critical
        {

            sum+=local_sum;
        }
    }
    double average=sum/A_S;
    printf("average:%f\n",average);
    return 0;
}


