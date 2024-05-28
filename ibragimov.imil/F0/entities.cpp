#include "entities.hpp"

ibragimov::Encodings::Encodings(const std::map< char, std::string >& encodingTable):
  encodingTable(encodingTable)
{}
ibragimov::DecodedText::DecodedText(const std::string& text):
  text(text),
  size(text.size()),
  bits(size * 8)
{}
ibragimov::EncodedText::EncodedText(const std::string& text):
  text(text),
  size(text.size()),
  bits(size)
{}
