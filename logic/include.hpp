#ifndef _CDefines
#define _CDefines
/*
 * Namespace
 */
using namespace std;

// TODO: DELETE BEFORE SEND
#define debug(x) cout << #x << " = " << x <<endl;

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

#define WIDTH_WINDOW 300
#define HEIGHT_WINDOW 400
#define ONE_MINUTE 60
#define ONE_SECOND 1
/*
 * Enum types
 */
 enum BEHAVIOURS{
   FARSIGTHED         = 0,
   GREGARIU           = 1,
   KAMIKAZE           = 2,
   LAZY               = 3,
   MULTIPLEBEHAVIOUR  = 4
 };
 enum ACCESSORY{
   CAMOUFLAGE  = 0,
   FIN         = 1,
   SHELL       = 2,
 };
 enum SENSOR{
   EAR = 0,
   EYE = 1,
 };



#endif

/**
  * New operations
  */
