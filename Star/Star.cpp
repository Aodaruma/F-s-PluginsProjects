//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010/VS2012
*/
//-----------------------------------------------------------------------------------

#include "Star.h"




//-------------------------------------------------------------------------------------------------
//AfterEffexts�Ƀp�����[�^��ʒB����
//Param_Utils.h���Q�Ƃ̂���
static PF_Err ParamsSetup (
	PF_InData		*in_data,
	PF_OutData		*out_data,
	PF_ParamDef		*params[],
	PF_LayerDef		*output)
{
	PF_Err			err = PF_Err_NONE;
	PF_ParamDef		def;

	//�S�̓I�ȃp�����[�^
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_LENGTH_PAR,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					500,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					100,			//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_LENGTH_PAR
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_STRONG_PAR,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					200,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,			//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_STRONG_PAR
					);
	//----------------------------------------------------------------
	//�p�x
	AEFX_CLR_STRUCT(def);
	PF_ADD_ANGLE(STR_ROT,0,ID_ROT); 
//----------------------------------------------------------------
//********************************************************
//********************************************************
	//�F�֌W
	AEFX_CLR_STRUCT(def);	
	def.flags 	= 	PF_ParamFlag_START_COLLAPSED;
	PF_ADD_TOPIC(STR_COLOR_TOPIC, ID_COLOR_TOPIC);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);	
	PF_ADD_POPUP(		STR_COLOR_KIND, 
						STR_COLOR_KIND_CNT,	//���j���[�̐�
						STR_COLOR_KIND_DEF,	//�f�t�H���g
						STR_COLOR_KIND_POP,
						ID_COLOR_KIND
						);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR_A,
					0xF7,
					0xFF,
					0xD2,
					ID_COLOR_A
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR_B, 
					0xF0,
					0xFF,
					0x05,
					ID_COLOR_B
					);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_COLOR_BORDER,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					30,			//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_COLOR_BORDER
					);
//----------------------------------------------------------------
//�F�֌W�I���
	AEFX_CLR_STRUCT(def);
	PF_END_TOPIC(ID_COLOR_TOPIC_END);
//----------------------------------------------------------------
//********************************************************
//********************************************************
	AEFX_CLR_STRUCT(def);	
	def.flags 	= 	PF_ParamFlag_START_COLLAPSED;
	PF_ADD_TOPIC(STR_LINE1_TOPIC, ID_LINE1_TOPIC);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LINE1_LENGTH,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					500,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					64,				//�f�t�H���g�̒l
					ID_LINE1_LENGTH
					);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_LINE1_STRONG,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,			//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_LINE1_STRONG
					);
//----------------------------------------------------------------
	//�p�x
	AEFX_CLR_STRUCT(def);
	PF_ADD_ANGLE(STR_LINE1_ANGLE,0,ID_LINE1_ROT); 
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_END_TOPIC(ID_LINE1_TOPIC_END);
//********************************************************
//********************************************************
	AEFX_CLR_STRUCT(def);	
	def.flags 	= 	PF_ParamFlag_START_COLLAPSED;
	PF_ADD_TOPIC(STR_LINE2_TOPIC, ID_LINE2_TOPIC);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LINE2_LENGTH,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					500,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					40,				//�f�t�H���g�̒l
					ID_LINE2_LENGTH
					);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_LINE2_STRONG,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,			//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_LINE2_STRONG
					);
//----------------------------------------------------------------
	//�p�x
	AEFX_CLR_STRUCT(def);
	PF_ADD_ANGLE(STR_LINE2_ANGLE,45,ID_LINE1_ROT); 
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_END_TOPIC(ID_LINE2_TOPIC_END);
	//----------------------------------------------------------------
//********************************************************
//********************************************************
	AEFX_CLR_STRUCT(def);	
	def.flags 	= 	PF_ParamFlag_START_COLLAPSED;
	PF_ADD_TOPIC(STR_LINE3_TOPIC, ID_LINE3_TOPIC);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LINE3_LENGTH,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					500,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					64,				//�f�t�H���g�̒l
					ID_LINE1_LENGTH
					);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_LINE3_STRONG,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,			//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_LINE3_STRONG
					);
