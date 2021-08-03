#pragma once
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<fstream>
#include<string>
#include "jsonxx/json.hpp"
using namespace std;
class WDexception:public std::exception{
	public:
		std::string error;
		WDexception(std::string s){
			error=s;
		}
 		virtual const char* what() const throw(){
			return error.c_str();
		}
};
void putl(const char *string){
    while(*string)putchar(*string++);
}
inline string GetAllData(char *FileName){
	ifstream JsonIn(FileName); 
	string result((istreambuf_iterator<char>(JsonIn)),istreambuf_iterator<char>());
	return result;
}
inline bool AuthFile(const std::string& name){
    ifstream f(name.c_str());
    return f.good();
}
void ClearCache(){
	if(AuthFile("config.json"))remove("config.json");
    if(AuthFile(".daemonize_history"))remove(".daemonize_history");
    puts("Cache Cleared.");
}
bool CheckConfig(){ 
	string ConfigString=GetAllData("config.json");
	jsonxx::json Config=jsonxx::json::parse(ConfigString);
	if(Config["Github"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Github\"");
	if(Config["Github"]["User"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Github.User\"");
	if(Config["Github"]["Repo"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Github.Repo\"");
	if(Config["Github"]["Token"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Github.Token\"");
	if(Config["Limit"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Limit\"");
	if(Config["Limit"]["Time"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Limit.Time\"");
	if(Config["Limit"]["Sign"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Limit.Sign\"");
	if(Config["Web"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Web\"");
	if(Config["Web"]["Open"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Web.Open\"");
	if(Config["Web"]["Port"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Web.Port\"");
	if(Config["Cli"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Cli\"");
	if(Config["Cli"]["Open"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Cli.Open\"");
	if(Config["Cli"]["Port"]==nullptr)throw WDexception("Error:Config doesn't hava key \"Cli.Port\"");
	return true;
}
inline bool GetYNAnswer(char *s){
	putl(s);
	char option=getchar();
	while(option!='y'&&option!='Y'&&option!='n'&&option!='N'&&option!='\n')option=getchar();
	if(option=='n'||option=='N')return false;
	return true;
}
void CreateConfig(){
	jsonxx::json Config={
		"Github",{
			{"User",""},
			{"Repo",""},
			{"Token",""}
		},
		"Limit",{
			{"Time",""},
			{"Sign",""}
		},
		"Web",{
			{"Open",true},
			{"Port",80},
		},
		"Cli",{
			{"Open",true},
			{"Port",16384}
		}
	};
	
}