#include <pthread.h>
#include <stdio.h>

/* this data is shared by the thread(s) */
int threads;
unsigned long long iterations;
double * pi;

typedef struct {
int Count;
int Start;
} param_t;

void * runner(void * param); /* the thread */

int main(int argc, char * argv[]) {

        if (argc != 3) {
            fprintf(stderr, "usage: a.out <iterations> <threads>\n");
            /*exit(1);*/
            return -1;
        }
        if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0) {
            fprintf(stderr, "Arguments must be non-negative\n ");
                /*exit(1);*/
                return -1;
            }

	// Should probably be constants.
	int threads    = atoi(argv[2]);
	int iterations = atoi(argv[1]);
	
       

        /* create the thread identifiers */

    pthread_t thread_id = (pthread_t*)malloc(threads*sizeof(pthread_t));

        /* create set of attributes for the thread */

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // no need to change attributes

    // What parameters are even necessary? Threads just need to calculate the nth value of the summation and add it to the original pi value?
    // I guess the parameter is the max product value the thread will calculate?
    // So we're gonna calculate 100 iterations with 4 threads itd be
    // thread 1: 0 - 24
    // thread 2: 25- 49
    // thread 3: 50- 74
    // thread 4: 75- 99

    param_t *params = (param_t*)malloc(threads*sizeof(param_t));

    // Each threads gets what value they're gonna start at.
    for(int i=0; i<=threads-1;i++){
	params[i].Count = (int)((float)1/threads* iterations);
	params[i].Start = (int)((float)i/threads * iterations);
    }

// attribute needs to have max value calculated. Unless if I divy up the threads differently. Could make it so threads calculate 1,

    //pthread attr_t tattr;

    //for(int att=0; i<0;i++){
    //}
         /* populate variables... */
    

            /* get the default attributes */
            ...
            /* create threads */
    pthread_create(&thread_id, NULL, runner, NULL);
            ...
            /* now wait for the threads to exit */
            ...

              /* compute and print results */
              ...

              ...printf("pi = %.15f\n",...


        }
        /**
         * The thread will begin control in this function
         */
        void * runner(void * param) {
            int threadid=param;
        // Why would we ever use pithread[threadid] ???
        // Why not just add it to the global value of pi ???

            *pi += (pow((-1),param)) /(2*param+1);


            //complete function


            pthread_exit(0);
        }


