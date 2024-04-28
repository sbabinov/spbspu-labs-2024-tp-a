#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include "figures_struct.hpp"
#include "commands.hpp"

bool isPolygonCorrect(const nikitov::Polygon& value)
{
  return !value.points.empty();
}

int main(int argc, char* argv[])
{
  using namespace nikitov;

  std::vector< Polygon > data;
  if (argc == 2)
  {
    std::ifstream input(argv[1]);
    using input_it_t = std::istream_iterator< Polygon >;
    std::copy_if(input_it_t{ input }, input_it_t{}, std::back_inserter(data), isPolygonCorrect);
  }
  else
  {
    std::cerr << "Error: Wrong input parameters" << '\n';
    return 1;
  }

  std::map< std::string, std::function< void(std::vector< Polygon >&, std::istream&, std::ostream&) > > commands;
  commands["AREA"] = areaCmd;
  commands["COUNT"] = countCmd;
  commands["MAX"] = maxCmd;
  commands["MIN"] = minCmd;

  std::string cmd = {};
  while (std::cin >> cmd)
  {
    try
    {
      commands.at(cmd)(data, std::cin, std::cout);
      std::cout << '\n';
    }
    catch(const std::out_of_range&)
    {
      std::cout << "<INVALID COMMAND>" << '\n';
    }
  }
}
