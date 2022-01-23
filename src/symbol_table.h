#include <cstdint>
#include <string>
#include <map>
#include <variant>
#include <vector>
#include <utility>

#pragma once

namespace gvl {
namespace lang {

using Position = std::pair<int, int>;

template <typename T>
struct Symbol {
  T value;
  std::vector<Position> positions;

  Symbol(T value, Position position) : value{value}, positions{} {
    positions.push_back(position);
  }
};

class SymbolTable {
 public:
  SymbolTable() = default;
  std::int32_t LookupInteger(const std::string& name, Position pos);
  std::string LookupString(const std::string& name, Position pos);
  std::int32_t AssignInteger(const std::string& name, Position pos, std::int32_t value);
  std::string AssignString(const std::string& name, Position pos, std::string value);

 private:
  std::map<std::string, Symbol<std::string>> str_table_{};
  std::map<std::string, Symbol<std::int32_t>> int_table_{};
};

}  // namespace lang
}  // namespace gvl
