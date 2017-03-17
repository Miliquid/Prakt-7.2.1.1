#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

class Shape {
protected:
		 double x, y, z;
public:
	Shape(float xc, float yc, float zc) {
		x = xc;
		y = yc;
		z = zc;
	}
	~Shape() {}
	void setX(float xlol) { x = xlol; }
	void setY(float ylol) { y = ylol; }
	void setZ(float zlol) { z = zlol; }

	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	virtual float ob()
	{
		return x*y*z;
	}
};

class Sphere : public Shape
{
public:
	Sphere(float xc1, float yc1, float zc1, float rc1) : Shape(xc1, yc1, zc1) {
		r = rc1;
	}
	~Sphere() {}
	void setR(float rlol) { r = rlol; }
	float getR() { return r; }
	float ob() {
		return r*r*r * 4 * 3.14 / 3;
	}
private:
	float r;
};
class Ellipsoid : public Shape {
private:
	float a, b, d;
public:
	Ellipsoid(float xc, float yc, float zc, float ac, float bc, float dc) : Shape(xc, yc, zc)
	{
		a = ac;
		b = bc;
		d = dc;
	}

	~Ellipsoid() {}
	inline float ob()
	{
		return a*b*d * 4 * 3.14 / 3;
	}
	void setA(float newA)
	{
		a = newA;
	}
	float getA()
	{
		return a;
	}
	void setB(float newB)
	{
		b = newB;
	}
	float getB()
	{
		return b;
	}
	void setD(float newD)
	{
		d = newD;
	}
	float getD()
	{
		return b;
	}
};

int main() {
	setlocale(LC_ALL, "RUS");
	Sphere s1(1, 2, 3, 4);
	Sphere *uk1 = &s1;
	cout << "\nCenter Corrdinates:\n x=" << uk1->getX();
	cout << "\ny=" << uk1->getY();
	cout << "\nz=" << uk1->getZ();
	cout << "\n Radius:" << uk1->getR();
	cout << "\n Capacity:" << uk1->ob();
	Shape *uk2;
	uk2 = uk1;
	cout << "\n Center Coordinates:\nx=" << uk2->getX();
	cout << "\ny=" << uk2->getY();
	cout << "\nz=" << uk2->getZ();
	Shape *u1, *u2;
	u1 = new Shape(1, 2, 3);
	u2 = new Ellipsoid(4, 5, 6, 7, 8, 9);

	cout << "\nÎáúåì ôèãóðû = " << u1->ob();
	cout << "\nÎáúåì ýëèïñà = " << u2->ob();
	system("pause");
	return 0;
}