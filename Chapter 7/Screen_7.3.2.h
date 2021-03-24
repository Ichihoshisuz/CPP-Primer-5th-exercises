
class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
public:
	Screen &move(pos r, pos cur) //�ƶ�����˼
	{
		pos row = r * width;
		cursor = row + cur;
		return *this;
	}
	Screen &set(char c)
	{
		contents[cursor] = c;
		return *this;
	}
	Screen &set(pos r, pos cur, char c)
	{
		contents[r*width + cur] = c;
		return *this;
	}
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
private:
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

}; 
