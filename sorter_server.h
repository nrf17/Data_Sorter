#ifndef _sorter_server_h
#define _sorter_server_h
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

#define SA struct sockaddr
#define LISTENQ 5

struct film{
  char *color;
  char *directorname;
  int numcriticforreviews;
  int duration;
  int directorfacebooklikes;
  int actor3facebooklikes;
  char *actor2name;
  int actor1facebooklikes;
  int gross;
  char *genres;
  char *actor1name;
  char *movietitle;
  int numvotedusers;
  int casttotalfacebooklikes;
  char *actor3name;
  int facenumberinposter;
  char *plotkeywords;
  char *movieimdblink;
  int numuserforreviews;
  char *language;
  char *country;
  char *contentrating;
  long budget;
  int titleyear;
  int actor2facebooklikes;
  float imdbscore;
  float aspectratio;
  int moviefacebooklikes;	
};

char *trim(char *string);
struct film makeFilm(char* arr[]);
void *connection_handler(void *arg);
void* sort(void* arg);
void* tok(void* arg);

#endif
