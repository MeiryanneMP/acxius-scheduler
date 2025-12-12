#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "acxius_mail.h"

void sendEmail(const char *to, const char *subject, SchedulerData *data)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    char message[1024];
    
    snprintf(message, sizeof(message),
             "From: email@\n"
             "To: <%s>\n"
             "Subject: %s\n\n"
             "Generate: ['%s', '%s', '%s']\n",
             to, subject, data->msg, data->date, data->send);
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
        curl_easy_setopt(curl, CURLOPT_USERNAME, "email@");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "");

        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:465");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "meiryannempereira@gmail.com");
        
        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        
        curl_easy_setopt(curl, CURLOPT_READDATA, message);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Email sent to: %s\n", to);
        }

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
}
