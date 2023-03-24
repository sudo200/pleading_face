#include <locale.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "");
  if(argc < 2) {
    printf("Usage: %s <program> [args]\n", *argv);
    return 1;
  }

  argv++;
  execvp(*argv, argv);

  perror(*argv);
  return 1;
}

