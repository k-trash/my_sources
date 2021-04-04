#include <iostream>
#include <cstdlib>
#include <cmath>
#include <complex.h>

void solveCubic(std::complex<double> x3_[3], double a3_, double b3_, double c3_, double d3_);
void solveQuartic(std::complex<double> x4_[4], double a4_, double b4_, double c4_, double d4_, double e4_);
double solveRoot3(double x3_);
std::complex<double> solveRootI(std::complex<double> xi_);

int main(int argc, char *argv[]){
	std::complex<double> x[4];
	double abcde[5];
	std::string str[] = { "a: ", "b: ", "c: ", "d: ", "e: "};	

	for(int i=0;i<5;i++){
		std::cout << str[i];
		std::cin >> abcde[i];
	}

	solveQuartic(x, abcde[0], abcde[1], abcde[2], abcde[3], abcde[4]);

	for(int i=0;i<4;i++){
		std::cout << real(x[i]) << " + " << imag(x[i]) << std::endl;
	}

	return 0;
}

void solveCubic(std::complex<double> x3_[3], double a3_, double b3_, double c3_, double d3_){
	double disc, con_a, con_b, con_c, con_p, con_q;
	double theta, double con_u, double con_v;

	if(a3_ == 0.0f){
		std::cout << "a = 0.0" << std::endl;
		exit(1);
	}

	con_a = b3_ / a3_;
	con_b = c3_ / a3_;
	con_c = d3_ / a3_;
	con_p = con_b - (con_a * con_a / 3.0f);
	con_q = (2.0f * con_a * con_a * con_a / 27.0f) - (con_a * con_b / 3.0f) + con_c;
	disc = (con_q * con_q / 4.0f) + (con_p * con_p * con_p / 27.0f);
	if(disc < 0.0f){
		theta = atan2(sqrt(-disc), -con_p * 0.5f);
		x3_[0] = (2.0f*sqrt(-con_p/3.0f) * cos(theta / 3.0f)) - (con_a / 3.0f);
		x3_[1] = (2.0f*sqrt(-con_p/3.0f)) * cos((theta+(2.0f*M_PI))/3.0f) - (con_a/3.0f);
		x3_[2] = (2.0f*sqrt(-con_p/3.0f)) * cos((theta+(4.0f*M_PI))/3.0f) - (con_a/3.0f);
	}else{
		con_u = solveRoot3((-con_p * 0.50f) + sqrt(disc));
		con_v = solveRoot3((-con_p * 0.50f) - sqrt(disc));
		x3_[0] = con_u + con_v - (con_a / 3.0f);
		x3_[1] = (-0.5f*(con_u+con_v)) + (sqrt(3.0f)*0.5f*1i*(con_u-con_v)) - (con_a/3.0f);
		x3_[2] = (-0.5f*(con_u+con_v)) - (sqrt(3.0f)*0.5f*1i*(con_u-con_v)) - (con_a/3.0f);
	}
}

void solveQuartic(std::complex<double> x4_[4], double a4_, double b4_, double c4_, double d4_, double e4_){
	double con_a, con_b, con_c, con_d, con_p, con_q, con_r;
	double epsilon_temp = 0.000001f;
	double con_t;
	std::complex<double> t_temp[3], con_m;
	
	if(a4_ == 0.0f){
		std::cout << "a = 0.0f" << std::endl;
	}

	con_a = b4_ / a4_;
	con_b = c4_ / a4_;
	con_c = d4_ / a4_;
	con_d = e4_ / a4_;
	con_p = (-3.0f * con_a * con_a / 8.0f) + con_b;
	con_q = (con_a * con_a * con_a / 8.0f) - (2.0f * con_a * con_b / 4.0f) + con_c;
	con_r = (-3.0f*con_a*con_a*con_a*con_a/256.0f) + (con_b*con_a*con_a/16.0f) - (con_c*con_a/4.0f) + con_d;

	solveCubic(t_temp, 1.0f, -con_p, -4.0f*con_r, (4.0f*con_p*con_r)-(con_q*con_q));
	con_t = creal(t_temp[0]);
	con_m = solveRootI(con_t-con_p);
	
	x4_[0] = ((-con_m + solveRootI(-con_t-con_p+(2.0f*con_q/con_m))) * 0.5f) - (con_a / 4.0f);
	x4_[1] = ((-con_m - solveRootI(-con_t-con_p+(2.0f*con_q/con_m))) * 0.5f) - (con_a / 4.0f);
	x4_[2] = (( con_m + solveRootI(-con_t-con_p-(2.0f*con_q/con_m))) * 0.5f) - (con_a / 4.0f);
	x4_[3] = (( con_m - solveRootI(-con_t-con_p-(2.0f*con_q/con_m))) * 0.5f) - (con_a / 4.0f);
}

double solveRoot3(double x3_){
	if(x3_ > 0.0f){
		return pow(x3_, 1.0f/3.0f);
	}else{
		return -pow(-x3_, 1.0f/3.0f);
	}
}

std::complex<double> solveRootI(std::complex<double> xi_){
	std::complex<double> val_y;
	double con_r, theta;
	
	con_r = sqrt((creal(xi_)*creal(xi_))+(cimag(xi_)*cimag(xi_)));
	theta = atan2(cimag(xi_), creal(xi_));

	if(cimag(xi_) == 0.0f){
		if(creal(xi_) > 0.0f){
			val_y = sqrt(con_r);
		}else{
			val_y = sqrt(con_r) * 1i;
		}
	}else{
		if(theta < 0.0f){
			theta += 2.0f * M_PI;
		}
		val_y = sqrt(con_r) * (cos(theta*0.5f) + (1i * sin(theta*0.5f)));
	}

	return val_y;
}
