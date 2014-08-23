#include "stdio.h"

char *Haab[] = {
"pop",	  "no",	    "zip",    "zotz", 
"tzec",	  "xul",	"yoxkin", "mol", 
"chen",	  "yax",	"zac",    "ceh", 
"mac",	  "kankin", "muan",	  "pax", 
"koyab",  "cumhu",  "uayet"
};

char *Holly[] = {
"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk",
"ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

int main() 
{
	int i, j, n;
	int days;
	char mon[8];
	char *str;

	int month, day, year;
	int num;

	scanf("%d", &n);
	printf("%d\n", n); //千万注意！
	for (j = 0; j < n; j++)
	{
		days = 0;
		scanf("%d.%s%d", &day, mon, &year);

		// resolve the month
		str = mon;
		for (i = 0; i < 19; i++)
		{ 
			if (Haab[i][0] == str[0] && Haab[i][1] == str[1]) {
				break;
			}
		}
		month = i;
		
		// resolve the day
		days = year*365 + month*20 + day;
		year = days / 260;
		num = days % 13 + 1;
		day = days % 20;

		// mapping
		printf("%d %s %d\n", num, Holly[day], year);
	}		
	
	return 0;
}
