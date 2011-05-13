//
// File:        ql_error.cc
// Description: QL_PrintError function
//

#include "ql_error.h"
#include <cerrno>
#include <cstdio>
#include <iostream>
#include "ql.h"

using namespace std;

//
// Error table
//
const char *QL_WarnMsg[] = {
  (char*)"key was not found in btree",
  (char*)"key attribute size is too qlall(<=0) or too big for a page",
  (char*)"key,rid already exists in index",
  (char*)"key,rid combination does not exist in index",
};

const char *QL_ErrorMsg[] = {
  (char*)"QL_BADJOINKEY Bad Join Key - is it present ?",
  (char*)"QL_ALREADYOPEN Iterator already open.",
  (char*)"DB is not open",
  (char*)"Bad Table name - no such table",
  (char*)"bad open",
  (char*)"QL_FNOTOPEN Iterator is not open",
  (char*)"QL_JOINKEYTYPEMISMATCH Join columns need to be the same on both sides",
  (char*)"Bad Table/Relation",
  (char*)"QL_EOF end of input on iterator",
};

//
// QL_PrintError
//
// Desc: Send a message corresponding to a QL return code to cerr
// In:   rc - return code for which a message is desired
//
void QL_PrintError(RC rc)
{
  // Check the return code is within proper limits
  if (rc >= START_QL_WARN && rc <= QL_LASTWARN)
    // Print warning
    cerr << "QL warning: " << QL_WarnMsg[rc - START_QL_WARN] << "\n";
  // Error codes are negative, so invert everything
  else if ((-rc >= -START_QL_ERR) && -rc <= -QL_LASTERROR)
  {
   // Print error
    cerr << "QL error: " << QL_ErrorMsg[-rc + START_QL_ERR] << "\n";
  }
  else if (rc == 0)
    cerr << "QL_PrintError called with return code of 0\n";
  else
  {
   // Print error
    cerr << "rc was " << rc << endl;
    cerr << "START_QL_ERR was " << START_QL_ERR << endl;
    cerr << "QL_LASTERROR was " << QL_LASTERROR << endl;
    cerr << "QL error: " << rc << " is out of bounds\n";
  }
}
