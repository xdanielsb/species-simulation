#ifndef _CDefines
#define _CDefines
/*
 * Namespace
 */
using namespace std;

/*
 * New Types
 */
typedef pair< float, float > ii;

/*
 * Constants and defines
 */
const double PI = acos(-1);
#define X first
#define Y second

/*
 * Enum types
 */
 enum BEHAVIOURS{
   FarSighted         = 0,
   Gregariu           = 1,
   Kamikaze           = 2,
   Lazy               = 3,
   MultipleBehaviour  = 4
 };
#endif

/**
  * New operations
  */
