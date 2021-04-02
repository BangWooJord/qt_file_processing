#ifndef QT_FILE_PROCESSING_TOML_RELATED_H
#define QT_FILE_PROCESSING_TOML_RELATED_H
#include <iostream>
#include <set>
#include <vector>
#include "../toml11-3.6.0/toml.hpp"

bool openConfig(std::string const &cfg_path, std::string const &value, std::set<std::string> &unique_path);

#endif //QT_FILE_PROCESSING_TOML_RELATED_H
