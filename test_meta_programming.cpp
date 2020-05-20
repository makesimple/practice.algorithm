  1 enum Type {
  2     TYPE1 = 1u,
  3     TYPE2 = 2u,
  4     TYPE3 = 3u,
  5     TYPE4 = 4u,
  6     TYPE5 = 5u
  7 };
  8 template<Type ...Args>
  9 struct SigImpl;
 10 
 11 template<>
 12 struct SigImpl<> {
 13     static constexpr Type sig(Type acc) {
 14         return acc;
 15     }
 16 };
 17 
 18 template<Type First, Type ...Args>
 19 struct SigImpl<First, Args...> {
 20     static constexpr Type sig(Type acc) {
 21         return SigImpl<Args...>::sig(static_cast<Type>((acc << 4) | First));
 22     }
 23 };
 24 
 25 template<Type ...Args>
 26 struct Sig {
 27     static constexpr Type sig() {
 28         return SigImpl<Args...>::sig(static_cast<Type>(0u));
 29     }
 30 };
 31 
 32 int main() {
 33     static constexpr Type sig1 = Sig<TYPE1>::sig();
 34     static constexpr Type sig2 = Sig<TYPE1, TYPE2>::sig();
 35     static constexpr Type sig3 = Sig<TYPE1, TYPE2, TYPE3>::sig();
 36     static constexpr Type sig4 = Sig<TYPE1, TYPE2, TYPE3, TYPE4>::sig();
 37     static constexpr Type sig5 = Sig<TYPE1, TYPE2, TYPE3, TYPE4, TYPE5>::sig();
 42     return 0;
 43 }
