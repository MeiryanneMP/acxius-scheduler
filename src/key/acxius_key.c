#include <stdio.h>
#include "acxius_key.h"
#include "scheduler.h"

void sendKey(SchedulerData *d){
  updateSend(d);
  printf("AcxiusKey: Send key...");
}