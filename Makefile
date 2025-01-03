CXXFLAGS=-std=c++23 -pedantic -Wall -Wpointer-arith -Wwrite-strings
CXXFLAGS+=-Wcast-qual -Wcast-align -Wformat-security
CXXFLAGS+=-Wformat-nonliteral -Wmissing-format-attribute
CXXFLAGS+=-Winline -funsigned-char
CC=$(CXX)

all: q1 q2 q3 q4 q5 q6 q7 q8 q9 q10 q11 q12

q1: q1.cc
	$(CC) $(CXXFLAGS) -o q1 q1.cc

q2: q2.cc
	$(CC) $(CXXFLAGS) -o q2 q2.cc

q3: q3.cc
	$(CC) $(CXXFLAGS) -o q3 q3.cc

q4: q4.cc
	$(CC) $(CXXFLAGS) -o q4 q4.cc

q5: q5.cc
	$(CC) $(CXXFLAGS) -o q5 q5.cc

q6: q6.cc
	$(CC) $(CXXFLAGS) -o q6 q6.cc

q7: q7.cc
	$(CC) $(CXXFLAGS) -o q7 q7.cc

q8: q8.cc
	$(CC) $(CXXFLAGS) -o q8 q8.cc

q9: q9.cc
	$(CC) $(CXXFLAGS) -o q9 q9.cc

q10: q10.cc
	$(CC) $(CXXFLAGS) -o q10 q10.cc

q11: q11.cc
	$(CC) $(CXXFLAGS) -o q11 q11.cc

q12: q12.cc
	$(CC) $(CXXFLAGS) -o q12 q12.cc

clean:
	rm -f q1 q2 q3 q4 q5 q6 q7 q8 q9 q10 q11 q12
