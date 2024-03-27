#include "dataStruct.hpp"
#include <iomanip>
#include "streamGuard.hpp"
#include "delimiter.hpp"
#include "formats.hpp"

std::istream& strelyaev::operator>>(std::istream& in, DataStruct& data)
{
  std::istream::sentry guard(in);
  if (!guard)
  {
    return in;
  }
  StreamGuard s_guard(in);
  DataStruct temp{0, 0, ""};
  using del = delimiter_t;
  int keys_cout = 3;
  in >> del{'('};
  int i = 0;
  while ((in) && (i != keys_cout))
  {
    in >> del{':'} >> del{'k'} >> del{'e'} >> del{'y'};
    int key_num = 0;
    in >> key_num;
    if (key_num == 1)
    {
      in >> Litll{temp.key1};
      i++;
    }
    else if (key_num == 2)
    {
      in >> HexUll{temp.key2};
      i++;
    }
    else if (key_num == 3)
    {
      in >> StringKey{temp.key3};
      i++;
    }
    else
    {
      in.setstate(std::ios::failbit);
    }
  }
  in >> del{':'} >> del{')'};
  data = temp;
  return in;
}

std::ostream& strelyaev::operator<<(std::ostream& out, const DataStruct& data)
{
  std::ostream::sentry guard(out);
  if (!guard)
  {
    return out;
  }
  StreamGuard s_guard(out);
  out << "(:key1 " << data.key1 << "ll";
  out << ":key2 0x" << std::hex << std::uppercase << data.key2 << std::nouppercase;
  out << ":key3 \"" << data.key3 << "\":)";
  return out;
}

bool strelyaev::DataStruct::operator<(const DataStruct& other) const
{
  if (key1 != other.key1)
  {
    return key1 < other.key1;
  }
  if (key2 != other.key2)
  {
    return key2 < other.key2;
  }
  return key3.size() < other.key3.size();
}
