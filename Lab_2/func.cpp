#include <iostream>
#include "func.h"
#include "complex.h"
#include "arraysequence.h"

template<class T>
Function<T>::Function() {
    _functions = (Sequence<Piece<T>> *) new ArraySequence<Piece<T>>;
}

template<class T>
void Function<T>::Generate(int start, int end, T (*random)()) {
    if (start == end) {
        Sequence<T> *coeff = (Sequence<T> *) new ArraySequence<T>;
        for (int j = 0; j < 3; ++j)
            coeff->Append(random());
        this->Set(coeff, start, end);
        return;
    }
    int current_step = 0;
    for (int i = start; i < end; i += current_step) {
        current_step = rand() % (end - i) + 1;
        Sequence<T> *coeff = (Sequence<T> *) new ArraySequence<T>;
        for (int j = 0; j < 3; ++j)
            coeff->Append(random());
        this->Set(coeff, i, i + current_step);
    }
}

template<class T>
void Function<T>::Generate(int n, T (*random)()) {
    int start = 0;
    int current_step = 0;
    for (int i = 0; i < n; ++i) {
        current_step = rand() % 10 + 1;
        Sequence<T> *coeff = (Sequence<T> *) new ArraySequence<T>;
        for (int j = 0; j < 3; ++j)
            coeff->Append(random());
        this->Set(coeff, start, start + current_step);
        start += current_step;
    }
}

template<class T>
Function<T>::Function(int start, int end) {
    _functions = (Sequence<Piece<T>> *) new ArraySequence<Piece<T>>;
    Piece<T> p;
    p.start = start;
    p.end = end;
    p.coefficients = (Sequence<T> *) new ArraySequence<T>;
    _functions->Append(p);
}

template<class T>
void Function<T>::Insert(Piece<T> p_new, int i) {
    Piece<T> p_add;
    p_add = (*_functions)[i];
    p_add.start = p_new.end;
    (*_functions)[i].end = p_new.start;
    if (i == _functions->GetLength() - 1) {
        _functions->Append(p_new);
        _functions->Append(p_add);
    }
    else {
        _functions->InsertAt(p_new, i + 1);
        _functions->InsertAt(p_add, i + 2);
    }
}

template<class T>
void Function<T>::Set(Sequence <T> *seq, int start, int end) {
    Piece<T> p_new;
    ArraySequence<T> *l = (ArraySequence<T> *) seq;
    p_new.coefficients = (Sequence<T> *) new ArraySequence<T>(*l);
    p_new.start = start;
    p_new.end = end;
    if (_functions->GetLength() == 0) {
        _functions->Append(p_new);
        return;
    }
    Piece<T> p;
    p = _functions->Get(_functions->GetLength() - 1);
    if (p.end <= start) {
        _functions->Append(p_new);
        return;
    }
    bool checker = false;
    p = _functions->Get(0);
    if (start <= p.start) {
        _functions->Prepend(p_new);
        if (end <= p.start)
            return;
        for (int i = 1; i < _functions->GetLength(); ++i) {
            p = _functions->Get(i);
            if (start <= p.start && p.end <= end) {
                _functions->DelByIndex(i);
                --i;
                continue;
            }
            else if (end < p.end) {
                p.start = end;
                _functions->Set(p, i);
                break;
            }
        }
        return;
    }
    for (int i = 0; i < _functions->GetLength(); ++i) {
        p = _functions->Get(i);
        if (!checker && p.start <= start && end <= p.end) {
            this->Insert(p_new, i);
            break;
        }
        if (!checker && p.start <= start && start <= p.end) {
            checker = true;
            p.end = start;
            _functions->Set(p, i);
            _functions->InsertAt(p_new, i + 1);
            ++i;
            continue;
        }
        else if (start <= p.start && p.end <= end) {
            _functions->DelByIndex(i);
            --i;
            continue;
        }
        else if (end < p.end) {
            p.start = end;
            _functions->Set(p, i);
            break;
        }
    }
}

