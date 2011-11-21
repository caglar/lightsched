/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2011 03:35:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include "scheduler.h"

static sighandler_t __handler = NULL;
static sem_t __semAlarm;
static unsigned count = 0;

static void *
waitForAlarm (void *)
{
  for (;;) {
    count--;
    printf("Inside thread %lu, %d\n", pthread_self(), count);
    sem_wait(&__semAlarm); // Lock the semaphore
  }
  return NULL;
}

static void
test_handler (int sig)
{
  if (sig == SIGALRM) {
    printf("Alarm number %5u at %lu\n", ++count, time(0));
    sem_post(&__semAlarm); //Unlock the semaphore
  } else if (__handler)
    __handler(sig);
}

int
main()
{
  unsigned int step = 3;
  unsigned int delay = 1;
  pthread_t thread;
  start_scheduler(&test_handler, step);
  printf("Started the scheduler\n");
  if (pthread_create(&thread, NULL, waitForAlarm, NULL) != 0)
  {
    perror(strerror(errno));
    return EXIT_FAILURE;
  }
  for (;;) { }
  pthread_join(thread, NULL);
  return EXIT_SUCCESS;
}