//----------------------------------------------------------------
	//�p�x
	AEFX_CLR_STRUCT(def);
	PF_ADD_ANGLE(STR_LINE3_ANGLE,90,ID_LINE3_ROT); 
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_END_TOPIC(ID_LINE3_TOPIC_END);
//----------------------------------------------------------------
//********************************************************
//********************************************************
	AEFX_CLR_STRUCT(def);	
	def.flags 	= 	PF_ParamFlag_START_COLLAPSED;
	PF_ADD_TOPIC(STR_LINE4_TOPIC, ID_LINE4_TOPIC);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LINE4_LENGTH,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					500,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					40,				//�f�t�H���g�̒l
					ID_LINE4_LENGTH
					);
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_LINE4_STRONG,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,			//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_LINE4_STRONG
					);
//----------------------------------------------------------------
	//�p�x
	AEFX_CLR_STRUCT(def);
	PF_ADD_ANGLE(STR_LINE4_ANGLE,135,ID_LINE4_ROT); 
//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_END_TOPIC(ID_LINE4_TOPIC_END);
//----------------------------------------------------------------
	out_data->num_params = 	ID_NUM_PARAMS; 

	return err;
}

//-------------------------------------------------------------------------------------------------
static PF_Err GetParams(CFsAE *ae, ParamInfo *infoP)
{
	PF_Err		err 		= PF_Err_NONE;

	PF_FpShort	all_length;
	PF_FpShort	all_strong;
	PF_Fixed	all_angle;
	ERR(ae->GetFIXED2FpShort_P1(ID_LENGTH_PAR,&all_length));
	ERR(ae->GetFIXED2FpShort_P1(ID_STRONG_PAR,&all_strong));
	ERR(ae->GetANGLE(ID_ROT,&all_angle));

	ERR(ae->GetPOPUP(ID_COLOR_KIND,&infoP->colTable.kind));
	if (!err){
		switch (infoP->colTable.kind) {
		case skBtoA:
			ERR(ae->GetCOLOR(ID_COLOR_B,&infoP->colTable.col1));
			ERR(ae->GetCOLOR(ID_COLOR_A,&infoP->colTable.col2));
			break;
		case skAonly:
			ERR(ae->GetCOLOR(ID_COLOR_A,&infoP->colTable.col1));
			ERR(ae->GetCOLOR(ID_COLOR_A,&infoP->colTable.col2));
			break;
		case skBonly:
			ERR(ae->GetCOLOR(ID_COLOR_B,&infoP->colTable.col1));
			ERR(ae->GetCOLOR(ID_COLOR_B,&infoP->colTable.col2));
			break;
		case skAtoB:
		default:
			ERR(ae->GetCOLOR(ID_COLOR_A,&infoP->colTable.col1));
			ERR(ae->GetCOLOR(ID_COLOR_B,&infoP->colTable.col2));
			break;
		}
	}
	ERR(ae->GetFIXED2FpShort_P1(ID_COLOR_BORDER,&infoP->colTable.border));

	A_long maxLength =0;
	for ( A_long i=0; i<4; i++){
		A_long idx = ID_LINE1_TOPIC + i*5;
		ERR(ae->GetADD(idx+1,&infoP->line[i].length));
		if (!err) infoP->line[i].length = ae->downScaleNoClip(infoP->line[i].length);
		ERR(ae->GetFIXED2FpShort_P1(idx+2,&infoP->line[i].strong));
		ERR(ae->GetANGLE(idx+3,&infoP->line[i].angle));
		if ( !err){
			infoP->line[i].length = (A_long)((PF_FpShort)infoP->line[i].length * all_length);
			if (infoP->line[i].length<0) infoP->line[i].length = 0;
			else if (infoP->line[i].length>2500) infoP->line[i].length = 500*5; 
			if (maxLength < infoP->line[i].length) maxLength = infoP->line[i].length;
			
			infoP->line[i].strong = infoP->line[i].strong * all_strong;
			if (infoP->line[i].strong<0) infoP->line[i].strong = 0;
			
			infoP->line[i].angle = infoP->line[i].angle + all_angle;
			infoP->line[i].angle %= (360L<<16);
			if ( infoP->line[i].angle<0) infoP->line[i].angle += (360L<<16);
			if ( infoP->line[i].angle>=(180L<<16)) infoP->line[i].angle -= (180L<<16);  
		}
	}
	infoP->colTable.maxLength = maxLength;
	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;
	
	ERR(ae->out->clear());	//����
	ERR(TargetCopy(ae));	//RGB�̍ő�l���R�s�[�@rgba�������l��
	A_long MinValue =5;
	MinMask(ae,ae->downScaleNoClip( MinValue));			//�A���t�@�[�݂̂��ŏ���

	ERR(SubtrackAlpha(ae));	// (alpha = red - alpha) �Ŕ͈͂����߂�
	
	//RGB�̏���
	if ( infoP->colTable.kind == skScreen){
		ScreenCopy(ae);
	}else{
		FillColorCopy(ae,infoP->colTable.col1);
	}
	ERR(StarDraw(ae,infoP));
	ERR(AlphaMake(ae));
	ERR(ae->premultiply(0));
	return err;
}
//-------------------------------------------------------------------------------------------------
//�����_�����O�̃��C��
static PF_Err Render (	PF_InData		*in_data,
						PF_OutData		*out_data,
						PF_ParamDef		*params[],
						PF_LayerDef		*output )
{
	
	PF_Err	err = PF_Err_NONE;
	PF_Handle		pixelTable = NULL;
	
	CFsAE ae(in_data,out_data,params,output,ID_NUM_PARAMS);
	err =ae.resultErr();
	if (!err){
		ParamInfo info;
		ERR(GetParams(&ae,&info));
		ERR(Exec(&ae,&info));
	}
	return err;
	
}
//-----------------------------------------------------------------------------------
/*
	SmartFX�Ή��̏ꍇ�A�܂����̊֐����Ă΂�ăp�����[�^�̊l�����s��
*/
#if defined(SUPPORT_SMARTFX)
static PF_Err
PreRender(
	PF_InData			*in_data,
	PF_OutData			*out_data,
	PF_PreRenderExtra	*extraP)
{
	PF_Err		err 		= PF_Err_NONE;
	CFsAE ae(in_data,out_data,extraP,sizeof(ParamInfo),ID_NUM_PARAMS);
	err = ae.resultErr();
	if (!err){

		ParamInfo *infoP = reinterpret_cast<ParamInfo*>(ae.LockPreRenderData());
		if (infoP){
			ae.SetHostPreRenderData();
			ERR(GetParams(&ae,infoP));
			ERR(ae.UnSetPreRenderData());
			ae.UnlockPreRenderData();
		}else{
			err = PF_Err_OUT_OF_MEMORY;
		}
	}
	return err;
}
#endif
//-----------------------------------------------------------------------------------
#if defined(SUPPORT_SMARTFX)
static PF_Err
SmartRender(
	PF_InData				*in_data,
	PF_OutData				*out_data,
	PF_SmartRenderExtra		*extraP)
{
	PF_Err			err		= PF_Err_NONE,
					err2 	= PF_Err_NONE;

	CFsAE ae(in_data,out_data,extraP,ID_NUM_PARAMS);
	err = ae.resultErr();
	if (!err){
		ParamInfo *infoP = reinterpret_cast<ParamInfo*>(ae.LockPreRenderData());
		if (infoP){
			ERR(Exec(&ae,infoP));
			ERR2(ae.UnsetSmartRender());
			ae.UnlockPreRenderData();
		}else{
			err = PF_Err_OUT_OF_MEMORY;
		}
	}
	return err;
}
#endif

#include "Fs_Entry.h"