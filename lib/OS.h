#pragma once
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<fstream>
#include<string>
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
inline bool AuthFile(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}