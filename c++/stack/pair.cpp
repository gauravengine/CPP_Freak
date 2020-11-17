template <typename T,typename V>
//template<class T>

class Pair {
  T x;
  V y;
 public :
      void setx(T x){
        this ->x=x;

      }
T getx() {
  return x;
}
void sety( V y)
{
  this-> y=y;
}
V  gety()
{
  return y;
}

};
