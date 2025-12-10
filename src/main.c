#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "scheduler.h"
#include "acxius_key.h"

int main() {
  SchedulerData data;

  beginScheduler(&data);

  printf("\n--- ACXIUS Scheduler begin ---\n");

  int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

  while (1)
  {
    char buffer[32];

    if (fgets(buffer, sizeof(buffer), stdin) != NULL){
      if (buffer[0] == 's' || buffer[0] == 'S') {
        sendKey(&data);
      }
    }
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