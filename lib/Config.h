#pragma once
#include<cstdio>
const char *VERSION_HEADER="Beta";
const int VERSION_MAJOR=0;
const int VERSION_MINOR=0;
const int VERSION_PATCH=0;
#define PrintVersion() printf("WillDaemon %s v%d.%d.%d\r\nGithub https://github.com/Torrekie/WillDaemon\r\n",VERSION_HEADER,VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH)
#define PrintArguments() printf("Arguments:\r\n\t-h or --help \tPrint manuals (this message)\r\n\t-v or --version Print version\r\n\t-s or --start\tStart with config.json \r\n\t-r or --reset\tDelete local cache and config\r\n\t-c or --creat\tInitialization the config.json\r\n")