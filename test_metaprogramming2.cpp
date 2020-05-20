  1 template <int N>
  2 constexpr int factor() {
  3     return factor<N - 1>() * N;
  4 }
  5 
  6 template <>
  7 constexpr int factor<0>() {
  8     return 1;
  9 }
 10 
 11 int main() {
 12     static constexpr int f5 = factor<5>();
 13     return f5;
 14 }
