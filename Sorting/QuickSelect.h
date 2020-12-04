#pragma once

#include <vector>

class QuickSelect
{
private:
    static void swap(std::vector<int> &arr, int first, int second);
    static void quickSelect(std::vector<int> &arr, int lower, int upper, int k);
public:
    static void quickSelect(std::vector<int> &arr, int k);
};
