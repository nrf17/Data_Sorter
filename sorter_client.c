#include "sorter_client.h"

char* portnum = NULL;
char* sortparam = NULL;
char* hostname = NULL;
char* outpath = NULL;

int sockfd;

int checkdirectory(struct dirent *entries){
  if( (strcmp(entries->d_name, "..") == 0) || (strcmp(entries->d_name, ".") == 0)  ){ return 0; }
  else if (entries->d_type == DT_DIR ){ return 1; }
  else{ return 0; }
}
int checkcsv(char* string){
  int x = 0;//intially set to false, if ends in .csv, set to true
  if (string[strlen(string)-4] == '.') { if (string[strlen(string)-3] == 'c') { if (string[strlen(string)-2] == 's') { 
	if (string[strlen(string)-1] == 'v') { x = 1; }
      }
    }
  }
  return x;
}
//-------------------------------------------------------------------------------------------------------------------------------------------

void* readSocket(void* arg){
  
  char* str = (char*)arg;
  usleep(5*1000);
  write(sockfd,str, strlen(str)+1 );
  usleep(5*1000);

  char* columns[28];
  columns[0] = "color";
  columns[1] = "director_name";
  columns[2] = "num_critic_for_reviews";
  columns[3] = "duration";
  columns[4] = "director_facebook_likes";
  columns[5] = "actor_3_facebook_likes";
  columns[6] = "actor_2_name";
  columns[7] = "actor_1_facebook_likes";
  columns[8] = "gross";
  columns[9] = "genres";
  columns[10] = "actor_1_name";
  columns[11] = "movie_title";
  columns[12] = "num_voted_users";
  columns[13] = "cast_total_facebook_likes";
  columns[14] = "actor_3_name";
  columns[15] = "facenumber_in_poster";
  columns[16] = "plot_keywords";
  columns[17] = "movie_imdb_link";
  columns[18] = "num_user_for_reviews";
  columns[19] = "language";
  columns[20] = "country";
  columns[21] = "content_rating";
  columns[22] = "budget";
  columns[23] = "title_year";
  columns[24] = "actor_2_facebook_likes";
  columns[25] = "imdb_score";
  columns[26] = "aspect_ratio";
  columns[27] = "movie_facebook_likes";
  
  char resp[1500];
  int len;
  int z;
  char *sortedname = "AllFiles-sorted-";
  char addtoname[500];
  strcpy(addtoname, outpath);
  strcat(addtoname, sortedname);
  strcat(addtoname, sortparam);
  strcat(addtoname, ".csv");
  FILE* fp = fopen(addtoname, "w");

  int i;
  for(i = 0; i < 28; i++){
    if(i == 27){ fprintf(fp, "%s\n", columns[i]); } 
    else{ fprintf(fp, "%s,", columns[i]); } /
  }
  
  while (1){
    len = read(sockfd, resp, 1501);
    if (len <= 0){ break; }
    if(strlen(resp) == 0){ break; }
    if(strcmp(resp, "") == 0){ break; }
    if(strcmp(resp, "end") == 0){ break; }
    fprintf(fp, "%s\n", resp);
    for(z =0 ; z < 1500; z++){ resp[z] = 0; }
  }
  fclose(fp);

  pthread_exit(0);
}
//=================================================================================================================================

void* callMerge(void* arg){
  char* str = (char*)arg;
  usleep(5*1000);
  write(sockfd, str, strlen(str)+1);
  usleep(5*1000);
  pthread_exit(0);
}
//==================================================================================================================================

void* writeSocket(void* arg){
  char* fileP = (char*)arg;
  char filepath[10000];
  strcpy(filepath, fileP);
  size_t size = 0;
  char* buffer;
  FILE *f;
  f=fopen(filepath,"r");

  getline(&buffer, &size, f);
  int i;
  int boolean = 0;
  char* token;
  for(i = 0; i < 28; i++){
    token = strsep(&buffer, ",");
    if(strcmp(sortparam, token) == 0){ boolean = 1; } 
  }
  if(boolean == 0){ fclose(f); pthread_exit(0); }


  while(getline(&buffer, &size, f) != EOF){
    write(sockfd,buffer,strlen(buffer)+1);
    usleep(5*1000);
  }
  fclose(f);
  pthread_exit(0);
}
//=======================================================================================================================================

