/*2つの粒子AとBがある。AとBはそれぞれ重さ120 g/molとする。
自然長3.5 Åのバネ（バネ定数 200 kcal/mol・Å^2）でAとBがつながっているとき、
A-B間距離を横軸にとり、エネルギー値をグラフにしてください。*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist"
#define l 3.5 //自然長
#define k 200 //バネ定数
#define FILENAME "EnergyDistance.txt"
double U (double x);

int main(void){

  double Eu[21];
  Eu[0]=0;
  double Dis[21];
  Dis[0]=0;
  double x=0;
  int i = 0;
  int j = 0;

  for(x=0; x<=10; x = x+0.5){
      Eu[i] = U(x);
      Dis[i] = x;
      i++;
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
  for(j=0; j<i; j++){
    fprintf(fp, "%lf %lf\n",Dis[j],Eu[j]);
  }

  fclose(fp);

/*Gnuplotで描図*/
      FILE *gp; //ファイル呼び出し
/*Open*/
  if ((gp = popen(GNUPLOT, "w")) == NULL) {
  fprintf(stderr, "Error: cannot open \"%s\".\n", GNUPLOT);
  exit(1);
  }
  /*設定*/
  /*目盛り*/
  fprintf(gp, "set tics nomirorr font 'Arial,20'\n");
  /*ラベル*/
  fprintf(gp, "set xlabel 'Distance[Å]' font 'Arial,24' offset 0,-1\n");
  fprintf(gp, "set ylabel 'PotentialEnergy' font 'Arial,24' offset -7,0\n");
  /*余白*/
  fprintf(gp, "set lmargin 18\n");//y軸
  fprintf(gp, "set bmargin 3\n");//x軸
  /*枠線*/
  fprintf(gp, "set border lw 2.5\n");
  /*サイズ*/
  fprintf(gp, "set size ratio 0.625\n");
  /*凡例*/
  fprintf(gp, "unset key\n");


  /*描図*/
  fprintf(gp, "plot \"%s\" with linespoints lt 7 lw 3\n", FILENAME);
  
  /*Close*/
  if (pclose(gp) == EOF) {
  fprintf(stderr, "Error: cannot close \"%s\".\n", GNUPLOT);
  exit(2);
  }
  
  return 0;
}

double U (double x){
	double Ux;
    Ux = 0.5 * k * (pow( (x-l), 2) );
	return Ux;
}
