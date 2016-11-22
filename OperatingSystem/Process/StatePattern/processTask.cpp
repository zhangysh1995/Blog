
// Author: Yushan Zhang

#include <string>
#include <iostream>
using std::string;
using std::cout; using std::endl; using std::cin;
#include "Process.cpp"
#include <queue>
#include <set>
#include <cstdlib>

using std::queue; using std::set;

void report(Process *process){
	cout << "Process " << process->getID() 
			<< " is " << process->report() << endl;
}

int main(){
	srand(time(nullptr));

	// process prototype
	Process prototypeProcess;

	// process containters
	Process* process[5];
	queue<Process*>readyQ;
	set<Process*>waitingQ;
	
	// clone five new process from prototype
	cout << "\nGet ready! " << endl;
	for(int i=0; i<5; i++){
		process[i]= prototypeProcess.clone();
		readyQ.push(process[i]);
		process[i]->admitted(process[i]);
		report(process[i]);
	}

	// running until ready queueis empty
	while(!readyQ.empty()){
		cout << "\nStart running: " << endl;
		// first process in ready queue
		Process *running = readyQ.front();
		readyQ.pop();
		//first process in queue is running
		running->scheduled(running);
		report(running);
		// randomely choose instruction
		int choice = rand()%3;
		switch (choice){
			case 0: 
				running->stop(running); break;
			case 1: 
				running->eventWait(running);
				waitingQ.insert(running); break;
			case 2: 
				running->interrupt(running);
				readyQ.push(running);break;
			default: cout << "Error!" << endl;
		}
		report(running);
		cout << "\nWaiting set: " << endl;
		//restart one from waiting set
		if(!waitingQ.empty()){
			// randomly pick one from waiting set
			int index = rand()%waitingQ.size();
			auto it = waitingQ.begin();
			for(int i=0 ;i< index; i++){it++;}
			Process *waiting = *(it);
			// move out of waiting set
			waitingQ.erase(it);
			// I/O complete, return to ready queue
			waiting->eventComplete(waiting);
			readyQ.push(waiting);
			waiting->report();
		}
	}
}