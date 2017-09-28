UTLIB = googletest/build/googlemock/libgmock_main.a\
        googletest/build/googlemock/libgmock.a\
        googletest/build/googlemock/gtest/libgtest.a

UTINC = -I./googletest/googlemock/include\
        -I./googletest/googletest/include\
        -I./Include

UTFLAG = -g -pthread -DUNIT_TEST  -Wall#-Wno-write-strings

all:
	g++ -std=c++14 -pthread -I./Include Source/*.cpp -o watch.exe -g

ut:
	g++ -std=c++14 ${UTFLAG} ${UTINC} ${UTLIB} Source/*.cpp Test_modules/*.cpp -o ut_watch.exe

clean:
	rm -rf *.o
	rm -rf Test_modules/*.o
	rm -rf *.exe
