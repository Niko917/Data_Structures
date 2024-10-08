#include <utility>

template <typename T1, typename T2>
class Pair {
public:
    T1 first_;
    T2 second_;

    Pair() : first_(), second_() {}

    Pair(const T1& f, const T2& s) : first_(f), second_(s) {}

    Pair(const Pair& other) : first_(other.first_), second_(other.second_) {}

    Pair(Pair&& other) noexcept : first_(std::move(other.first_)), second_(std::move(other.second_)) {}

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first_ = other.first_;
            second_ = other.second_;
        }
        return *this;
    }

    Pair& operator=(Pair&& other) noexcept {
        if (this != &other) {
            first_ = std::move(other.first_);
            second_ = std::move(other.second_);
        }
        return *this;
    }

    bool operator==(const Pair& other) const {
        return first_ == other.first_ && second_ == other.second_;
    }

    bool operator!=(const Pair& other) const {
        return !(*this == other);
    }

    bool operator<(const Pair& other) const {
        return first_ < other.first_ || (first_ == other.first_ && second_ < other.second_);
    }

    bool operator<=(const Pair& other) const {
        return !(other < *this);
    }

    bool operator>(const Pair& other) const {
        return other < *this;
    }

    bool operator>=(const Pair& other) const {
        return !(*this < other);
    }
};

template <typename T1, typename T2>
Pair<T1, T2> make_my_pair(T1&& first_, T2&& second_) {
    return Pair<T1, T2>(std::forward<T1>(first_), std::forward<T2>(second_));
}
