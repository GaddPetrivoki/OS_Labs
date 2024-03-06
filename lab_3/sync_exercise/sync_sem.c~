#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

// FOR SLEEP NEED THIS

#include <unistd.h>

#define BUFFER_SIZE 20


//pthread_mutex_t mutexBuffer;
//pthread_cond_t condBuffernotFull;
//pthread_cond_t condBuffernotEmpty;

sem_t semFull;
sem_t semEmpty;

int iInserts = 0;
int iRemoves = 0;

int count = 0;
int buffer [BUFFER_SIZE];

int producerIndex = 0;
int consumerIndex = 0;

pthread_t tid;

typedef struct {
int threadCount;
} param_t;

void insert(int item){
   sem_wait(&semEmpty);

 //  pthread_mutex_lock(&mutexBuffer);
   buffer[count] = item;
   count++;
  // pthread_mutex_unlock(&mutexBuffer);
   sem_post(&semFull);
   sleep(1); 
}

int remove_item(){
   int item;

   sem_wait(&semFull);
   //pthread_mutex_lock(&mutexBuffer);
   item = buffer[count-1];
   count--;

   //pthread_mutex_unlock(&mutexBuffer);
   sem_post(&semEmpty);
   sleep(1); 
   return item;
}
void * producer(void * param){
   int item;

   while(1){
   item = rand() % BUFFER_SIZE ;
      insert(item);
      iInserts++;
      printf("in: %d inserted: %d\n",iInserts, item);
	
   }

}

void * consumer(void * param){
   int item;
   param_t *p = (param_t*)param;
   while(1){
   	item = remove_item();
	iRemoves++;	
   	printf("out: %d removed: %d\n",iRemoves, item);
   }
 
}

int main(int argc, char * argv[])
{
    int producers = atoi(argv[1]);
    int consumers = atoi(argv[2]);
    int i;

    // array of threads
    pthread_t tid_producer[producers];
    pthread_t tid_consumer[consumers];

    // Initialize mutex 
    //pthread_mutex_init(&mutexBuffer, NULL);
    
    //pthread_cond_init(&condBuffernotFull,NULL);
    //pthread_cond_init(&condBuffernotEmpty,NULL);

    sem_init(&semEmpty, 0, BUFFER_SIZE);
    sem_init(&semFull, 0, 0);


    param_t *params = (param_t*)malloc((producers+consumers) * sizeof(param_t));
    for (i=0; i<(producers+consumers);i++)
	params[i].threadCount = i+1;

    for (i = 0; i < producers; i++)
       pthread_create(&tid_producer[i], NULL, producer,&params[i]);

    for (i = 0; i < consumers; i++)
       pthread_create(&tid_consumer[i], NULL, consumer,&params[i]);

    for (i = 0; i < producers; i++)
	pthread_join(tid_producer[i],NULL);
    for (i = 0; i < consumers; i++)
    	pthread_join(tid_consumer[i],NULL);
     
    // Free up mutex
    //pthread_mutex_destroy(&mutexBuffer);
    //pthread_cond_destroy(&condBuffernotFull);
    //pthread_cond_destroy(&condBuffernotEmpty);

    // Sem destroy
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);


}

