#pragma once
#include<cstdio>
const char *VERSION_HEADER="Beta";
const int VERSION_MAJOR=0;
const int VERSION_MINOR=0;
const int VERSION_PATCH=0;
#define PrintVersion() printf("WillDaemon %s v%d.%d.%d\nGithub https://github.com/Torrekie/WillDaemon\n",VERSION_HEADER,VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH)