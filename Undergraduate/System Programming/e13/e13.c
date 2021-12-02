#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

int pointInCircle=0;
double rad=1.0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *threadFunc(void* arg)
{
    int* points = (int*) arg;
    int count=0; 

    for(int i=0;i<(*points);i++)
    {
        pthread_mutex_lock(&m);
        double x = (double)rand() / RAND_MAX; // 0-1
        double y = (double)rand() / RAND_MAX; // 0-1
        double distance = sqrt(x*x+y*y); 
        if(distance<rad)
            count++;
        pthread_mutex_unlock(&m);
    }

    pointInCircle+=count;

    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    int numOfThread=atoi(argv[1]);
    int numOfPoints=atoi(argv[2]);

    srand(time(NULL));
    float pi;

    pthread_t tid[numOfThread];
    int cnt[numOfThread];

    for(int i=0;i<numOfThread;i++)
        pthread_create(&tid[i],NULL,threadFunc,(void*)(&numOfPoints));
    for(int i=0;i<numOfThread;i++)
        pthread_join(tid[i],NULL);

    pi = (float)4*pointInCircle/(numOfThread*numOfPoints);


    printf("%f\n",pi);
    return 0;
}