#include "lib/Config.h"
#include "lib/Opt.h"
#include "lib/OS.h"
#include "lib/jsonxx/json.hpp"
using namespace std;
int main(int argc,char *argv[]){
    vector<string>str={
		"--help","-h",
		"--version","-v",
        "--start","-s",
        "--reset","-r",
        "--create","-c",
        "--daemonize","-d"
	};
    vector<LampOpt::CommandRead>Ret=LampOpt::getopt(argc,argv,str);
    for(int i=0;i<Ret.size();++i){
        if(Ret[i].CommandName=="-h")PrintVersion(),PrintArguments();
        else if(Ret[i].CommandName=="-v")PrintVersion();
    }
}