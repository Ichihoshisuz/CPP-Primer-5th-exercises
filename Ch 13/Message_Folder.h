#include <string>
#include <set>
using std::set;
using std::string;

class Message;

class Folder
{
public:
	explicit Folder(Message* m);

	Folder(const Folder& f);
	//Folder& operator=(const Folder& F);
	~Folder();

	//void swap(const Folder& lhs, const Folder& rhs);
	void save(Message* m);
	void remove(Message* m);
	void addMsg(Message* m)
	{
		messages.insert(m);
	}
	void remMsg(Message* m)
	{
		messages.erase(m);
	}
private:
	set<Message*> messages;
	void add_to_Messages(const Folder& f);
	void remove_from_Messages();
};


Folder::Folder(const Folder& f) : messages(f.messages)
{
	add_to_Messages(*this);
}

//Folder& Folder::operator=(const Folder& f)

Folder::~Folder()
{
	remove_from_Messages();
}


class Message
{
	friend class Folder;
public:
	explicit Message(const string& str = "") :
		contents(str) { };
	Message(const Message& m);
	Message& operator=(const Message& m);
	~Message()
	{
		remove_from_Folders();
	}


	void save(Folder& f)
	{
		folders.insert(&f);
		f.addMsg(this);
	}

	void remove(Folder& f)
	{
		folders.erase(&f);
		f.remMsg(this);
	}

	void addFold(Folder* f)
	{
		folders.insert(f);
	}

	void remFold(Folder* f)
	{
		folders.erase(f);
	}
	//void swap(const Message& lhs, const Message& rhs);
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message& m)
	{
		for (auto f : m.folders)
			f->save(this);
	}
	void remove_from_Folders()
	{
		for (auto f : folders)
			f->remove(this);
	}
};


Message::Message(const Message& m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);      //add_to_Folders(*this);
}

Message& Message::operator=(const Message& m)
{
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}


Folder::Folder(Message* m)
{
	messages.insert(m);
	m->folders.insert(this);
}

void Folder::add_to_Messages(const Folder& folders)
{
	for (auto m : folders.messages)
		m->save(*this);
}

void Folder::remove_from_Messages()
{
	for (auto m : messages)
		m->remove(*this);
}

void Folder::save(Message* m)
{
	messages.insert(m);
	m->addFold(this);
}

void Folder::remove(Message* m)
{
	messages.erase(m);
	m->remFold(this);
}