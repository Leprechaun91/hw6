#include<fstream>
#include<iostream>

using namespace std;

void funktion(double* , const double* , double , double , double );

int main(){

	double tanfang = 0, tende = 100, dt = 0.1;
	int N = tende/dt;
	double array[3];
	array[0] = 10.0;
	array[1] = 28.0;
	array[2] = 8/3.0;

	double x=1,y=1,z=1;
	double k1[3],k2[3],k3[3],k4[3];

	ofstream out("rk.txt");
	out << tanfang << "\t" << x << "\t" << y << "\t" << z << endl;

	for (int i =0; i<N;i++){
		funktion(k1, array, x, y, z);
		funktion(k2, array, x+dt/2*k1[0], y+dt/2*k1[1], z+dt/2*k1[2]);
		funktion(k3, array, x+dt/2*k2[0], y+dt/2*k2[1], z+dt/2*k2[2]);
		funktion(k4, array, x+dt*k3[0], y+dt*k3[1], z+dt*k3[2]);

		x += dt/6*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
		y += dt/6*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
		z += dt/6*(k1[2]+2*k2[2]+2*k3[2]+k4[2]);
	out << i*dt << "\t" << x << "\t" << y << "\t" << z << endl;
 	}

out.close();
return 0;
}

void funktion(double* k, const double* array, double x, double y, double z){
k[0] = array[0]*(y-x);
k[1] = x*(array[1]-z)-y;
k[2] =x*y-array[2]-z;
}
