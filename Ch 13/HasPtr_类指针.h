#include <string>
class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0),use(new std::size_t) {}

	HasPtr(const HasPtr& orig) :
		ps(new std::string(*orig.ps)), i(orig.i), use(orig.use) {
		++* use;
	}

	HasPtr& operator=(const HasPtr& rhs);

	~HasPtr()
	{
		if (-- * use == 0)
		{
			delete use;
			delete ps;
		}
	}
private:
	std::size_t* use;
	std::string* ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++* rhs.use;
	if (-- * use == 0)
	{
		delete use;
		delete ps;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}