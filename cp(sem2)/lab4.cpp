#include <iostream>

class Employee {
	public:
		virtual double getSalary() const = 0;
		virtual std::string getRole() const = 0;
		virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee
{
	protected:
		double monthlySalary;

	public:
		FullTimeEmployee(double monthlySalary) : monthlySalary(monthlySalary) {}

		double getSalary() const
		{
			return monthlySalary;
		}

		std::string getRole() const
		{
			return "Full time employee";
		}
};

class Manager : public FullTimeEmployee
{
	protected:
		double bonus;

	public:
		Manager(double monthlySalary, double bonus): FullTimeEmployee(monthlySalary), bonus(bonus) {}

		double getSalary() const
		{
			return FullTimeEmployee::getSalary() + bonus;
		}

		std::string getRole() const
		{
			return "Manager";
		}
};

class Engineer : public FullTimeEmployee
{
	protected:
		const double bonus = 500;
		int projectsCompleted;

	public:
		Engineer(double monthlySalary, int projectsCompleted) : FullTimeEmployee(monthlySalary), projectsCompleted(projectsCompleted) {}

		double getSalary() const
		{
			return FullTimeEmployee::getSalary() + (bonus * projectsCompleted);
		}

		std::string getRole() const
		{
			return "Engineer";
		}
};

class PartTimeEmployee : public Employee
{
	protected:
		double hourlyRate;
		int hoursWorked;

	public:
		PartTimeEmployee(double hourlyRate, int hoursWorked) : hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

		double getSalary() const
		{
			return hourlyRate * hoursWorked;
		}

		std::string getRole() const
		{
			return "Part time employee";
		}
};

class Intern : public PartTimeEmployee
{
	public:
		using PartTimeEmployee::PartTimeEmployee;

		double getSalary() const
		{
			return PartTimeEmployee::getSalary() * 0.8;
		}

		std::string getRole() const
		{
			return "Intern";
		}
};

int main()
{
	FullTimeEmployee fte(4000); // 4000
	Manager m(6000, 1000); // 7000
	Engineer e(5000, 4); // 7000
	PartTimeEmployee pte(20, 60); // 1200
	Intern i(25, 40); // 800

	Employee* list[5] = { &fte, &m, &e, &pte, &i };
	int totalSalary = 0;

	for (auto employee : list)
	{
		totalSalary += employee->getSalary();
	}

	std::cout << "Total salary: " << totalSalary << std::endl;

	return 0;
}