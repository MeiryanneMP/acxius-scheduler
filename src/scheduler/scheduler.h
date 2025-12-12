#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct
{
  char msg[32];
  char date[32];
  char send[4];
} SchedulerData;

void beginScheduler(SchedulerData *d);
void updateDate(SchedulerData *d);
void updateSend(SchedulerData *d);

#endif