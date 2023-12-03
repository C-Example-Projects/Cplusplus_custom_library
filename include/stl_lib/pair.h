namespace lib {
    template <typename F, typename S>
    class pair {
    public:
        F first;
        S second;

        pair(const F& firstVal, const S& secondVal)
        {
            first = firstVal;
            second = secondVal;
        }

    };

    template <typename F, typename S>
    pair<F, S> make_pair(const F& firstVal, const S& secondVal)
    {
        return pair(firstVal, secondVal);
    }
}