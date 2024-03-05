#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

// FOR SLEEP NEED THIS

#include <unistd.h>

#define BUFFER_SIZE 20

pthread_mutex_t mutexBuffer;
int count = 0;
int buffer [BUFFER_SIZE];

pthread_t tid;

typedef struct {
int threadCount;
} param_t;

void insert(int item){
   while (count == BUFFER_SIZE);
   pthread_mutex_lock(&mutexBuffer);
   buffer[count] = item;
   count++;
   pthread_mutex_unlock(&mutexBuffer);
   sleep(1); 
}

int remove_item(){
   int item;
   while (count == 0);

	pthread_mutex_lock(&mutexBuffer);
	item = buffer[count];
	count--;

	pthread_mutex_unlock(&mutexBuffer);
   sleep(1); 
   return item;
}
void * producer(void * param){
   int item;
   param_t *p = (param_t*)param;
   while(1){

      item = rand() % BUFFER_SIZE ;
      if(count < BUFFER_SIZE){
      insert(item);
     
      printf("in: %d inserted: %d\n",p->threadCount, item);
	}

   }

}

void * consumer(void * param){
   int item;
   param_t *p = (param_t*)param;
   while(1){

	if(count > 0) { 
   	item = remove_item();
   	printf("out: %d removed: %d\n",p->threadCount, item);
	}

   }
 
}

int main(int argc, char * argv[])
{
    int producers = atoi(argv[1]);
    int consumers = atoi(argv[2]);
    int i;

    // Initialize mutex 
    pthread_mutex_init(&mutexBuffer, NULL);

    param_t *params = (param_t*)malloc(producers+consumers * sizeof(param_t));
    for (i=0; i<producers+consumers;i++)
	params[i].threadCount == i;

    for (i = 0; i < producers; i++)
       pthread_create(&tid, NULL, producer,&params[i]);

    for (i = 0; i < consumers; i++)
       pthread_create(&tid, NULL, consumer,&params[i]);

	for (i = 0; i < producers+ consumers; i++)
		pthread_join(tid,NULL);
    // Free up mutex
    pthread_mutex_destroy(&mutexBuffer);
}

