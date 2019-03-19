

//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#1
/*color MERGE SORT TYPE: STRING*/


void colorMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;

  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].color, temp2[j].color) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void colorMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    colorMergeSort(movie, low, middle);
    colorMergeSort(movie, middle+1, right);
    colorMerge(movie, low, middle, right);
  }
}
//#1
/*color MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________










//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#2
/*directorname MERGE SORT TYPE: STRING*/

void directorNameMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 

  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low;

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].directorname, temp2[j].directorname) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void directorNameMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    directorNameMergeSort(movie, low, middle);
    directorNameMergeSort(movie, middle+1, right);
    directorNameMerge(movie, low, middle, right);
  }
}


//#2
/*directorname MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________









//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#3
/*numcriticforreviews MERGE SORT TYPE: INT*/



void numCriticForReviewsMerge(struct film *movie, int low, int middle, int right)
{
  int i; 
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;

  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {  
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low;

  while (i < size1 && j < size2)
  {
    if (temp1[i].numcriticforreviews < temp2[j].numcriticforreviews)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void numCriticForReviewsMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    numCriticForReviewsMergeSort(movie, low, middle);
    numCriticForReviewsMergeSort(movie, middle+1, right);
    numCriticForReviewsMerge(movie, low, middle, right);
  }
}
//#3
/*numcriticforreviews MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________










//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#4
/*duration MERGE SORT TYPE: INT*/






void durationMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].duration < temp2[j].duration)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void durationMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    durationMergeSort(movie, low, middle);
    durationMergeSort(movie, middle+1, right);
    durationMerge(movie, low, middle, right);
  }
}
//#4
/*duration MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________






//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#5
/*directorfacebooklikes MERGE SORT TYPE: INT*/



void directorFacebookLikesMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low;


  while (i < size1 && j < size2)
  {
    if (temp1[i].directorfacebooklikes < temp2[j].directorfacebooklikes)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void directorFacebookLikesMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    directorFacebookLikesMergeSort(movie, low, middle);
    directorFacebookLikesMergeSort(movie, middle+1, right);
    directorFacebookLikesMerge(movie, low, middle, right);
  }
}
//#5
/*directorfacebooklikes MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________





//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#6
/*actor3facebooklikes MERGE SORT TYPE: INT*/



void actor3FacebookLikesMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].actor3facebooklikes < temp2[j].actor3facebooklikes)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void actor3FacebookLikesMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    actor3FacebookLikesMergeSort(movie, low, middle);
    actor3FacebookLikesMergeSort(movie, middle+1, right);
    actor3FacebookLikesMerge(movie, low, middle, right);
  }
}







//#6
/*actor3facebooklikes MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________








//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#7
/*actor2name MERGE SORT TYPE: STRING*/



  void actor2NameMerge(struct film *movie, int low, int middle, int right)
  {
  int i;
  int j; 
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low;

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].actor2name, temp2[j].actor2name) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void actor2NameMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    actor2NameMergeSort(movie, low, middle);
    actor2NameMergeSort(movie, middle+1, right);
    actor2NameMerge(movie, low, middle, right);
  }
}

//#7
/*actor2name MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________










//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#8
/*actor1facebooklikes MERGE SORT TYPE: INT*/



void actor1FacebookLikesMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0;
  j = 0; 
  k = low; 


  while (i < size1 && j < size2)
  {
    if (temp1[i].actor1facebooklikes < temp2[j].actor1facebooklikes)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
  
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void actor1FacebookLikesMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    actor1FacebookLikesMergeSort(movie, low, middle);
    actor1FacebookLikesMergeSort(movie, middle+1, right);
    actor1FacebookLikesMerge(movie, low, middle, right);
  }
}


//#8
/*actor1facebooklikes MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________









//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#9
/*gross MERGE SORT TYPE: INT*/


void grossMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0;
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].gross < temp2[j].gross)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void grossMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    grossMergeSort(movie, low, middle);
    grossMergeSort(movie, middle+1, right);
    grossMerge(movie, low, middle, right);
  }
}



//#9
/*gross MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________









//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#10
/*genres MERGE SORT TYPE: STRING*/


void genresMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].genres, temp2[j].genres) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void genresMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    genresMergeSort(movie, low, middle);
    genresMergeSort(movie, middle+1, right);
    genresMerge(movie, low, middle, right);
  }
}

//#10
/*genres MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________











//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#11
/*actor1name MERGE SORT TYPE: STRING*/


