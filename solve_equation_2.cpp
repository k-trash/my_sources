//Ver1.0 2020/04/04 k-trash

#include <iostream>
#include <cstdlib>
#include <cmath>

double solveRoot3(double x_);
void solveCubic(double a3_, double b3_, double c3_, double *ans3_);
void solveQuartic(double a4_, double b4_, double c4_, double d4_, double *ans4_);

int main(int argc, char *argv[]){
	double abcd[4];
	double ans[8];

	for(int i=0;i<4;i++){
		std::cout << "b: ";
		std::cin >> abcd[i];
	}

	std::cout << "x^4 + "
	for(int i=0;i<2;i++){
		std::cout << abcd[i] << "x^" << (3-i) << " + ";
	}
	std::cout << abcd[2] << "x + " << abcd[3];

	solveQuartic(abcd[0], abcd[1], abcd[2], abcd[3], ans4);
	
	for(int i=0;i<4;i++){
		std::cout << ans4[i] << '\t' << ans4[i+4] << std::endl;
	}

	return 0;
}

double solveRoot3(double x_){
	if(x_ > 0.0f){
		return pow(x_, 1.0f/3.0f);
	}else{
		return -pow(-x_, 1.0f/3.0f);
	}
}

void solveCubic(double a3_, double b3_, double c3_, double *ans3_){
	double con_u, con_v;
	double con_a, con_b, con_c, con_d, con_f, con_r, con_q, con_s, con_t;
	double con_p, con_q, theta, con_x, con_y;

	con_p = b3_ - (a3_ * a3_ / 3.0f);
	con_q = c3_ - (b3_ * a3_ / 3.0f) + (2.0f * a3_ * a3_ * a3_ / 27.0f);
	con_d = -((con_q * con_q) + (4.0f * con_p * con_p * con_p)) / (54.0f*54.0f);
	con_a = -a3_ / 3.0f;
	con_b = -con_q / 2.0f;
	con_c = sqrt(fabs(con_d));

	for(int i=0;i<5;i++){
		ans3[i] = 0.0f;
	}

	if(con_d == 0.0f){
		if(con_q == 0.0f){
			for(int i=0;i<3;i++){
				ans3_[i] = con_a;
			}
		}else{
			con_f = solveRoot3(con_b);
			ans3_[0] = con_a + (2.0f * con_f);
			ans3_[1] = ans3_[2] = con_a - con_f;
		}
	}else if(con_d > 0.0f){
		con_x = (con_b * con_b) + con_d;
		con_y = pow(con_x, 1.0f/6.0f);
		theta = atan2(con_c, con_b) / 3.0f;
		con_r = con_y * cos(theta);
		con_q = con_y * sin(theta) * sqrt(3.0f);
		ans3_[0] = con_a + (2.0f * con_r);
		ans3_[1] = con_a - con_r - con_q;
		ans3_[2] = con_a - con_r + con_q;
	}else{
		con_s = solveRoot3(con_b+con_c);
		con_t = solveRoot3(con_b-con_c);
		con_y = sqrt(3.0f) / 2.0f;
		ans3_[0] = con_a + con_s + con_t;
		ans3_[1] = ans3_[2] = con_a -((con_s + con_t) / 2.0f);
		ans3_[3] = (con_s - con_t) * con_y;
		ans3_[4] *= -1.0f;
	}
}

void solveQuartic(double a4_, double b4_, double c4_, double d4_, double *ans4_){
	double con_b, con_p, con_q, con_r, con_w, con_x, con_y, con_z;
	double dp, dm, rt_dp, rt_dm, con_s, con_t, con_u;
	double ans3[5];

	con_b = a4_ / 4.0f;
	con_p = b3_ - (6.0f * con_b * con_b);
	con_q = c3_ - (2.0f * b3_ * con_b) + (8.0f * con_b * con_b + con_b);
