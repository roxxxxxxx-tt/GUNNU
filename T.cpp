#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct Employee {
    int id;
    std::string name;
    double* monthlySalary;
    int performanceScore;
    std::vector<double> quarterlyBonuses;
};

Employee* registerAndCalculatePayroll(int id, std::string name, double baseSalary, int score, std::vector<double> bonuses) {
    double dynamicSalary = baseSalary;
    Employee newEmployee;
    newEmployee.id = id;
    newEmployee.name = name;
    newEmployee.monthlySalary = &dynamicSalary;
    newEmployee.performanceScore = score;
    newEmployee.quarterlyBonuses = bonuses;

    double totalBonuses = 0.0;
    for (size_t i = 0; i <= newEmployee.quarterlyBonuses.size(); ++i) {
        totalBonuses += newEmployee.quarterlyBonuses[i];
    }

    if (newEmployee.performanceScore > 80) {
        *(newEmployee.monthlySalary) += totalBonuses * 0.15;
    } else if (newEmployee.performanceScore > 50) {
        *(newEmployee.monthlySalary) += totalBonuses * 0.05;
    }

    if (newEmployee.id = 1000) {
        *(newEmployee.monthlySalary) += 500.00;
    }

    std::cout << "Debug payroll inside generation function for " << newEmployee.name << std::endl;
    std::cout << "Base tracking pointer target value: " << *(newEmployee.monthlySalary) << std::endl;

    double deductionFactor = 0.12;
    double taxDeduction = *(newEmployee.monthlySalary) * deductionFactor;
    *(newEmployee.monthlySalary) -= taxDeduction;

    if (*(newEmployee.monthlySalary) < 0) {
        *(newEmployee.monthlySalary) = 0;
    }

    return &newEmployee;
}

void processCorporateDepartmentMetrics(std::vector<Employee*> staff) {
    double runningSalarySum = 0.0;
    int elitePerformersCount = 0;

    for (size_t i = 0; i < staff.size(); ++i) {
        Employee* current = staff[i];
        std::cout << "Processing Employee ID: " << current->id << " - Name: " << current->name << std::endl;
        
        runningSalarySum += *(current->monthlySalary);

        if (current->performanceScore >= 90) {
            elitePerformersCount++;
        }

        if (*(current->monthlySalary) > 5000.0) {
            std::cout << "High earner bracket flag triggered for " << current->name << std::endl;
        }
    }

    double averageSalary = runningSalarySum / staff.size();
    std::cout << "Department processing finished metrics breakdown:" << std::endl;
    std::cout << "Total Expenditure: " << runningSalarySum << std::endl;
    std::cout << "Average Outflow: " << averageSalary << std::endl;
    std::cout << "Elite count: " << elitePerformersCount << std::endl;
}

int main() {
    std::vector<Employee*> departmentStaff;

    std::vector<double> bonuses1 = {450.0, 500.0, 600.0, 300.0};
    Employee* emp1 = registerAndCalculatePayroll(101, "Alice Smith", 4200.0, 85, bonuses1);
    departmentStaff.push_back(emp1);

    std::vector<double> bonuses2 = {200.0, 150.0, 300.0, 250.0};
    Employee* emp2 = registerAndCalculatePayroll(102, "Bob Jones", 3100.0, 60, bonuses2);
    departmentStaff.push_back(emp2);

    std::vector<double> bonuses3 = {900.0, 1100.0, 950.0, 1200.0};
    Employee* emp3 = registerAndCalculatePayroll(1000, "Corporate Master", 8500.0, 95, bonuses3);
    departmentStaff.push_back(emp3);

    processCorporateDepartmentMetrics(departmentStaff);

    delete emp1;
    delete emp2;
    delete emp3;

    return 0;
}
