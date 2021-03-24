class Account
{
public:
	double calculate() 
	{
		saving += saving * interestRate;
		return saving;
	}
	static double rate() { return interestRate; }
	static void change(double r) { interestRate = r; }
private:
	static double interestRate;
	static double initRate();
	std::string name;
	double saving=0.0;
};
double Account::initRate()
{
	double r;
	std::cin >> r;
	return r;
}
double Account::interestRate = initRate();