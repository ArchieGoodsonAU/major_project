#include <string>

extern void C2A(std::string filename, int x);

int main() {
  int map_length = 16;  // change map (csv) length
  // const int map_height = 16;
  std::string map_name = "map_load_test_1.csv";  // csv file name
  C2A(map_name, map_length);                     // call function
  return 0;
}