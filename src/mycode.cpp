#include "../inc/mycode.hpp"

#include "foo.cpp"

int main(int ArgCount, char *Args[])
{
	if(1 < ArgCount)
	{
		u8 ValidOptionCtr	= 0;

	    b8x VerboseOut = 0;
	    b8x LogData = 0;
	    u32 MaxData = 0;

		for(u8 j = 1; j < (u8) ArgCount; j++)
	    {
			for(u8 i = 0; ARGUMENTS > i; i++)
	    	{
				if(Args[j][1] == Arguments[i])
	        	{
						ValidOptionCtr++;
						switch(i)
						{
							case 0: {VerboseOut = 1;break;}		/* -v */
							case 1: {LogData = 1;break;}		/* -l */
							case 2: {j++;ValidOptionCtr++;MaxData = atoi(Args[j]);break;}	/* -t %d */
							default: {printf("%s", HelpStr);return 0;}	/* -h */
						}
					}
				}
			}
			if(ValidOptionCtr != (ArgCount-1)) {
				printf("%s", HelpStr);
				return 0;
			}
	}
	else
	{
		printf("Please provide arguments!\n");
		printf("%s", HelpStr);
		return 0;
	}
	printf("You are executing this program!\n");
	myFunction();

	return 0;
}
