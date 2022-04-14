#ifndef __MAIN_CODE__
#define __MAIN_CODE__


#include <cstdio>

#include "../inc/common.hpp"

#define ARGUMENTS 4

gconst char Arguments[ARGUMENTS]	=	{'v', 'l', 't', 'h'};

gconst char HelpStr[]	=	"usage: myCode [option 1] [option 2] ... [option n]\n"
							"Options:\n"
							"\t-v:\t\t"			"enable verbose output.\n"
							"\t-l:\t\t"			"enable storage of received data.\n"
							"\t-t time:\t"		"specify the maximum capture time in seconds.\n"
							"\t-h:\t\t"			"display this help information.\n\n";
#endif
