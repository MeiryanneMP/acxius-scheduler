#include <stdio.h>
#include <string.h>
#include <time.h>


#include "scheduler.h"

void beginScheduler(SchedulerData *d){
  strcpy(d-> msg, "Meiryanne");

  updateDate(d);

  strcpy(d->send, "não");
}

void updateDate(SchedulerData *d) {
  time_t now = time(NULL);
  struct  tm *tm_info = localtime(&now);

  strftime(d->date, 32, "%d%m%Y%H%M", tm_info);

}

void updateSend(SchedulerData *d){
  strcpy(d->send, "sim");
}

