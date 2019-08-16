#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char __start_bindata;
extern char __stop_bindata;

extern char __start_exec;
extern char __stop_exec;

int main()
{
  char *p;
  int res;
  int (*fp)(int, int);
  int size;
  unsigned char *porg, *pcode;

  printf("__start_bindata = 0x%08x\n", (int)(&__start_bindata));
  printf("__stop_bindata = 0x%08x\n", (int)(&__stop_bindata));

  pcode = (unsigned char *)&__start_bindata;
  size = &__stop_bindata - &__start_bindata;
  printf("%d\n0", size);

  porg = (unsigned char *)&__start_exec;
  memcpy(porg + 0x40, pcode, size);

  fp = (int(*)(int, int))(&__start_exec + 0x40);

  res = (*fp)(10, 90);
  printf("%d\n", res);
  return 0;
}
