#include <stdio.h>
#include <unistd.h>
#include "scheduler.h"

int main() {
  SchedulerData data;

  beginScheduler(&data);

  printf("\n--- ACXIUS Scheduler begin ---\n");

  while (1)
  {
    updateDate(&data);

    printf("Generate: ['%s', '%s, '%s']\n",
      data.msg,
      data.date,
      data.send
    );

    sleep(5);
  }

  return 0;
  
}