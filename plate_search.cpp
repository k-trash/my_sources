#include<stdio.h>
#include<math.h>

typedef struct Zahyou{ /*座標構造体*/
	/*long*/ double x;
	/*long*/ double y;
	/*long*/ double z;
}Zy;		/*Zyとした*/

int main(void){	
	int s[] = {2,3,5,7,11,13,17,19,23,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,163,167,173,179,181,191,193,197,199,211,223,227,229,241,251,257,263,269,271,277,281,283,293,0};
	int i = 0;  //↑素数一覧　
	double etc;  //+dを格納する

	Zy zy[3];
	Zy ab; //ABベクトル
	Zy ac; //ACベクトル
	Zy hs; //法線ベクトル

	for(i=0;i<4;i++){
		zy[i].x = 0;
		zy[i].y = 0;
		zy[i].z = 0;
	}

	for(i = 1;i <= 3;i++){
		printf("%dつ目の座標を、x,y,zの順に入力してください\n",i);
		scanf(" %lf",&(zy[i-1].x));
		scanf(" %lf",&(zy[i-1].y));
		scanf(" %lf",&(zy[i-1].z));
	}

	for(i = 1;i <= 3;i++){
		printf("%dつ目の座標は（%lf,%lf,%lf）です\n",i,zy[i-1].x,zy[i-1].y,zy[i-1].z);
	}

	printf("以上の座標として面の式を計算します\n");

	ab.x =(zy[1].x - zy[0].x);	//ABベクトルの計算
	ab.y =(zy[1].y - zy[0].y);
	ab.z =(zy[1].z - zy[0].z);
	
	//printf("ab%f %f %f\n",ab.x,ab.y,ab.z);

	ac.x = (zy[2].x - zy[0].x);	//ACベクトルの計算
	ac.y = (zy[2].y - zy[0].y);
	ac.z = (zy[2].z - zy[0].z);

	//printf("ac%f %f %f\n",ac.x,ac.y,ac.z);

	hs.x = (ab.y)*(ac.z) - (ac.y)*(ab.z); /*外積で法線をだす*/
	hs.y = -(ab.x)*(ac.z) + (ac.x)*(ab.z);
	hs.z = (ab.x)*(ac.y) - (ac.x)*(ab.y);

	//	printf("法線%f,%f,%f\n",hs.x,hs.y,hs.z);

	/*
	do //数10倍して、簡単な式にしようと思ったけど、double型の誤差の対策が思いつかなかったため没
	{
		hs.x *= 10;
		hs.y *= 10;
		hs.z *= 10; 
	}while(fmod(hs.x ,1) != 0 || fmod(hs.y , 1) != 0 || fmod(hs.z , 1) != 0);
	*/

	i = 0;	//整数の時、素数表を用いることで少し式が簡単になる。
	while(1){
		if(fmod(hs.x,s[i])==0 && fmod(hs.y,s[i]) == 0 && fmod(hs.z,s[i]) == 0 && s[i]!=0 && hs.x !=0){
			hs.x /= s[i];
			hs.y /= s[i];
			hs.z /= s[i];

			i = 0;
		}else{
			//printf("else");
			i++;
		}if(s[i] ==0)
			break;
	}

	etc = -(hs.x)*(zy[0].x)-(hs.y)*(zy[0].y)-(hs.z)*(zy[0].z);

	//printf("%f",etc);

	printf("面の式は");

	if(hs.x != 0)

	printf("%fx",hs.x);

	if(hs.y>0){
		printf("+%lfy",hs.y);
	}else if(hs.y<0){
		printf("%lfy",hs.y);
	}

	if(hs.z>0){
		printf("+%lfz",hs.z);
	}else if(hs.z<0){
		printf("%lfz",hs.z);
	}

	if(etc>0){
		printf("+%lf = 0 です。",etc);
	}else{
		printf("%lf = 0 です。",etc);
	}

	putchar('\n');	

	return 0;
}
