#include "sorter_server.h"
#include "mergesort.c"

struct film movies[10000000];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int high = 0;
//_________________________________________________________________________________________________________________________________________

char *trim(char *string){
  char *trail;
  while(isspace((unsigned char)*string)) { string++; } 
  if(*string == 0){ return string; }
  trail = string + strlen(string) - 1;
  while(trail > string && isspace((unsigned char)*trail)) { trail--; }
  *(trail+1) = 0;
  return string;
}

struct film makeFilm(char* arr[]){
  struct film movie;
  movie.color = arr[0];
  movie.directorname = arr[1];
  movie.numcriticforreviews = atoi(arr[2]);
  movie.duration = atoi(arr[3]);
  movie.directorfacebooklikes = atoi(arr[4]);
  movie.actor3facebooklikes = atoi(arr[5]);
  movie.actor2name = arr[6];
  movie.actor1facebooklikes = atoi(arr[7]);
  movie.gross = atoi(arr[8]);
  movie.genres = arr[9];
  movie.actor1name = arr[10];
  movie.movietitle = arr[11];
  movie.numvotedusers = atoi(arr[12]);
  movie.casttotalfacebooklikes = atoi(arr[13]);
  movie.actor3name = arr[14];
  movie.facenumberinposter = atoi(arr[15]);
  movie.plotkeywords = arr[16];
  movie.movieimdblink = arr[17];
  movie.numuserforreviews = atoi(arr[18]);
  movie.language = arr[19];
  movie.country = arr[20];
  movie.contentrating = arr[21];
  movie.budget = atol(arr[22]);
  movie.titleyear = atoi(arr[23]);
  movie.actor2facebooklikes = atoi(arr[24]);
  movie.imdbscore = atof(arr[25]);
  movie.aspectratio = atof(arr[26]);
  movie.moviefacebooklikes = atoi(arr[27]);
  return movie;
}

//__________________________________________________________________________________________________________________________________________
void* tok(void* arg){
  char* str = (char*)arg;
  char* token;
  char *strArr[28];
  int i;
  int boolean = 0;
  for(i = 9; i < strlen(str); i++){ if(str[i] == '\"'){ boolean = 1; break; } }
    

  if(boolean == 1){//if quotes are in the movie title
    for (i = 0; i < 28; i++){//walk through the 28 tokens and store them
      if(i == 11){
	token = strsep(&str, "\"");
	token = trim(token);
 	token = strsep(&str, "\"");
	token = trim(token);
	strArr[i] = trim(token);
	token = strsep(&str, ",");
	token = trim(token);
      }
      
      else{//tokenize all other columns tokenize by commas
	token = strsep(&str, ",");
	token = trim(token);
	strArr[i] = trim(token);
      }
    }
  }
  
  
  
  else{//BOOL == FALSE, no quotes in movie title, only tokenize by commas
    for (i = 0; i<28; i++ ){
      token = strsep(&str, ",");
      token = trim(token);
      strArr[i] = trim(token);
    }
  }
  
  
  pthread_mutex_lock(&m);
  movies[high] = makeFilm(strArr);
  high++;
  pthread_mutex_unlock(&m);
  
  pthread_exit(0);
}
//_______________________________________________________________________________________________________________________________________

