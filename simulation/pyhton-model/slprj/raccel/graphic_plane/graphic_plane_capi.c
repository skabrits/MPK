#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "graphic_plane_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "graphic_plane.h"
#include "graphic_plane_capi.h"
#include "graphic_plane_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"graphic_plane/gama" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0
, TARGET_STRING ( "graphic_plane/psi" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 2 , 0 , TARGET_STRING ( "graphic_plane/theta" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 4 , 0 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 6 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA" ) , TARGET_STRING ( "LL0" ) , 0 , 1 , 0 } ,
{ 7 , TARGET_STRING ( "graphic_plane/Flat Earth to LLA" ) , TARGET_STRING (
"psi" ) , 0 , 0 , 0 } , { 8 , TARGET_STRING (
"graphic_plane/FlightGear Preconfigured 6DoF Animation" ) , TARGET_STRING (
"DestinationPort" ) , 1 , 0 , 0 } , { 9 , TARGET_STRING (
"graphic_plane/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 10
, TARGET_STRING ( "graphic_plane/gama" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 11 , TARGET_STRING ( "graphic_plane/psi" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING ( "graphic_plane/theta" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 13 , TARGET_STRING (
"graphic_plane/x" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 14 ,
TARGET_STRING ( "graphic_plane/y" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 15 , TARGET_STRING ( "graphic_plane/z" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 16 , TARGET_STRING (
"graphic_plane/FlightGear Preconfigured 6DoF Animation/PacketSize" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P1" ) , 2 , 1 , 0 } , { 18 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P2" ) , 2 , 1 , 0 } , { 19 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P3" ) , 2 , 2 , 0 } , { 20 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P4" ) , 2 , 2 , 0 } , { 21 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P5" ) , 2 , 2 , 0 } , { 22 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P6" ) , 2 , 2 , 0 } , { 23 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P7" ) , 2 , 2 , 0 } , { 24 , TARGET_STRING (
 "graphic_plane/FlightGear Preconfigured 6DoF Animation/Pack net_fdm Packet for FlightGear"
) , TARGET_STRING ( "P8" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
"graphic_plane/FlightGear Preconfigured 6DoF Animation/Simulation Pace" ) ,
TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 26 , TARGET_STRING (
"graphic_plane/FlightGear Preconfigured 6DoF Animation/Simulation Pace" ) ,
TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING (
"graphic_plane/FlightGear Preconfigured 6DoF Animation/Simulation Pace" ) ,
TARGET_STRING ( "P3" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING (
"graphic_plane/FlightGear Preconfigured 6DoF Animation/Simulation Pace" ) ,
TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 30 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Bias" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Bias1" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Bias" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Bias1" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias1" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 44 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias1" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 48 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/f" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
 "graphic_plane/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . kgzgt0fmwb , & rtB . piczck40ik ,
& rtB . fyvanjft0r , & rtB . dhvfuzmxio , & rtB . gdfxliypwc , & rtB .
datymt25li , & rtP . FlatEarthtoLLA_LL0 [ 0 ] , & rtP . FlatEarthtoLLA_psi ,
& rtP . FlightGearPreconfigured6DoFAnimation_DestinationPort , & rtP .
Constant1_Value_c1zfghbdbg , & rtP . gama_Value , & rtP . psi_Value , & rtP .
theta_Value , & rtP . x_Value , & rtP . y_Value , & rtP . z_Value , & rtP .
PacketSize_Value , & rtP . Packnet_fdmPacketforFlightGear_P1 [ 0 ] , & rtP .
Packnet_fdmPacketforFlightGear_P2 [ 0 ] , & rtP .
Packnet_fdmPacketforFlightGear_P3 [ 0 ] , & rtP .
Packnet_fdmPacketforFlightGear_P4 [ 0 ] , & rtP .
Packnet_fdmPacketforFlightGear_P5 [ 0 ] , & rtP .
Packnet_fdmPacketforFlightGear_P6 [ 0 ] , & rtP .
Packnet_fdmPacketforFlightGear_P7 [ 0 ] , & rtP .
Packnet_fdmPacketforFlightGear_P8 , & rtP . SimulationPace_P1 , & rtP .
SimulationPace_P2 , & rtP . SimulationPace_P3 , & rtP . SimulationPace_P4 , &
rtP . Constant_Value , & rtP . Constant1_Value_powldid0mm , & rtP .
Constant_Value_a10nlnrpwn , & rtP . Constant1_Value_fipwkjv1k4 , & rtP .
CompareToConstant_const_ourdeuccjb , & rtP . Bias_Bias_fj5p4fqtlh , & rtP .
Bias1_Bias_f0n3qnphy4 , & rtP . Gain_Gain_jlh2aj143k , & rtP .
CompareToConstant_const_kcefi55u0t , & rtP . Bias_Bias_a2ngdjn3cn , & rtP .
Bias1_Bias_beqlpqjuhh , & rtP . Constant2_Value_o503yjt3g1 , & rtP .
CompareToConstant_const_lpgrzvb4zb , & rtP . Bias_Bias_l4mmzmheyi , & rtP .
Bias1_Bias_lwb2x0lz4t , & rtP . Gain_Gain , & rtP .
CompareToConstant_const_ln1vphan13 , & rtP . Bias_Bias_ezzhbbeoze , & rtP .
Bias1_Bias_g3odia1kmy , & rtP . Constant2_Value_c1ysq1elqy , & rtP .
Constant_Value_bugcmhye3g , & rtP . Constant1_Value , & rtP . Constant2_Value
, & rtP . Constant3_Value , & rtP . CompareToConstant_const_cuek01fcm1 , &
rtP . Bias_Bias_pz4bj2aggk , & rtP . Bias1_Bias_k5af1gwgsv , & rtP .
Constant2_Value_lzvy0bomjv , & rtP . CompareToConstant_const , & rtP .
Bias_Bias , & rtP . Bias1_Bias , & rtP . Constant2_Value_krlazp4iwf , & rtP .
Constant_Value_ah3sen0uqm , & rtP . Constant_Value_jntboeoydz , & rtP .
f_Value , & rtP . Constant_Value_h3mh4e54un , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "int" , "int32_T" , 0 , 0 , sizeof ( int32_T ) , ( uint8_T ) SS_INT32 , 0 ,
0 , 0 } , { "unsigned short" , "uint16_T" , 0 , 0 , sizeof ( uint16_T ) , (
uint8_T ) SS_UINT16 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 1 , 2 , 1 , 3 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { {
( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ;
static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL ) , (
NULL ) , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 6 , rtRootInputs , 0 , rtRootOutputs , 0 } , {
rtBlockParameters , 59 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2582406175U , 1527522671U , 249056648U ,
1448194977U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * graphic_plane_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void graphic_plane_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void graphic_plane_host_InitializeDataMapInfo (
graphic_plane_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
