#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void C2A(std::string filename, int x) {
  const int y = 16;  // constant to make 2d dyanmic array easy (could make 1d
                     // array and have it be 256 long)

  std::vector<std::vector<std::string>>
      map_array;  // the final vector of vectors, 2d string array of map

  std::vector<std::string>
      map_row;  // honetsly no clue, stores whole rows which are then moved to
                // map_array i believe

  std::string buffer1,
      buffer2;  // get line function needs temporary places to store strings

  std::fstream file(filename, std::ios::in);  // reads in csv to/as input stream

  if (file.is_open()) {  // while file isnt done
    while (std::getline(
        file, buffer1)) {  // go along row of csv until newline and put those
                           // values and chars in string buffer1
      map_row.clear();

      std::stringstream input_string(buffer1);  // take buffer 1

      while (getline(input_string, buffer2, ','))
        map_row.push_back(
            buffer2);  // put buffer1 as the new input stream and remove commas
                       // and place that into buffer 2
      map_array.push_back(
          map_row);  // put those values into final 2d string array
    }
  } else
    std::cout << "Unable to open file\n";  // something broken itl say

  auto intMapArray = new int[x][y]();  // make 2d int array of n*16

  for (int i = 0; i < x;
       i++) {  // trying to go from string to int and then trying to return that
               // (array should be pointer of pointers i know but like ugh)
    for (int j = 0; j < y; j++) {
      intMapArray[i][j] = std::stoi(map_array[i][j]);
      std::cout << intMapArray[i][j] << " ";
    }
  }
}