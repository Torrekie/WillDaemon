#pragma once
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<fstream>
#include<string>
#include<iostream>
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
inline void putl(const char *string){
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
inline string GetStrAnswer(char *s){
	putl(s);
	string Ans;
	cin>>Ans;
	return Ans;
}
inline int GetNumberAnswer(char *s){
	putl(s);
	int Ans;
	scanf("%d",&Ans);
	return Ans;
}
void CreateConfig(){
	puts("Set your GitHub user information.");
	string UserName=GetStrAnswer("Please enter your github username:");
	string Repo=GetStrAnswer("Please enter your github private repository name:");
	string Token=GetStrAnswer("Please enter your github token:");
	puts("Configure your preferences.");
	puts("Please be sure to enter the date in year-month-day format.");
	string Time=GetStrAnswer("Extending lifetime needs periodically sign-in, set a regular interval.");
	puts("Finally, lets set a sign-in method that you prefered");
	bool Web=true,Cli=true;
	int WebPort=80,CliPort=16384;
	getchar();
	if(GetYNAnswer("Would you like to sign in via webpage?"))WebPort=GetNumberAnswer("Set a HTTP port for this.");
	else Web=false;
	getchar();
	if(GetYNAnswer("Would you like to use cli to sign in?"))CliPort=GetNumberAnswer("Set a cli port for this.");
	else CliPort=false;
	jsonxx::json Config={
		{
			"Github",{
				{"User",UserName},
				{"Repo",Repo},
				{"Token",Token}
			}
		},
		{
			"Limit",{
				{"Time",Time}
			}
		},
		{
			"Web",{
				{"Open",Web},
				{"Port",WebPort},
			}
		},
		{
			"Cli",{
				{"Open",Cli},
				{"Port",CliPort}
			}
		}
	};
	ofstream JSONFileOut;
	JSONFileOut.open("config.json");
	JSONFileOut<<Config.dump(' ',4);
	JSONFileOut.close();
	puts("Configuration done.");
}