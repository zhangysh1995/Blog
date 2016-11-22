//Initial code by Naser Al Madi (Zero-Cool)
//Operating Systems - Scheduling project
//21-OCT-2016
//student name:
//

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
using std::vector;
using std::deque;
using std::string;
using std::cout; using std::endl; using std::cin;
#include "process.h"


//data process ID, Burst time, and priority
//size is the size of the arrays or data records
std::string pID[10];
int burst[10];
int priority[10];
int size;
deque<Process>process;

//the function initializes the data arrays with records from the file stream
void initFrom(std::ifstream& in){

	std::string id, temp;
	int b_time;
	int proi;
	int i = 0;

	//prints out the header of the file
	if (!in.eof()){
		in>>id;
		std::cout<<"\n"<<id<<"\t";
		in>>temp;
		std::cout<<temp<<"\t";
		in>>temp;
        std::cout<<temp<<"\n";
	}

	//reading in data from the file and storing it in the right array
	while (!in.eof() && in>>id && in>>b_time && in>>proi && i < 10){

		pID[i] = id;
                std::cout<<pID[i]<<"\t";

		burst[i] = b_time;
                std::cout<< burst[i]<<"\t";

		priority[i] = proi;
                std::cout<<priority[i]<<"\n";
        // save process in vector
        Process newProcess(id, b_time, proi);
        process.push_back(newProcess);
		i++;
	}
	//the size of the arrays is the same
	size = i;
	std::cout<<"size: "<<size;
	std::cout<<"\nDone reading data from file\n";
}

// NO REFACTORING
//First Come First Serve implementation, this is a working example to show you how the output could look like
void myFCFS(){
	int wait_t[10];
	int turn_t[10];
	double avg_wait=0;
	double avg_turn=0;
	int i=0;
	int t=0;

	std::cout<<"\nPID\twait\tturnaround\n";

	//calculating wait-time and turnarround-time for each process
	while (i<size){
		//compute wait time
		wait_t[i]=t;
		t = t + burst[i];
		//compute turnaround time
		turn_t[i]=wait_t[i] + burst[i];

		std::cout<<"P"<<i+1<<"\t"<<wait_t[i]<<"\t"<<turn_t[i]<<"\n";
		i++;
	}

	//calculating the averages of wait time and turnaround time
	i=0;
	while(i<size){
		avg_wait = avg_wait +  wait_t[i];
		avg_turn = avg_turn + turn_t[i];
		i++;
	}

	avg_wait = avg_wait/size;
	avg_turn = avg_turn/size;

	//printing the averages
	std::cout<<"AVG wait is: "<<avg_wait<<"\n";
	std::cout<<"AVG turnaround is: "<<avg_turn<<"\n";

}

// the implemantation of this algorithms 
// is applied to SJF, LJF and Priority
void commonAlgorithm(){
	int wait = 0;	
	cout << endl <<"PID\t" << "wait\t" << "turn-around" << endl;
	// calculate wait & turnaround time
	for(int i = 0; i< size; i++){
		process[i].wait_ = wait;
		// wait time for next process is turnaround time of previuos process
		// only for non-preemptive scheduling
		wait = process[i].turnaround_ = wait + process[i].burst_;
	}
	// sor by pid, easier to print
	std::sort(process.begin(), process.end(),
				[=](Process &X, Process &Y){return X.pid_ < Y.pid_;});

	wait = 0;	//total wait-time
	int turnaround = 0;	//total turn-around time
	for(auto it: process){
		cout << it.pid_ << "\t" << it.wait_ << "\t" << it.turnaround_ << endl;
		wait += it.wait_;
		turnaround += it.turnaround_;
	}
	std::cout<<"AVG wait is: "<<(double)wait/size<<"\n";
	std::cout<<"AVG turnaround is: "<<(double)turnaround/size<<"\n";
}

void mySJF(){	
	// sort by burst time
	std::sort(process.begin(), process.end(),
				[=](Process &X, Process &Y){return X.burst_ <= Y.burst_;});
	commonAlgorithm();
}

void myPriority(){
	// sort by priority
	std::sort(process.begin(), process.end(),
				[=](Process &X, Process &Y){return X.priority_ >= Y.priority_;});
	commonAlgorithm();
}

void myLJF(){	
	// sort by burst time
	std::sort(process.begin(), process.end(),
				[=](Process &X, Process &Y){return X.burst_ > Y.burst_;});
	commonAlgorithm();
}

void myRR(int slice = 2){
	//for(auto& it: process) it->turnaround_ += it->burst_;
	int total = 0;
	int wait = 0;
	int turnaround = 0;
	vector<Process>finishQ;
	deque<Process>copy = process;
		std::sort(copy.begin(), copy.end(),
				[=](Process &X, Process &Y){return X.pid_ < Y.pid_;});
	Process *p;	
	while(true){
		p = &copy.front();
		
		if(p->burst_ > 0 && p->burst_ < slice){	
			// wait
			p->wait_ += total - p->lastEnd_;
			total += p->burst_;	
			// turnaround
			p->turnaround_ += p->burst_;		
			// burst
			p->burst_ = 0;

			p->lastEnd_ = total;
		}
		else if (p->burst_ >= slice){
			//wait
			p->wait_ += total - p->lastEnd_;

			// turnaround
			p->turnaround_ += slice;
			// burst
			p->burst_ -= slice;

			total += slice;
			p->lastEnd_ = total;		
		}

		if(p->burst_ == 0){
			finishQ.push_back(*p);
		}
		else copy.push_back(*p);
		copy.pop_front();

		if(copy.empty()) break;
	}

	std::sort(finishQ.begin(), finishQ.end(),
				[=](Process &X, Process &Y){return X.pid_ < Y.pid_;});
	cout << endl <<"PID\t" << "wait\t" << "turn-around" << endl;
	for(auto it: finishQ){
		cout << it.pid_ << "\t" << it.wait_ << "\t" << it.turnaround_ << endl;
		wait += it.wait_;
		turnaround += it.turnaround_;
	}
	std::cout<<"AVG wait is: "<<(double)wait/size<<"\n";
	std::cout<<"AVG turnaround is: "<<(double)turnaround/size<<"\n";

}

int main (){
	//open a file stream
	std::ifstream file ("proc.txt");

	if (!file){
		std::cerr<<"\ncould not open file!\n";
	return 1;
	}
	initFrom(file);

	int alg;
	//this outputs the usage message
	while (true){

		std::cout<<"\nwhich scheduling algorithm do you want to run:\n 1- First Come First Serve (FCFS)\n 2- Shortest Job First (SJF)\n 3- Priority (p)\n 4- Longest Job First (LJF) (bonus)\n 5- Round-Robin (RR)(bonus)\nchoice: ";
		std::cin>>alg;

		switch(alg) {
    		case 1: myFCFS();
					break;
			case 2: mySJF();
                    break;
			case 3: myPriority();
                    break;
			case 4: myLJF();
					break;
			case 5: cout << endl << "====== How long is time slice? ======" << endl;
					int slice; cin >> slice;
					myRR(slice);
					break;
			default: std::cout<<"\npick 1 or 2 or 3.\n"; 
		}
	}

	return 0;
}
