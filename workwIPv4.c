// 12/12/2019
// IP Calculator in C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function converts decimal to binary and returns the binary number.
long long bincnv(int num)
{	long long bin = 0;
    int rem, i = 1, step = 1;
    while (num != 0) 
	{   rem = num % 2;
        num /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

// This function extracts the IP address and returns the IP address in decimal.
void extrAdd(unsigned char *sourceString, short *ip) 
{	unsigned short len = 0;
  	unsigned char  oct[4] = {0}, cnt = 0, cnt1 = 0, i, buf[5];
    len = strlen(sourceString);
   	for(i = 0; i < len; i++)
	{	if(sourceString[i] != '.')
		{	buf[cnt++] = sourceString[i];		 
	  	}
	 	if(sourceString[i] == '.' || i == len - 1)
		{	buf[cnt] = '\0';				 
         	cnt = 0;								
        	oct[cnt1++] = atoi(buf);
    	}
	}
    ip[0] = oct[0];
    ip[1] = oct[1];				
    ip[2] = oct[2];
    ip[3] = oct[3];
}

// This function returns the subnet mask.
int mask(int sub, int ss)
{   int sol;
    if(sub == 0 && ss == 1)
        sol = 8;
		
	else if(sub == 128 && ss == 1)
        sol = 9;
		
	else if(sub == 192 && ss == 1)
        sol = 10;

	else if(sub == 224 && ss == 1)
        sol = 11;
		
	else if(sub == 240 && ss == 1)
        sol = 12;

	else if(sub == 248 && ss == 1)
        sol = 13;

	else if(sub == 252 && ss == 1)
        sol = 14;

	else if(sub > 252 && ss == 1)
        sol = 15;
	
    else if(sub == 0 && ss == 2)
        sol = 16;
		
	else if(sub == 128 && ss == 2)
        sol = 17;
		
	else if(sub == 192 && ss == 2)
        sol = 18; 

	else if(sub == 224 && ss == 2)
        sol = 19;
		
	else if(sub == 240 && ss == 2)
        sol = 20;

	else if(sub == 248 && ss == 2)
        sol = 21;

	else if(sub == 252 && ss == 2)
        sol = 22;

	else if(sub > 252 && ss == 2)
        sol = 23;
    
    else if (sub == 0)
        sol = 24;
		
	else if(sub == 128)
        sol = 25;

    else if(sub == 192)
        sol = 26;

	else if(sub == 224)
        sol = 27;

	else if(sub == 240)
        sol = 28;
		
	else if(sub == 248)
        sol = 29;
            
	else if(sub == 252)
        sol = 30;
	
    return sol;
} 

// Main function
int main()
{   unsigned char ip[20] = {0}, subN[20] = {0}; 	// ip[20] and subN[20] are the IP address and the subnet mask respectively.
    short ipAdd[4], subAdd[4];						// ipAdd[4] and subAdd[4] are the IP address and the subnet mask in decimal respectively.
	long long bin[4], binsub[4];					// bin[4] and binsub[4] are the IP address and the subnet mask in binary respectively.
	int num, func = 0, i = 0;						
    char cls[10];									// cls[10] is the class of the IP address.

    printf("Give the IP Address  : ");
    scanf("%s", ip);					 
    extrAdd(ip, &ipAdd[0]);
	printf("Give the Subnet Mask : "); 
	scanf("%s", subN);
	extrAdd(subN, &subAdd[0]);

    // This if-else if-else statement determines the class of the IP address.
	if(ipAdd[0] >= 0 && ipAdd[0] < 127)	
     	sprintf((char*)cls,"Class A");

    else if(ipAdd[0] >= 127 && ipAdd[0] < 192)
      	sprintf((char*)cls,"Class B");

    else if(ipAdd[0] >= 191 && ipAdd[0] < 224)
     	sprintf((char*)cls,"Class C");

    else if(ipAdd[0] >= 224 && ipAdd[0] < 240)
		sprintf((char*)cls,"Class D");

	else if(ipAdd[0] >= 240 && ipAdd[0] <= 255)
		sprintf((char*)cls,"Class E");

	// This loop converts the IP address and the subnet mask to binary.	
	while(i < 4)
	{	num = subAdd[i];
		binsub[i] = bincnv(num);
		if(subAdd[i] != 255 && i > 0 && func == 0)
        {    func = mask(num, i);
        }
		num = ipAdd[i];
		bin[i] = bincnv(num);
		i++;
	} 
	
	printf("========= IP ADDRESS : %s ----------> %03d. %03d. %03d. %03d  /%d\n", cls, ipAdd[0], ipAdd[1], ipAdd[2], ipAdd[3], func);
	printf("========= IP(BINARY VERSION) ------------> %08lld. %08lld. %08lld. %08lld \n", bin[0], bin[1], bin[2], bin[3]);    
	printf("========= SUBNETMASK  -------------------> %03d. %03d. %03d. %03d\n", subAdd[0], subAdd[1], subAdd[2], subAdd[3]); 
	printf("========= SUBNETMASK(BINARY VERSION) ----> %08lld. %08lld. %08lld. %08lld \n", binsub[0], binsub[1], binsub[2], binsub[3]);
	return 0;
}