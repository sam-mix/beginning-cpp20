#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> vs{1, 2, 3, 4, 45, 5, 6, 7, 8, 8, 89, 9, 6};

  for (int i = vs.size() - 1; i >= 0; i--) {
    cout << vs[i] << endl;
  }

  return 0;
}
