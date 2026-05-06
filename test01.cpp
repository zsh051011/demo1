#include<iostream>
#include<stdio.h>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> numtemp(m+n);
        int index = 0;
        int label = 0;
        vector<int>::iterator it1,it2;
        for(it1 = nums1.begin(),it2 = nums2.begin();label != m && it2 != nums2.end();)
        {
            if(*it1 >= *it2)
            {
                numtemp[index] = *it2;
                ++index;
                ++it2;
            }
            else
            {
                numtemp[index] = *it1;
                ++index;
                ++it1;
                ++label;
            }
        }

        if(label == m)
        {
            for(;it2 != nums2.end();)
            {
                numtemp[index] = *it2;
                ++index;
                ++it2;
            }
        }
        else
        {
            for(;label != m;)
            {
                numtemp[index] = *it1;
                ++index;
                ++label;
                ++it1;
            }
        }
        nums1 = numtemp;

    }
};