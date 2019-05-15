//-----------------------------------------------------------------------------------
/*
	PluginSkeleton for VS2010
*/
//-----------------------------------------------------------------------------------

#pragma once

#ifndef RandomLineNoise_H
#define RandomLineNoise_H

#include "Fs_Target.h"

#include "AEConfig.h"
#include "entry.h"

//#include "PrSDKAESupport.h"
#include "AE_Effect.h"
#include "AE_EffectCB.h"
#include "AE_EffectCBSuites.h"
#include "AE_Macros.h"
#include "AEGP_SuiteHandler.h"
#include "String_Utils.h"
#include "Param_Utils.h"
#include "Smart_Utils.h"

#if defined(PF_AE100_PLUG_IN_VERSION)
	#include "AEFX_SuiteHelper.h"
	#define refconType void*
#else
	#include "PF_Suite_Helper.h"
	#define refconType A_long
#endif

#ifdef AE_OS_WIN
	#include <Windows.h>
#endif

#include "../FsLibrary/FsAE.h"
//#include "FsAE.h"


//���[�U�[�C���^�[�t�F�[�X��ID
//ParamsSetup�֐���Render�֐���params�p�����[�^��ID�ɂȂ�
enum {
	ID_INPUT = 0,	// default input layer 
	ID_VALUE,
	ID_STRONG,
	ID_LENGTH_MIN,
	ID_LENGTH_MAX,
	ID_COLOR,
	ID_WEIGHT,
	ID_VERTUAL,
	ID_NUM_PARAMS
	};

#define STR_VALUE		"�m�C�Y��"
#define STR_STRONG		"�m�C�Y�̋���(%)"
#define STR_LENGTH_MIN	"�m�C�Y�̒���(�ŏ�)"
#define STR_LENGTH_MAX	"�m�C�Y�̒���(�ő�)"
#define STR_COLOR1		"�m�C�Y�̐F"
#define STR_COLOR2		"�J���["

#define STR_WEIGHT		"�m�C�Y�̕�"
#define STR_VERTUAL1	"�c������"
#define STR_VERTUAL2	"�c"


typedef struct ParamInfo{
	A_long		value;
	PF_Fixed	strong;
	A_long		lengthMin;
	A_long		lengthMax;
	PF_Boolean	color;
	PF_Boolean	vertualFlag;
	A_long		weight;
	A_long		x;
	A_long		y;
}ParamInfo;
typedef struct LineDrawParam{
	A_long		x0;
	A_long		x1;
	A_long		y0;
	A_long		y1;

	A_long		r;
	A_long		g;
	A_long		b;

	PF_PixelPtr	data;
	A_long		width;
	A_long		widthTrue;
	A_long		height;
}LineDrawParam;
//-----------------------------------------------------------------
extern "C" {
DllExport
PF_Err 
EntryPointFunc (
	PF_Cmd			cmd,
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output,
	void			*extraP);
}

//-------------------------------------------------------

#endif // RandomLineNoise_H
