#include "lib/Config.h"
#include "lib/Opt.h"
#include "lib/OS.h"
int main(int argc,char *argv[]){
    vector<string>str={
		"--help","-h",
		"--version","-v",
        "--start","-s",
        "--reset","-r",
        "--create","-c",
	};
    vector<LampOpt::CommandRead>Ret=LampOpt::getopt(argc,argv,str);
    for(int i=0;i<Ret.size();++i){
        if(Ret[i].CommandName=="-h")PrintVersion(),PrintArguments();
        else if(Ret[i].CommandName=="-v")PrintVersion();
        else if(Ret[i].CommandName=="-r")ClearCache();
        else if(Ret[i].CommandName=="-c"){
            bool flag=1;
            if(AuthFile("config.json")){
                if(GetYNAnswer("There is already a config in this directory, do you want to continue (Y/n)?")){
                    ClearCache();
                    CreateConfig();
                    flag=0;
                }else{
                    puts("Give up creating configuration files.");
                    return 0;
                }
            }
            if(flag)CreateConfig();
        }else if(Ret[i].CommandName=="-s"){
            if(!AuthFile("config.json"))throw WDexception("Error:config not found, try -c?");
            CheckConfig();
        }
    }
}