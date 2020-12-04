#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

template<typename T>
class CountMap
{
public:
    std::unordered_map<T, int> hm;

    virtual void add(T key)
    {
        if (hm.find(key) != hm.end())
        {
            int count = hm[key];
            hm[key] = count + 1;
        }
        else
        {
            hm[key] = 1;
        }
    }

    virtual void remove(T key)
    {
        if (hm.find(key) != hm.end())
        {
            if (hm[key] == 1)
            {
                hm.erase(key);
            }
            else
            {
                int count = hm[key];
                hm[key] = count - 1;
            }
        }
    }

    virtual int get(T key)
    {
        if (hm.find(key) != hm.end())
        {
            return hm[key];
        }
        return 0;
    }

    virtual bool containsKey(T key)
    {
        return hm.find(key) != hm.end();
    }

    virtual int size()
    {
        return hm.size();
    }
};
