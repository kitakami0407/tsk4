/*2つの粒子AとBがある。AとBはそれぞれ重さ120 g/molとする。
自然長3.5 Åのバネ（バネ定数 200 kcal/mol・Å^2）でAとBがつながっているとき、
A-B間距離を横軸にとり、エネルギー値をグラフにしてください。*/

#include <stdio.h>
#include <math.h>

#define l 3.5 //自然長
#define k 200 //バネ定数
#define FILENAME "EnergyDistance.txt"
double U (double x);

int main{

	double Eu[];
		Eu[0]=0;
	double Dis[];
		Dis[0]=0;
	double x=0;
	int i = 0;
	int k = 0;

	for(x; x<=10; x+0.5){
		Eu[i] = U(x);
		Dis[i] = x
		i++
	}
	
	FILE *fp;
		fp = fopen(FILENAME, "w");
		if(fp == NULL){
				printf("ファイルをオープンできませんでした。\n");
				return 1;
		}
		else{
				printf("ファイルをオープンしました。\n");
		}
		while(k<=i){
			fprintf(fp, "%d %llu\n",Dis[k],Eu[k]);
			k++;
		}
		fclose(fp);
}

double U (double x){
  double Ux;
    Ux = 0.5 * k * (pow( (x-l), 2) );
	return Ux;
}