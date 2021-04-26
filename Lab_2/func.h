#ifndef CUSTOM_H
#define CUSTOM_H

#include "listsequence.h"
#include "listsequence.cpp"
#include "arraysequence.h"
#include "arraysequence.cpp"

template<class T>
class Piece {
public:
    Sequence<T> *coefficients;
    int start;
    int end;
    T& Value(const int &value) {
        T *res = new T;
        *res = (*coefficients)[0] + (*coefficients)[1] * value + (*coefficients)[2] * value * value;
        return *res;
    }
    friend std::ostream& operator<< (std::ostream &out, const Piece<T> &p) {
        out << "[ " << p.start << " ; " << p.end << " ) : ";
        out << (*p.coefficients)[0] << " + " << (*p.coefficients)[1] << " * x + " << (*p.coefficients)[2] << " * x^2" << std::endl;
        return out;
    }
};


template<class T>
class Function {
private:
    Sequence<Piece<T>> *_functions;

    //Operations
    void Insert(Piece<T> p_new, int i);

public:
    //Constructors
    Function();
    Function(int start, int end);
    Function(const Function<T>& func);

    // Generation
    void Generate(int start, int end, T (*random)());
    void Generate(int n, T (*random)());

    //Decomposition
    void Clear();
    int GetLength() const;

    //Operations
    void Set(Sequence<T> *seq, int start, int end);
    T& Value(const int &value);
    T& Value(const int &value, T& error);
    bool IsMonotone();
    bool IsContinuous();


    template<class R>
    friend std::ostream& operator<<(std::ostream &out, const Function<R> &f);

    //Destructor
    ~Function();

};


#endif // CUSTOM_H