template<class T>
T &Function<T>::Value(const int &value) {
    try {
        for (int i = 0; i < _functions->GetLength(); ++i) {
            Piece<T> p = (*_functions)[i];
            if ((p.start == p.end && p.start == value) || (p.start <= value && value < p.end))
                return p.Value(value);
        }
        throw "The value doesn't belong to the scope";
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

template<class T>
T &Function<T>::Value(const int &value, T& error) {
    try {
        for (int i = 0; i < _functions->GetLength(); ++i) {
            Piece<T> p = (*_functions)[i];
            if ((p.start == p.end && p.start == value) || (p.start <= value && value < p.end))
                return p.Value(value);
        }
        throw "The value doesn't belong to the scope";
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
    return error;
}

template<class T>
bool Function<T>::IsMonotone() {
    for (int i = 0; i < _functions->GetLength(); ++i) {
        Piece<T> p = _functions->Get(i);
        // -b / 2a - min/max
        // start < -b / 2a < end
        // 2a start < -b < 2a end
        if (p.start * (*p.coefficients)[2] * 2 < (*p.coefficients)[1] * (-1) &&
                (*p.coefficients)[1] * (-1) < p.end * (*p.coefficients)[2] * 2)
            return false;
    }
    int direction = 0;
    for (int i = 0; i < _functions->GetLength() - 1; ++i) {
        Piece<T> p1 = (*_functions)[i];
        Piece<T> p2 = (*_functions)[i + 1];
        if (!direction) {
            if (p2.Value(p2.start) != p1.Value(p1.start))
                direction = (p2.Value(p2.start) > p1.Value(p1.start)) ? 1 : -1;
        }
        else {
            if (p2.Value(p2.start) != p1.Value(p1.start)) {
                int current_direction = (p2.Value(p2.start) > p1.Value(p1.start)) ? 1 : -1;
                if (current_direction != direction) return false;
            }
        }
    }
    for (int i = 0; i < _functions->GetLength() - 1; ++i) {
        Piece<T> p1 = (*_functions)[i];
        Piece<T> p2 = (*_functions)[i + 1];
        if (!direction) {
            if (p2.Value(p2.end) != p1.Value(p1.end))
                direction = (p2.Value(p2.end) > p1.Value(p1.end)) ? 1 : -1;
        }
        else {
            if (p2.Value(p2.end) != p1.Value(p1.end)) {
                int current_direction = (p2.Value(p2.end) > p1.Value(p1.end)) ? 1 : -1;
                if (current_direction != direction) return false;
            }
        }
    }
    for (int i = 0; i < _functions->GetLength(); ++i) {
        Piece<T> p1 = (*_functions)[i];
        if (!direction) {
            if (p1.Value(p1.end) != p1.Value(p1.start))
                direction = (p1.Value(p1.end) > p1.Value(p1.start)) ? 1 : -1;
        }
        else {
            if (p1.Value(p1.end) != p1.Value(p1.start)) {
                int current_direction = (p1.Value(p1.end) > p1.Value(p1.start)) ? 1 : -1;
                if (current_direction != direction) return false;
            }
        }
    }
    for (int i = 0; i < _functions->GetLength() - 1; ++i) {
        Piece<T> p = _functions->Get(i);
        Piece<T> p_next = _functions->Get(i + 1);
        if (!direction) {
            if (p.Value(p.end) != p_next.Value(p_next.start))
                direction = (p_next.Value(p_next.start) > p.Value(p.end)) ? 1 : -1;
        }
        else {
            if (p.Value(p.end) != p_next.Value(p_next.start)) {
                int current_direction = (p_next.Value(p_next.start) > p.Value(p.end)) ? 1 : -1;
                if (current_direction != direction) return false;
            }
        }
    }
    return true;
}

template<class T>
bool Function<T>::IsContinuous() {
    for (int i = 0; i < _functions->GetLength() - 1; ++i) {
        Piece<T> p = _functions->Get(i);
        Piece<T> p_next = _functions->Get(i + 1);
        if (p.end != p_next.start ||  p.Value(p.end) != p_next.Value(p_next.start))
            return false;
    }
    return true;
}

template<class T>
void Function<T>::Clear() {
    delete[] _functions;
    _functions = (Sequence<Piece<T>> *) new ArraySequence<Piece<T>>;
}

template<class T>
int Function<T>::GetLength() const {
    return _functions->GetLength();
}

template<class T>
std::ostream& operator<<(std::ostream &out, const Function<T> &f) {
    for (int i = 0; i < f._functions->GetLength(); ++i)
        out << (*f._functions)[i];
    return out;
}

template<class T>
Function<T>::~Function() {
    delete[] _functions;
}
