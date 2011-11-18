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

#include "scheduler.h"
#include <stdio.h>
#include <ctime>

void test(int sig)
{
  static unsigned count = 0;
  printf("Alarm number %5u at %d\n", ++count, time(0));
}

int
main()
{
  unsigned int step = 10;
  unsigned int delay = 1;
  start_scheduler(&test, step);
  printf("Started the scheduler\n");
  for (;;){}
  return 0;
}
