#include<stdio.h>
#include<math.h>
#include<signal.h>

//An array with 100 elements have values described as; e^index if index is odd, and ln(index) in index is even. 
//The array is displayed one element value per line with index. 

void INThandler(int sig);

int main(){
	double x,y;
	int array[100];
	printf("Please enter values of array:");
	int i;
	for(i=0;i<100;i++){
		
		scanf("%d",&array[i]);
		
		if(array[i]%2==0){
			
			x=exp(array[i]);//The exp () function is the function that performs e ^ arg.
			
			printf("e^%d=%.2f\n",array[i],x);
		}
		
		else{
			
			y=log(array[i]);//The log() function is that performs ln(arg).
			
			printf("ln(%d)=%.2f\n",array[i],y);
		}
		
		signal(SIGINT,INThandler);
		
	}

	return 0;
}
void INThandler(int sig){
	
	signal(sig,SIG_IGN);
	exit(1);
}