void* sort(void* arg){
  
  char* sortparam = (char*)arg;
  int low = 0;
  pthread_mutex_lock(&m); 
  high = high -1;
  
  if(strcmp(sortparam,  "color") == 0){ colorMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "director_name"  ) == 0){ directorNameMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "num_critic_for_reviews" ) == 0){ numCriticForReviewsMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "duration" ) == 0){ durationMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "director_facebook_likes" ) == 0){ directorFacebookLikesMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "actor_3_facebook_likes" ) == 0){ actor3FacebookLikesMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "actor_2_name" ) == 0){ actor2NameMergeSort(movies, low, high); }
  else if (strcmp(sortparam,  "actor_1_facebook_likes" ) == 0){ actor1FacebookLikesMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "gross" ) == 0){ grossMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "genres" ) == 0){ genresMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "actor_1_name" ) == 0){ actor1NameMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "movie_title" ) == 0){ movieTitleMergeSort(movies, low, high ); }
  else if (strcmp(sortparam, "num_voted_users" ) == 0){ numVotedUsersMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "cast_total_facebook_likes" ) == 0){ castTotalFacebookLikesMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "actor_3_name" ) == 0){ acotr3NameMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "facenumber_in_poster" ) == 0){ faceNumberInPosterMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "plot_keywords" ) == 0){ plotKeyWordsMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "movie_imdb_link"  ) == 0){ movieImdbLinkMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "num_user_for_reviews" ) == 0){ numUserForReviewsMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "language" ) == 0){ languageMergeSort(movies, low, high); }
  else if (strcmp(sortparam,  "country" ) == 0){ countryMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "content_rating" ) == 0){ contentRatingMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "budget" ) == 0){ budgetMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "title_year" ) == 0){ titleYearMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "actor_2_facebook_likes" ) == 0){ actor2FacebookLikesMergeSort(movies, low, high); }
  else if (strcmp(sortparam,  "imdb_score" ) == 0){ imdbScoreMergeSort(movies, low, high); }
  else if (strcmp(sortparam, "aspect_ratio" ) == 0){ aspectRatioMergeSort(movies, low, high); }
  else if (strcmp(sortparam,  "movie_facebook_likes" ) == 0){ movieFacebookLikesMergeSort(movies, low, high); }
  else{ printf("sort parameter is incorrect\n"); exit(0); }

  high = high+1;
  pthread_mutex_unlock(&m); 



  pthread_exit(0);
}
//==========================================================================================================================================
void *connection_handler(void *arg){

  //Get the socket descriptor
  int connfd = *(int*)arg;
  pthread_t tids[1000000];
  int i = 0;
  pthread_t tid;
  int n;
  int boolean = 0;
  
  //Receive a message from client
  while(1){ 
    char* buffer = (char*)malloc(sizeof(char)*20000);
    n =  read(connfd,buffer,20001);
    if(n<=0){ break; }
    if (strlen(buffer) <= 0){ break; }
    //---------------------------------------------------------------------------------------------------------------------------
    if(boolean == 0){ 
      if(strcmp(buffer, "merge") == 0){ boolean = 1; }
      else{
	pthread_create(&tids[i], NULL, tok, buffer);
	i++;
      }
    } 
    
    //----------------------------------------------------------------------------------------------------------------------------
    else{ 
      int j;
      for(j = 0; j < i; j++){ pthread_join(tids[j], NULL); }
      
      pthread_create(&tid, NULL, sort, buffer);
      pthread_join(tid, NULL);
  
      char rturn[1500];
      int z;
      rturn[0] = '\0';
      char output[50];
      int i;

      for (i =0; i<high; i++){
	strcat(rturn, movies[i].color);
	strcat(rturn, ",");
	strcat(rturn, movies[i].directorname);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].numcriticforreviews);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].duration);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].directorfacebooklikes);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].actor3facebooklikes);
	strcat(rturn, output);
	strcat(rturn, ",");
	strcat(rturn, movies[i].actor2name);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].actor1facebooklikes);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].gross);
	strcat(rturn, output);
	strcat(rturn, ",");
	strcat(rturn, movies[i].genres);
	strcat(rturn, ",");
	strcat(rturn, movies[i].actor1name);
	strcat(rturn, ",");
	strcat(rturn, "\"");
	strcat(rturn, movies[i].movietitle);
	strcat(rturn, "\"");
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].numvotedusers);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].casttotalfacebooklikes);
	strcat(rturn, output);
	strcat(rturn, ",");
	strcat(rturn, movies[i].actor3name);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].facenumberinposter);
	strcat(rturn, output);
	strcat(rturn, ",");
	strcat(rturn, movies[i].plotkeywords);
	strcat(rturn, ",");
	strcat(rturn, movies[i].movieimdblink);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].numuserforreviews);
	strcat(rturn, output);
	strcat(rturn, ",");
	strcat(rturn, movies[i].language);
	strcat(rturn, ",");
	strcat(rturn, movies[i].country);
	strcat(rturn, ",");
	strcat(rturn, movies[i].contentrating);
	strcat(rturn, ",");
	snprintf(output, 50, "%li", movies[i].budget);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].titleyear);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].actor2facebooklikes);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%f", movies[i].imdbscore);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%f", movies[i].aspectratio);
	strcat(rturn, output);
	strcat(rturn, ",");
	snprintf(output, 50, "%d", movies[i].moviefacebooklikes);
	strcat(rturn, output);
	
	usleep(5*1000);
	//write to client here
	write(connfd, rturn, strlen(rturn)+1);
	
	for(z=0; z<1500; z++){ rturn[z] = 0; }
	usleep(5*1000);
      }

      write(connfd, "end", 4);
    } 
      //-----------------------------------------------------------------------------------------------------------------------
  } 

  high=0; //------------------------------------------------------------------------------------------------------------------------------
  close(connfd);
  pthread_exit(0);
}

//==========================================================================================================================================
int main(int argc,char**argv){

  int portnum;

  if (argc<3) { printf("%s\n", "not enough params in command line" ); exit(0); }
  else if (strcmp(argv[1], "-p") == 0){ portnum = atoi(argv[2]); }
  else{ printf("%s\n", "Incorrect flag" );}

  int listenfd,connfd;
  socklen_t client;
  struct sockaddr_in servaddr,cliaddr;
  listenfd=socket(AF_INET,SOCK_STREAM,0);
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
  servaddr.sin_port=htons(portnum);
  bind(listenfd,(SA*)&servaddr,sizeof(servaddr));
  listen(listenfd,LISTENQ);
  client=sizeof(cliaddr);
  
  pthread_t tids[1000000];
  int i = 0;

  fprintf(stderr, "Received connections from: ");
  
  while(1){ 
    connfd=accept(listenfd,(SA*)&cliaddr,&client);
    if(connfd <= 0){ break; }
    struct in_addr addr = cliaddr.sin_addr;
    fprintf(stderr, "%s,", inet_ntoa(addr));    
    pthread_create( &tids[i] , NULL , connection_handler , (void*) &connfd);
    i++;
  }
  
  close(listenfd);
  return 0;
}
