//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010 and VS2012
*/
//-----------------------------------------------------------------------------------

#pragma once
#ifndef FS_TAGET_H
#define FS_TAGET_H

#define FS_NAME			"F's AlphaFix"
#define FS_DESCRIPTION	"�s����������h��Ԃ��܂��B"

//#define FS_CATEGORY "F's Plugins-Fx"
#define FS_CATEGORY "F's Plugins-Channel"
//#define FS_CATEGORY "F's Plugins-Paint"
//#define FS_CATEGORY "F's Plugins-Script"
//#define FS_CATEGORY "F's Plugins-Draw"

//-----------------------------------------------------------
#ifndef SUPPORT_SMARTFX			//�Q�d�o�^��h��
#define SUPPORT_SMARTFX			//�����L���ɂ����SmartFX+Float_Color�ɑΉ�����
#endif
//#define NO_USE_FSGRAPHICS	//�����L���ɂ����FsGraphics�֌W���C���N���[�h����Ȃ�


//-----------------------------------------------------------------------------------
//�o�[�W�����𔃂���AlphaFixPiPL.r��AE_Effect_Version���ς��邱��
#define	MAJOR_VERSION		1
#define	MINOR_VERSION		0
#define	BUG_VERSION			0
//#define	STAGE_VERSION		PF_Stage_DEVELOP
//#define	STAGE_VERSION		PF_Stage_ALPHA
//#define	STAGE_VERSION		PF_Stage_BETA
#define	STAGE_VERSION		PF_Stage_RELEASE
#define	BUILD_VERSION		0

//��̒l���v�Z��������
#define FS_VERSION	525824
//-----------------------------------------------------------------------------------
//out_flags
/*
	out_data->out_flags	  =	
		PF_OutFlag_PIX_INDEPENDENT
		//| PF_OutFlag_NON_PARAM_VARY	
		| PF_OutFlag_DEEP_COLOR_AWARE
		| PF_OutFlag_USE_OUTPUT_EXTENT
		| PF_OutFlag_I_EXPAND_BUFFER;
		//33556032	
		//33556036 +PF_OutFlag_NON_PARAM_VARY
*/
#define FS_OUT_FLAGS 33556032
//#define Fs_OUTFLAGS 33556036

//-----------------------------------------------------------------------------------
//out_flags2
/*
	out_data->out_flags2  =	PF_OutFlag2_FLOAT_COLOR_AWARE
						  | PF_OutFlag2_PARAM_GROUP_START_COLLAPSED_FLAG
						  | PF_OutFlag2_SUPPORTS_SMART_RENDER
						  | PF_OutFlag2_SUPPORTS_QUERY_DYNAMIC_FLAGS
						  | PF_OutFlag2_DOESNT_NEED_EMPTY_PIXELS;
						//5193
*/
#if defined(SUPPORT_SMARTFX)
#define FS_OUT_FLAGS2	5193
#else
#define FS_OUT_FLAGS2	73
#endif

#endif
