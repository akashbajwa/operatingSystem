#include <stdlib.h> // free, perror
#include <stdio.h>  // printf
#include <string.h> // strlen
#include"direct.h" // _getcwd
#include<unistd.h>
#include <dirent.h>
int main(int argc,char*argv[])
{
    char arg[100];
    gets(arg); /*Taking arguments*/

    /*Arguments are up there*/
   char* buffer;
   while(buffer != "exit" || buffer != "EXIT"){

   if ( (buffer = _getcwd( NULL, 0 )) == NULL )
      perror( "_getcwd error,Unable to Find >" );/* Get the current working directory:*/
   else
   {
      printf( "%s >", buffer, strlen(buffer) );
      free(buffer);
   }


   if (chdir("/tmp") != 0)
    perror("chdir() to /temp failed");


    printf("%s\n", getcwd(buffer, 100));

    struct dirent *de;  /* Pointer for directory entry*/

    /* opendir() returns a pointer of DIR type.*/
    DIR *dr = opendir(".");

    if (dr == NULL)   /* opendir returns NULL if couldn't open directory*/
    {
        printf("Could not open current directory" );
        return 0;
    }

    /* Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    for readdir()*/

    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);

    closedir(dr);

   }

    return 0;
}
char** Tokenizer(char* arg)
{
    char* argList[100];
     int  i =  0;
     int  k = 0;
     while(arg[i]!= '\0'){

       if(arg[i]!= ' ')
       {

        int j = 0 ;
          while(arg[i] != ' '){
            argList[k][j] = arg[i];

            j++;i++;
           }
           argList[k][j] = '\0';
           k++;
       }
        if(arg[i] == '\0' )
            break;
        else if(arg[i] == ' ')
            i++;
     }



}
