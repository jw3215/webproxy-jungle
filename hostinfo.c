#include "csapp.h"

int main(int argc, char **argv)
{
  struct addrinfo *p, *listp, hints;
  char buf1[MAXLINE];
  char buf2[MAXLINE];
  int rc, flags;

  if (argc != 2)
  {
    fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
    exit(0);
  }

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  rc = getaddrinfo(argv[1], NULL, &hints, &listp);
  if (rc != 0)
  {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
    exit(1);
  }

  flags = NI_NUMERICHOST;
  p = listp;
  while (p)
  {
    Getnameinfo(p->ai_addr, p->ai_addrlen, buf1, MAXLINE, NULL, 0, flags);
    printf("%s\n", buf1);
    p = p->ai_next;
  }

  Freeaddrinfo(listp);

  exit(0);
}
