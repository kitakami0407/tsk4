/*2つの粒子AとBがある。AとBはそれぞれ重さ120 g/molとする。
自然長3.5 Åのバネ（バネ定数 200 kcal/mol・Å^2）でAとBがつながっているとき、
A-B間距離を横軸にとり、エネルギー値をグラフにしてください。*/

#include <stdio.h>
#include <math.h>

#define Ma 120 //質量
#define Mb 120 //質量
#define l 3.5 //自然長
#define k 200 //バネ定数

double Myu;
  Myu = (Ma * Mb)/(Ma + Mb);

double Sigma;
  Omega = sqrt(k/Myu);

int main(void){

}

double E(double x){
  double Ex;
    Ex = 0.5 * k * pow((x - l), 2)
}