#include <iostream>
#include <vector>

using std::ostream;
using std::vector;
using std::cout;


template<class T>
class List {
  private:
    std::vector<T> vec;
  public:
    void push_back(T t) {
      vec.push_back(t);
    };

    template<class U>
    friend ostream& operator<<(ostream& os, const List<U>& L);
};

template<class T>
ostream& operator<<(ostream& os, const List<T>& L) {
  for (T it : L.vec) {
    os << it << " .. ";
  }

  return os;
}

int main(void) {
  List<float> L;
  L.push_back(1.0);
  L.push_back(2.3);
  L.push_back(3.5);

  std::cout << L;

  return 0;
}