void actor1NameMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].actor1name, temp2[j].actor1name) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void actor1NameMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    actor1NameMergeSort(movie, low, middle);
    actor1NameMergeSort(movie, middle+1, right);
    actor1NameMerge(movie, low, middle, right);
  }
}

//#11
/*actor1name MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________











//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#12
/*movietitle MERGE SORT TYPE: STRING*/


void movieTitleMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j; 
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0;
  j = 0; 
  k = low; 


  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].movietitle, temp2[j].movietitle) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void movieTitleMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    movieTitleMergeSort(movie, low, middle);
    movieTitleMergeSort(movie, middle+1, right);
    movieTitleMerge(movie, low, middle, right);
  }
}

//#12
/*movietitle MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________










//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#13
/*numvotedusers MERGE SORT TYPE: INT*/


void numVotedUsersMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j; 
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].numvotedusers < temp2[j].numvotedusers)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }


  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void numVotedUsersMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    numVotedUsersMergeSort(movie, low, middle);
    numVotedUsersMergeSort(movie, middle+1, right);
    numVotedUsersMerge(movie, low, middle, right);
  }
}


//#13
/*numvotedusers MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________









//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#14
/*casttotalfacebooklikes MERGE SORT TYPE: INT*/

void castTotalFacebookLikesMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0;
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].casttotalfacebooklikes < temp2[j].casttotalfacebooklikes)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void castTotalFacebookLikesMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    castTotalFacebookLikesMergeSort(movie, low, middle);
    castTotalFacebookLikesMergeSort(movie, middle+1, right);
    castTotalFacebookLikesMerge(movie, low, middle, right);
  }
}


//#14
/*casttotalfacebooklikes MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________










//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#15
/*actor3name MERGE SORT TYPE: STRING*/





void acotr3NameMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
 for (i = 0; i < size1; i++)
 {
    temp1[i] = movie[low + i];
 }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].actor3name, temp2[j].actor3name) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void acotr3NameMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    acotr3NameMergeSort(movie, low, middle);
    acotr3NameMergeSort(movie, middle+1, right);
    acotr3NameMerge(movie, low, middle, right);
  }
}
//#15
/*actor3name MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________














//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#16
/*facenumberinposter MERGE SORT TYPE: INT*/

void faceNumberInPosterMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0;
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].facenumberinposter < temp2[j].facenumberinposter)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void faceNumberInPosterMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    faceNumberInPosterMergeSort(movie, low, middle);
    faceNumberInPosterMergeSort(movie, middle+1, right);
    faceNumberInPosterMerge(movie, low, middle, right);
  }
}


//#16
/*facenumberinposter MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________












//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#17
/*plotkeywords MERGE SORT TYPE: STRING*/

void plotKeyWordsMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].plotkeywords, temp2[j].plotkeywords) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void plotKeyWordsMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    plotKeyWordsMergeSort(movie, low, middle);
    plotKeyWordsMergeSort(movie, middle+1, right);
    plotKeyWordsMerge(movie, low, middle, right);
  }
}


//#17
/*plotkeywords MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________











//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#18
/*movieimdblink MERGE SORT TYPE: STRING*/

void movieImdbLinkMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].movieimdblink, temp2[j].movieimdblink) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void movieImdbLinkMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    movieImdbLinkMergeSort(movie, low, middle);
    movieImdbLinkMergeSort(movie, middle+1, right);
    movieImdbLinkMerge(movie, low, middle, right);
  }
}


//#18
/*movieimdblink MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
















//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#19
/*numuserforreviews MERGE SORT TYPE: INT*/

void numUserForReviewsMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].numuserforreviews < temp2[j].numuserforreviews)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void numUserForReviewsMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    numUserForReviewsMergeSort(movie, low, middle);
    numUserForReviewsMergeSort(movie, middle+1, right);
    numUserForReviewsMerge(movie, low, middle, right);
  }
}


//#19
/*numuserforreviews MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________












//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#20
/*language MERGE SORT TYPE: STRING*/


void languageMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low;

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].language, temp2[j].language) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void languageMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    languageMergeSort(movie, low, middle);
    languageMergeSort(movie, middle+1, right);
    languageMerge(movie, low, middle, right);
  }
}

//#20
/*language MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________










//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#21
/*country MERGE SORT TYPE: STRING*/

void countryMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2){
    if ( strcasecmp(temp1[i].country, temp2[j].country) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void countryMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    countryMergeSort(movie, low, middle);
    countryMergeSort(movie, middle+1, right);
    countryMerge(movie, low, middle, right);
  }
}


//#21
/*country MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________














//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#22
/*contentrating MERGE SORT TYPE: STRING*/

void contentRatingMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if ( strcasecmp(temp1[i].contentrating, temp2[j].contentrating) < 0 )
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void contentRatingMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    contentRatingMergeSort(movie, low, middle);
    contentRatingMergeSort(movie, middle+1, right);
    contentRatingMerge(movie, low, middle, right);
  }
}



//#22
/*contentrating MERGE SORT TYPE: STRING*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________


















//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#23
/*budget MERGE SORT TYPE: INT*/


void budgetMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].budget < temp2[j].budget)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void budgetMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    budgetMergeSort(movie, low, middle);
    budgetMergeSort(movie, middle+1, right);
    budgetMerge(movie, low, middle, right);
  }
}

//#23
/*budget MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
















//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#24
/*titleyear MERGE SORT TYPE: INT*/



void titleYearMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low;

  while (i < size1 && j < size2)
  {
    if (temp1[i].titleyear < temp2[j].titleyear)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void titleYearMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    titleYearMergeSort(movie, low, middle);
    titleYearMergeSort(movie, middle+1, right);
    titleYearMerge(movie, low, middle, right);
  }
}

//#24
/*titleyear MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________













//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#25
/*actor2facebooklikes MERGE SORT TYPE: INT*/


void actor2FacebookLikesMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].actor2facebooklikes < temp2[j].actor2facebooklikes)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void actor2FacebookLikesMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    actor2FacebookLikesMergeSort(movie, low, middle);
    actor2FacebookLikesMergeSort(movie, middle+1, right);
    actor2FacebookLikesMerge(movie, low, middle, right);
  }
}

//#25
/*actor2facebooklikes MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________














//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#26
/*imdbscore MERGE SORT TYPE: FLOAT*/



void imdbScoreMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].imdbscore < temp2[j].imdbscore)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void imdbScoreMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    imdbScoreMergeSort(movie, low, middle);
    imdbScoreMergeSort(movie, middle+1, right);
    imdbScoreMerge(movie, low, middle, right);
  }
}
//#26
/*imdbscore MERGE SORT TYPE: FLOAT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________














//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#27
/*aspectratio MERGE SORT TYPE: FLOAT*/


void aspectRatioMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0;
  j = 0; 
  k = low;

  while (i < size1 && j < size2)
  {
    if (temp1[i].aspectratio < temp2[j].aspectratio)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 

  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 

  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void aspectRatioMergeSort(struct film* movie, int low, int right)
{  
  if (low < right)
  {
    int middle = low+(right-low)/2;
    aspectRatioMergeSort(movie, low, middle);
    aspectRatioMergeSort(movie, middle+1, right);
    aspectRatioMerge(movie, low, middle, right);
  }
}

//#27
/*aspectratio MERGE SORT TYPE: FLOAT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________









//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________
//#28
/*moviefacebooklikes MERGE SORT TYPE: INT*/


void movieFacebookLikesMerge(struct film *movie, int low, int middle, int right)
{
  int i;
  int j;
  int k;
  int size1 = middle - low + 1;
  int size2 =  right - middle;
 
  //struct film temp1[size1];
  //struct film temp2[size2];
  struct film* temp1 = malloc(sizeof(struct film)*size1);
  struct film* temp2 = malloc(sizeof(struct film)*size2);
 
  for (i = 0; i < size1; i++)
  {
    temp1[i] = movie[low + i];
  }
  for (j = 0; j < size2; j++)
  {
    temp2[j] = movie[middle + 1+ j];
  }
 
  i = 0; 
  j = 0; 
  k = low; 

  while (i < size1 && j < size2)
  {
    if (temp1[i].moviefacebooklikes < temp2[j].moviefacebooklikes)
    {
      movie[k] = temp1[i];
      i++;
    }
    else
    {
      movie[k] = temp2[j];
      j++;
    }
    k++;
  }
 
 
  while (i < size1)
  {
    movie[k] = temp1[i];
    i++;
    k++;
  }
 
 
  while (j < size2)
  {
    movie[k] = temp2[j];
    j++;
    k++;
  }
}

void movieFacebookLikesMergeSort(struct film* movie, int low, int right)
{ 
  if (low < right)
  {
    int middle = low+(right-low)/2;
    movieFacebookLikesMergeSort(movie, low, middle);
    movieFacebookLikesMergeSort(movie, middle+1, right);
    movieFacebookLikesMerge(movie, low, middle, right);
  }
}

//#28
/*moviefacebooklikes MERGE SORT TYPE: INT*/
//________________________________________________________________________________________________________________________________________________
//________________________________________________________________________________________________________________________________________________

