/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <string>
#include <sstream>
using namespace std;
#include "str_util.h"


string StrUtil::trim(const string & s) {
	
	//trim returns a trimmed version of s
	//trim removes leading and trailing white space
	//AND also removes repeated white space between words
	
	stringstream stream(s);
	string trimmedString;
	stream >> trimmedString;  //grab first word
	string buffer;
	while (stream >> buffer){
       trimmedString.append(" " + buffer);
	}
	return trimmedString;		
}

string StrUtil::toTitleCase(const string & s) {
	
	//Return a title-cased version of s
	//In Title Case each word should start with a captial letter
	//and the remaining letters should be lower case.
	//Also strings starting with "The " will have that replaced
	//with ", The" at the end of the string.
	//e.g. "The Girl From Ipanema" becomes "Girl From Ipanema, The"
    //Note this function effectively does a trim() operation as well
	
	stringstream stream(s);
	string buffer;
    string titleCasedString;
	while (stream >> buffer){
		buffer = StrUtil::toLowerCase(buffer);
        buffer[0] = toupper(buffer[0]);
		titleCasedString.append(" " + buffer);
	}
	//strip off leading blank
	titleCasedString = StrUtil::trim(titleCasedString);
	
    if(StrUtil::startsWith(titleCasedString, "The ")) {
       titleCasedString = titleCasedString.substr(4,titleCasedString.length() -4) + ", The";
    }
	return titleCasedString;		
}

string StrUtil::toUpperCase(const string & s){
	string upperCaseString;
    for(string::const_iterator itr=s.begin(); itr != s.end(); ++itr){
		upperCaseString.append(1,toupper(*itr));
	}
	return upperCaseString;
}

string StrUtil::toLowerCase(const string & s){
	string lowerCaseString;
    for(string::const_iterator itr=s.begin(); itr != s.end(); ++itr){
		lowerCaseString.append(1,tolower(*itr));
	}
	return lowerCaseString;
}

string StrUtil:: stripPunctuation (const string & sa){
    string s=sa;
    if (s[0]=='\0'){
        //printf ("endchar reached \n");
        return s;
    }
    else{
        //printf("char is %c \n",(s[0]));
        if (((((int)s[0])<48)
            ^(((((int)s[0]))>57)&((((int)s[0]))<65))
            ^((((((int)s[0]))>90)&((((int)s[0]))<97))) //reading range of acceptable (non-punctuation)  ascii characters
            ^((((int)s[0]))>122))
            &(((int)s[0])!=32)){
            //printf ("deleting char: %c\n", s[0]);
            s.erase(s.begin());
            //printf ("s after upper erase: %s \n", s.c_str());
            return (stripPunctuation (s));
            
        }
        else{
            string b;
            b.append(s.substr(0,1));
            s.erase(s.begin());
            //printf ("s after lower erase: %s, b= %s\n", s.c_str(),b.c_str() );
            return (b+stripPunctuation(s));
            
        }
    }
}

string StrUtil:: firstSpaceRemove(const string & sa){
    string s=sa;
    if (s[0]=='\0'){
        //printf ("endchar reached \n");
        return s;
    }
    //printf ("s[0]: %c \n", (s[0]));
    if ((s[0])!=' '){
        return s;
    }
    else s.erase(s.begin());
    printf ("new %s",s.c_str());
    return firstSpaceRemove(s);
}

string StrUtil:: removeExtraWhitespace(const string & sa){
    string s=sa;
    if (s[0]=='\0'){
        //printf ("endchar reached \n");
        return s;
    }
    else{
        //printf ("s[0]=%c s[1]=%c \n", s[0], s[1]);
        //printf("char is %c \n",(s[0]));
        if ((((int)s[0])==' ')&(((int)s[1])==' ')){
            //printf ("deleting char: %c\n", s[0]);
            s.erase(s.begin());
            //printf ("s after upper erase: %s \n", s.c_str());
            return (removeExtraWhitespace (s));
            
        }
        else{
            string b;
            b.append(s.substr(0,1));
            s.erase(s.begin());
            //printf ("s after lower erase: %s, b= %s\n", s.c_str(),b.c_str() );
            return (b+removeExtraWhitespace(s));
            
        }
    }
}

int StrUtil::compareIgnoreCase(const string & s1, const string & s2){
    
    //returns a compare() value for the two entered strings when converted to lower case
    
    string news1=toLowerCase(s1);
    string news2=toLowerCase(s2);
    return news1.compare(news2);
    
}

bool StrUtil::startsWith(const string & s, const string & prefix){
	//answer whether s starts with prefix	
	if(prefix.length() > s.length()) return false;
	return (prefix.compare(s.substr(0, prefix.length())) == 0);
}

bool StrUtil::endsWith(const string & s, const string & suffix){
	//answer whether s ends with suffix	
	if(suffix.length() > s.length()) return false;
	return (suffix.compare(s.substr(s.length()-suffix.length(), suffix.length())) == 0);
}
bool StrUtil::isComment(const string & s){
	//answer whether s is a comment string
	//comment strings start with "//" prefix
	
	string trimmed = StrUtil::trim(s);
    string commentPrefix = "//";
	return StrUtil::startsWith(trimmed, commentPrefix);
}



