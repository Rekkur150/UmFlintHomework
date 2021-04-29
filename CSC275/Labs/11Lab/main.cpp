#include <iostream>
#include <vector>
#include <set>
#include <time.h>
#include <random>

using namespace std;

void RandFill_Vector(int n);
void RandFill_Set(int n);
int main()
{
    time_t starttime, endtime;
    double dif;

    cout << "Running RandFill_Set 1024" << endl;
    time(&starttime);   //Record start time for vector
    RandFill_Set(1024); ///<----------------------------------Modify this line of code for testing
    time(&endtime);     //Record end time for vector
    dif = difftime(endtime, starttime);
    cout << "It took " << dif << " seconds to execute." << endl << endl;;


    cout << "Running RandFill_Set 2048" << endl;
    time(&starttime);   //Record start time for vector
    RandFill_Set(2048); ///<----------------------------------Modify this line of code for testing
    time(&endtime);     //Record end time for vector
    dif = difftime(endtime, starttime);
    cout << "It took " << dif << " seconds to execute." << endl << endl;


    cout << "Running RandFill_Set 4096" << endl;
    time(&starttime);   //Record start time for vector
    RandFill_Set(4096); ///<----------------------------------Modify this line of code for testing
    time(&endtime);     //Record end time for vector
    dif = difftime(endtime, starttime);
    cout << "It took " << dif << " seconds to execute." << endl << endl;


    cout << "Running RandFill_Set 8192" << endl;
    time(&starttime);   //Record start time for vector
    RandFill_Set(8192); ///<----------------------------------Modify this line of code for testing
    time(&endtime);     //Record end time for vector
    dif = difftime(endtime, starttime);
    cout << "It took " << dif << " seconds to execute." << endl << endl;


    cout << "Running RandFill_Set 16384" << endl;
    time(&starttime);   //Record start time for vector
    RandFill_Set(16384); ///<----------------------------------Modify this line of code for testing
    time(&endtime);     //Record end time for vector
    dif = difftime(endtime, starttime);
    cout << "It took " << dif << " seconds to execute." << endl << endl;


    cout << "Running RandFill_Set 32768" << endl;
    time(&starttime);   //Record start time for vector
    RandFill_Set(32768); ///<----------------------------------Modify this line of code for testing
    time(&endtime);     //Record end time for vector
    dif = difftime(endtime, starttime);
    cout << "It took " << dif << " seconds to execute." << endl << endl;
    /*

    B) Test results here:

	RandFill_Vector
		1024 = 0 seconds
		2048 = 0 seconds
		4096 = 1 seconds
		8192 = 6 seconds
		16384 = 25 seconds
		32768 = 122 seconds

    C) Test results here:

	RandFill_Set
		1024 = 0 seconds
		2048 = 0 seconds
		4096 = 0 seconds
		8192 = 0 seconds
		16384 = 0 seconds
		32768 = 1 seconds


    D) Big Oh running time of find()

	O(log n)




    E) Big Oh running time of RandFill_Vector

	O(n^2)



    F) Big Oh running time of RandFill_Set

	O(n log(n))


    */

    return 0;

}

void RandFill_Vector(int n){
    //Input n from user
    int r;
    bool found_r = false;
    //Create a vector v of type int
    vector<int> myvec;
    //Loop i = 1 to n
    int i = 1;
    while(i <= n){
        //r = random integer between 0 and n-1
        r = rand()%n;
        //linearly search through v for value r
        for(int j = 0; j<myvec.size(); j++){
            if( r == myvec[j]){
                found_r = true;
            }
        }
        if(!found_r){
            myvec.push_back(r);
            i++;
        }
        found_r = false;
    }

    cout << myvec.size() << " unique random values put into the vector " << endl;

}


void RandFill_Set(int n){
    //input n from user
    int r;
    //create set s of type int
    set<int> s;
    set<int>::iterator it;
    //loop i = 1 to n
    int i = 1;
    while(i <= n){ //O(n)
        //r = random integer between 0 and n-1
        r = rand()%n;
        //use s.find(r) to search of r is already in the set
        it = s.find(r); //O(log(n))
        if(it == s.end()){ //O(1)
            s.insert(r); //O(log(n))
            i++;
        }

    }

    cout << s.size() << " unique random values put into the set " << endl;


}
