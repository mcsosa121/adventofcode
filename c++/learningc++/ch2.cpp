//Illustrates scopes, linkages, and visibilities of various identifiers

int i = 2;  //is a file variable with external linkage
static int si; //a file variable with internal linkage
const int ci = 2; // a file variable with internal linkage
struct { int i, j; }; S = {21, 22}; //creates a struct s with coordinates

main() {
    int j = 11; //block variable, internal linkage
    cout << s.i //file variable, so can be accessed (displays 21)
    cout << i; // i != s.i internal vs file, so displays 2
    funct(j); //only changes j internally, as shown by next line, when j
    //is printed again is only changed inside that scope.
    cout << j ; // displays 11
    {
        goto a1; //function variable

    a1: cout << si; //displays 0. default initialization
    cout << ci; // file variable. displays 2
    }
}
funct (int j)  { //block var, no linkage
    cout << i; //file variable, displays 2
    cout << j; // when called, will display 11
    {
        j = 12;
        cout << j ; //block variable, displays 12
    }
    cout << j ; //j has been changed inside block, will display 12
}

//Data types

//classes
class NUMBER {
    public:
        NUMBER(int in) {
            n = in; // constructor
        };
        int getNum() {
            return n; // member function
        };
    private:
        int n;
};
NUMBER nm(2); // compile time object
NUMBER *pnm = new NUMBER(3); /* Access to objects nm's getNum()
member function */

//struct
struct address {
    long housenumber;
    char street[32];
};

//union
union number {
    long longnum;
    float floatnum;
};
//enumerations
//ex 1
    enum {zero, one};
    enum {one = 1, two, three};
    enum {one = 1, two, three, ten = 10, eleven};
//ex 2
    enum {FALSE, TRUE} bool;
    bool = TRUE;
    bool = 1; //error, evon though TRUE=1

//Arrays
char str[12]; //char string
int i[2][3] //2x3 multidimensional array

//pointers
int i;
int *pi; // pointer to int
pi = &i // pi is a pointer to i
int **pi //pointer to a pointer of a int
ppi = &pi; //ppi is a pointer to pi

//references
int i,k;
int &ri = i; //ri is a reference to i
ri = k; //ri is now a reference to k

//initialization
int i = 1; //int i is initializated to 1
i = 1; assignment //i -> a
char c = 'a' // i.
auto float j = 1.0;
struct st {int i; char c;} s = {1, 'a'}; //data aggregations
char ac[] = "alpha"; // string data aggregation

//Data storage identities
//nonpersistent identifiers
class NUM {
    public:
        int TestId(NUM &rn) {
            if (this == &rn)
                return 1
            return 0
        }
};
NUM n1, n2;
cout << "n12:" << n1.TestId(n2) << endl; //returns 0 since n1!=n2
cout << "n11:" << n1.TestId(n1) << endl; // returns 1 since n1 == n1
//Testid tests for identity of th einvoking object and the obj specified as argument

//persistent identifiers
#include <iostream.h>
#include <time.h>

static short instct = 0;  //instance counter

struct ID {
    static char SystemId[8];
    unsigned long Time;
    unsigned short Inst;
};

char ID::SystemId[8] = 'number' ; //system id

class NUM {
    public:
        ID id;
        NUM() {id.time = time(0); id.Inst = instct++l}
        //constructor
};
void main() {
    NUM n1, n2;
    cout << n1.id.SystemId << ';' << n1.id.Time << ';'
        << n1.id.Inst << endl; // form of number;2969211602;0
    cout << n2.id.SystemId << ';' << n2.id.Time << ';'
        << n2.id.Inst << endl; // form of number;2969211602;1
}

//Because standard time does not return a value of suff prevision
// (the number of elapsed seconds since jan 1, 1900)
//the instantiatio counter is required to produce a unique identifier
//SystemID identifies the object class -> if the persistent data is shared
// by multiple computer systems, the systemId has to identify the creating
//computer system. An alternative approach is to have a global counter
//(peristent data that is incremented for each object created)

