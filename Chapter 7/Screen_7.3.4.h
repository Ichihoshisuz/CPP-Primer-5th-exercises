class Screen;
class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex i);
	Window_mgr();
private:
	std::vector<Screen> Screens;
};
class Screen
{
public:
	using pos = std::string::size_type;
	friend void Window_mgr::clear(ScreenIndex);
public:
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
public:
	Screen & move(pos r, pos cur) //移动到意思
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
Window_mgr::Window_mgr()
{
	Screens = { Screen(27,48,' ') };
}
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = Screens[i];
	s.contents = (s.height*s.width, ' ');
}
