#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>
#include <iostream>
#include <atomic>
using namespace std;

int main(void){
  if (wiringPiSetup () == -1)
    return 1 ;
  std::atomic<bool> out (false);
  pinMode (1, OUTPUT);
  pinMode (4,OUTPUT);
  pinMode (27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode (29,INPUT);
  pinMode(24,INPUT);
  FILE *ptr=fopen("black.txt","wb");

int value = 0,grey=0,value1=0;
int j=0;
long int c=3;
int cp=0,a=2;
int r=0,g,b;
    while (r!=-1)
    { 
        j++;
        std::cin>>r;
        std::cin>>g;
        std::cin>>b;
         if(r!=-1)
         {
            for(int i=0;i<8;i++)
            {
     	        digitalWrite(27,r%2);r=r>>1;
     	        digitalWrite(4,b%2);b=b>>1;
     	        digitalWrite(28,g%2);g=g>>1;
              digitalWrite(1,out);
   	          out=!out;
   	          digitalWrite(1,out); 
      	      out=!out; 
              value = digitalRead(29);
              grey=(grey<<1)+value; 	      
            }  
             value1 = digitalRead(24);
             fprintf(ptr,"%d\n",value1);
             printf("%d\n",grey);
             grey=0;     
          }  
        
        
   }
   r=0;g=0;b=0;
   for(int i=0;i<8;i++)
   {
           digitalWrite(27,r%2);r>>1;
           digitalWrite(4,b%2);b>>1;
           digitalWrite(28,g%2);g>>1;
           digitalWrite(1,out);
           out=!out;

           value = digitalRead(29);
   }  
    value1 = digitalRead(24);
    fprintf(ptr,"%d\n",value1);
    printf("%d\n",grey);
    grey=0;
    fclose(ptr);
}