#ifndef QT_FILE_PROCESSING_FILE_RELATED_H
#define QT_FILE_PROCESSING_FILE_RELATED_H
#include <iostream>
#include <fstream>
#include "ERR_ENUM.h"

//writing random numbers into binary file
int binary_write(std::string const &filename, std::string const &path, const char *data);
//reads binary file, and processes its data
int binary_read(std::string const &path, long double &data, uint32_t file_size);

//doing something with data from read file
void process_data(long double data);

//calculates amount of characters in a binary file
uint32_t file_length(std::string const &path);

//removes path from full file path - aka extracts file name
bool remove_path(std::string &full_path);

#endif //QT_FILE_PROCESSING_FILE_RELATED_H
