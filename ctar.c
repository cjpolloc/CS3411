#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* This needs to be able to:
: ctar -a <archive file name>                       ->Archive file must be created
: ctar -a <archive file name> file1 file2 file3 ... ->If archive file exists just append, if not then create archive file
: ctar -d <archive file name> <file name>           ->Delete file from the archive
*/
int main(int argc, char *argv[])
{
    char buf[100];
    sprintf(buf, argv[2]);
    int newArchive;
    errno = 0;
    //Check if archive file exists
    if(argv[1] == "-a"){
      newArchive = open(buf, O_RDWR|O_CREAT, 0600);
      if(newArchive == -1){
        write(1, "ERROR ERROR ERROR\n", 18);
      }
      else{
        write(1, "Archive File Created Successfully\n", 34);
      }
    }else{
      write(1, "wot\n",4);
    }
    return 0;

}

/* Needs to verify that the file given to append actually exists
void verify()
{

}
*/
