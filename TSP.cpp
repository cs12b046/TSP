#include<stdio.h>
#include<iostream>
#include<stdlib.h>
float eval(float** dist,int* path,int num);
int main()
{
	int num;			//no of cities
	scanf("%d",&num);
	float* x;			//array of x cordinate of the cities
	float* y;			//array of y cordinate of cities
	float** dist;			//nXn matrix of distances
	x=(float*)malloc(num*sizeof(float));
	y=(float*)malloc(num*sizeof(float));
	dist=(float**)malloc(num*sizeof(float*));
	for(int i=0;i<num;i++){
		scanf("%f",&x[i]);
		scanf("%f",&y[i]);
	}
	for(int i=0;i<num;i++){
		*(dist+i)=(float*)malloc(num*sizeof(float));
		for(int j=0;j<num;j++){
			///dist[i][j]=0;
			scanf("%f",&dist[i][j]);
		}
	}
	int path[3]={1,3,2};
	float c=eval(dist,path,num);
	printf("cost is:%f",c);
	return 0;
}
/************************************
* This function takes distance array as input and path as an array and return cost
* Warning path is starting from 1..n but matrix are 0..n-1 0..n-1 be careful  
*************************************/
float eval(float** dist,int* path,int num){
	float cost=0;
	for(int i=0;i<num-1;i++){
		int c1=path[i]-1;
		int c2=path[i+1]-1;
		cost+=dist[c1][c2];
	}
	return cost;
}
