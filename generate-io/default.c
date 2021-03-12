#define _GNU_SOURCE // O_DIRECT
#define IOUNIT 128 * 1024

int main()
{
  char *nBuf; // not aligned buffer
  char *aBuf; // aligned buffer
  int fd;     // file descriptor

  // 1MB buffer (not aligned yet)
  nBuf = (char *)malloc(IOUNIT + getpagesize());
  // aligned buffer 'aBuf'
  aBuf = (char *)((unsigned)(nBuf + getpagesize() - 1) / getpagesize() * getpagesize());

  printf("OPEN FD: %d\n", fd = open("[블록장치경로]", O_RDWR));
  printf("WRITE: %d\n", write(fd, aBuf, IOUNIT));
  printf("READ: %d\n", read(fd, aBuf, IOUNIT));
  close(fd);

  free(nBuf);
}