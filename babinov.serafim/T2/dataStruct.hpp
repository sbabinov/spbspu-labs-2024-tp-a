#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP
#include <iostream>
#include <string>

namespace babinov
{
  struct DataStruct
  {
    unsigned long long key1;
    unsigned long long key2;
    std::string key3;

    bool operator>(const DataStruct& right) const;
    bool operator<(const DataStruct& right) const;
    bool operator>=(const DataStruct& right) const;
    bool operator<=(const DataStruct& right) const;
    bool operator==(const DataStruct& right) const;
    bool operator!=(const DataStruct& right) const;
  };
  std::istream& operator>>(std::istream& in, DataStruct& data);
  std::ostream& operator<<(std::ostream& out, const DataStruct& data);

  struct DataProcessor
  {
    DataStruct& dataStruct;
    int key;
  };
  std::istream& operator>>(std::istream& in, DataProcessor&& proc);

  struct BinaryNumber
  {
    std::string value;
    unsigned long long toUll() const;
  };
  std::istream& operator>>(std::istream& in, BinaryNumber& bin);
}

#endif