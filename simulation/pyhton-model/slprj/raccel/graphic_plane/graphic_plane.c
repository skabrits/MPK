#include "graphic_plane.h"
#include "mwmathutil.h"
#include "rtwtypes.h"
#include "rt_logging_mmi.h"
#include "graphic_plane_capi.h"
#include "graphic_plane_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.7 (R2022a) 13-Nov-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlStart ( void ) { { bool externalInputIsInDatasetFormat =
false ; void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtDW . ogbwgfogay = 0 ; rtDW . fs3gqwtfzy = 0 ; } void MdlOutputs ( int_T
tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid ) {
real_T e1nzprofwt ; real_T fpxq2ecpb5 ; real_T gncajgrhmg ; real_T gziux4pcyq
; real_T iuvsvclc3k ; real_T k3iaoqulib ; real_T n4lxkawe54 ; real_T
oerlchswgt ; boolean_T k22fvt0mqq ; muDoubleScalarSinCos (
0.017453292519943295 * rtP . FlatEarthtoLLA_psi , & oerlchswgt , & e1nzprofwt
) ; n4lxkawe54 = rtP . x_Value * e1nzprofwt - rtP . y_Value * oerlchswgt ;
k3iaoqulib = rtP . f_Value - rtP . Constant_Value_jntboeoydz ; iuvsvclc3k =
rtP . Constant_Value_h3mh4e54un - k3iaoqulib * k3iaoqulib ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . ogbwgfogay != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
ogbwgfogay = 0 ; } k3iaoqulib = muDoubleScalarSqrt ( iuvsvclc3k ) ; } else if
( iuvsvclc3k < 0.0 ) { k3iaoqulib = - muDoubleScalarSqrt ( muDoubleScalarAbs
( iuvsvclc3k ) ) ; rtDW . ogbwgfogay = 1 ; } else { k3iaoqulib =
muDoubleScalarSqrt ( iuvsvclc3k ) ; } if ( muDoubleScalarAbs ( rtP .
FlatEarthtoLLA_LL0 [ 0 ] ) > rtP . CompareToConstant_const ) { iuvsvclc3k =
muDoubleScalarMod ( rtP . FlatEarthtoLLA_LL0 [ 0 ] + rtP . Bias_Bias , rtP .
Constant2_Value_krlazp4iwf ) + rtP . Bias1_Bias ; } else { iuvsvclc3k = rtP .
FlatEarthtoLLA_LL0 [ 0 ] ; } fpxq2ecpb5 = muDoubleScalarAbs ( iuvsvclc3k ) ;
k22fvt0mqq = ( fpxq2ecpb5 > rtP . CompareToConstant_const_lpgrzvb4zb ) ; if (
k22fvt0mqq ) { iuvsvclc3k = ( ( fpxq2ecpb5 + rtP . Bias_Bias_l4mmzmheyi ) *
rtP . Gain_Gain + rtP . Bias1_Bias_lwb2x0lz4t ) * muDoubleScalarSign (
iuvsvclc3k ) ; } fpxq2ecpb5 = 0.017453292519943295 * iuvsvclc3k ; gziux4pcyq
= muDoubleScalarSin ( fpxq2ecpb5 ) ; gziux4pcyq = rtP .
Constant_Value_ah3sen0uqm - k3iaoqulib * k3iaoqulib * gziux4pcyq * gziux4pcyq
; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . fs3gqwtfzy != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
fs3gqwtfzy = 0 ; } gncajgrhmg = muDoubleScalarSqrt ( gziux4pcyq ) ; } else if
( gziux4pcyq < 0.0 ) { gncajgrhmg = - muDoubleScalarSqrt ( muDoubleScalarAbs
( gziux4pcyq ) ) ; rtDW . fs3gqwtfzy = 1 ; } else { gncajgrhmg =
muDoubleScalarSqrt ( gziux4pcyq ) ; } gncajgrhmg = rtP . Constant1_Value /
gncajgrhmg ; e1nzprofwt = ( rtP . x_Value * oerlchswgt + rtP . y_Value *
e1nzprofwt ) * muDoubleScalarAtan2 ( rtP . Constant3_Value , gncajgrhmg *
muDoubleScalarCos ( fpxq2ecpb5 ) ) * 57.295779513082323 ; if ( k22fvt0mqq ) {
fpxq2ecpb5 = rtP . Constant_Value_a10nlnrpwn ; } else { fpxq2ecpb5 = rtP .
Constant1_Value_fipwkjv1k4 ; } oerlchswgt = fpxq2ecpb5 + rtP .
FlatEarthtoLLA_LL0 [ 1 ] ; if ( muDoubleScalarAbs ( oerlchswgt ) > rtP .
CompareToConstant_const_ln1vphan13 ) { oerlchswgt = muDoubleScalarMod (
oerlchswgt + rtP . Bias_Bias_ezzhbbeoze , rtP . Constant2_Value_c1ysq1elqy )
+ rtP . Bias1_Bias_g3odia1kmy ; } k3iaoqulib = muDoubleScalarAtan2 ( rtP .
Constant2_Value , ( rtP . Constant_Value_bugcmhye3g - k3iaoqulib * k3iaoqulib
) * gncajgrhmg / gziux4pcyq ) * n4lxkawe54 * 57.295779513082323 + iuvsvclc3k
; n4lxkawe54 = e1nzprofwt + oerlchswgt ; if ( muDoubleScalarAbs ( k3iaoqulib
) > rtP . CompareToConstant_const_cuek01fcm1 ) { oerlchswgt =
muDoubleScalarMod ( k3iaoqulib + rtP . Bias_Bias_pz4bj2aggk , rtP .
Constant2_Value_lzvy0bomjv ) + rtP . Bias1_Bias_k5af1gwgsv ; } else {
oerlchswgt = k3iaoqulib ; } e1nzprofwt = muDoubleScalarAbs ( oerlchswgt ) ;
k22fvt0mqq = ( e1nzprofwt > rtP . CompareToConstant_const_ourdeuccjb ) ; if (
k22fvt0mqq ) { fpxq2ecpb5 = rtP . Constant_Value ; } else { fpxq2ecpb5 = rtP
. Constant1_Value_powldid0mm ; } n4lxkawe54 += fpxq2ecpb5 ; if (
muDoubleScalarAbs ( n4lxkawe54 ) > rtP . CompareToConstant_const_kcefi55u0t )
{ rtB . datymt25li = muDoubleScalarMod ( n4lxkawe54 + rtP .
Bias_Bias_a2ngdjn3cn , rtP . Constant2_Value_o503yjt3g1 ) + rtP .
Bias1_Bias_beqlpqjuhh ; } else { rtB . datymt25li = n4lxkawe54 ; } if (
k22fvt0mqq ) { rtB . gdfxliypwc = ( ( e1nzprofwt + rtP . Bias_Bias_fj5p4fqtlh
) * rtP . Gain_Gain_jlh2aj143k + rtP . Bias1_Bias_f0n3qnphy4 ) *
muDoubleScalarSign ( oerlchswgt ) ; } else { rtB . gdfxliypwc = oerlchswgt ;
} rtB . dhvfuzmxio = - rtP . z_Value - rtP . Constant1_Value_c1zfghbdbg ; rtB
. kgzgt0fmwb = rtP . gama_Value ; rtB . fyvanjft0r = rtP . theta_Value ; rtB
. piczck40ik = rtP . psi_Value ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid )
{ UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { } static void
mr_graphic_plane_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) ; static void
mr_graphic_plane_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_graphic_plane_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_graphic_plane_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_graphic_plane_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void mr_graphic_plane_cacheBitFieldToMxArray
( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( double )
bitVal ) ) ; } static uint_T mr_graphic_plane_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static
uint_T mr_graphic_plane_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_graphic_plane_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_graphic_plane_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_graphic_plane_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_graphic_plane_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_graphic_plane_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_graphic_plane_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_graphic_plane_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_graphic_plane_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_graphic_plane_GetDWork ( ) { static
const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ;
mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_graphic_plane_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB
) , sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 3 ] = {
"rtDW.ogbwgfogay" , "rtDW.fs3gqwtfzy" , "rtDW.ik244sfmwe" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 3 , rtdwDataFieldNames ) ;
mr_graphic_plane_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & (
rtDW . ogbwgfogay ) , sizeof ( rtDW . ogbwgfogay ) ) ;
mr_graphic_plane_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . fs3gqwtfzy ) , sizeof ( rtDW . fs3gqwtfzy ) ) ;
mr_graphic_plane_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . ik244sfmwe ) , sizeof ( rtDW . ik244sfmwe ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_graphic_plane_SetDWork
( const mxArray * ssDW ) { ( void ) ssDW ;
mr_graphic_plane_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0
, sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW ,
0 , 1 ) ; mr_graphic_plane_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ogbwgfogay ) , rtdwData , 0 , 0 , sizeof ( rtDW . ogbwgfogay ) ) ;
mr_graphic_plane_restoreDataFromMxArray ( ( void * ) & ( rtDW . fs3gqwtfzy )
, rtdwData , 0 , 1 , sizeof ( rtDW . fs3gqwtfzy ) ) ;
mr_graphic_plane_restoreDataFromMxArray ( ( void * ) & ( rtDW . ik244sfmwe )
, rtdwData , 0 , 2 , sizeof ( rtDW . ik244sfmwe ) ) ; } } mxArray *
mr_graphic_plane_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 116 ) ;
ssSetNumBlockIO ( rtS , 12 ) ; ssSetNumBlockParams ( rtS , 72 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.033333333333333333 ) ; ssSetOffsetTime ( rtS ,
0 , 1.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum (
) { ssSetChecksumVal ( rtS , 0 , 2582406175U ) ; ssSetChecksumVal ( rtS , 1 ,
1527522671U ) ; ssSetChecksumVal ( rtS , 2 , 249056648U ) ; ssSetChecksumVal
( rtS , 3 , 1448194977U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 22 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
graphic_plane_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS
, true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "graphic_plane" ) ;
ssSetPath ( rtS , "graphic_plane" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , rtInf ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo
. loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo )
; } { rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 0.033333333333333333 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS ,
0.033333333333333333 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
2582406175U ) ; ssSetChecksumVal ( rtS , 1 , 1527522671U ) ; ssSetChecksumVal
( rtS , 2 , 249056648U ) ; ssSetChecksumVal ( rtS , 3 , 1448194977U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 2 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_graphic_plane_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP
( rtS , mr_graphic_plane_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_graphic_plane_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if
( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
