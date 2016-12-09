
aps: Car.o Bay.o GuideSystem.o Kiosk.o Logger.o Member.o MemberCatalog.o Transaction.o TransactionCatalog.o User.o main.o
	clang++ -std=c++11 Car.o Bay.o GuideSystem.o Kiosk.o Logger.o Member.o MemberCatalog.o Transaction.o TransactionCatalog.o User.o main.o -o aps

main.o: main.cpp
	clang++ -std=c++11 -c main.cpp

Logger.o: Logger.cpp Logger.h
	clang++ -std=c++11 -c Logger.cpp

GuideSystem.o: GuideSystem.cpp GuideSystem.h
	clang++ -std=c++11 -c GuideSystem.cpp

Car.o: Car.cpp Car.h
	clang++ -std=c++11 -c Car.cpp

Bay.o: Bay.cpp Bay.h
	clang++ -std=c++11 -c Bay.cpp

Spot.o: Spot.cpp Spot.h
	clang++ -std=c++11 -c Spot.cpp

User.o: User.cpp User.h
	clang++ -std=c++11 -c User.cpp

Member.o: Member.cpp Member.h
	clang++ -std=c++11 -c Member.cpp

MemberCatalog.o: MemberCatalog.cpp MemberCatalog.h
	clang++ -std=c++11 -c MemberCatalog.cpp

Transaction.o: Transaction.cpp Transaction.h
	clang++ -std=c++11 -c Transaction.cpp

TransactionCatalog.o: TransactionCatalog.cpp TransactionCatalog.h
	clang++ -std=c++11 -c TransactionCatalog.cpp
Kiosk.o: Kiosk.cpp Kiosk.h
	clang++ -std=c++11 -c Kiosk.cpp

clean:
	rm *.o aps
