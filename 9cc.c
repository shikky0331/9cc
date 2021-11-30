#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "number of args aren't correct");
    return 1;
  }

  char *p = argv[1];

  printf(".intel_syntax noprefix\n");
  printf(".globl main\n");
  printf("main:\n");
  printf("  mov rax, 5ld\n", strtol(p, &p, 10));

  while (*p)
  {
    if (*p == '+')
    {
      p++;
      printf("  add rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    if (*p == '-')
    {
      p++;
      printf("  sub rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "not expected string: '%c'\n", *p);
    return 1;
  }

  printf("  ret\n");
  return 0;
}
