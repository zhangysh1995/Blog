
struct Process{

	Process(string pid, int burst, int priority):
			pid_(pid), burst_(burst), priority_(priority),
			wait_(0), turnaround_(0){ }

	string pid_;
	int burst_;
	int priority_;
	int wait_;
	int turnaround_;
};