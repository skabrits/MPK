#ifndef RTW_HEADER_graphic_plane_h_
#define RTW_HEADER_graphic_plane_h_
#ifndef graphic_plane_COMMON_INCLUDES_
#define graphic_plane_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "graphic_plane_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME graphic_plane
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (12) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T datymt25li ; real_T gdfxliypwc ; real_T dhvfuzmxio ;
real_T kgzgt0fmwb ; real_T fyvanjft0r ; real_T piczck40ik ; real_T iz4nmuuwka
; real_T bsnqbjvtek ; real32_T hoiago1axe ; real32_T ol3rikcdfs ; real32_T
pipaywda1d ; uint8_T a23sv4sybs [ 408 ] ; } B ; typedef struct { int8_T
ogbwgfogay ; int8_T fs3gqwtfzy ; uint8_T ik244sfmwe [ 20 ] ; } DW ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
FlatEarthtoLLA_LL0 [ 2 ] ; real_T CompareToConstant_const ; real_T
CompareToConstant_const_lpgrzvb4zb ; real_T
CompareToConstant_const_ln1vphan13 ; real_T
CompareToConstant_const_cuek01fcm1 ; real_T
CompareToConstant_const_ourdeuccjb ; real_T
CompareToConstant_const_kcefi55u0t ; real_T FlatEarthtoLLA_psi ; int32_T
FlightGearPreconfigured6DoFAnimation_DestinationPort ; real_T
Packnet_fdmPacketforFlightGear_P8 ; real_T SimulationPace_P1 ; real_T
SimulationPace_P2 ; real_T SimulationPace_P3 ; real_T SimulationPace_P4 ;
real_T PacketSize_Value ; real_T Constant_Value ; real_T x_Value ; real_T
y_Value ; real_T Constant2_Value ; real_T Constant1_Value ; real_T
Constant_Value_ah3sen0uqm ; real_T Constant_Value_h3mh4e54un ; real_T
Constant_Value_jntboeoydz ; real_T f_Value ; real_T Bias_Bias ; real_T
Constant2_Value_krlazp4iwf ; real_T Bias1_Bias ; real_T Bias_Bias_l4mmzmheyi
; real_T Gain_Gain ; real_T Bias1_Bias_lwb2x0lz4t ; real_T
Constant_Value_bugcmhye3g ; real_T Constant3_Value ; real_T
Constant_Value_a10nlnrpwn ; real_T Constant1_Value_fipwkjv1k4 ; real_T
Bias_Bias_ezzhbbeoze ; real_T Constant2_Value_c1ysq1elqy ; real_T
Bias1_Bias_g3odia1kmy ; real_T Bias_Bias_pz4bj2aggk ; real_T
Constant2_Value_lzvy0bomjv ; real_T Bias1_Bias_k5af1gwgsv ; real_T
Constant1_Value_powldid0mm ; real_T Bias_Bias_a2ngdjn3cn ; real_T
Constant2_Value_o503yjt3g1 ; real_T Bias1_Bias_beqlpqjuhh ; real_T
Bias_Bias_fj5p4fqtlh ; real_T Gain_Gain_jlh2aj143k ; real_T
Bias1_Bias_f0n3qnphy4 ; real_T Constant1_Value_c1zfghbdbg ; real_T z_Value ;
real_T gama_Value ; real_T theta_Value ; real_T psi_Value ; uint16_T
Packnet_fdmPacketforFlightGear_P1 [ 2 ] ; uint16_T
Packnet_fdmPacketforFlightGear_P2 [ 2 ] ; uint16_T
Packnet_fdmPacketforFlightGear_P3 [ 3 ] ; uint16_T
Packnet_fdmPacketforFlightGear_P4 [ 3 ] ; uint16_T
Packnet_fdmPacketforFlightGear_P5 [ 3 ] ; uint16_T
Packnet_fdmPacketforFlightGear_P6 [ 3 ] ; uint16_T
Packnet_fdmPacketforFlightGear_P7 [ 3 ] ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern mxArray * mr_graphic_plane_GetDWork ( ) ; extern void
mr_graphic_plane_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_graphic_plane_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * graphic_plane_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
