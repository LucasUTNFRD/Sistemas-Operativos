#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

sem_t empty;
sem_t full;
int buffer[MAX];
int fill = 0;
int use = 0;

// the problem:
/*
 * A producer should not produce items into the buffer when the consumer is
 * consuming an item from the buffer and vice versa. So the buffer should only
 * be accessed by the producer or consumer at a time.
 */

// put routine

void put(int value) {
  buffer[fill] = value;
  fill = (fill + 1) % MAX;
}

// get routine
int get() {
  int tmp = buffer[use];
  use = (use + 1) % MAX;
  return tmp;
}

void *producer(void *arg) {
  int item;
  while (1) {
    item = rand() % 100;
    put(item);
    printf("item produced: %d\n", item);
    sleep(1);
  }
}

void *consumer(void *arg) {
  int item;
  while (1) {
    item = get();
    printf("item consumed: %d\n", item);
    sleep(1);
  }
}

int main() {
  pthread_t producer_tid;
  pthread_t consumer_tid;

  // semaphore declaration

  sem_init(&empty, 0, MAX);
  sem_init(&full, 0, 0);

  // thread creation
  pthread_create(&producer_tid, NULL, producer, NULL);
  pthread_create(&consumer_tid, NULL, consumer, NULL);
  // thread completion
  pthread_join(producer_tid, NULL);
  pthread_join(consumer_tid, NULL);

  return 0;
}
