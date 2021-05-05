/*
  Originally created and maintained by Torrekie. Now her
  friends joined this project and they did truely help on
  this quite a lot.

  WillDaemon 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

//WillDaemon basic info
//VERSION* chars should output like "NONRELEASE 0.0.0.0-1" or "NONRELEASE 0.0.0" in short.
static const char *VERSION_HEADER = "NONRELEASE "; //This can be something like "v", "Ver. ", "Version ", etc.
static const char *VERSION_MAJOR = "0";            //Major Version
static const char *VERSION_MINOR = "0";            //Minor Version
static const char *VERSION_PATCH = "0";            //Patch
static const char *VERSION_BETA = "0";             //Beta Version, should only show in beta versions.
static const char *VERSION_DEVELOPMENT = "1";      //Development Version, should only show in unstable/development versions.

static const bool UNDER_DEVELOPMENT = true; //When this set true, function printVersion will output Development Version.
static const bool BETA_RELEASE = false;     //When this set true, function printVeriosn will output Beta Version.
static const bool COMPLETED = false;        //When this set false, you shouldn't build WillDaemon for use, because it means we didn't finish the basic features of this project so you can't really get it in use.

int printVersion(bool simple)
{
  char versionOutput[100];
  sprintf(versionOutput, "%s%s.%s.%s", VERSION_HEADER, VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
  if (BETA_RELEASE)
  {
    sprintf(versionOutput, "%s.%s", versionOutput, VERSION_BETA);
  }
  if (UNDER_DEVELOPMENT)
  {
    sprintf(versionOutput, "%s-%s", versionOutput, VERSION_DEVELOPMENT);
  }
  if (simple)
  {
    printf("%s\n", versionOutput);
  }
  else
  {
    printf("WillDaemon %s\nOriginally created by Torrekie, maintained by her friends.\n", versionOutput);
  }
  return 0;
}
int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "WillDaemon main project, unfinished.\n\033[0;37mType \'%s --help\' to see the instructions.\033[0;0m\n", argv[0]);
    exit(1);
  }
  else
  {
    int opt;
    bool showSimple = false;
    const char *short_options = "a:hvf";
    int option_index = 0;
    struct option long_options[] = {
        {"add", required_argument, 0, 'a'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"full", no_argument, 0, 'f'},
        {0, 0, 0, 0}};
    while (-1 != (opt = getopt_long(argc, argv, short_options, long_options, &option_index)))
    {
      switch (opt)
      {
      case 'a':
        printf("option: -%c, optarg: %s\r\n", opt, optarg);
        break;
      case 'h':
        //printUsage();
        break;
      case 'f':
        showSimple = true;
        //printf("%c",opt);
        break;
      case 'v':
        printVersion(showSimple);
        break;
      case '?': 
        printf("Argument error.\r\n");
        printf("Type \'%s --help\' to see the instructions.\033[0;0m\n", argv[0]);
        break;
      default:
        printf("%s: invalid option -- '%c'\r\n", argv[0], opt);
        printf("Type \'%s --help\' to see the instructions.\033[0;0m\n", argv[0]);
        break;
      }
    }
    return 0;
  }
  return 0;
}
