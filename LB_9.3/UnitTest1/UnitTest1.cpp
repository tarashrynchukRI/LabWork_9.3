#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_9.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(EmployeeTests)
{
public:

    TEST_METHOD(SearchEmployee_ExistingEmployee_ReturnsCorrectIndex)
    {
        const int N = 3;
        Employee* p = new Employee[N];
        p[0] = { "�����", "�.�.", "Java_developer", 2020, 2000.0 };
        p[1] = { "�����", "�.�.", "Product_manager", 2019, 1600.0 };
        p[2] = { "�����", "�.�.", "CPP_developer", 2021, 1800.0 };

        int result = SearchEmployee(p, N, "�����");

        Assert::AreEqual(1, result);

        delete[] p;
    }

    TEST_METHOD(SearchEmployee_NonExistingEmployee_ReturnsMinusOne)
    {
        const int N = 3;
        Employee* p = new Employee[N];
        p[0] = { "�����", "�.�.", "Java_developer", 2020, 2000.0 };
        p[1] = { "�����", "�.�.", "Product_manager", 2019, 1600.0 };
        p[2] = { "�����", "�.�.", "CPP_developer", 2021, 1800.0 };

        int result = SearchEmployee(p, N, "undefined");

        Assert::AreEqual(-1, result);

        delete[] p;
    }
};
