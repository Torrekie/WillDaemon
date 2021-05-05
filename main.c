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
static const char* VERSION_HEADER = "NONRELEASE "; //This can be something like "v", "Ver. ", "Version ", etc.
static const char* VERSION_MAJOR = "0"; //Major Version
static const char* VERSION_MINOR = "0"; //Minor Version
static const char* VERSION_PATCH = "0"; //Patch
static const char* VERSION_BETA = "0"; //Beta Version, should only show in beta versions.
static const char* VERSION_DEVELOPMENT = "1"; //Development Version, should only show in unstable/development versions.

static const bool UNDER_DEVELOPMENT = true; //When this set true, function printVersion will output Development Version.
static const bool BETA_RELEASE = false; //When this set true, function printVeriosn will output Beta Version.
static const bool COMPLETED = false; //When this set false, you shouldn't build WillDaemon for use, because it means we didn't finish the basic features of this project so you can't really get it in use.

int printVersion(bool simple) {
  char* versionOutput;
  sprintf(versionOutput, "%s%s.%s.%s", VERSION_HEADER, VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
  if(BETA_RELEASE) {
    sprintf(versionOutput, "%s.%s", versionOutput, VERSION_BETA);
  }
  if(UNDER_DEVELOPMENT) {
    sprintf(versionOutput, "%s-%s", versionOutput, VERSION_DEVELOPMENT);
  }
  if(simple) {
    printf("%s", versionOutput);
  }
  return 0;
}
int main(int argc, char** argv) {
  if (argc < 2) {
    fprintf(stderr, "WillDaemon main project, unfinished.\n\033[0;37mType \'%s --help\' to see the instructions.\033[0;0m\n", argv[0]);
    exit(1);
  } else {
    printVersion(true);
  }
}
