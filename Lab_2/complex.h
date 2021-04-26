#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>

class Complex {
private:
    double Re;
    double Im;
public:
    Complex(double Re = 0.0, double Im = 0.0) {
        this->Re = Re;
        this->Im = Im;
    }
    Complex(const Complex& z) {
        this->Re = z.Re;
        this->Im = z.Im;
    }

    void Set(double Re, double Im) {
        this->Re = Re;
        this->Im = Im;
    }
    double GetRe() {
        return Re;
    }
    double GetIm() {
        return Im;
    }
    Complex& operator+(const Complex& z) {
        Complex *r = new Complex(this->Re, this->Im);
        r->Re += z.Re;
        r->Im += z.Im;
        return *r;
    }
    Complex& operator*(const Complex& z) {
        // (a + b i)(c + d i) = ac + ad i + bc i - bd
        Complex *r = new Complex;
        r->Re = this->Re * z.Re - this->Im * z.Im;
        r->Im = this->Im * z.Re + this->Re * z.Im;
        return *r;
    }
    Complex& operator*(const int& a) {
        Complex *r = new Complex;
        r->Re = this->Re * a;
        r->Im = this->Im * a;
        return *r;
    }
    Complex& operator/(const Complex& z) {
        try {
            if (z.Re == 0 && z.Im == 0)
                throw "Division by zero";
            Complex *r = new Complex;
            Complex a(z.Re, -z.Im);
            *r = *this * a;
            r->Re /= (z.Re * z.Re + z.Im * z.Im);
            r->Im /= (z.Re * z.Re + z.Im * z.Im);
            return *r;
        }
        catch (const char *error) {
            std::cout << error << std::endl;
        }
        return *this;
    }
    bool operator!=(const Complex &z) {
        if (this->Re == z.Re && this->Im == z.Im)
            return false;
        return true;
    }
    bool operator==(const Complex &z) {
        if (this->Re == z.Re && this->Im == z.Im)
            return true;
        return false;
    }

    friend std::ostream& operator<< (std::ostream &out, const Complex &z) {
        out << "(" << z.Re << "+" << z.Im << "i)";
        return out;
    }

    ~Complex() = default;

};

Complex COMPLEX_INF {10e8, 10e8};
Complex complexRandom() {
    Complex* z = new Complex;
    double re = rand() % 10;
    double im = rand() % 10;
    z->Set(re, im);
    return *z;
}

#endif // COMPLEX_H
