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

#ifndef STR_UTIL_H
#define STR_UTIL_H

#include <string>
#include <sstream>
using namespace std;

//String Utilties Class
//Should this be done by sub-classing the <string> lib?

class StrUtil
{
  public:
    static string trim(const string & s);
    static string toTitleCase(const string & s);
    static string toUpperCase(const string & s);
    static string toLowerCase(const string & s);
    static string stripPunctuation (const string & s);
    static string firstSpaceRemove(const string & sa);
    static string removeExtraWhitespace (const string & s);
    static int compareIgnoreCase (const string & s1, const string & s2);
    static bool startsWith(const string & s, const string & prefix);
    static bool endsWith(const string & s, const string & suffix);
    static bool isComment(const string & s);
};

#endif
