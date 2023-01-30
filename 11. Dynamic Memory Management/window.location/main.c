#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

Location *parse_url(char *url) {
    int dashNum = 0;
    for (int i = 0 ; i < strlen(url) ; i++) {
        if (url[i] == '/') {
            dashNum++;
        }
    }

    Location *p = malloc(sizeof(Location));
    p->protocol = strtok(url, ":");

    url = strtok(NULL, " ");

    if (dashNum > 2) { // pathname exists
        char *hostAndPort = strtok(url, "/");

        url = strtok(NULL, " ");

        p->host = strtok(hostAndPort, ":");
        char *port = strtok(NULL, ":");
        if (port == NULL) {
            p->port = 0;
        } else {
            p->port = strtol(port, NULL, 10);
        }

        p->pathname = "";
        p->search = "";
        p->hash = "";

        if (url[0] != '?' && url[0] != '#') { // contain pathname
            if (strchr(url, '?') != NULL && strchr(url, '#') != NULL) { // contain search & hash
                p->pathname = strtok(url, "?");
                url = strtok(NULL, " ");
                p->search = strtok(url, "#");
                p->hash = strtok(NULL, " ");
                p->hash[strlen(p->hash) - 1] = 0;
                return p;
            } else if (strchr(url, '?') != NULL && strchr(url, '#') == NULL) { // only contain search
                p->pathname = strtok(url, "?");
                p->search = strtok(NULL, " ");
                p->search[strlen(p->search)-1] = 0;
                return p;
            } else if (strchr(url, '?') == NULL && strchr(url, '#') != NULL) { // only contain hash
                p->pathname = strtok(url, "#");
                p->hash = strtok(NULL, " ");
                p->hash[strlen(p->hash)-1] = 0;
                return p;
            } else { // contain no search nor hash
                p->pathname = url;
                p->pathname[strlen(p->pathname)-1] = 0;
                return p;
            }
        }
    } else { //pathname dne
        p->pathname = "";
        p->search = "";
        p->hash = "";

        url = strtok(url, "/");
        if (strchr(url, ':') == NULL) { // port dne
            p->port = 0;
            if (strchr(url, '?') == NULL && strchr(url, '#') == NULL) { // search & hash dne
                p->host = url;
                p->host[strlen(p->host)-1] = 0;
                return p;
            } else if (strchr(url, '?') != NULL && strchr(url, '#') == NULL) { //search exists but hash dne
                p->host = strtok(url, "?");
                p->search = strtok(NULL, " ");
                p->search[strlen(p->search)-1] = 0;
                return p;
            } else if (strchr(url, '?') == NULL && strchr(url, '#') != NULL) { //search dne but hash exists
                p->host = strtok(url, "#");
                p->hash = strtok(NULL, " ");
                p->hash[strlen(p->hash) - 1] = 0;
                return p;
            } else { // search & hash exists
                p->host = strtok(url, "?");
                url = strtok(NULL, " ");
                p->search = strtok(url, "#");
                p->hash = strtok(NULL, " ");
                p->hash[strlen(p->hash) - 1] = 0;
                return p;
            }
        } else { // port exists
            p->host = strtok(url, ":");
            url = strtok(NULL, " ");

            if (strchr(url, '?') == NULL && strchr(url, '#') == NULL) { // search & hash dne
                p->port = strtol(url, NULL, 10);
                return p;
            } else if (strchr(url, '?') != NULL && strchr(url, '#') == NULL) { //search exists but hash dne
                char* port = strtok(url, "?");
                p->port = strtol(port, NULL, 10);
                p->search = strtok(NULL, " ");
                p->search[strlen(p->search)-1] = 0;
                return p;
            } else if (strchr(url, '?') == NULL && strchr(url, '#') != NULL) { //search dne but hash exists
                char* port = strtok(url, "#");
                p->port = strtol(port, NULL, 10);
                p->hash = strtok(NULL, " ");
                p->hash[strlen(p->hash) - 1] = 0;
                return p;
            } else { // search & hash exists
                char* port = strtok(url, "?");
                p->port = strtol(port, NULL, 10);
                url = strtok(NULL, " ");
                p->search = strtok(url, "#");
                p->hash = strtok(NULL, " ");
                p->hash[strlen(p->hash) - 1] = 0;
                return p;
            }
        }
    }
}