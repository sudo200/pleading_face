#include <locale.h>
#include <stdio.h>
#include <unistd.h>

#include <grp.h>

int main(int argc, char **argv)
{
  setlocale(LC_ALL, ""); // Show help
  if(argc < 2) {
    printf("Usage: %s <program> [args]\n", *argv);
    return 1;
  }

  setuid(0);// Be root
  setgid(0);

  setgroups(0, NULL); // Drop supplementary groups

  argv++; // Execute process
  execvp(*argv, argv);

  perror(*argv); // Show error
  return 1;
}

