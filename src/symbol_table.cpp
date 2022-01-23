#include "symbol_table.h"

#include <iostream>

namespace {

using namespace gvl::lang;

template<typename T>
void InvalidType(const std::string &name, const Symbol<T> &symbol, const Position &pos, const std::string &type_name) {
  std::cerr << "[line " << pos.first << ", column " << pos.second << "] Incorrect type of \"" << name
            << "\" (= " << symbol.value << ") variable.\n";
  std::cerr << "Declared as " << type_name << " type and used at: ";
  for (const auto &p : symbol.positions) {
    std::cerr << "[line " << p.first << ", column " << p.second << "] ";
  }
  std::cerr << std::endl;
  exit(1);
}

}  // namespace

namespace gvl {
namespace lang {

std::int32_t SymbolTable::LookupInteger(const std::string &name, Position pos) {
  // Lookup in both maps
  auto int_it = int_table_.find(name);
  auto str_it = str_table_.find(name);

  if (str_it != str_table_.end()) {
    // Variable exists - incorrect type
    InvalidType(name, str_it->second, pos, "STRING");
    return -1; // Unreachable
  } else if (int_it != int_table_.end()) {
    // Variable exists - correct type
    auto &symbol = int_it->second;
    symbol.positions.push_back(pos);
    return symbol.value;
  } else {
    // Create new variable
    int_table_.insert({name, gvl::lang::Symbol<int32_t>(0, pos)});
    return 0;
  }
}

std::string SymbolTable::LookupString(const std::string &name, Position pos) {
  // Lookup in both maps
  auto int_it = int_table_.find(name);
  auto str_it = str_table_.find(name);

  if (int_it != int_table_.end()) {
    // Variable exists - incorrect type
    InvalidType(name, int_it->second, pos, "NUM");
    return "N/A"; // Unreachable
  } else if (str_it != str_table_.end()) {
    // Variable exists - correct type
    auto &symbol = str_it->second;
    symbol.positions.push_back(pos);
    return symbol.value;
  } else {
    // Create a new variable
    str_table_.insert({name, gvl::lang::Symbol<std::string>("", pos)});
    return "";
  }
}

std::int32_t SymbolTable::AssignInteger(const std::string &name, Position pos, std::int32_t value) {
  // Lookup in both maps
  auto int_it = int_table_.find(name);
  auto str_it = str_table_.find(name);

  if (str_it != str_table_.end()) {
    // Variable exists - incorrect type
    InvalidType(name, str_it->second, pos, "STRING");
    return -1; // Unreachable
  } else if (int_it != int_table_.end()) {
    // Variable exists - correct type
    auto &symbol = int_it->second;
    symbol.value = value;
    symbol.positions.push_back(pos);
    return symbol.value;
  } else {
    // Create new variable
    int_table_.insert({name, gvl::lang::Symbol<int32_t>(value, pos)});
    return value;
  }
}

std::string SymbolTable::AssignString(const std::string &name, Position pos, std::string value) {
  // Lookup in both maps
  auto int_it = int_table_.find(name);
  auto str_it = str_table_.find(name);

  if (int_it != int_table_.end()) {
    // Variable exists - incorrect type
    InvalidType(name, int_it->second, pos, "NUM");
    return "N/A"; // Unreachable
  } else if (str_it != str_table_.end()) {
    // Variable exists - correct type
    auto &symbol = str_it->second;
    symbol.value = value;
    symbol.positions.push_back(pos);
    return symbol.value;
  } else {
    // Create a new variable
    str_table_.insert({name, gvl::lang::Symbol<std::string>(value, pos)});
    return value;
  }
}

}
}
