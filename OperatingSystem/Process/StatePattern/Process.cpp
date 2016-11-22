// Author: Yushan Zhang

#include <string>
class ProcessState;
class Process{
public:
	Process();
	Process* clone();
	std::string report();
	int getID();
	void admitted(Process * p);
	void scheduled(Process * p);
	void interrupt(Process * p);
	void stop(Process * p);
	void eventWait(Process * p);
	void eventComplete(Process * p);
	void changeState(ProcessState* s);
private:
	ProcessState *state_;
	static int processID;
	int processID_;	
};

int Process::processID = 0;
Process* Process::clone(){
	return new Process();	
}
int Process::getID(){return processID_;}

class ProcessState{
public:
	virtual void admitted(Process * p){}
	virtual void scheduled(Process * p){}
	virtual void interrupt(Process * p){}
	virtual void stop(Process * p){}
	virtual void eventWait(Process * p){}
	virtual void eventComplete(Process * p){}
	void changeState(Process* p, ProcessState* s){
      p->changeState(s);
    }
	virtual std::string report()=0;
};

// Process delegation
void Process::admitted(Process * p){state_ -> admitted(this);}
void Process::scheduled(Process * p){state_ -> scheduled(this);}
void Process::interrupt(Process * p){state_ -> interrupt(this);}
void Process::stop(Process * p){state_ -> stop(this);}
void Process::eventWait(Process * p){state_ -> eventWait(this);}
void Process::eventComplete(Process * p){state_ -> eventComplete(this);}
std::string Process::report(){
	return state_ -> report();
}

void Process::changeState(ProcessState* s){state_ = s;}

// State types
class New: public ProcessState{
public:
	void admitted(Process * p);
	string report(){return "new";}
};

//=========================================
// Process initialization
Process::Process(): processID_(processID){
	processID++;
	state_ = new New();
}
//=========================================

// Continue state types
class Ready: public ProcessState{
	void scheduled(Process * p);
	string report(){return "ready";}
};

void New::admitted(Process * p){changeState(p, new Ready());}

class Waiting: public ProcessState{
	void eventComplete(Process * p){changeState(p, new Ready());}
	string report(){return "waiting";}
};

class Terminated: public ProcessState{
	string report(){return "terminated";}
};

class Running: public ProcessState{
	void interupt(Process * p){changeState(p, new Ready());}
	void stop(Process *p){changeState(p, new Terminated());}
	void eventWait(Process *p){changeState(p, new Waiting());}
	string report(){return "running";}
};

void Ready::scheduled(Process * p){changeState(p, new Running());}
