#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>
//Ensure safe array size based on highly composite numbers up to ULONG_MAX (2^64-1), using https://gist.github.com/dario2994/fb4713f252ca86c1254d as reference.
#define max_size 104000

typedef unsigned long long ull;

int sort(const void* a,const void* b){
    return (*(const ull*)a)< (*(const ull*)b)? -1: (*(const ull*)a)> (*(const ull*)b) ? 1 : 0;
}

void factor_count(ull number){
ull factors = 0;
ull *factor_array=calloc(max_size,sizeof(ull));
if(factor_array == NULL){
    printf("Unable to allocate memory to factor array, exiting...");
    exit(EXIT_FAILURE);
}
if((ull)sqrt(number)*(ull)sqrt(number) == number){
    factor_array[factors]=(ull)sqrt(number);
    factors+=1;
}
for(ull i=1;i<(ull)ceil(sqrt(number));i++){
    if(number%i==0){
        factor_array[factors]=i;
        factor_array[factors+1]=number/i;
        factors+=2;
    }
}
factor_array = realloc(factor_array,(factors)*sizeof(ull));
qsort(factor_array,factors,sizeof(ull),sort);
printf("{");
 for(ull i=0;i<factors;i++){
    i == factors-1 ? printf("%llu",factor_array[i]):printf("%llu,",factor_array[i]);
 }
 printf("}\n");
 factors == 2 ? printf("%llu is prime because it has 2 factors.\n",number) : printf("%llu is not prime because it has %llu factor(s).\n",number,factors);
 free(factor_array);
}

int main(){
    while(1==1){
    ull number_test;
    char buffer[1024];
    int success;
    //Extensive input validation by https://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html with some modifications for ULL.
    do{
        printf("Enter a number or 'q' to quit: ");
        //If input has failed to get anything
        if(!fgets(buffer,1024,stdin)){
            printf("Unable to get a reading, exiting...");
            exit(EXIT_FAILURE);
        }
        errno = 0;
        char *endptr;
        //Prevent negatives from ruining the factor calculations
         if(strncmp(&buffer[0],"-",1)==0){
            errno=ERANGE;
        }
        number_test=strtoull(buffer,&endptr,10);
        //Quitting is now case insensitive
        if(strlen(buffer)==2 && strnicmp(buffer,"q",1)==0){
            printf("Thank you for running the factor counter, exiting...");
            exit(EXIT_SUCCESS);
        }
        else if(endptr==buffer){
            printf("Please input a valid number between 1 and 18446744073709551615, as you pressed 'enter' without inputting anything.\n");
            success=0;
        }
        else if(errno==ERANGE || number_test==0){
            printf("Please input a valid number between 1 and 18446744073709551615, as your number is too small or large.\n");
            success=0;
        }
        else if(*endptr && *endptr != '\n'){
            printf("Please input a valid number between 1 and 18446744073709551615, as you have non-digit characters in your input.\n");
            success=0;
        }
        else{
            success=1;
        }
    }while(!success);
    factor_count(number_test);
    }
    return 0;
}