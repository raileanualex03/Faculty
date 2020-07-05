#pragma once
#include <string>
class Task
{
private:
	std::string _description;
	std::string _status;
	// id=-1 will be for no programmer assigned.
	int _id;
public:
	Task(std::string description, std::string status, int id):_description{ description }, _id{ id }, _status{ status }{};
	Task(std::string description) :_description{ description } { _status = "opened"; _id = -1; };
	std::string getDescription() {
		return _description;
	}

	std::string getStatus() {
		return _status;
	}

	void setStatus(std::string status) {
		_status = status;
	}

	void setID(int id) {
		_id = id;
	}
	int getID() {
		return _id;
	}
	
	std::string toString() {
		std::string s;
		s += _description + ',';
		s += _status + ',';
		s += std::to_string(_id);
		return s;
	}

};

