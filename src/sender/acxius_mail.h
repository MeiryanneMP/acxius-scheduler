#ifndef ACXIUS_MAIL_H
#define ACXIUS_MAIL_H

#include "scheduler.h"

void sendEmail(const char **to_list, int count, const char *subject, SchedulerData *data);

#endif
