//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010/VS2012
*/
//-----------------------------------------------------------------------------------

#pragma once
#ifndef FS_TAGET_H
#define FS_TAGET_H

//-----------------------------------------------------------------------------------
//�v���O�C���̎��ʂɎg���閼�O
#define FS_NAME			"F's ColorChange"

//-----------------------------------------------------------------------------------
//�v���O�C���̐����Ɏg���镶��
#define FS_DESCRIPTION	"�P�F�̐F�ς������܂�"

//-----------------------------------------------------------------------------------
//�v���O�C�����\������郁�j���[��
//#define FS_CATEGORY "F's Plugins-Fx"
//#define FS_CATEGORY "F's Plugins-Channel"
#define FS_CATEGORY "F's Plugins-Paint"
//#define FS_CATEGORY "F's Plugins-Script"
//#define FS_CATEGORY "F's Plugins-Draw"

//-----------------------------------------------------------
#define SUPPORT_SMARTFX			//�����L���ɂ����SmartFX+Float_Color�ɑΉ�����
//#define NO_USE_FSGRAPHICS	//�����L���ɂ����FsGraphics�֌W���C���N���[�h����Ȃ�

//-----------------------------------------------------------------------------------
//�v���O�C���̃o�[�W����
#define	MAJOR_VERSION	1
#define	MINOR_VERSION	1
#define	BUG_VERSION		0
//#define	STAGE_VERSION		PF_Stage_DEVELOP
//#define	STAGE_VERSION		PF_Stage_ALPHA
//#define	STAGE_VERSION		PF_Stage_BETA
#define	STAGE_VERSION		PF_Stage_RELEASE
#define	BUILD_VERSION	0

#define FS_VERSION		558592
//-----------------------------------------------------------------------------------
//out_flags
/*
out_data->out_flags
	PF_OutFlag_PIX_INDEPENDENT		1024
	PF_OutFlag_NON_PARAM_VARY			4
	PF_OutFlag_DEEP_COLOR_AWARE		33554432
	PF_OutFlag_USE_OUTPUT_EXTENT	64
	PF_OutFlag_I_EXPAND_BUFFER		512
	PF_OutFlag_I_DO_DIALOG				32
*/

#define FS_OUT_FLAGS	33556032	//�ʏ�͂�����
//#define FS_OUT_FLAGS	33556036	//��������L���ɂ���Ɩ��t���[�����Ƃɕ`�悷��BNON_PARAM_VARY�𓮍쒆�ɐ؂�ւ���Ƃ����������
//#define FS_OUT_FLAGS	1600		//8bit�̂�

#if defined(SUPPORT_SMARTFX)
#define FS_OUT_FLAGS2	5193
#else
#define FS_OUT_FLAGS2	73
#endif


#endif
