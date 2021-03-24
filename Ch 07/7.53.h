class Debug
{
public:
	constexpr Debug(bool t = true) :gra(t), io(t), cache(t), net(t) {}
	constexpr Debug(bool _gra, bool _io, bool _cache, bool _net) : gra(_gra), io(_io), cache(_cache), net(_net) {}
	void set_gra(bool g) { gra = g; }
	void set_io(bool i) { io = i; }
	void set_cache(bool c) { cache = c; }
	void set_net(bool n) { net = n; }
	constexpr bool tof() { return gra || io || cache || net ; }
private:
	bool gra;
	bool io;
	bool cache;
	bool net;
};