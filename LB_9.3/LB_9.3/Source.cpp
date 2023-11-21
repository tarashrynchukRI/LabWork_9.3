#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;

struct Employee {
    string surname;
    string initials;
    string position;
    int year;
    double salary;
};

void AddEmployee(Employee*& p, int& N);
void DeleteEmployee(Employee*& p, int& N);
void EditEmployee(Employee* p, const int N);
void SortBySurname(Employee* p, const int N);
void SortBySalary(Employee* p, const int N);
void SortByYear(Employee* p, const int N);
void PrintEmployee(Employee* p, const int N);
void DisplayEmployeesTable(Employee* p, const int N);
int SearchEmployee(Employee* p, const int N, const string surname);

int main() {
    SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

    int N = 3;
    Employee* p = new Employee[N];

    // ����������� ������ ���������� �� �����������
    p[0] = { "�����", "�.�.", "Java_developer", 2020, 2000.0 };
    p[1] = { "�����", "�.�.", "Product_manager", 2019, 1600.0 };
    p[2] = { "�����", "�.�.", "CPP_developer", 2021, 1800.0 };

    int menuItem;
    string surname;
    do {
        DisplayEmployeesTable(p, N);
        cout << "\n\n\n������� ��:\n\n";
        cout << " [1] - ������ ����������\n";
        cout << " [2] - �������� ����������\n";
        cout << " [3] - ���������� ��� ����������\n";
        cout << " [4] - ��������� �� ��������\n";
        cout << " [5] - ��������� �� �������\n";
        cout << " [6] - ��������� �� ����� ������� �� ������\n";
        cout << " [7] - ������� ��� ����������\n";
        cout << " [0] - ����� �� ���������� ������ ��������\n\n";
        cout << "������ ��������: "; cin >> menuItem;
        cout << "\n\n\n";
        switch (menuItem) {
        case 1:
            AddEmployee(p, N);
            break;
        case 2:
            DeleteEmployee(p, N);
            break;
        case 3:
            EditEmployee(p, N);
            break;
        case 4:
            SortBySurname(p, N);
            break;
        case 5:
            SortBySalary(p, N);
            break;
        case 6:
            SortByYear(p, N);
            break;
        case 7:
            cout << "������ ������� ����������: "; cin >> surname;
            PrintEmployee(p, SearchEmployee(p, N, surname));
            break;
        default:
            cout << "�� ����� ����������� ��������! ��������� �� ���..." << endl;
            break;
        }
    } while (menuItem != 0);

    return 0;
}

void AddEmployee(Employee*& p, int& N) {
    Employee* tmp = new Employee[N + 1];
    for (int i = 0; i < N; i++)
        tmp[i] = p[i];
    cout << "������ ������� ����������: "; cin >> tmp[N].surname;
    cout << "������ ������� ����������: "; cin >> tmp[N].initials;
    cout << "������ ����� ������ ����������: "; cin >> tmp[N].position;
    cout << "������ �� ������� �� ������: "; cin >> tmp[N].year;
    cout << "������ ����� ����������: "; cin >> tmp[N].salary;
    N++;
    delete[] p;
    p = tmp;
}

void DeleteEmployee(Employee*& p, int& N) {
    int k;
    cout << "������ ����� ����������, ����� ����� ��������: "; cin >> k;
    if (k < 1 || k > N) {
        cout << "���������� � ����� ������� �� ����!" << endl;
        return;
    }
    Employee* tmp = new Employee[N - 1];
    for (int i = 0; i < k - 1; i++)
        tmp[i] = p[i];
    for (int i = k - 1; i < N - 1; i++)
        tmp[i] = p[i + 1];
    N--;
    delete[] p;
    p = tmp;
}

void EditEmployee(Employee* p, const int N) {
    int k;
    cout << "������ ����� ����������, ��� ����� ����� ����������: "; cin >> k;
    if (k < 1 || k > N) {
        cout << "���������� � ����� ������� �� ����!" << endl;
        return;
    }
    cout << "������ ������� ����������: "; cin >> p[k - 1].surname;
    cout << "������ ������� ����������: "; cin >> p[k - 1].initials;
    cout << "������ ����� ������ ����������: "; cin >> p[k - 1].position;
    cout << "������ �� ������� �� ������: "; cin >> p[k - 1].year;
    cout << "������ ����� ����������: "; cin >> p[k - 1].salary;
}

void SortBySurname(Employee* p, const int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (p[j].surname > p[j + 1].surname)
                swap(p[j], p[j + 1]);
}

void SortBySalary(Employee* p, const int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (p[j].salary > p[j + 1].salary)
                swap(p[j], p[j + 1]);
}

void SortByYear(Employee* p, const int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (p[j].year > p[j + 1].year)
                swap(p[j], p[j + 1]);
}

void PrintEmployee(Employee* p, const int N) {
    if (N < 0) {
        cout << "���������� � ����� �������� �� ����!" << endl;
        return;
    }
    cout << "�������: " << p[N].surname << endl;
    cout << "�������: " << p[N].initials << endl;
    cout << "������: " << p[N].position << endl;
    cout << "г� ������� �� ������: " << p[N].year << endl;
    cout << "�����: " << p[N].salary << endl;
}

void DisplayEmployeesTable(Employee* p, const int N) {
    cout << setfill('=') << setw(85) << "=" << setfill(' ') << endl;
    cout << "|" << setw(15) << "�������" << "|" << setw(15) << "�������" << "|" << setw(20) << "������" << "|" << setw(15) << "г� �������" << "|" << setw(10) << "�����" << "|" << endl;
    cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(15) << p[i].surname << "|" << setw(15) << p[i].initials << "|" << setw(20) << p[i].position << "|" << setw(15) << p[i].year << "|" << setw(10) << p[i].salary << "|" << endl;
    }
    cout << setfill('=') << setw(85) << "=" << setfill(' ') << endl;
}

int SearchEmployee(Employee* p, const int N, const string surname) {
    for (int i = 0; i < N; i++)
        if (p[i].surname == surname)
            return i;
    return -1;
}