void* readdirectory(void* arg){
  char* fileP = (char*)arg;
  DIR *dir;
  struct dirent *entries;
  char filepath[10000];
  strcpy(filepath, fileP);
  char* slash = "/";

  pthread_t tids[1024];
  int i = 0;

  if (filepath[strlen(filepath)-1] != '/'){ strcat(filepath, slash); }
  if ((dir = opendir(filepath)) != NULL){//check to see if the directory even exist
    while ((entries = readdir(dir)) != NULL){//reads everything in directory until no more files
      
      if (checkcsv(entries->d_name) == 1 ){
	char csvFile[10000];
	strcpy(csvFile, filepath);
	char *string = entries->d_name;
	strcat(csvFile, string);
	pthread_create(&tids[i], NULL, writeSocket, csvFile);
	i++;
      }

      
      if (checkdirectory(entries) == 1 ){
	char newPath[10000];
	strcpy(newPath, filepath);
	char *string = entries->d_name;
	strcat(newPath, string);
	strcat(newPath, slash);
	pthread_create(&tids[i], NULL, readdirectory, newPath);
	i++;
      }
      
      
      usleep(70*1000);
    }
  }
  closedir (dir);

  int j;
  for(j = 0; j < i; j++){ pthread_join(tids[j], NULL); }
  
  pthread_exit(0);
}
//===========================================================================================================================================


int main(int argc, char** argv){


  char* filepath;
  char *slash = "/";
  char relativedir[100] = "./";
  char relativedir2[100] = "./";


  if (argc < 7)
  {
    printf("%s\n", "not enough params in command line" );
    exit(0);
  }
  else if (argc == 7)
  {
    sortparam = argv[2];
    hostname = argv[4];;
    portnum = argv[6];
    filepath = "./";
    outpath = "./";
  }
  else if (argc == 9)
  {
    sortparam = argv[2];
    hostname = argv[4];;
    portnum = argv[6];
    if ((strcmp(argv[7], "-d") == 0))
    {
      filepath = argv[8];
      outpath = "./";
      if (filepath[0] != '/')
      {
            filepath = strcat(relativedir, filepath);
      } 
    }
    if ((strcmp(argv[7], "-o") == 0))
    {
      filepath = "./";
      outpath = argv[8];
      if (outpath[0] != '/')
      {
            outpath = strcat(relativedir, outpath);
      } 
    }
  }
  else if (argc == 11)
  {
    sortparam = argv[2];
    hostname = argv[4];;
    portnum = argv[6];
    filepath = argv[8];
    outpath = argv[10];
    if (filepath[0] != '/')
    {
          filepath = strcat(relativedir, filepath);
    } 
    if (outpath[0] != '/')
    {
          outpath = strcat(relativedir2, outpath);
    } 
  }
  if (filepath[strlen(filepath)-1] != '/' )
  {
    strcat(filepath, slash);
  }
  if (outpath[strlen(outpath)-1] != '/' )
  {
    strcat(outpath, slash);
  }
 
  if(!opendir(outpath)){
    printf("%s\n", "Output directory does not exist. Failed. Exit");
    exit(0);
  }

/////////////////////////////////////////////////////////////////////////////////////////


  int s;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0){ printf("%s\n", "ERROR opening socket"); exit(0);}
  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  s = getaddrinfo(hostname, portnum, &hints, &result);
  if (s !=0){ printf("addrinfo error\n"); exit(0);}
  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) { printf("%s\n","ERROR connecting in openSocket method"); exit(0);}

  pthread_t tid;
  char* merge = "merge";
  pthread_create(&tid, NULL, readdirectory, filepath);
  pthread_join(tid, NULL);
  usleep(5*1000);

  pthread_create(&tid, NULL, callMerge, merge);
  pthread_join(tid, NULL);
  usleep(5*1000);
  
  pthread_create(&tid, NULL, readSocket, sortparam);
  pthread_join(tid, NULL);
  usleep(5*1000);
  
  close(sockfd);
  return 0;
}
