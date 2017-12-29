/*
###########################################################################
##                                                                       ##
##                Centre for Development of Advanced Computing           ##
##                               Mumbai                                  ##
##                         Copyright (c) 2017                            ##
##                        All Rights Reserved.                           ##
##                                                                       ##
##  Permission is hereby granted, free of charge, to use and distribute  ##
##  this software and its documentation without restriction, including   ##
##  without limitation the rights to use, copy, modify, merge, publish,  ##
##  distribute, sublicense, and/or sell copies of this work, and to      ##
##  permit persons to whom this work is furnished to do so, subject to   ##
##  the following conditions:                                            ##
##   1. The code must retain the above copyright notice, this list of    ##
##      conditions and the following disclaimer.                         ##
##   2. Any modifications must be clearly marked as such.                ##
##   3. Original authors' names are not deleted.                         ##
##   4. The authors' names are not used to endorse or promote products   ##
##      derived from this software without specific prior written        ##
##      permission.                                                      ##
##                                                                       ##
##                                                                       ##
###########################################################################
##                                                                       ##
##                     TTS Building Toolkit                              ##
##                                                                       ##
##            Designed and Developed by Atish and Rachana                ##
##          		Date:  April 2017                                ##
##                                                                       ## 
###########################################################################
*/


#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
		char command[1111];
	 	char str[1111];
		//char *command;
		////////////////////////////////////////////////////////////////sprintf(cmd,"whereis %s",str);
		system("$FESTVOXDIR/src/unitsel/setup_clunits phone level lab");
		
		 

		//system("cp -r ../phoneme/Marathi_PhoneSet.txt bin/");
//		sprintf(str,"cp -r %s%s%s %s","../resources/languages/",argv[1],"/phoneme/PhoneSet.txt","bin/");
//		system(str);

		sprintf(str,"cp -r %s %s","../input/txt.done.data","etc/");
		system(str);
		
		//sprintf(str,"cp -r %s%s%s %s","../resources/languages/",argv[1], "/phoneme/il_parser_hts.pl","bin/");  
		//system(str);

		sprintf(str,"cp %s%s%s %s","../resources/languages/",argv[1], "/phoneme/phone_level_lab_lexicon.scm","festvox/");
		system(str);

		sprintf(str,"rm -rf %s%s%s","../resources/languages/",argv[1], "/phoneme/phone_level_lab_phoneset.scm");
		system(str);

		system("rm -rf festvox/phone_level_lab_phoneset.scm");
		
		sprintf(str,"cat %s%s%s %s","../resources/languages/",argv[1], "/phoneme/phoneset.scm"," > phone_level_lab_phoneset.scm");
		system(str);
	
		sprintf(str,"cat %s%s%s %s","../resources/languages/",argv[1], "/phoneme/phoneset_base.scm"," >> phone_level_lab_phoneset.scm");
		system(str);

		system("cp -r phone_level_lab_phoneset.scm festvox/");
		system("rm -rf phone_level_lab_phoneset.scm");

/////		sprintf(str,"cp -r %s %s","../resources/common/parser/*", "./");
/////		system(str);    //copy parser to current directory
/////		system("make");

		sprintf(str,"cp %s %s","../resources/common/parser/utfparser", "./");
		system(str);

		strcpy(command,"festival -b festvox/build_clunits.scm '(build_prompts \"etc/txt.done.data\")'");   /* generate prompts*/
		printf("\n\n ****Building PHONE level LAB files ****\n\n");
		system(command);
		printf("\n\n ****Completed building PHONE level LAB files ****\n\n");
		
		return 0;
}

