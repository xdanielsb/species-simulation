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
 * Base colors
 */

const float WHITE[] = { 255, 255, 255 }, BLACK[] = { 0, 0, 0 };

/*
 * Constants and defines
 */
const double PI = acos(-1);
#define X first
#define Y second

const unsigned int WIDTH_WINDOW  = 600;
const unsigned int HEIGHT_WINDOW = 600;
const unsigned int ONE_MINUTE    = 300;
const unsigned int MARGIN    =  20;
const unsigned int ONE_SECOND    = 1;

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

const int NUMBEHAVIOURS  = 5;
const int NUMACCESORIES  = 3;
const int NUMSENSORS     = 2;

 inline const char* INITALS_BEHAVIOURS[ NUMBEHAVIOURS ] ={
  "FARSIGTHED",
  "GREGARIU",
  "KAMIKAZE",
  "LAZY",
  "MULTIPLEBEHAVIOUR"};


#endif

/**
  * New operations
  */
