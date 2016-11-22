// Author: Yushan Zhang

#include <string>
#include <iostream>
using std::string;
using std::cout; using std::endl; using std::cin;
#include "Process.cpp"

void report(Process *process){
	cout << "Process " << process->getID() 
			<< " is " << process->report() << endl;
}

// test for process
int main(){
	Process pp;
	Process* process[2];

	for(int i=0; i<5; i++){
		process[i] = pp.clone();
		report(process[i]);
		process[i]->admitted(process[i]);
		report(process[i]);
		process[i]->scheduled(process[i]);
		report(process[i]);
		process[i]->eventWait(process[i]);
		report(process[i]);
		process[i]->eventComplete(process[i]);
		report(process[i]);
		process[i]->scheduled(process[i]);
		report(process[i]);
		process[i]->stop(process[i]);	
		report(process[i]);
	}

}