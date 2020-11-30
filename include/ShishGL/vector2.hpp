#ifndef VECTOR_2_HPP
#define VECTOR_2_HPP


namespace ShishGL {

    template <typename T>
    struct Vector2;


    template <typename T>
    Vector2<T> operator-(const Vector2<T>& vec) {
        return Vector2<T>{-vec.x, -vec.y};
    }


    template <typename T>
    Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right) {
        return Vector2<T>{left.x + right.x, left.y + right.y};
    }


    template <typename T>
    Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right) {
        left.x += right.x;
        left.y += right.y;
        return left;
    }


    template <typename T>
    Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right) {
        return (left + (-right));
    }


    template <typename T>
    Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right) {
        return (left += (-right));
    }


    template <typename T>
    Vector2<T> operator*(const T& mul, const Vector2<T>& right) {
        return Vector2<T>{right.x * mul, right.y * mul};
    }


    template <typename T>
    Vector2<T>& operator*=(Vector2<T>& left, const T& mul) {
        left.x *= mul;
        left.y *= mul;
        return left;
    }

    template <typename T>
    struct Vector2 {
        T x, y;

        friend Vector2<T> operator-<>(const Vector2<T>& vec);
        friend Vector2<T> operator+<>(const Vector2<T>& left, const Vector2<T>& right);
        friend Vector2<T>& operator+=<>(Vector2<T>& left, const Vector2<T>& right);
        friend Vector2<T> operator-<>(const Vector2<T>& left, const Vector2<T>& right);
        friend Vector2<T>& operator-=<>(Vector2<T>& left, const Vector2<T>& right);
        friend Vector2<T> operator*<>(const T& mul, const Vector2<T>& right);
        friend Vector2<T>& operator*=<>(Vector2<T>& left, const T& mul);
    };

}


#endif //VECTOR_2_HPP
