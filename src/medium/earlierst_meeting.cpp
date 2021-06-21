//
// Created by shyamnath on 6/10/21.
//
//A=[[2, 10], [11, 20], [21, 25]]
//B=[[5, 12] [12, 15] [16, 25]]
//[5, 11]
//
//fully subset -> A.first <= B.first and A.second >= B.second
//partial subset A-> A.first <=B.first and A.second >= B.second
//partial subset B-> A.first >=B.first and A.second >= B.second
//no subset-> A.second <= B.first
//            B.second <= A.first

#include <vector>
#include <map>

int main() {
    std::vector<std::pair<int, int>> a = {{5, 10}, {11, 14}, {16, 20}};
    std::vector<std::pair<int, int>> b = {{7, 12}, {13, 14}, {15, 20}};

    int i=0, j=0;
    std::pair<int, int> result;
    while (i!=a.size() and j!=b.size())
    {
        bool firstLessEq = a[i].first <= b[j].first;
        bool secondLessEq = b[j].second <= a[i].second;
        //fully subset
        if(firstLessEq and secondLessEq)
        {
            result.first = b[j].first;
            result.second = b[j].second;
            break;
        }
        else if ((not firstLessEq) and (not secondLessEq))
        {
            result.first = a[i].first;
            result.second = a[i].second;
            break;
        }


        //partial subset
        if(firstLessEq and (not secondLessEq) and (b[j].first < a[i].second))
        {
            result.first = b[j].first;
            result.second = a[i].second;
            break;
        }
        else if((not firstLessEq) and secondLessEq and (a[i].first < b[j].second))
        {
            result.first = a[i].first;
            result.second = b[j].second;
            break;
        }

        //no subset
        if (a[i].second <= b[j].second)
        {
            ++i;
        }
        else if (b[j].second <= a[i].first)
        {
            ++j;
        }

    }
}