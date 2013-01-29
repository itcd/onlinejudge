#include <string>
#include <iostream>
#include <fstream>
#include "account.h"
#include "accountList.h"
#include "customer.h"
#include "customerList.h"
#include "windows.h"
using namespace std;

#define MAXTHREADS16 // max number of threads
HANDLE threadH[MAXTHREADS]; // thread handles
more = 1;                                                                 // threads run until more = 0
for (int thread = 0; thread < ncpu; thread++) // create ncpu threads
threadH[thread] = CreateThread(NULL, 0, worker, (LPVOID) thread, 0, NULL);
Sleep(10000); // main thread sleeps for 10,000ms (10 seconds)
more = 0; // set more = 0 so worker threads will terminate
// wait for all threads to terminate
WaitForMultipleObjects(ncpu, threadH, true, INFINITE);
