#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void convertSize(unsigned long size){
  char *suffix[4] = {"B", "Kb","Mb","Gb"};
  int suffIndex = 0 ;
  unsigned long end;
  char ans[256];
  while(size > 1024.0){
    suffIndex ++;
    size = size/1024.0;
  }
  end = size;
  sprintf(ans,"%lu",end);
  strcat(ans,suffix[suffIndex]);
  printf("%s\n",ans);
}

int main(){
  DIR * direct = opendir(".");
  int size = 0;
  struct dirent * directory;
  
  char deRekt[256]="List of Directores:\n";
  char deFiles[256]= "List of Files:\n";
  while(directory=readdir(direct)){
     if(directory ->d_type ==DT_DIR){
      strcat(deRekt,"\t");
      strcat(deRekt,directory ->d_name);
      strcat(deRekt,"\n");
    }
    else{
      struct stat buffer;
      stat(directory->d_name,&buffer);
      int intSize= buffer.st_size;
      size +=intSize;
      strcat(deFiles,"\t");
      strcat(deFiles,directory->d_name);
      strcat(deFiles,"\n");
    }
  }
  printf("%s\n",deRekt);
  printf("%s\n\n",deFiles);
  printf("Size of Directory:%d Bytes/",size);
  convertSize(size);
  return 0;
}

