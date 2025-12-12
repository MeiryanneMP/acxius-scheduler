#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "scheduler.h"
#include "acxius_key.h"
#include "acxius_mail.h"
#include "acxius_wifi.h"

#ifdef __cplusplus
extern "C" {
#endif

void testFaceDetection();

#ifdef __cplusplus
}
#endif

int main() {
    SchedulerData data;

    beginScheduler(&data);

    printf("\n--- ACXIUS Scheduler begin ---\n");

    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    testFaceDetection();

    while (1) {
        char buffer[32];

        if (fgets(buffer, sizeof(buffer), stdin) != NULL){
            if (buffer[0] == 's' || buffer[0] == 'S') {
                sendKey(&data);
            }
        }

        updateDate(&data);

        printf("Generate: ['%s', '%s', '%s']\n",
            data.msg,
            data.date,
            data.send
        );

        if (strcmp(data.send, "sim") == 0) {
            enable_wifi();
            // sendEmail("email@", "ACXIUS Scheduler Update", &data);
        }

        sleep(5);
    }

    return 0;
}
