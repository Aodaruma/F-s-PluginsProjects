//-----------------------------------------------------------------------------------
/*
	F's Plugins for VS2010/VS2012
*/
//-----------------------------------------------------------------------------------

#include "TouchDrawStraght.h"


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
	//----------------------------------------------------------------
	//�����̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_SEED,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					32000,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					144,			//�X���C�_�[�̍ő�l
					0,				//�f�t�H���g�̒l
					ID_SEED
					);
	
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_TARGET_VALUE,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					25,			//�X���C�_�[�̍ő�l
					5,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_TARGET_VALUE
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);	
	def.flags 	= 	PF_ParamFlag_START_COLLAPSED;
	PF_ADD_TOPIC(STR_TARGET_TOPIC, ID_TARGRT_TOPIC);
	//----------------------------------------------------------------
	//�|�b�v�A�b�v���j���[
	AEFX_CLR_STRUCT(def);	
	PF_ADD_POPUP(		STR_TARGET_MODE1, 
						3,	//���j���[�̐�
						2,	//�f�t�H���g
						STR_TARGET_MODE2,
						ID_TARGET_MODE
						);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_TARGET_COLOR, 
					0x00,
					0x00,
					0x00,
					ID_TARGET_COLOR
					);
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_COLOR_RANGE,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					25,				//�X���C�_�[�̍ő�l
					0,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_COLOR_RANGE
					);
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_DELTA_RANGE,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					90,				//�X���C�_�[�̍ő�l
					50,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_DELTA_RANGE
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_END_TOPIC(ID_TARGRT_TOPIC_END);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);	
	PF_ADD_ANGLE(STR_ROT,45,ID_ROT); 
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LENGTH_I_MAX,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					32000,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					200,			//�X���C�_�[�̍ő�l
					30,				//�f�t�H���g�̒l
					ID_LENGTH_I_MAX
					);

	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_LENGTH_I_RND,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_LENGTH_I_RND
					);
	//----------------------------------------------------------------
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_LENGTH_O_MAX,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					32000,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					200,			//�X���C�_�[�̍ő�l
					15,				//�f�t�H���g�̒l
					ID_LENGTH_O_MAX
					);
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_LENGTH_O_RND,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_LENGTH_O_RND
					);
	//----------------------------------------------------------------
	//�F�̎w��
	AEFX_CLR_STRUCT(def);
	PF_ADD_COLOR(	STR_COLOR, 
					0x00,
					0x00,
					0x00,
					ID_COLOR
					);
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_OPACITY,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					100,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_OPACITY
					);
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_OPACITY_RND,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_OPACITY_RND
					);
	//----------------------------------------------------------------
	//�����̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_POINT_COUNT,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					100,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					10,			//�X���C�_�[�̍ő�l
					2,				//�f�t�H���g�̒l
					ID_POINT_COUNT
					);
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_POINT_LENGTH,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					300,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					10,			//�X���C�_�[�̍ő�l
					1,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_POINT_LENGTH
					);
	
	//----------------------------------------------------------------
	//�Œ菬���̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_FIXED(	STR_BLOCK_VALUE,	//�p�����[�^�̖��O
					0, 				//���l���͂���ꍇ�̍ŏ��l
					300,			//���l���͂���ꍇ�̍ő�l
					0,				//�X���C�_�[�̍ŏ��l 
					100,			//�X���C�_�[�̍ő�l
					50,				//�f�t�H���g�̒l
					1,				//���l�\���Ɋւ���t���O 
					0,
					0,
					ID_BLOCK_VALUE
					);
	//----------------------------------------------------------------
	//�����̃X���C�_�[�o�[
	AEFX_CLR_STRUCT(def);
	PF_ADD_SLIDER(	STR_BLOCK_SIZE,	//�p�����[�^�̖��O
					8, 				//���l���͂���ꍇ�̍ŏ��l
					128,			//���l���͂���ꍇ�̍ő�l
					8,				//�X���C�_�[�̍ŏ��l 
					64,			//�X���C�_�[�̍ő�l
					2,				//�f�t�H���g�̒l
					ID_BLOCK_SIZE
					);
	
	//----------------------------------------------------------------
	//�`�F�b�N�{�b�N�X
	AEFX_CLR_STRUCT(def);
	PF_ADD_CHECKBOX(STR_ORG_CB1,
					STR_ORG_CB2,
					TRUE,
					0,
					ID_ORG
					);
	//----------------------------------------------------------------
	out_data->num_params = 	ID_NUM_PARAMS; 

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err GetParams(CFsAE *ae, ParamInfo *infoP)
{
	PF_Err		err 		= PF_Err_NONE;
	//-----------------------
	ERR(ae->GetADD(ID_SEED,&infoP->seed));
	ERR(ae->GetFIXED_PER2ONE(ID_TARGET_VALUE,&infoP->target_value));
	ERR(ae->GetPOPUP(ID_TARGET_MODE,&infoP->target_mode));
	ERR(ae->GetCOLOR(ID_TARGET_COLOR,&infoP->target_color));
	ERR(ae->GetFIXED_PER2ONE(ID_COLOR_RANGE,&infoP->color_range));
	ERR(ae->GetFIXED_PER2ONE(ID_DELTA_RANGE,&infoP->delta_range));

	ERR(ae->GetANGLE(ID_ROT,&infoP->rot));
	if (!err){
		infoP->rot %= 360L<<16;
		if ( infoP->rot<0) infoP->rot += 360L<<16; 
	}

	ERR(ae->GetADD(ID_LENGTH_I_MAX,&infoP->length_i_max));
	ERR(ae->GetFIXED_PER2ONE(ID_LENGTH_I_RND,&infoP->length_i_rnd));
	ERR(ae->GetADD(ID_LENGTH_O_MAX,&infoP->length_o_max));
	ERR(ae->GetFIXED_PER2ONE(ID_LENGTH_O_RND,&infoP->length_o_rnd));

	ERR(ae->GetCOLOR(ID_COLOR,&infoP->color));
	ERR(ae->GetFIXED_PER2ONE(ID_OPACITY,&infoP->opacity));
	ERR(ae->GetFIXED_PER2ONE(ID_OPACITY_RND,&infoP->opacity_rnd));

	ERR(ae->GetADD(ID_POINT_COUNT,&infoP->point_count));
	ERR(ae->GetFIXED(ID_POINT_LENGTH,&infoP->point_length));
	if (!err) {
		infoP->point_length = ae->downScaleNoClip(infoP->point_length);
		infoP->point_length += (1L<<16);
	}
	infoP->target_count = 0;
	
		
	ERR(ae->GetFIXED_PER2ONE(ID_BLOCK_VALUE,&infoP->block_value));
	ERR(ae->GetADD(ID_BLOCK_SIZE,&infoP->block_size));
	if (!err) {
		infoP->block_size = ae->downScaleNoClip(infoP->block_size);
		if ( infoP->block_size<2) infoP->block_size = 2;
	}

	A_long pW = ae->in_data->width;
	A_long pH = ae->in_data->height;
	if ((pW % infoP->block_size)!=0) { pW = pW/infoP->block_size +1;}else{pW = pW/infoP->block_size;}
	if ((pH % infoP->block_size)!=0) { pH = pH/infoP->block_size +1;}else{pH = pH/infoP->block_size;}
	infoP->block_count = pW * pH * infoP->block_value >> 16;

	ERR(ae->GetCHECKBOX(ID_ORG,&infoP->org));

	return err;
}
//-------------------------------------------------------------------------------------------------
static PF_Err 
	Exec (CFsAE *ae , ParamInfo *infoP)
{
	PF_Err	err = PF_Err_NONE;
	
	ae->out->clear();
	switch (infoP->target_mode)
	{
	case 1:
		FindTarget(ae,infoP->target_color,infoP->color_range);
		break;
	case 2:
		FindTargetDeltaBright(ae,infoP->delta_range);
		break;
	case 3:
		FindTargetDeltaAlpha(ae,infoP->delta_range);
		break;
	}

	blockDraw(ae,infoP->block_size,infoP->block_count,infoP->seed);
	
	
	switch(ae->pixelFormat()){
	case PF_PixelFormat_ARGB128:
		drawTouchS32(ae,infoP);
		break;
	case PF_PixelFormat_ARGB64:
		drawTouchS16(ae,infoP);
		break;
	case PF_PixelFormat_ARGB32:
		drawTouchS8(ae,infoP);
		break;
	}
	greenBlur(ae);
	
	copyAlpha(ae,infoP->color,infoP->org);
	
	
	return err;
}


//-------------------------------------------------------------------------------------------------
//�����_�����O�̃��C��
static PF_Err Render (
	PF_InData			*in_data,
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