#ifndef TUPLE_H_
#define TUPLE_H_

namespace softedge {

template<int N, typename TYPE>
class Tuple {
public:
    Tuple();
    Tuple(const Tuple& tuple);
    virtual ~Tuple();

    Tuple& operator=(const Tuple<N, TYPE>& t);

    TYPE& operator[](const unsigned int index) const;

    Tuple operator +(const Tuple&) const;
    Tuple operator -(const Tuple&) const;
    Tuple operator *(const TYPE) const;
    Tuple operator /(const TYPE) const;

    bool operator==(const Tuple<N, TYPE>& t) const;

protected:
    TYPE tuple[N];
};

template<int N, typename TYPE>
Tuple<N, TYPE>::Tuple() {
}

template<int N, typename TYPE>
Tuple<N, TYPE>::Tuple(const Tuple& tuple) {
    *this = tuple;
}

template<int N, typename TYPE>
Tuple<N, TYPE>::~Tuple() {
}

template<int N, typename TYPE>
Tuple<N, TYPE>& Tuple<N, TYPE>::operator=(const Tuple<N, TYPE>& t) {
    if (this != &t) {
        for (int n = 0; n < N; n++) {
            this->tuple[n] = t.tuple[n];
        }
    }
    return *this;
}

template<int N, typename TYPE>
TYPE& Tuple<N, TYPE>::operator[](const unsigned int index) const {
    return tuple[index];
}

template<int N, typename TYPE>
Tuple<N, TYPE> Tuple<N, TYPE>::operator +(const Tuple<N, TYPE>& t) const {
    Tuple<N, TYPE> tuple(*this);
    for (int n = 0; n < N; n++) {
        tuple.tuple[n] += t.tuple[n];
    }
    return tuple;
}

template<int N, typename TYPE>
Tuple<N, TYPE> Tuple<N, TYPE>::operator -(const Tuple<N, TYPE>& t) const {
    Tuple<N, TYPE> tuple(*this);
    for (int n = 0; n < N; n++) {
        tuple.tuple[n] -= t.tuple[n];
    }
    return tuple;
}

template<int N, typename TYPE>
Tuple<N, TYPE> Tuple<N, TYPE>::operator *(const TYPE t) const {
    Tuple<N, TYPE> tuple(*this);
    for (int n = 0; n < N; n++) {
        tuple.tuple[n] *= t;
    }
    return tuple;
}

template<int N, typename TYPE>
Tuple<N, TYPE> Tuple<N, TYPE>::operator /(const TYPE t) const {
    Tuple<N, TYPE> tuple(*this);
    for (int n = 0; n < N; n++) {
        tuple.tuple[n] /= t.tuple[n];
    }
    return tuple;
}

template<int N, typename TYPE>
bool Tuple<N, TYPE>::operator==(const Tuple<N, TYPE>& t) const {
    return true;
}

} /* namespace softedge */
#endif /* TUPLE_H_ */
