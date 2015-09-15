#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
 /* Our file descriptor */
 int fd,size;
 int wcount = 0;
 char write_buffer[20];
 if(argc>0)
 strcpy(write_buffer,argv[1]);
 else
 {
   printf("Nothing to write");
   return 0;
 }
 size = strlen(argv[1]);
 printf("%s: entered\n", argv[0]);
 /* Open the device */
 
 fd = open("/dev/DriverMain", O_RDWR);
 if ( fd == -1 )
 {
  perror("open failed");
  wcount = fd;
  exit(-1);
 }
 printf("%s: open: successful\n", argv[0]);
 /* Issue a read */
 

 wcount = write(fd,write_buffer,size);

 if ( wcount == -1 ) {
 perror("Failed to write");
 close(fd);
 exit(-1);
 }
 printf("%s: write: Success - %i characters\n", argv[0], wcount);
 close(fd);
 return 0;
}

