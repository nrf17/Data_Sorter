#ifndef _sorter_client_h
#define _sorter_client_h
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <sys/mman.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int checkdirectory(struct dirent *entries);
int checkcsv(char* string);
void* readSocket(void* arg);
void* callMerge(void* arg);
void* writeSocket(void* arg);
void* readdirectory(void* arg);

#endif
