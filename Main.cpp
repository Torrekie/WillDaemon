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
        "--daemonize","-d"
	};
    vector<LampOpt::CommandRead>Ret=LampOpt::getopt(argc,argv,str);
    for(int i=0;i<Ret.size();++i){
        if(Ret[i].CommandName=="-h")PrintVersion(),PrintArguments();
        else if(Ret[i].CommandName=="-v")PrintVersion();
        else if(Ret[i].CommandName=="-r")ClearCache();
        else if(Ret[i].CommandName=="-c"){
            if(AuthFile("config.json")){
                printf("There is already a config in this directory, do you want to continue (Y/n)?");
                char option=getchar();
                while(option!='y'&&option!='Y'&&option!='n'&&option!='N'&&option!='\n')option=getchar();
                if(option=='n'||option=='N'){
                    puts("Give up creating configuration files.");
                    return 0;
                }else{
                    ClearCache();
                    CreateConfig();
                }
            }
        }else if(Ret[i].CommandName=="-s"){
            if(!AuthFile("config.json"))throw WDexception("Error:config not found, try -c?");
            CheckConfig();
        }
    }
}