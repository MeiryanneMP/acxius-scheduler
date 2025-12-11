#include <stdio.h>
#include <stdlib.h>
#include "acxius_wifi.h"

void enable_wifi() {
    printf("Enable Wi-Fi...\n");
    system("nmcli radio wifi on");
}

void disable_wifi() {
    printf("Disable Wi-Fi...\n");
    system("nmcli radio wifi off");
}
