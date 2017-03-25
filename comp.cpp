#include <iostream>
#include <math.h>

using namespace std;

class C
{
    public:
	double im, re;
	C(){
        re = im = 0;
	}
	C(double nre) : re(nre), im(0.0)
	{ }
	C(double nre, double nim) : re(nre), im(nim)
	{ }
	C(const C &cl) : re(cl.re), im(cl.im)
	{ }
	double abs(){
    	    return sqrt((im)*(im)+(re)*(re));
	}

	friend std::ostream& operator<< (std::ostream &os, const C &cl){
            os << cl.re << " " << cl.im << std::endl;
	    return os;
	}

	C operator+ ( C );
	C operator- ( C );
	C operator* (C);
	C operator/ (C);
	bool operator== ( C );
	bool operator!= (C);

	C operator+ (double);
	C operator- (double);
	C operator* (double);
	C operator/ (double);
	bool operator== (double);
	bool operator!= (double);

	friend C operator+ (double, C);
	friend C operator- (double, C);
	friend C operator* (double, C);
	friend C operator/ (double, C);
	friend bool operator== (double, C);
	friend bool operator!= (double, C);
	};

bool operator!= (double z, C cl){
    C nn(z);
    C nn2(cl.re, cl.im);
    return nn != nn2;
}

bool operator== (double z, C cl){
    C nn(z);
    C nn2(cl.re, cl.im);
    return nn == nn2;
}

C operator* (double z, C cl){
    return C(z * cl.re, z * cl.im);
}

C operator/ (double z, C cl){
    C nn(z);
    return nn / cl;
}

C operator- (double z, C cl){
    C nn(z);
    return nn - cl;
}

C operator+  (double z,C cl) {
    C nn(z);
    return nn + cl;
}

C C::operator- (double z){
    double ren = re - z;
    return C(ren, im);
}

C C:: operator/ (double z){
    C nc(re, im);
    C nc2(z);
    return nc / nc2;
}

C C::operator+ (double z){
    double ren = z + re;
    double imn = im;
    return C(ren, imn);
}

bool C::operator!= (double z){
    C nn(re, im);
    C nn2(z);
    return nn == nn2;
}

bool C::operator== (double z){
    C nn(z);
    C nn2(re, im);
    return nn == nn2;
}

C C::operator* (double z){
    return C (re * z, im * z);
}


C C::operator/ (C cl){
    double ren1 = (re * cl.re + im * cl.im);
    double ren2 = (cl.re * cl.re + cl.im * cl.im);
    double imn1 = (cl.re * im - re * cl.im);
    double imn2 = (cl.re * cl.re + cl.im * cl.im);
    return C (ren1/ren2, imn1/imn2);
}

C C::operator* (C cl){
    double ren = re * cl.re - im * cl.im;
    double imn = re * cl.im + cl.re * im;
    return C (ren, imn);
}

bool C::operator!= (C cl){
    bool u;
    if (re != cl.re || im != cl.im)
	u = true;
    else
	u = false;
    return bool (u);
}

bool C::operator== (C cl){
    bool u;
    if (re == cl.re && im == cl.im)
	u = true;
    else
	u = false;
    return bool (u);
}

C C::operator- (C cl){
    double ren = re - cl.re;
    double imn = im - cl.im;
    return C (ren, imn);
}

C C::operator+ (C cl2){
    double ren = re + cl2.re;
    double imn = im + cl2.im;
    return C (ren, imn);
}

int main(){
    C a(1, 1);
    cout <<a.abs()  << "\n";
    C b(2, 2);
    C c = a - b;
    cout << c.re << " " << c.im << "\n";
    double j = 2;
    if (j != a)
	cout << "OK\n";
    double i = 2;
    C q =  i - a;
    cout << q;
    return 0;
}