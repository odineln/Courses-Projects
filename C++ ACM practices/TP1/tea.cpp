#include<stdio.h>
int main(){
	int T,c,compt;
	while (scanf("%d",&T)==1){
		compt=0;
		for (int i=0; i<5; i++){
			scanf("%d",&c);
			if (T==c){
				compt++;
			}
		}
	printf("%d\n",compt);
	}
	return 0;
}